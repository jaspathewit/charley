/* File contains print_population   
   
(c) Mr J Hewitt 7-NOV-1994 */   
   
/* standard included files */   
#include <stdio.h>   
#include <stdlib.h>                                    
              
/* project in clude files */   
#include "network.h"   
   
/* global varibles */   
   
/* static varibles */   
   
/* exported functions */   
void print_population(unsigned, POPULATION *, unsigned);   
   
/* imported functions */   
extern void print_network(NETWORK *);   
   
/* local functions */                          
   
/* Function print_population   
   
Function creates prints out the contents of a population of networks   
   
Function takes the pop id, the population to print and the number of networks in the population   
   
Function returns nothing   
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/   
   
void print_population(unsigned generation, POPULATION * temp, unsigned no_networks)   
{   
	unsigned count=0;   
	   
/* print out the population statistics */   
/*printf("\n\nPopulation: mean fitness %f best fitness %f worst fitness %f",temp->mean_fitness, temp->best_fitness, temp->worst_fitness);*/   
   
/* print out the networks that make this population */   
for(count=0;count<no_networks;count++)   
	{   
	/* print out this network */  
	printf("\n%u %u %f %f %f %u",generation, count, (temp->networks[count])->delay,(temp->networks[count])->connectivity+(temp->networks[count])->cost,(temp->networks[count])->fitness, (temp->networks[count])->no_links);  
	print_network(temp->networks[count]);
	}	   
		   
return;   
} 
