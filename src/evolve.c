/* File contains evolve   
   
(c) Mr J Hewitt 9-JAN-1994 */

/* standard included files */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* project include files */
#include "network.h"

/* global varibles */

/* static varibles */

/* exported functions */
POPULATION *evolve(POPULATION *, NETWORK_PARAM *);

/* imported functions */
extern POPULATION *mate(POPULATION *, NETWORK_PARAM *);

extern NETWORK *find_best_network(POPULATION *, unsigned);

extern float net_fitness(NETWORK *, NETWORK_PARAM *);

extern void destroy_population(POPULATION *, unsigned);

extern void destroy_network(NETWORK *);

extern void logger(char *, ...);

extern void print_population(unsigned, POPULATION *, unsigned);

extern void print_network(NETWORK *);

/* local functions */
static void sort_population(POPULATION *, NETWORK_PARAM *);

static int compare_networks(const void *, const void *);


/* Function evolve

Function evolves the population of networks through a number of generations

Function takes a painter to the initial population and the network parameters

Function returns a pointer to the final population NULL if any error occured during the evolution.

Function uses nothing

Function calls

Function called by

Modifications

*/

POPULATION *evolve(POPULATION *temp, NETWORK_PARAM *params) {
	unsigned generation = 0;
	NETWORK *best_network = NULL;
	NETWORK *temp_best_network = NULL;
	POPULATION *new_pop = NULL;
	POPULATION *current_pop = NULL;

	current_pop = temp;

	/* sort the population */
	sort_population(current_pop, params);
	/* store the best network that exists in the current population */
	best_network = find_best_network(current_pop, params->population_size);

	/* print the best network so far */
	printf("\nGeneration 0 best network");
	print_network(best_network);

	/* loop through the number of generations */
	for (generation = 1; generation <= params->no_generations; generation++) {
		/* mate the members of the population */
		new_pop = mate(current_pop, params);

		/* sort the population */
		sort_population(new_pop, params);

		/*print_population(generation,new_pop,params->population_size); */

		/* find the best network that exists in the new population */
		temp_best_network = find_best_network(new_pop, params->population_size);

		/* does this new_population have a better member that the current best network */
		if (compare_networks(&temp_best_network, &best_network) == 1) {
			/* destroy the current best network */
			destroy_network(best_network);

			/* record the new network as the current best */
			best_network = temp_best_network;

			/* print the best network so far */
			printf("\nGeneration %u produced a better network", generation);
			print_network(best_network);
		} else {
			/* destroy the temp best network */
			destroy_network(temp_best_network);
		}


		/* make the new population the current population */
		destroy_population(current_pop, params->population_size);
		current_pop = new_pop;

		logger("Processed generation %u", generation);

		/*print this generation */
		printf("\nGeneration %u ", generation);

		/* print out the current population stats */
		printf("\nFitness: Mean: %f Best: %f Worst: %f", new_pop->mean_fitness, new_pop->best_fitness,
		       new_pop->worst_fitness);
	}

	print_network(best_network);

	/* destroy the copy of the current best population */
	destroy_network(best_network);

	return (current_pop);
}

/* Function sort population

Function orders the population in accending order of fitness function

Function takes a painter to the population to sort and the network parameters

Function returns nothing.

Function uses the qsort function

Function calls

Function called by

Modifications

*/
static void sort_population(POPULATION *temp, NETWORK_PARAM *params) {
	/* call the qsort function */
	qsort((void *) temp->networks, (const size_t) params->population_size, sizeof(NETWORK *), compare_networks);

	return;
}

/* Function compare_networks

Function compares two network using delay as the first key

Function takes a pointers to the pointers to the two networks

Function returns -1 if the network1 fitness is less than network2 fitness
returns 0  if the fitness values of the two networks are identical
returns 1 if the fitness value of network1 is greater than that of network 2

Function uses

Function calls

Function called by

Modifications

*/
static int compare_networks(const void *network1, const void *network2) {
	int value = 0;
	float delay_net1 = 0;
	float delay_net2 = 0;
	float cost_net1 = 0;
	float cost_net2 = 0;

	char comp1[40];
	char comp2[40];

	/* store the delays and the costs */
	delay_net1 = (*(NETWORK **) network1)->delay;
	delay_net2 = (*(NETWORK **) network2)->delay;
	cost_net1 = (*(NETWORK **) network1)->connectivity + (*(NETWORK **) network1)->cost;
	cost_net2 = (*(NETWORK **) network2)->connectivity + (*(NETWORK **) network2)->cost;

	/* make the two strings */
	sprintf(comp1, "%010.6f%010.6f", delay_net1, cost_net1);
	sprintf(comp2, "%010.6f%010.6f", delay_net2, cost_net2);

	if (strcmp(comp1, comp2) <= -1)
		value = 1;
	if (strcmp(comp1, comp2) == 0)
		value = 0;
	if (strcmp(comp1, comp2) >= 1)
		value = -1;

	return (value);
}

















