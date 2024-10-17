/* File contains find_node  
  
(c) Mr J Hewitt 19-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>                                   
             
/* project include files */    
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
NODE * find_node(char *,NODE *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function find_route_rec  
  
Function finds the node rec with a given name  
  
Function takes the name of the node and a pointer to the node_list  
  
Function returns a pointer to the matching node record. NULL indicates not found  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
NODE * find_node(char * node_name, NODE * node_list)  
{  
  
	NODE * node_poss=NULL;  
  
/* start from the first record in the node_list */  
node_poss=node_list;  
  
/* search through all the node records */  
while(node_poss)  
	{  
	/* check if this node record is the one req */  
	if(strcmp(node_poss->node_name,node_name)==0)  
		{  
  
		/* get out of the loop */  
		break;  
		}  
  
	/* move on to the next route record */  
	node_poss=node_poss->prev;  
	}  
	  
/*return the found node */  
return(node_poss);  
                                      
} 
