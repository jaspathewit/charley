/* Program Charley   
   
Program uses a Genetc algorithum to evolve networks that satisfy criteria   
entered into a network discription file.   
   
Full documentation of the program may be found in the final year report,   
"CHARLEY" a program to evolve networks. 1994    
   
(c) Mr J Hewitt 5-NOV-1994 */


/* program modification history

*/

/* standard included files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* project include files */
#include "network.h"


/* global varibles */
char *log_file_name = NULL;
unsigned long DEBUG;

/* static varibles */

/* exported functions */
int main(int, char *[]);

/* imported functions */
extern int check_args(int, char *[]);

extern NETWORK_PARAM *charley_init(char *);

extern void destroy_network_param(NETWORK_PARAM *);

extern void print_network_param(NETWORK_PARAM *);

extern POPULATION *make_population(NETWORK_PARAM *);

extern void print_population(POPULATION *, unsigned);

extern void destroy_population(POPULATION *, unsigned);

extern POPULATION *evolve(POPULATION *, NETWORK_PARAM *);

extern void logger(char *, ...);

/* local functions */

/* Function main

Function starts the charley program

Function takes nothing

Function returns nothing

Function uses nothing

Function calls

Function called by USER

Modifications

*/

int main(int no_args, char *args[]) {
	NETWORK_PARAM *network_params = NULL;
	POPULATION *temp = NULL;
	// unsigned count = 0;
	// float fitness = 0;

	/* check the arguments are ok */
	if (check_args(no_args, args)) {
		/* record the logfile name */
		log_file_name = args[2];

		/* initialize the network parameters from the ini file */
		network_params = charley_init(args[1]);
		if (network_params != NULL) {
			/* print out the network parameters */
			/*print_network_param(network_params);*/

			/* seed the random number */
			srand((unsigned) time(NULL));

			logger("**************Program start*************");

			/* create the initial population */
			temp = make_population(network_params);

			/* check made the initial population */
			if (temp) {
				/*print_population(temp, network_params->population_size);*/

				/* evolve the population network */

				temp = evolve(temp, network_params);
				if (temp == NULL) {
					/* error during network evolution */
					logger("Error during Evolution");
				}

				/* delete the final population */
				destroy_population(temp, network_params->population_size);
			}
			/* delete the network parameters */
			destroy_network_param(network_params);
		}
	}
	logger("***********Program end***********");

	return 0;
} 
