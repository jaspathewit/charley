/* File contains print_traffic  
  
(c) Mr J Hewitt 6-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void print_traffic(TRAFFIC *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function print_traffic  
  
Function creates prints out the contents of linked list of traffic recs  
  
Function takes a pointer to the list of traffic recs to print  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
void print_traffic(TRAFFIC * temp)  
{  
	TRAFFIC * poss_traffic=NULL;  
  
/* start from the first traffic rec */  
poss_traffic=temp;  
  
while(poss_traffic)  
	{  
	/* print out this traffic rec */  
	printf("\nSends %f messages of mean length %f to node %s",poss_traffic->no_messages, poss_traffic->message_len,poss_traffic->node2->node_name);  
  
	/* move on to the next traffic rec */  
	poss_traffic=poss_traffic->prev;  
	}  
  
return;  
} 
