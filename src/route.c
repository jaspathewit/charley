/* File contains functions that create and destroy route record structures
  
(c) Mr J Hewitt 21-NOV-1994 */

/* standard included files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* project include files */
#include "network.h"

/* global varibles */

/* static varibles */

/* exported functions */
ROUTE_REC *create_route_rec(void);

void destroy_route_rec(ROUTE_REC *);

/* imported functions */
extern void logger(char *, ...);

/* local functions */

/* Function create_route_rec

Function creates an empty route_rec structure

Function takes nothing

Function returns a pointer to the created record. NULL indicates out of memory.

Function uses nothing

Function calls nothing

Function called by

Modifications

*/

ROUTE_REC *create_route_rec(void) {
	ROUTE_REC *temp = NULL;

	/* try and allocate memory for the link structure */
	temp = (ROUTE_REC *) malloc(sizeof(ROUTE_REC));
	if (temp != NULL) {
		/* logger allocation successful */
#ifdef DEBUG_MEM
	logger("Route allocation %p",temp);
#endif
		/* allocation successful */
		/* fill structure with default values */
		strcpy(temp->struct_id, "ROUTE_REC");
		temp->node1 = NULL;
		temp->node2 = NULL;
		temp->cost = 0;
		temp->route = NULL;
		temp->prev = NULL;
		temp->next = NULL;
	} else {
		/* memory could not be allocated */
		/* logger allocation unsuccessful */
#ifdef DEBUG_MEM
	logger("Route allocation FAIL");
#endif
		printf("Out of memory allocating a route");

		exit(0);
	}

	return (temp);
}

/* Function destroy_route_rec

Function frees the memory allocated to a route_rec structure

Function takes a pointer to the route_rec structure to destroy

Function returns nothing

Function uses nothing

Function calls nothing

Function called by

Modification

*/
void destroy_route_rec(ROUTE_REC *this_route_rec) {
	/* logger freed memory */
#ifdef DEBUG_MEM
logger("Route freed %p",this_route_rec);
#endif

	/* free the memory */
	free(this_route_rec);

	return;
} 
