/* File contains functions that create and destroy traffic structures
  
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
TRAFFIC *create_traffic(void);

void destroy_traffic(TRAFFIC *);

/* imported functions */
extern void logger(char *, ...);

/* local functions */

/* Function create_traffic

Function creates an empty traffic structure

Function takes nothing

Function returns a pointer to the created traffic. NULL indicates out of memory.

Function uses nothing

Function calls nothing

Function called make_rand_network

Modifications

*/

TRAFFIC *create_traffic(void) {
	TRAFFIC *temp = NULL;

	/* try and allocate memory for the traffic structure */
	temp = (TRAFFIC *) malloc(sizeof(TRAFFIC));
	if (temp != NULL) {
		/* logger allocation successful */
#ifdef DEBUG_MEM
    logger("traffic allocation %p",temp);
#endif

		/* allocation successful */
		/* fill structure with default values */
		strcpy(temp->struct_id, "TRAFFIC");

		/* traffic not connected */
		temp->node1 = NULL;
		temp->node2 = NULL;

		/* no messages is zero */
		temp->no_messages = 0;

		/* average message length */
		temp->message_len = 0;

		/* traffic is not connected into a traffic list */
		temp->prev = NULL;
		temp->next = NULL;
	} else {
		/* memory could not be allocated */
		/* logger allocation unsuccessful */
#ifdef DEBUG_MEM
	logger("Traffic allocation FAIL");
#endif

		printf("Out of memory allocating a traffic");

		exit(0);
	}

	return (temp);
}

/* Function destroy_traffic

Function frees the memory allocated to a traffic structure

Function takes a pointer to the traffic structure to destroy

Function returns nothing

Function uses nothing

Function calls nothing

Function called by

Modification

*/
void destroy_traffic(TRAFFIC *this_traffic) {
	/* logger freed memory */
#ifdef DEBUG_MEM
logger("traffic freed %p",this_traffic);
#endif

	/* free the memory */
	free(this_traffic);

	return;
} 
