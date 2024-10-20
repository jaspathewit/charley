/* File contains functions that create and destroy node structures
  
(c) Mr J Hewitt 5-NOV-1994 */

/* standard included files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* project include files */
#include "network.h"

/* global varibles */

/* static varibles */

/* exported functions */
NODE *create_node(void);

void destroy_node(NODE *);

/* imported functions */
extern void logger(char *, ...);

/* local functions */

/* Function create_node

Function creates an empty node structure

Function takes nothing

Function returns a pointer to the created node. NULL indicates out of memory.

Function uses nothing

Function calls nothing

Function called make_rand_link

Modifications

*/

NODE *create_node(void) {
	NODE *temp = NULL;

	/* try and allocate memory for the link structure */
	temp = (NODE *) malloc(sizeof(NODE));
	if (temp != NULL) {
		/* logger allocation successful */
#ifdef DEBUG_MEM
	logger("Node allocation %p",temp);
#endif

		/* allocation successful */
		/* fill structure with default values */
		strcpy(temp->struct_id, "NODE");

		temp->node_name = NULL;
		temp->state = 0;
		temp->hops = 0;
		temp->no_links = 0;
		temp->allowed_links = NULL;
		temp->traffic = NULL;
		temp->prev = NULL;
		temp->next = NULL;
	} else {
		/* memory could not be allocated */
		/* logger allocation unsuccessful */
#ifdef DEBUG_MEM
	logger("Node allocation FAIL");
#endif
		printf("Out of memory allocating a node");

		exit(0);
	}

	return (temp);
}

/* Function destroy_node

Function frees the memory allocated to a node structure

Function takes a pointer to the node structure to destroy

Function returns nothing

Function uses nothing

Function calls nothing

Function called by

Modification

*/
void destroy_node(NODE *this_node) {
	/* logger freed memory */
#ifdef DEBUG_MEM
logger("Node name freed  %p",this_node->node_name);
#endif

	/* free the memoy allocated to the node name */
	free(this_node->node_name);

	/* logger freed memory */
#ifdef DEBUG_MEM
logger("Node freed %p",this_node);
#endif
	/* free the memory */
	free(this_node);

	return;
} 
