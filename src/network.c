/* File contains functions that create and destroy network structures
  
(c) Mr J Hewitt 21-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
#include <string.h>
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
NETWORK * create_network(void);  
void destroy_network(NETWORK *);
  
/* imported functions */                                          
extern void logger(char *,...);  
extern void delete_links(LINK *);  
/* local functions */                         
  
/* Function create_network  
  
Function creates an empty network structure  
  
Function takes nothing  
  
Function returns a pointer to the created network Null indicates out of memory  
  
Function uses nothing  
  
Function calls nothing  
  
Function called  
  
Modifications  
  
*/  
  
NETWORK * create_network()  
{  
	NETWORK * temp=NULL;  
	                   
/* try and allocate memory for the network structure */  
if(temp=(NETWORK *)malloc(sizeof(NETWORK)))  
	{                                    
	/* logger allocation successful */  
	#ifdef DEBUG_MEM  
    logger("Network allocation %p",temp);  
    #endif  
      
	/* fill with default values */ 
	strcpy(temp->struct_id,"NETWORK_REC");	        
	temp->links=NULL;   
	temp->delay=0;  
	temp->connectivity=0;  
	temp->duplication=0;  
	temp->cost=0;  
	temp->real_cost=0;  
	temp->fitness=0;   
	temp->no_links=0;  
    }  
else  
	{                                   
	/* memory could not be allocated */	                            
	/* logger allocation unsuccessful */  
	#ifdef DEBUG_MEM  
	logger("Network allocation FAIL");  
	#endif  
	  
	printf("Out of memory allocating a network");  
	  
	exit(0);  
	  
	}  
	  
return(temp);  
}	  
	  
/* Function destroy_network
   
Function frees the memory allocated to a network  
   
Function takes a pointer to the network to destroy
  
Function returns nothing   
  
Function uses nothing  
  
Function calls nothing  
  
Function called by   
  
Modification  
  
*/  
void destroy_network(NETWORK * this_net)
{  
/* check that there is a network to destroy */
if(this_net) 
  { 
    /* destroy the links of this network */
    delete_links(this_net->links);  
                  
    /* logger freed memory */  
#ifdef DEBUG_MEM  
    logger("Network freed %p",this_net);  
#endif  
  
    /* free the memory allocated to this network structure */  
    free(this_net);                               
  } 
 
return;  
} 
