/* File contains net_connectivity  
  
(c) Mr J Hewitt 7-NOV-1994 */

/* standard included files */
#include <stdio.h>
#include <stdlib.h>

/* project include files */
#include "network.h"

/* global varibles */

/* static varibles */

/* exported functions */
float net_connectivity(NETWORK *, NETWORK_PARAM *);

/* imported functions */
extern CONNECTIVITY_REC *create_con_rec(void);

extern CONNECTIVITY_REC *add_con_rec(CONNECTIVITY_REC *, CONNECTIVITY_REC *);

extern void reset_links(LINK *);

extern void reset_nodes(NODE *);

extern void delete_connectivity_recs(CONNECTIVITY_REC *);

extern void logger(char *, ...);

/* local functions */
static CONNECTIVITY_REC *calc_connectivity(LINK *, NODE *);

static unsigned long calc_conn_penalty(CONNECTIVITY_REC *, unsigned);

static unsigned find_paths(LINK *, NODE *, NODE *, NODE *);

static unsigned walk(LINK *, NODE *, NODE *);

static NODE *find_lowest_node(LINK *, NODE *);

static NODE *find_node(LINK *, NODE *);

static void count_hops(LINK *, NODE *, NODE *);

static NODE *get_lowest_node(NODE *);

static void reset_hops(NODE *);

/* Function net_connectivity

Function finds the number of link independant paths between all nodes and calculates the
connectivity penalty for this network

Function takes a pointer to the network and a pointer to the network parameters

Function returns the connectivity penalty for this network 0 indicates the
connectivity of the network could not be calculated 1 indicates the connectivity requirement is satisfied.

Function uses nothing

Function calls

Function called by

Modifications

*/
float net_connectivity(NETWORK *temp, NETWORK_PARAM *param) {
	CONNECTIVITY_REC *con_recs = NULL;
	unsigned long connectivity_penalty = 0;
	unsigned total_connectivity = 0;
	float connectivity = 0;

	/* obtain the number of link independant paths for each node */
	con_recs = calc_connectivity(temp->links, param->node_list);
	if (con_recs != NULL) {
		/* calculate the connectivity penalty */
		connectivity_penalty = calc_conn_penalty(con_recs, param->connectivity_req);

		/* calculate the total possible paths */
		total_connectivity = ((param->no_nodes * (param->no_nodes - 1)) * param->connectivity_req) / 2;

		/* calculate the connectivity */
		connectivity = ((float) connectivity_penalty / (float) total_connectivity);
	}

	/* delete all the connectivity records */
	delete_connectivity_recs(con_recs);

#ifdef DEBUG_MEM
logger("Calculated connectivity penalty");
#endif

	return (connectivity);
}

/* Function calc_connectivity

Function calculates the number of independant paths between each node in the network

Function takes a pointer to the network and the list of nodes in the network

Function returns a pointer to the connectivity list

Function uses nothing

Function calls

Function called by

Modifications

*/
static CONNECTIVITY_REC *calc_connectivity(LINK *temp, NODE *node_list) {
	NODE *start_node = NULL;
	NODE *end_node = NULL;
	CONNECTIVITY_REC *this_con_rec = NULL;
	CONNECTIVITY_REC *last_con_rec = NULL;
	unsigned paths = 0;

	/* start from the begining */
	start_node = node_list;
	end_node = node_list->prev;

	/* find connectivity between all nodes */
	while (start_node->prev) {
		while (end_node) {
			paths = find_paths(temp, start_node, end_node, node_list);

			/* make some storage for this connectivity record */
			this_con_rec = create_con_rec();

			/* record the number of paths between node 1 and node 2 */
			this_con_rec->node1 = start_node;
			this_con_rec->node2 = end_node;
			this_con_rec->connectivity = paths;

			/* store this record */
			last_con_rec = add_con_rec(last_con_rec, this_con_rec);

			/* reset all link, nodes and hop counts */
			reset_links(temp);
			reset_nodes(node_list);
			reset_hops(node_list);


			/* move on to the next end node */
			end_node = end_node->prev;
		}

		/* move on to the next start node */
		start_node = start_node->prev;
		end_node = start_node->prev;
	}

	return (last_con_rec);
}

/* Function find_paths

Function finds number of independant paths between two nodes in the network

Function takes a pointer to the network a pointer to the start and end nodes and the list of nodes in the network

Function returns the number of independent paths between the two nodes

Function uses nothing

Function calls

Function called by

Modifications

*/
static unsigned find_paths(LINK *temp, NODE *start, NODE *end, NODE *node_list) {
	unsigned no_paths = 0;

	/* count the number of hops from the end node to all other nodes */
	count_hops(temp, end, node_list);

	/* reset all the nodes */
	reset_nodes(node_list);

	/* try to walk from the start node to the end node */
	while (walk(temp, start, end)) {
		/* there is a path from start to end */
		no_paths++;
	}

	return (no_paths);
}

/* Function walk

Function attempts to find a path between two nodes in the network

Function takes a pointer to the network a pointer to the start and end nodes

Function returns True if a path exists False if not

Function uses nothing

Function calls

Function called by

Modifications

*/
static unsigned walk(LINK *temp, NODE *start, NODE *end) {
	unsigned success = 0;
	NODE *temp_start = NULL;

	/* mark this node as visited */
	start->state = 1;

	/* try to find a link from this node to another node */
	/* that has not been previously visited or deleted */
	temp_start = find_lowest_node(temp, start);

	/* if there is a node */
	while (temp_start) {
		/* is this node the end node */
		if (temp_start == end) {
			/* return the success */
			success = 1;
			break;
		} else {
			/* try to find a path from this node to the end node */
			success = walk(temp, temp_start, end);
			if (success != 0) {
				/* if found a path from this node to the end node */
				/* get out of the loop */
				break;
			}
		}

		/* try to find another link */
		temp_start = find_lowest_node(temp, start);
	}

	/* cannot find a walk from this node to the end node */
	return (success);
}

/* Function find_lowest_node

Function attempts to find a node that is connected to this node that has the lowest hop count

Function takes a pointer to the network a pointer to the node to search from

Function returns a pointer to the found node NULL indicates that no more nodes are connected

Function uses nothing

Function calls

Function called by

Modifications

*/
static NODE *find_lowest_node(LINK *temp, NODE *poss) {
	NODE *lowest_node = NULL;
	LINK *used_link = NULL;
	LINK *net_poss = NULL;

	/* start from the first link in the network */
	net_poss = temp;

	/* search through all the links in the network */
	while (net_poss) {
		/* check if this link has been used before */
		if (!net_poss->state) {
			/* check if this link is connected to the required node */
			if ((net_poss->node1) == poss && ((net_poss->node2)->state) == FALSE) {
				/* check if no current lowest hop count */
				if (lowest_node == NULL) {
					/* remember the node and the link */
					lowest_node = net_poss->node2;
					used_link = net_poss;
				} else {
					/* check if this node has a lower hop count */
					if ((net_poss->node2)->hops < lowest_node->hops) {
						/* remember the node and the link */
						lowest_node = net_poss->node2;
						used_link = net_poss;
					}
				}
			}

			/* check if this link is connected to the required node */
			if ((net_poss->node2) == poss && ((net_poss->node1)->state) == 0) {
				/* check if no current lowest hop count */
				if (lowest_node == NULL) {
					/* remember the node and the link */
					lowest_node = net_poss->node1;
					used_link = net_poss;
				} else {
					/* check if this node has a lower hop count */
					if ((net_poss->node1)->hops < lowest_node->hops) {
						/* remember the node and the link */
						lowest_node = net_poss->node1;
						used_link = net_poss;
					}
				}
			}
		}
		/* move on to the next link */
		net_poss = net_poss->prev;
	}
	/* check if a node was found */
	if (lowest_node) {
		/* mark the link as used */
		used_link->state = TRUE;
	}

	/*return any found node */
	return (lowest_node);
}

/* Function count_hops

Function counts the number of hops between this node and all other nodes in the network

Function takes a pointer to the network a pointer to the node to count from

Function returns  nothing

Function uses nothing

Function calls

Function called by

Modifications

*/
static void count_hops(LINK *temp, NODE *end_node, NODE *node_list) {
	unsigned no_hops = 0;
	NODE *poss = NULL;
	NODE *temp_node = NULL;

	/* start from the last node */
	poss = end_node;

	/* loop through all the nodes */
	while (poss) {
		/* mark this node as having been used as the end node */
		poss->state = 2;

		/* make this nodes hop count the current hop count and add one */
		no_hops = poss->hops + 1;

		/* find the first neighbour for this node that has not been used already */
		temp_node = find_node(temp, poss);

		/* loop through all the neighbours */
		while (temp_node) {
			/* mark this neighbour as having been processed */
			temp_node->state = 1;

			/* if the current hop count is less than the neigbouring nodes hops count or the count is zero */
			if (temp_node->hops < no_hops) {
				/* update this nodes hop count */
				temp_node->hops = no_hops;
			}

			/* find the next neigbour */
			temp_node = find_node(temp, poss);
		}

		/* find a node in the network with the lowest hop count */
		poss = get_lowest_node(node_list);
	}

	return;
}

/* Function find_node

Function attempts to find a node that is connected to this node
that has not been previously visited or deleted

Function takes a pointer to the network a pointer to the node to search from

Function returns a pointer to the found node NULL indicates that no more nodes are connected

Function uses nothing

Function calls

Function called by

Modifications

*/
static NODE *find_node(LINK *temp, NODE *poss) {
	NODE *connected_node = NULL;
	LINK *net_poss = NULL;

	/* start from the first link in the network */
	net_poss = temp;

	/* search through all the links in the network */
	while (net_poss) {
		/* check if this link has been used before */
		if (!net_poss->state) {
			/* check if this link is connected to the required node */
			if ((net_poss->node1) == poss && ((net_poss->node2)->state) == 0) {
				/* return a pointer to this node */
				connected_node = net_poss->node2;

				/* get out of the loop */
				break;
			}

			/* check if this link is connected to the required node */
			if ((net_poss->node2) == poss && ((net_poss->node1)->state) == 0) {
				/* return a pointer to this node */
				connected_node = net_poss->node1;

				/* get out of the loop */
				break;
			}
		}
		/* move on to the next link */
		net_poss = net_poss->prev;
	}

	/*return any found node */
	return (connected_node);
}


/* Function get_lowest_node

Function finds a node that has not been used that has the lowest non zero hop count in the network

Function takes a pointer to the node list

Function returns a pointer to the found node NULL indicates that no more nodes are present

Function uses nothing

Function calls

Function called by

Modifications

*/
static NODE *get_lowest_node(NODE *node_list) {
	NODE *node_poss = NULL;
	NODE *lowest_node = NULL;

	/* start from the beginning of the node poss */
	node_poss = node_list;

	/* loop through all the nodes */
	while (node_poss) {
		/* check if this node has a hop count and has not been used as the end before */
		if ((node_poss->hops != 0) && (node_poss->state != 2)) {
			/* if have no current lowest */
			if (lowest_node == NULL) {
				/* make the current lowest this node */
				lowest_node = node_poss;
			} else {
				/* check  if this node hop count less than the current lowest */
				if (node_poss->hops < lowest_node->hops) {
					/* make the current lowest this node */
					lowest_node = node_poss;
				}
			}
		}
		/* move on to the next node */
		node_poss = node_poss->prev;
	}

	/*return any found node */
	return (lowest_node);
}

/* Function reset_hops

Function resets the number of hops of all nodes to 0

Function takes a pointer to the node list

Function returns nothing

Function uses nothing

Function calls

Function called by

Modifications

*/
static void reset_hops(NODE *temp) {
	NODE *poss = NULL;

	/* start from the beginning of the linked list */
	poss = temp;

	/* loop through the entire network */
	while (poss) {
		/* reset this link */
		poss->hops = 0;

		/* move on to the next link */
		poss = poss->prev;
	}

	return;
}

/* Function calc_conn_penalty

Function calculates this networks connectivity penalty

Function takes a pointer to the list of con_recs to reqired connectivity and the connectivity
to apply

Function returns the connectivity penalty for this netwok

Function uses nothing

Function calls

Function called by

Modifications

*/

static unsigned long calc_conn_penalty(CONNECTIVITY_REC *temp, unsigned req_conn) {
	CONNECTIVITY_REC *poss_con_rec = NULL;
	unsigned long penalty = 0;

	/* start from the beginning of the linked list */
	poss_con_rec = temp;

	/* loop through all the connectivity records */
	while (poss_con_rec) {
		/* calculate the penalty for this conn record */
		if (poss_con_rec->connectivity < req_conn) {
			penalty += (req_conn - poss_con_rec->connectivity);
		}

		/* move on to the next node */
		poss_con_rec = poss_con_rec->prev;
	}

	return (penalty);
} 
