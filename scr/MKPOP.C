/* File contains make_population  
  
(c) Mr J Hewitt 7-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
POPULATION * make_population(NETWORK_PARAM *);  
  
/* imported functions */  
extern NETWORK * create_network(void);  
extern POPULATION * create_population(unsigned);  
extern void distroy_population(POPULATION *, unsigned);  
extern LINK * make_rand_network(NETWORK_PARAM *);     
extern unsigned count_links(LINK *);  
extern float net_fitness(NETWORK *, NETWORK_PARAM *);  
/* local functions */                         
  
/* Function make_population  
  
Function creates a population of random networks  
  
Function takes the network parameters  
  
Function returns a pointer to the population NULL indicates out of memory  
  
Function uses nothing  
  
Function calls  
  
Function called by   
  
Modifications  
  
*/  
  
POPULATION * make_population(NETWORK_PARAM * params)  
{  
  
	POPULATION * temp=NULL;  
	unsigned count=0;                           
	NETWORK * network=NULL;  
	unsigned success=TRUE;         
	float fitness=0;  
	double total_fitness=0;  
	  
/* create an empty population */  
if(temp=create_population(params->population_size))  
	{                                                   
	/* add the required number of networks to the population */  
	for(count=0;count<params->population_size;count++)  
		{                                       
		/* create some storage space for the network */  
		if(!(network=create_network()))  
			{  
			/* record the failure */  
			success=FALSE;  
			/* get out of the loop */  
			break;  
			}  
		  
		/* create a random network using the node list */  
		if(!(network->links=make_rand_network(params)))  
    		{                                          
    		/* record the failure */  
			success=FALSE;  
			/* get out of the loop */  
			break;  
			}  
		  
		/* store the number of links in this network */  
		network->no_links=count_links(network->links);  
				  
    	/* store the fitness value of this network */  
		if((fitness=net_fitness(network,params))==-1)  
			{  
			/* there was an error assesing the networks fitness */  
			success=FALSE;  
			/* get out of the loop */  
			break;  
			}               
		/* store the fitness value for this network */  
		network->fitness=fitness;  
			  
		/* add this fitness to the total fitness of the population */  
		total_fitness+=(double)fitness;  
		  
		/* if this fitness is better than the previous best fitness then store it */  
		if(fitness<temp->best_fitness||count==0)  
			temp->best_fitness=fitness;  
		  
		/* if this fitness is worse than the previous worst fitness then store it */  
		if(fitness>temp->worst_fitness||count==0)  
			temp->worst_fitness=fitness;  
	  
			  
		/* store this tempory net in the population */  
		temp->networks[count]=network;	  
		}	  
	  
	/* add in the total fitness and mean fitness to the population */  
	temp->total_fitness=total_fitness;  
	temp->mean_fitness=total_fitness/params->population_size;  
	}  
  
/* check that there were no errors */  
if(!success)  
	{  
	/* there was an error */  
	distroy_population(temp,params->population_size);  
	temp=NULL;  
	}	  
	/*printf("\n\n0 Population mean fitness %f best fitness %f worst fitness %f",temp->mean_fitness, temp->best_fitness, temp->worst_fitness);	*/  
	  
return(temp);  
  
} 
