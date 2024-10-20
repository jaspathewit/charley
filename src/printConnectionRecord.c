/* File contains print_con_rec  
  
(c) Mr J Hewitt 20-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void print_con_recs(CONNECTIVITY_REC * );  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function print_con_recs  
  
Function prints out the contents of linked list of connectivity records  
  
Function takes a pointer to the list of con_recs to print  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
void print_con_recs(CONNECTIVITY_REC * temp)  
{  
	CONNECTIVITY_REC * poss_con_rec=NULL;  
  
/* start from the beginning of the linked list */  
poss_con_rec=temp;  
  
/* loop through the entire network */  
while(poss_con_rec)  
	{  
	/* print out the node details */  
	printf("\nNode %s has connectivity %u to node %s",poss_con_rec->node1->node_name,poss_con_rec->connectivity,poss_con_rec->node2->node_name);  
    	  
	/* move on to the next node */  
	poss_con_rec=poss_con_rec->prev;  
	}  
	  
return;  
} 
