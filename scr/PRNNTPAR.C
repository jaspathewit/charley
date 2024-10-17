/* File contains print_network_param  
  
(c) Mr J Hewitt 19-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void print_network_params(NETWORK_PARAM *);  
  
/* imported functions */  
extern void print_nodes(NODE *);  
  
/* local functions */                         
  
/* Function print_network_params  
  
Function creates prints out the contents of the network parameters  
  
Function takes a pointer to network parameters to print  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
void print_network_param(NETWORK_PARAM * temp)  
{  
  
printf("\nGenetic Parameters");    
  
/* print the run time parameters */  
printf("\nPopulation size %u",temp->population_size);  
printf("\nNumber of generations %u",temp->no_generations);  
  
printf("\nNetwork Parameters");  
/* the network connectivity requirement */  
printf("\nThe network nmust be %u connected",temp->connectivity_req);  
  
/* the acceptable mean message delay */  
printf("\nThe acceptable mean message delay is %f",temp->acceptable_delay);  
	                              
/* setup penalties */  
printf("\n\nMutation rates");  
printf("\nAdd/del mutation per 100 networks %f",temp->addel_mutation);  
printf("\nLink mutation per 100 networks %f",temp->link_mutation);  
	                       
/* a pointer to the nodes in the network */  
printf("\n\nNetwork has %u nodes",temp->no_nodes);  
print_nodes(temp->node_list);  
  
return;  
  
} 
