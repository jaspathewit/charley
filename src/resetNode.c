/* File contains reset_nodes  
  
(c) Mr J Hewitt 22-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void reset_nodes(NODE * temp);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function reset_nodes  
  
Function resets the state flag of all nodes to 0 (not used)  
  
Function takes a pointer to the node list  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications             
  
*/  
void reset_nodes(NODE * temp)  
{  
	NODE * poss=NULL;  
	                   
/* start from the beginning of the linked list */  
poss=temp;  
  
/* loop through the entire network */  
while(poss)  
	{  
	/* reset this link */  
	poss->state=0;  
	  
	/* move on to the next link */  
	poss=poss->prev;  
	}  
	  
return;  
} 
