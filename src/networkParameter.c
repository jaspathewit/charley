/* File contains functions that create and destroy net parameter structures
  
(c) Mr J Hewitt 19-DEC-1994 */

/* standard included files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* project include files */
#include "network.h"

/* global varibles */

/* static varibles */

/* exported functions */
NETWORK_PARAM *create_network_param(void);

void destroy_network_param(NETWORK_PARAM *);

/* imported functions */
extern void delete_nodes(NODE *);

extern void logger(char *, ...);

/* local functions */

/* Function create_network_parameter

Function creates an empty network parameter structure

Function takes nothing

Function returns a pointer to the created network parameter structure. NULL indicates out of memory.

Function uses nothing

Function calls nothing

Function called

Modifications

*/

NETWORK_PARAM *create_network_param(void) {
	NETWORK_PARAM *temp = NULL;

	/* try and allocate memory for the network_param structure */
	if (temp = (NETWORK_PARAM *) malloc(sizeof(NETWORK_PARAM))) {
		/* logger allocation successful */
#ifdef DEBUG_MEM
    logger("Network param allocation %p",temp);
#endif

		/* allocation successful */
		/* fill structure with default values */
		strcpy(temp->struct_id, "NET PARAMS");

		/* link not connected */
		/* set run time parameters */
		temp->population_size = 0;
		temp->no_generations = 0;

		/* set the connectivity requirement */
		temp->connectivity_req = 0;

		/* set the acceptable delay */
		temp->acceptable_delay = 0;

		/* set the translocation mutation */
		temp->addel_mutation = 0;

		/* set the link mutaytion rate */
		temp->link_mutation = 0;

		/* the number of nodes in the network */
		temp->no_nodes = 0;

		/* a pointer to the nodes in the network */
		temp->node_list = NULL;
	} else {
		/* memory could not be allocated */
		/* logger allocation unsuccessful */
#ifdef DEBUG_MEM
	logger("network param allocation FAIL");
#endif

		printf("Out of memory allocating a network params");

		exit(0);
	}

	return (temp);
}

/* Function destroy_network_parameter

Function frees the memory allocated to the network parameter structure

Function takes a pointer to the network parameter structure to destroy

Function returns nothing

Function uses nothing

Function calls nothing

Function called by

Modification

*/
void destroy_network_param(NETWORK_PARAM *this_network_param) {
	/* free the memory used by the node lisy */
	delete_nodes(this_network_param->node_list);

	/* logger freed memory */
#ifdef DEBUG_MEM
logger("Network params freed %p",this_network_param);
#endif

	/* free the memory */
	free(this_network_param);

	return;
} 
