/* File contains net_fitness   
   
(c) Mr J Hewitt 21-DEC-1994 */   
   
/* standard included files */   
#include <stdio.h>   
#include <stdlib.h>                                    
              
/* project include files */   
#include "network.h"   
   
/* global varibles */   
extern int add_cost;   
   
/* static varibles */   
   
/* exported functions */   
float net_fitness(NETWORK *, NETWORK_PARAM *);   
   
/* imported functions */   
extern float net_connectivity(NETWORK *,NETWORK_PARAM *);   
extern float net_delay(NETWORK *, NETWORK_PARAM *);   
extern float net_dup_link(NETWORK *);   
extern float net_cost(NETWORK *);   
extern void logger(char *,...);   
   
/* local functions */                          
   
/* Function net_fitness   
   
Function calculates the fitness of a particular network   
   
Function takes a painter to the network and the network parameters   
   
Function returns a value representing the fitness of a network -1 indicates an error   
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/   
   
float net_fitness(NETWORK * temp, NETWORK_PARAM * params)   
{   
	float fitness=-1;   
	float delay_penalty=0;   
	float conn_penalty=0;   
	float total_cost=0;   
	float dup_link=0;   
   
/* calculate the connectivity penalty */   
if(!((conn_penalty=10*net_connectivity(temp,params))<0))   
  {    
    /* get the message delay */   
    if(!((delay_penalty=net_delay(temp,params))<0))   
      {     
  
	/* get the cost of the network */   
	if(!((total_cost=10*(net_cost(temp)/9000))<0))   
	  { 
	    
	    
	    /* store the delay penalty */  
	    temp->delay=delay_penalty;
	    
	    /* store the cost of the network */  
	    temp->cost=total_cost;  
	    
	    /* store the connectivity */  
	    temp->connectivity=conn_penalty;

	    /* if(!((dup_link=0*net_dup_link(temp))<0))   
	       {                                     */ 
		/* store the duplicated link penalty */  
		/*temp->duplication=dup_link; */ 
  
	   
	    /* calculate the network fitness */   
	    fitness=(delay_penalty+conn_penalty+total_cost);  
		  
	    /*}*/  
	  }   
      }   
  }        	       
return(fitness);   
} 
