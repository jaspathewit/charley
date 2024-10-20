/* File inserts a route rec into the linked list of route recs  
  
(c) Mr J Hewitt 21-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>  
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
ROUTE_REC * add_route_rec(ROUTE_REC *,ROUTE_REC *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function add_route_rec  
  
Function adds a route record into the route_rec list  
  
Function takes a route pointer to the route_rec in the list and a pointer  
to the rec to be added.  
  
Function returns a pointer to the inserted route_rec.  
  
Function uses nothing  
  
Function calls nothing  
  
Function called by  
  
Modifications  
  
*/  
  
ROUTE_REC * add_route_rec(ROUTE_REC * pre_route_rec, ROUTE_REC * route_rec_to_add)  
{  
/* make this route rec point to the preceding route_rec */  
route_rec_to_add->prev=pre_route_rec;  
  
/* if not the first con_rec in the list */  
if(pre_route_rec)  
	{  
	/* make con_rec_to_add point to pre_con_recs next con_rec */  
	route_rec_to_add->next=pre_route_rec->next;  
  
	/* make pre_con_rec point to con_rec_to_add */  
	pre_route_rec->next=route_rec_to_add;  
  
	}  
	  
/* if there is a route_rec after route_rec_to_add make it point to route_rec_to_add */  
if(route_rec_to_add->next)  
	{  
	/* make the next con_rec point back to the con_rec_to_add */  
	(route_rec_to_add->next)->prev=route_rec_to_add;  
	}  
  
return(route_rec_to_add);  
} 
