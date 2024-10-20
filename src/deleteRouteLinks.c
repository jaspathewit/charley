/* File contains delete_route_links  
  
(c) Mr J Hewitt 22-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void delete_route_links(ROUTE_LINK *);  
  
/* imported functions */  
extern void destroy_route_link(ROUTE_LINK *);
  
/* local functions */                         
  
/* Function delete_route_links  
  
Function deletes all the route links that make a route  
  
Function takes a pointer to the route to destroy
  
Function returns nothing  
  
Function uses nothing  
  
Function calls nothing  
  
Function called  
  
Modifications  
  
*/  
  
void delete_route_links(ROUTE_LINK * the_route)  
{  
	ROUTE_LINK * temp_route_link=NULL;  
	ROUTE_LINK * route_link_poss=NULL;  
	                   
/* start from the begining of this route */  
route_link_poss=the_route;  
  
/* loop through all the route_links */  
while(route_link_poss)  
	{  
	/* get the possition of the next route_link */  
	temp_route_link=route_link_poss->prev;  
	  
	/* free the memory for this route_link */  
	destroy_route_link(route_link_poss);
	  
	/* move on to the next route_link */  
	route_link_poss=temp_route_link;  
	  
	}  
	  
return;  
      } 
 
 
