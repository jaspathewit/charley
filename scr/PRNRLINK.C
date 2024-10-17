/* File contains print_route_links  
  
(c) Mr J Hewitt 21-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void print_route_links(ROUTE_LINK *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function print_routes  
  
Function creates prints out the contents of linked list of route links  
  
Function takes a pointer to the list of route links to print  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
void print_route_links(ROUTE_LINK * temp)  
{  
	ROUTE_LINK * poss_route_link=NULL;  
    unsigned count=0;  
          
/* start from the beginning of the linked list */  
poss_route_link=temp;  
  
printf("\nRoute");  
  
/* loop through the entire list */  
while(poss_route_link)  
	{  
	/*printf("\nRoute link address %p and prev %p next %p",poss_route_link,poss_route_link->prev,poss_route_link->next);*/  
	  
 	/* print out this link */  
	printf("\nlink from %s to %s %lu",poss_route_link->link->node1->node_name ,poss_route_link->link->node2->node_name,poss_route_link->link->speed);  
	  
	/* for debugging */  
	if(count>100)  
		{  
		printf("Exit on error");  
		exit(0);                      
		}  
	  
	count++;  
	  
	/* move on to the next link in the route */  
	poss_route_link=poss_route_link->prev;  
	}  
  
return;  
      } 
