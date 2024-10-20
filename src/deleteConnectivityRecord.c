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
void delete_connetivity_recs(CONNECTIVITY_REC *);  
  
/* imported functions */  
extern void destroy_con_rec(CONNECTIVITY_REC *);
      
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
  
void delete_connectivity_recs(CONNECTIVITY_REC * temp)  
{  
	CONNECTIVITY_REC * poss_con_rec=NULL;  
	CONNECTIVITY_REC * temp_con_rec=NULL;  
  
/* start from the beginning of the linked list */  
poss_con_rec=temp;  
  
/* loop through the entire network */  
while(poss_con_rec)  
	{             
	/* get the next node to delete */  
	temp_con_rec=poss_con_rec->prev;  
	  
	/* delete this route record */  
	destroy_con_rec(poss_con_rec);
	  
	/* move on to the next route_rec */  
	poss_con_rec=temp_con_rec;  
	}  
	  
return;  
} 
