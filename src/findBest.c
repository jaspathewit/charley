/* File contains find_best_network  
  
(c) Mr J Hewitt 9-JAN-1994 */

/* standard included files */
#include <stdio.h>
#include <stdlib.h>

/* project include files */
#include "network.h"

/* global varibles */

/* static varibles */

/* exported functions */
NETWORK *find_best_network(POPULATION *, unsigned);

/* imported functions */
extern NETWORK *create_network();

extern void destroy_network(NETWORK *);

extern LINK *add_link(LINK *, LINK *);

extern void logger(char *, ...);

extern LINK *create_link(void);

/* local functions */
static NETWORK *exact_copy_network(NETWORK *);

static LINK *exact_copy_link(LINK *);

/* Function find_best_network

Function examins all the networks in a population and copies the best network

Function takes a pointer to a population and the number of networks in the population

Function returns a pointer to a copy of the best network

Function uses nothing

Function calls

Function called by

Modifications

*/

NETWORK *find_best_network(POPULATION *temp, unsigned no_networks) {
	unsigned count = 0;
	float best_fitness = 0;
	unsigned best_network_index = 0;
	NETWORK *best_network = NULL;

	/* return a pointer to the first network in the population */
	/* make a copy of this network */
	best_network = exact_copy_network(temp->networks[no_networks - 1]);

	return (best_network);


	/* set the best fitness to the fitness of the first network in the population */
	best_fitness = temp->networks[0]->fitness;

	/* search through the networks that make this population */
	for (count = 0; count < no_networks; count++) {
		/* check if this network has a better fitness that the previouse best */
		if (temp->networks[count]->fitness < best_fitness) {
			/* make this the new best fitness */
			best_fitness = temp->networks[count]->fitness;

			/* remember this networks index in the population */
			best_network_index = count;
		}
	}

	/* make a copy of this network */
	best_network = exact_copy_network(temp->networks[best_network_index]);

	return (best_network);
}

/* Function exact_copy_network

Function makes an exact copy of a network into a another network structure

Function takes a pointer to the network to copy

Function returns a pointer to a copy of the network if network is null
returns NULL

Function uses nothing

Function calls

Function called by

Modifications

*/

static NETWORK *exact_copy_network(NETWORK *network) {
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
				if (!(this_link = exact_copy_link(poss_link))) {
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

	/* return a pointer to the copy of te network */
	return (temp);
}

/* Function exact_copy_link

Function makes an exact copy of a link into a another link structure

Function takes a pointer to the link to copy

Function returns a pointer to a copy of the link if link is null
returns NULL

Function uses nothing

Function calls

Function called by

Modifications

*/

static LINK *exact_copy_link(LINK *link) {
	LINK *temp = NULL;

	/* check if the link is NULL */
	if (link) {
		/* create storage space for this link */
		temp = create_link();
		if (temp != NULL) {
			/* copy the contents of this link to the new storage */
			temp->node1 = link->node1;
			temp->node2 = link->node2;
			temp->speed = link->speed;
			temp->no_messages = link->no_messages;
			temp->message_len = link->message_len;
			temp->delay = link->delay;
			temp->cost = link->cost;
			temp->state = link->state;
			temp->prev = link->prev;
			temp->next = link->next;
		} else {
			logger("Out of memory copying link");
			printf("\nOut of memory copying link");
		}
	}

	/* return a pointer to the copy of the link */
	return (temp);
} 
