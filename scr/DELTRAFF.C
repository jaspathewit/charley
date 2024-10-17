/* File contains delete_traffic  
  
(c) Mr J Hewitt 7-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void delete_traffic(TRAFFIC *);  
  
/* imported functions */  
void distroy_traffic(TRAFFIC *);  
  
/* local functions */                         
  
/* Function delete_traffic  
  
Function deletes all the traffic recs in a link list  
  
Function takes a pointer to the list of traffic recs to distroy  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls nothing  
  
Function called  
  
Modifications  
  
*/  
  
void delete_traffic(TRAFFIC * the_traffic)  
{  
	TRAFFIC * temp_traffic=NULL;  
	TRAFFIC * traffic_poss=NULL;  
	                   
/* start from the begining of this route */  
traffic_poss=the_traffic;  
  
/* loop through all the traffic recs */  
while(traffic_poss)  
	{  
	/* get the possition of the next traffic rec */  
	temp_traffic=traffic_poss->prev;  
	  
	/* free the memory for this traffic */  
	distroy_traffic(traffic_poss);  
	  
	/* move on to the next traffic */  
	traffic_poss=temp_traffic;  
	  
	}  
	  
return;  
  
} 
