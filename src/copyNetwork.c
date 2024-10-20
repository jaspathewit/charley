/* File contains copy_network  
  
(c) Mr J Hewitt 5-NOV-1994 */

/* standard included files */
#include <stdio.h>
#include <stdlib.h>

/* project include files */
#include "network.h"

/* global varibles */

/* static varibles */

/* exported functions */
NETWORK *copy_network(NETWORK *);

/* imported functions */
extern NETWORK *create_network(void);

extern LINK *copy_link(LINK *);

extern LINK *add_link(LINK *, LINK *);

extern void destroy_network(NETWORK *);

extern void logger(char *, ...);

/* local functions */

/* Function copy_network

Function copys a network into a another network structure

Function takes a pointer to the network to copy

Function returns a pointer to a copy of the network if network is null
returns NULL

Function uses nothing

Function calls

Function called by

Modifications

*/

NETWORK *copy_network(NETWORK *network) {
	NETWORK *temp = NULL;
	LINK *this_link = NULL;
	LINK *poss_link = NULL;

	/* check if the network is NULL */
	if (network) {
		/* create storage space for network copy */
		temp = create_network();
		if (temp != NULL) {
			/* copy the factors */
			temp->delay = network->delay;
			temp->connectivity = network->connectivity;
			temp->duplication = network->duplication;
			temp->cost = network->cost;

			/* copy the monetory cost of this network */
			temp->real_cost = network->real_cost;

			/* copy the fitness value for this network */
			temp->fitness = network->fitness;

			/* copy the number of links in this network */
			temp->no_links = network->no_links;

			/* copy the links that make the network */
			poss_link = network->links;

			/* copy the links contents of network to the new storage */
			while (poss_link) {
				/* copy this link */
				if (!(this_link = copy_link(poss_link))) {
					/* could not copy the link */
					/*destroy the partial copy of the network */
					destroy_network(temp);
					temp = NULL;
					break ;
				}

				/* set the linked list pointers to null	*/
				this_link->prev = NULL;
				this_link->next = NULL;

				/* add this copy of the link into the network */
				temp->links = add_link(temp->links, this_link);

				/* move on to the next link */
				poss_link = poss_link->prev;
			}
		} else {
			logger("Out of memory copying network");
			printf("\nOut of memory copying network");
		}
	}

	/* return a pointer to the copy of the network */
	return (temp);
} 
