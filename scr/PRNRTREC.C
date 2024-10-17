/* File contains print_routes  
  
(c) Mr J Hewitt 21-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void print_routes(ROUTE_REC *);  
  
/* imported functions */  
extern void print_route_links(ROUTE_LINK *);  
  
/* local functions */                         
  
/* Function print_routes  
  
Function creates prints out the contents of linked list of routes  
  
Function takes a pointer to the list of routes to print  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
void print_routes(ROUTE_REC * temp)  
{  
	ROUTE_REC * poss_route_rec=NULL;  
  
/* start from the beginning of the linked list */  
poss_route_rec=temp;  
  
/* loop through the entire network */  
while(poss_route_rec)  
	{  
	/* print out the node details */  
	printf("\nRoute between Node %s and %s is",poss_route_rec->node1->node_name,poss_route_rec->node2->node_name);  
  
	/* print out the route between these two nodes */  
	/* start from the first link */  
	print_route_links(poss_route_rec->route);  
  
	/* if there is a route print out the cost */  
	if(poss_route_rec->route)  
        printf("\nOf cost %lu",poss_route_rec->cost);  
      
	/* move on to the next node */  
	poss_route_rec=poss_route_rec->prev;  
	}  
	  
return;  
} 
