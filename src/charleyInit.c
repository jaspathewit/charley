/* File contains charley_init */
/* (C) J Hewitt 2 Aug 1994 */

/* included files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* project include files*/
#include "network.h"

/* exported functions */
NETWORK_PARAM *charley_init(char *);

/* local functions */
static NETWORK_PARAM *fill_up(FILE *);

static unsigned get_network_params(FILE *, NETWORK_PARAM *);

static unsigned get_network_nodes(FILE *, NETWORK_PARAM *);

static unsigned get_network_links(FILE *, NETWORK_PARAM *);

static NODE *locate_node(char *, NODE *);

static unsigned long get_link_speed(FILE *);

static unsigned long get_link_cost(FILE *);

static unsigned update_allowed_links(NODE *, NODE *, LINK *);

static unsigned get_network_traffic(FILE *, NETWORK_PARAM *);

static float get_traffic_no_messages(FILE *);

static float get_traffic_message_len(FILE *);

static void update_traffic(NODE *, NODE *, TRAFFIC *);

/* imported functions */
extern NETWORK_PARAM *create_network_param(void);

extern void destroy_network_param(NETWORK_PARAM *);

extern NODE *create_node(void);

extern NODE *add_node(NODE *, NODE *);

extern LINK *create_link(void);

extern LINK *add_link(LINK *, LINK *);

extern LINK *copy_link(LINK *);

extern NODE *find_node(char *, NODE *);

extern TRAFFIC *create_traffic(void);

extern TRAFFIC *add_traffic(TRAFFIC *, TRAFFIC *);

extern char *ini_value(FILE *, char *);

extern void logger(char *, ...);

/* Function charley_init

Function reads in parameters of the network stored in the ini file into the
network_parameters structure

Function takes the filename of the ini file

Function returns a pointer to the network_parameters structure NULL
indicates the initilization failed */

NETWORK_PARAM *charley_init(char *file_name) {
	NETWORK_PARAM *temp = NULL;
	FILE *ini_file = NULL;

	/* open inifile and check ok */
	ini_file = fopen(file_name, "r");
	if (ini_file != NULL) {
		/* fill up the structure */
		logger("Initialization started");
		/*printf("\nStarted initialization"); */

		temp = fill_up(ini_file);
		if (temp != NULL) {
			logger("Initialization finished");
			/*printf("\nCompleted initialization"); */
		}

		/* close the file */
		fclose(ini_file);
	} else {
		/*record could not open the ini file */
		logger("Initialization failed. Could not open file %s", file_name);
		printf("\nCannot open file %s", file_name);
	}

	return (temp);
}

/* Function fill_up

Function fills the network_parameter structure with the
contents of the ini file

Function takes a pointer to the opened ini file

Function returns a pointer to the filled network_parameter structure
a NULL value indicates an out of memory condition or one of the
network_parameters is missing from the file */

static NETWORK_PARAM *fill_up(FILE *ini_file) {
	NETWORK_PARAM *temp = NULL;
	unsigned success = TRUE;
	// char *value=NULL;

	/* get the comm_parameters structure */
	temp = create_network_param();

	/* check that the memory was allocated */
	if (temp) {
		/* get the nodes */
		if (!get_network_nodes(ini_file, temp))
			success = FALSE;

		/* get the links */
		if (!get_network_links(ini_file, temp))
			success = FALSE;

		/* get the traffic */
		if (!get_network_traffic(ini_file, temp))
			success = FALSE;

		/* get the general network parameters */
		if (!get_network_params(ini_file, temp))
			success = FALSE;
	}

	/* check all elements assigned */
	if (!success) {
		/* print error message free memory and return */
		logger("Initilization failed");
		printf("\nInitilisation	Failed. Please check the itilisation file.");

		/* destroy the network_parameters created so far*/
		destroy_network_param(temp);
		temp = NULL;
	}

	return (temp);
}

/* Function get_network_params

Function fills the general network parameters of the ini file

Function takes a pointer to the opened ini file and the network_params structure

Function returns TRUE if all general elements were found.
a NULL value indicates an out of memory condition or one of the
network_parameters is missing from the file */

static unsigned get_network_params(FILE *ini_file, NETWORK_PARAM *temp) {
	unsigned success = TRUE;
	char *value = NULL;

	/* get the population size */
	if (!(value = ini_value(ini_file, "GENETICS.population_size"))) {
		/* record the failure */
		success = FALSE;
	} else {
		/* store this value */
		temp->population_size = (unsigned) atoi(value);
#ifdef DEBUG_MEM
		/*logger("freed %p",value);*/
#endif
		free(value);
	}

	/* get the number of generations */
	if (!(value = ini_value(ini_file, "GENETICS.no_generations"))) {
		/* record the failure */
		success = FALSE;
	} else {
		/* store this value */
		temp->no_generations = (unsigned) atoi(value);
#ifdef DEBUG_MEM
		/*logger("freed %p",value);*/
#endif
		free(value);
	}

	/* get the connectivity requirement */
	if (!(value = ini_value(ini_file, "NETWORK.connectivity_req"))) {
		/* record the failure */
		success = FALSE;
	} else {
		/* store this value */
		temp->connectivity_req = (unsigned) atoi(value);
#ifdef DEBUG_MEM
		/*logger("freed %p",value);*/
#endif
		free(value);
	}

	/* get the acceptable mean message delay */
	if (!(value = ini_value(ini_file, "NETWORK.acceptable_delay"))) {
		/* record the failure */
		success = FALSE;
	} else {
		/* store this value */
		temp->acceptable_delay = (float) atof(value);
#ifdef DEBUG_MEM
		/*logger("freed %p",value);*/
#endif
		free(value);
	}

	/* get the translocation mutation rate */
	if (!(value = ini_value(ini_file, "MUTATION.addel"))) {
		/* record the failure */
		success = FALSE;
	} else {
		/* store this value */
		temp->addel_mutation = (float) atof(value);
#ifdef DEBUG_MEM
		/*logger("freed %p",value);*/
#endif
		free(value);
	}

	/* get the link mutation rate */
	if (!(value = ini_value(ini_file, "MUTATION.link"))) {
		/* record the failure */
		success = FALSE;
	} else {
		/* store this value */
		temp->link_mutation = (float) atof(value);
#ifdef DEBUG_MEM
		/*logger("freed %p",value);*/
#endif
		free(value);
	}

	return (success);
}

/* Function get_network_nodes

Function fills the node list for a network and enters the number of nodes
in the network parameters.

Function takes a pointer to the opened ini file and the network_params structure

Function returns TRUE if all nodes allocated ok
a NULL value indicates an out of memory condition or one of the
node_parameters is missing from the file */

static unsigned get_network_nodes(FILE *ini_file, NETWORK_PARAM *temp) {
	unsigned success = TRUE;
	char *value = NULL;
	NODE *this_node = NULL;
	NODE *last_node = NULL;

	/* get the first node */
	value = ini_value(ini_file, "NODES.node_name");

	/* get all the nodes for this network */
	while (value) {
		/* get a node record for this node */
		this_node = create_node();

		/* check allocated ok */
		if (!this_node) {
			/* record the failure */
			success = FALSE;

#ifdef DEBUG_MEM
			/*logger("freed %p",value);*/
#endif
			free(value);

			/* get out of the loop */
			break;
		}

		/* store this nodes name */
		this_node->node_name = value;

		/* link this node into the list */
		last_node = add_node(last_node, this_node);

		/* add on to the number of nodes in the network */
		temp->no_nodes++;

		/* get the next node */
		value = ini_value(ini_file, ".node_name");
	}

	/* store the node list in the network params */
	temp->node_list = last_node;

	return (success);
}


/* Function get_network_links

Function fills the allowed link for all nodes in the network

Function takes a pointer to the opened ini file and the network_params structure

Function returns TRUE if all linkss allocated ok
a NULL value indicates an out of memory condition or one of the
link_parameters is missing from the file */

static unsigned get_network_links(FILE *ini_file, NETWORK_PARAM *temp) {
	unsigned success = TRUE;
	char *value = NULL;
	NODE *from_node = NULL;
	NODE *to_node = NULL;
	LINK *this_link = NULL;

	/* get the first link */
	value = ini_value(ini_file, "LINKS.from");

	/* get all the links for this network */
	while (value) {
		/* get a link record for this node */
		if (!(this_link = create_link())) {
			/* record the failure */
			success = FALSE;
			/* get out of the loop */
			break;
		}

		/* find the node record for from node */
		if (!(from_node = locate_node(value, temp->node_list))) {
			/* record the failure */
			success = FALSE;
			/* get out of the loop */
			break;
		}

		/* free value */
#ifdef DEBUG_MEM
		/*logger("freed %p",value);*/
#endif
		free(value);

		/* get the name of the to node */
		value = ini_value(ini_file, ".to");

		/* find the node record for to node */
		if (!(to_node = locate_node(value, temp->node_list))) {
			/* record the failure */
			success = FALSE;
			/* get out of the loop */
			break;
		}

		/* free value */
#ifdef DEBUG_MEM
		/*logger("freed %p",value);*/
#endif
		free(value);

		/* get the speed of the link */
		if (!(this_link->speed = get_link_speed(ini_file))) {
			/* record the failure */
			success = FALSE;

			/* get out of the loop */
			break;
		}

		/* get the cost of the link */
		if (!(this_link->cost = get_link_cost(ini_file))) {
			/* record the failure */
			success = FALSE;
			/* get out of the loop */
			break;
		}

		/* update the allowed link lists in the from and to nodes */
		if (!update_allowed_links(from_node, to_node, this_link)) {
			/* record the failure */
			success = FALSE;
			/* get out of the loop */
			break;
		}

		/* get the next link */
		value = ini_value(ini_file, ".from");
	}

	/* free any value that may still exist */
#ifdef DEBUG_MEM
	/*logger("freed %p",value);*/
#endif
	free(value);

	return (success);
}


/* Function locate_node

Function finds a node with a given name in the node_list

Function takes the string to search for and a pointer to the node list

Function returns a pointer to the node record NULL value that there is no node with
this name in the network*/

static NODE *locate_node(char *name, NODE *node_list) {
	NODE *temp = NULL;

	/* find the node record for from node */
	if (!(temp = find_node(name, node_list))) {
		/* indicate that the node could not be found */
		logger("Could not find a node with \"%s\" as a name", name);
		printf("\nCould not find node \"%s\"", name);
	}
	return (temp);
}


/* Function get_link_speed

Function gets the speed of a link

Function takes a pointer to the ini file

Function returns a the speed of this link zero indicates that the speed could not be read
from th ini file */
static unsigned long get_link_speed(FILE *ini_file) {
	char *value = NULL;
	unsigned long temp = 0;
	/* read in the speed of this link */
	if (!(value = ini_value(ini_file, ".speed"))) {
		/* record could not read the speed for a link */
		logger("Could not read link speed");
		printf("\nCould not read link speed");
	} else {
		/* record the link speed */
		temp = (unsigned) atol(value);
	}
	/* free the memory */
#ifdef DEBUG_MEM
	/*logger("freed %p",value);*/
#endif
	free(value);

	return (temp);
}


/* Function get_link_cost

Function gets the cost of a link

Function takes a pointer to the ini file

Function returns a the cost of this link 0 indicates that the cost could not be read
from the ini file */
static unsigned long get_link_cost(FILE *ini_file) {
	char *value = NULL;
	unsigned long temp = 0;

	/* read in the cost of this link */
	if (!(value = ini_value(ini_file, ".cost"))) {
		/* record could not read the cost for a link */
		logger("Could not read link cost");
		printf("\nCould not read link cost");
	} else {
		/* record the link speed */
		temp = (unsigned) atol(value);
	}
	/* free the memory */
#ifdef DEBUG_MEM
	/*logger("freed %p",value);*/
#endif
	free(value);

	return (temp);
}

/* Function update_allowed_links

Function adds a new allowed link to two nodes

Function takes a pointer to the from node the to node and the link to add

Function returns TRUE if the two allowed link lists were updated successfully*/
static unsigned update_allowed_links(NODE *from_node, NODE *to_node, LINK *this_link) {
	unsigned success = FALSE;
	LINK *dup_link = NULL;

	/* copy the link */
	dup_link = copy_link(this_link);
	if (dup_link != NULL) {
		/* record the success */
		success = TRUE;

		/* make this link point to the from and to nodes */
		dup_link->node1 = to_node;
		dup_link->node2 = from_node;

		/* add this link into the to nodes allowd link list */
		to_node->allowed_links = add_link(to_node->allowed_links, dup_link);

		/* increment the number of allowed link for this node*/
		to_node->no_links++;
	}

	/* make this link point to the from and to nodes */
	this_link->node1 = from_node;
	this_link->node2 = to_node;

	/* add this link into the from nodes allowd link list */
	from_node->allowed_links = add_link(from_node->allowed_links, this_link);

	/* increment the number of allowed link for this node*/
	from_node->no_links++;

	return (success);
}


/* Function get_network_traffic

Function fills the traffic list for all nodes in the network

Function takes a pointer to the opened ini file and the network_params structure

Function returns TRUE if all traffic allocated ok
a NULL value indicates an out of memory condition or one of the
traffic_parameters is missing from the file */

static unsigned get_network_traffic(FILE *ini_file, NETWORK_PARAM *temp) {
	unsigned success = TRUE;
	char *value = NULL;
	NODE *from_node = NULL;
	NODE *to_node = NULL;
	TRAFFIC *this_traffic = NULL;

	/* get the first traffic */
	value = ini_value(ini_file, "TRAFFIC.from");

	/* get all the traffic for this network */
	while (value) {
		/* get a traffic record for this node */
		if (!(this_traffic = create_traffic())) {
			/* record the failure */
			success = FALSE;
			/* get out of the loop */
			break;
		}

		/* find the node record for from node */
		if (!(from_node = locate_node(value, temp->node_list))) {
			/* record the failure */
			success = FALSE;
			/* get out of the loop */
			break;
		}

		/* free value */
#ifdef DEBUG_MEM
		/*logger("freed %p",value);*/
#endif
		free(value);

		/* get the name of the to node */
		value = ini_value(ini_file, ".to");

		/* find the node record for to node */
		if (!(to_node = locate_node(value, temp->node_list))) {
			/* record the failure */
			success = FALSE;
			/* get out of the loop */
			break;
		}

		/* free value */
#ifdef DEBUG_MEM
		/*logger("freed %p",value);*/
#endif
		free(value);

		/* get the number of messages */
		if (!(this_traffic->no_messages = get_traffic_no_messages(ini_file))) {
			/* record the failure */
			success = FALSE;
			/* get out of the loop */
			break;
		}

		/* get the length of the messages */
		if (!(this_traffic->message_len = get_traffic_message_len(ini_file))) {
			/* record the failure */
			success = FALSE;
			/* get out of the loop */
			break;
		}

		/* update the traffic records for the from node */
		update_traffic(from_node, to_node, this_traffic);

		/* get the next traffic */
		value = ini_value(ini_file, ".from");
	}

	/* free any value that may still exist */
#ifdef DEBUG_MEM
	/*logger("freed %p",value);*/
#endif
	free(value);

	return (success);
}


/* Function get_traffic_no_messages

Function gets the number of messages sent

Function takes a pointer to the ini file

Function returns a the number of messages zero indicates that the no of messages could not
be read from the ini file */
static float get_traffic_no_messages(FILE *ini_file) {
	char *value = NULL;
	float temp = 0;

	/* read in the no of messages of this link */
	if (!(value = ini_value(ini_file, ".no_messages"))) {
		/* record could not read the speed for a link */
		logger("Could not read the number of messages");
		printf("\nCould not read the number of messages");
	} else {
		/* record the number of messages */
		temp = (float) atof(value);
	}

	/* free the memory */
#ifdef DEBUG_MEM
	/*logger("freed %p",value);*/
#endif
	free(value);

	return (temp);
}


/* Function get_traffic_message_len

Function gets the average message length in this traffic

Function takes a pointer to the ini file

Function returns a the mean message length from the ini file */
static float get_traffic_message_len(FILE *ini_file) {
	char *value = NULL;
	float temp = 0;

	/* read in the cost of this link */
	if (!(value = ini_value(ini_file, ".message_len"))) {
		/* record could not read the cost for a link */
		logger("Could not read the message len");
		printf("\nCould not read the message len");
	} else {
		/* record the link speed */
		temp = (float) atof(value);
	}
	/* free the memory */
#ifdef DEBUG_MEM
	/*logger("freed %p",value);*/
#endif
	free(value);

	return (temp);
}

/* Function update_traffic

Function adds a new traffic record to the from node

Function takes a pointer to the from node the to node and the traffic record to add

Function returns TRUE if the the traffic records were updated successfully*/
static void update_traffic(NODE *from_node, NODE *to_node, TRAFFIC *this_traffic) {
	/* make this traffic point to the from and to nodes */
	this_traffic->node1 = from_node;
	this_traffic->node2 = to_node;

	/* add this traffic into the from nodes traffic */
	from_node->traffic = add_traffic(from_node->traffic, this_traffic);
} 
 
 
 
