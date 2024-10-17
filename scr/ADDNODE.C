/* File inserts a node into the linked list of nodes  
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
NODE * add_node(NODE *,NODE *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function add_node  
  
Function adds a node into the linked list of nodes   
  
Function takes a node pointer to the preceding node in the list and a pointer  
to the node to be added.  
  
Function returns a pointer to the inserted node.  
  
Function uses nothing  
  
Function calls nothing  
  
Function called by  
  
Modifications  
  
*/  
  
NODE * add_node(NODE * pre_node, NODE * node_to_add)  
{  
/* make this node point to the preceding node */  
node_to_add->prev=pre_node;  
  
/* if not the first node in the list*/  
if(pre_node)  
	{  
	/* make node_to_add point to pre_nodes next node */  
	node_to_add->next=pre_node->next;  
	  
	/* make pre_node point to node_to_add */  
	pre_node->next=node_to_add;  
	  
	}  
	  
/* if there is a node after node_to_add make it point to node_to_add */  
if(node_to_add->next)  
	{  
	/* make the next node point bake to the node_to_add */  
	(node_to_add->next)->prev=node_to_add;  
	}  
  
return(node_to_add);  
} 
