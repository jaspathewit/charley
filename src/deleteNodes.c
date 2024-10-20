/* File contains delete_nodes  
  
(c) Mr J Hewitt 22-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void delete_nodes(NODE *);  
  
/* imported functions */  
extern void delete_links(LINK *);  
extern void delete_traffic(TRAFFIC *);      
extern void destroy_node(NODE *);
      
/* local functions */                         
  
/* Function delete_nodes  
  
Function deletes all the nodes for this network  
  
Function takes a pointer to the list of nodes to delete  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
void delete_nodes(NODE * temp)  
{  
	NODE * poss_node=NULL;  
	NODE * temp_node=NULL;  
  
/* start from the beginning of the linked list */  
poss_node=temp;  
  
/* loop through the entire network */  
while(poss_node)  
	{             
	/* get the next node to delete */  
	temp_node=poss_node->prev;  
	  
	/* delete allowed links */  
	delete_links(poss_node->allowed_links);  
	  
	/* delete traffic recs */  
	delete_traffic(poss_node->traffic);  
	  
	/* delete this route record */  
	destroy_node(poss_node);
	  
	/* move on to the next route_rec */  
	poss_node=temp_node;  
	}  
	  
return;  
} 
