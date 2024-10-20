/* File contains reset_links  
  
(c) Mr J Hewitt 7-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void reset_links(LINK * temp);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function reset_links  
  
Function resets the state flag of all links in the network to 0 (not used)  
  
Function takes a pointer to the network  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications             
  
*/  
void reset_links(LINK * temp)  
{  
	LINK * poss=NULL;  
	                   
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
