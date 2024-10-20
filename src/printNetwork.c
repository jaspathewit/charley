/* File contains print_network  
  
(c) Mr J Hewitt 7-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void print_network(NETWORK *);  
  
/* imported functions */  
extern void print_links(LINK *);  
  
/* local functions */                         
  
/* Function print_network  
  
Function creates prints out the contents of linked list of links that comprise a network  
  
Function takes a network to print  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
void print_network(NETWORK * temp)  
{  
	LINK * poss=NULL;  
  
/* start from the beginning of the linked list */  
poss=temp->links;  
  
/* print the links in the network */  
printf("\n#Network consists of %u links ",temp->no_links);  
print_links(poss);   
printf("\n#Factors Performance %f Conn %f Cost %f fitness %f", temp->delay, temp->connectivity, temp->cost, temp->fitness);   
printf("\n#and has a cost of %f",temp->real_cost); 
  
return;  
} 
