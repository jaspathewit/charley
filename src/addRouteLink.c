/* File inserts a route_link into the linked list of links makes a route between two nodes   
  
(c) Mr J Hewitt 22-NOV-1994 */  
  
/* standard included files */  
/*#include <stdio.h>  
#include <stdlib.h>*/  
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
ROUTE_LINK * add_route_link(ROUTE_LINK *,ROUTE_LINK *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function add_route_link  
  
Function adds a route_link into the route  
  
Function takes a route_link pointer to the preceding route_link in the network and a pointer  
to the route_link to be added.  
  
Function returns a pointer to the inserted route_link.  
  
Function uses nothing  
  
Function calls nothing  
  
Function called by  
  
Modifications  
  
*/  
  
ROUTE_LINK * add_route_link(ROUTE_LINK * pre_route_link, ROUTE_LINK * route_link_to_add)  
{  
/* make this route_link point to the preceding route_link */  
route_link_to_add->prev=pre_route_link;  
  
/* if not the first route_link in the list */  
if(pre_route_link)  
	{  
	  
	/* make route_link_to_add point to pre_route_links next link */  
	route_link_to_add->next=pre_route_link->next;  
		  
	/* make pre_route_link point to route_link_to_add */  
	pre_route_link->next=route_link_to_add;   
	}  
	  
/* if there is a route_link after route_link_to_add make it point to route_link_to_add */  
if(route_link_to_add->next)  
	{  
	/* make the next route_link point back to the route_link_to_add */  
	(route_link_to_add->next)->prev=route_link_to_add;  
	}                                                    
	  
return(route_link_to_add);  
} 
