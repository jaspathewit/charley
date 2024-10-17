/* File contains print_nodes  
  
(c) Mr J Hewitt 7-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void print_nodes(NODE *);  
  
/* imported functions */  
extern void print_links(LINK *);  
extern void print_traffic(TRAFFIC *);  
  
/* local functions */                         
  
/* Function print_nodes  
  
Function creates prints out the contents of linked list of nodes  
  
Function takes a pointer to the list of nodes to print  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
void print_nodes(NODE * temp)  
{  
	NODE * poss_node=NULL;  
  
/* start from the beginning of the linked list */  
poss_node=temp;  
  
/* loop through the entire network */  
while(poss_node)  
	{  
	/* print out the node details */  
	printf("\n\nNode %s",poss_node->node_name);  
  
	/* print out the allowed links for this node */  
	printf("\nHas %u allowed link(s)",poss_node->no_links);  
	print_links(poss_node->allowed_links);  
	  
	/* print out the traffic flows for this node */  
	print_traffic(poss_node->traffic);                     
		  
	/* move on to the next node */  
	poss_node=poss_node->prev;  
	}  
	  
return;  
} 
