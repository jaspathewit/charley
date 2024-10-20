/* File contains print_links  
  
(c) Mr J Hewitt 7-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */    
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void print_links(LINK *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function print_links  
  
Function creates prints out the contents of linked list of links  
  
Function takes a pointer to the list of links to print  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
void print_links(LINK * temp)  
{  
	LINK * poss_link=NULL;  
  
/* start from the first link */  
poss_link=temp;  
  
while(poss_link)  
	{  
	/* print out this link */  
	printf("\n#Link between %s %u and %s %u of speed %lu, costing %lu",poss_link->node1->node_name,poss_link->node1->hops,poss_link->node2->node_name,poss_link->node2->hops,poss_link->speed,poss_link->cost); 
	printf("\n#No messages %f ",	poss_link->no_messages); 
	 
	/*printf("\n#Link %p",poss_link);*/ 
	 
	/* check that this link has some messages going down it*/ 
	if(poss_link->no_messages>0) 
		{ 
		printf("Mess len %f ",poss_link->message_len/poss_link->no_messages); 
		} 
	else	 
		{ 
		printf("Mess len 0.000000 "); 
		} 
	 
	printf("Link delay %f", poss_link->delay); 
	  
	/* move on to the next allowed link */ 
	 
	poss_link=poss_link->prev; 
	} 
 
return; 
} 
 
 
