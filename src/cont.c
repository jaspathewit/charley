/* File contains net_cost  
  
(c) Mr J Hewitt 21-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
float net_cost(NETWORK *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function net_cost  
  
Function calculates the total cost of the links in a network  
  
Function takes a painter to tthe network to calculate the cost for  
  
Function returns the cost of the network  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
float net_cost(NETWORK * temp)  
{  
	LINK * poss=NULL;  
    float total_cost=0;  
    float real_cost=0;  
      
/* start from the beginning of the linked list */  
poss=temp->links;  
  
/* loop through all the links in the network */  
while(poss)  
	{  
	/* add the cost of this link to the total cost */  
	total_cost+=(float)poss->cost;  
      
    	real_cost+=(float)poss->cost;  
    	  
	/* move on to the next allowed link */  
	poss=poss->prev;  
	}  
                                    
/* store the real cost of this network */  
temp->real_cost=real_cost;                                    
                                     
return(total_cost);  
} 
