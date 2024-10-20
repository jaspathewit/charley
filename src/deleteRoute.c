/* File contains delete_routes  
  
(c) Mr J Hewitt 22-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void delete_routes(ROUTE_REC *);  
  
/* imported functions */  
extern void delete_route_links(ROUTE_LINK *);      
extern void destroy_route_rec(ROUTE_REC *);
      
/* local functions */                         
  
/* Function deletes_routes  
  
Function deletes all the route records for this network  
  
Function takes a pointer to the list of routes to delete  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
void delete_routes(ROUTE_REC * temp)  
{  
	ROUTE_REC * poss_route_rec=NULL;  
	ROUTE_REC * temp_route_rec=NULL;  
  
/* start from the beginning of the linked list */  
poss_route_rec=temp;  
  
/* loop through the entire network */  
while(poss_route_rec)  
	{             
	/* get the next node to delete */  
	temp_route_rec=poss_route_rec->prev;  
	  
	/* delete any route */  
	delete_route_links(poss_route_rec->route);  
	  
	/* delete this route record */  
	destroy_route_rec(poss_route_rec);
	  
	/* move on to the next route_rec */  
	poss_route_rec=temp_route_rec;  
	}  
	  
return;  
} 
