/* File contains find_route_rec  
  
(c) Mr J Hewitt 13-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */    
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
ROUTE_REC * find_route_rec(NODE *, NODE *, ROUTE_REC *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function find_route_rec  
  
Function finds the route rec that starts from one node and ends at another node  
  
Function takes a pointer to the starting node, a pointer to the to node and  
a pointer to the route records to search  
  
Function returns a pointer to the route record  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
ROUTE_REC * find_route_rec(NODE * from_node, NODE * to_node, ROUTE_REC * route_recs)  
{  
  
	ROUTE_REC * route_rec_poss=NULL;  
	ROUTE_REC * required_rec=NULL;  
  
/* start from the first record in the route_records */  
route_rec_poss=route_recs;  
  
/* search through all the route_records */  
while(route_rec_poss)  
	{  
	/* check if this route record is the one req */  
	if(route_rec_poss->node1==from_node)  
		{  
  
		/* see if this record is the one required */  
		if(route_rec_poss->node2==to_node)  
			{  
			/* return a pointer to this route_rec */  
			required_rec=route_rec_poss;  
  
			/* get out of the loop */  
			break;  
			}  
  
		}  
	/* move on to the next route record */  
	route_rec_poss=route_rec_poss->prev;  
	}  
	  
/*return any found link */  
return(required_rec);  
                                      
} 
