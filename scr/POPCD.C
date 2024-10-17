/* File contains functions that create and distroy population structures  
  
(c) Mr J Hewitt 21-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
#include <string.h>
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
POPULATION * create_population(unsigned);  
void distroy_population(POPULATION *,unsigned);  
  
/* imported functions */                                          
extern void distroy_network(NETWORK *);  
extern void logger(char *,...);  
  
/* local functions */                         
  
/* Function create_population  
  
Function creates an empty population structure  
  
Function takes the number of networks to be stored in this population  
  
Function returns a pointer to the created population. NULL indicates out of memory.  
  
Function uses nothing  
  
Function calls nothing  
  
Function called  
  
Modifications  
  
*/  
  
POPULATION * create_population(unsigned no_networks)  
{  
	POPULATION * temp=NULL;  
	NETWORK ** networks=NULL;  
	                   
/* try and allocate memory for the population structure */  
if(temp=(POPULATION *)malloc(sizeof(POPULATION)))  
	{                                    
	/* logger allocation successful */  
	#ifdef DEBUG_MEM  
    logger("Population allocation %p",temp);  
    #endif  
      
	/* allocation successful */  
	/*try to allocate array to hold network structures */  
	if(networks=(NETWORK **)calloc(no_networks,sizeof(NETWORK*)))  
		{  
		/* logger allocation successful */  
		#ifdef DEBUG_MEM  
    	logger("Network array allocation %p",networks);  
    	#endif  
		  
		/* allocation successful*/  
		/* fill with default values */	    
		strcpy(temp->struct_id,"POPULATION"); 
		     
		temp->networks=networks;  
		  
		temp->mean_fitness=0;  
		temp->total_fitness=0;  
		temp->best_fitness=0;  
		temp->worst_fitness=0;  
		}  
	else  
		{	  
        /* memory could not be allocated */	                            
		/* logger allocation unsuccessful */  
		#ifdef DEBUG_MEM  
		logger("Network array allocation FAIL");  
		#endif  
	  
		printf("Out of memory allocating networks to a population");  
		  
		exit(0);  
		  
		}  
	}  
else  
	{                                   
	/* memory could not be allocated */	                            
	/* logger allocation unsuccessful */  
	#ifdef DEBUG_MEM  
	logger("Population allocation FAIL");  
	#endif  
	  
	printf("Out of memory allocating a population");  
	  
	exit(0);  
	}  
	  
return(temp);  
}	  
	  
/* Function distroy_population  
   
Function frees the memory allocated to a population   
   
Function takes a pointer to the population to distroy and  
the number of networks in this population  
  
Function returns nothing   
  
Function uses nothing  
  
Function calls nothing  
  
Function called by   
  
Modification  
  
*/  
void distroy_population(POPULATION * this_pop, unsigned no_networks)  
{             
	unsigned count=0;  
 
/* check there is a population to distroy */ 
if(this_pop) 
  { 
    /* distroy the networks	stored in the population */  
    for(count=0;count<no_networks;count++) 
      { 
    /* distroying network */ 
	distroy_network(this_pop->networks[count]); 
      } 
  
    /* logger freed memory */  
#ifdef DEBUG_MEM  
    logger("Networks array freed %p",this_pop->networks);  
#endif  
  
    /* free the memory allocated to store the networks */  
    free(this_pop->networks);  
  
    /* logger freed memory */  
#ifdef DEBUG_MEM  
    logger("Population freed %p",this_pop);  
#endif  
   
    /* free the memory */  
    free(this_pop);  
  } 
  
return;  
} 
