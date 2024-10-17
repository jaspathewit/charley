/* File contains functions that create and distroy link structures  
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
#include <string.h>             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
LINK * create_link(void);  
void distroy_link(LINK *);  
  
/* imported functions */  
extern void logger(char *,...);  
  
/* local functions */                         
  
/* Function create_link  
  
Function creates an empty link structure  
  
Function takes nothing  
  
Function returns a pointer to the created link. NULL indicates out of memory.  
  
Function uses nothing  
  
Function calls nothing  
  
Function called make_rand_network  
  
Modifications  
  
*/  
  
LINK * create_link(void)  
{  
	LINK * temp=NULL;  
	                   
/* try and allocate memory for the link structure */  
if(temp=(LINK *)malloc(sizeof(LINK)))  
	{                                    
	/* logger allocation successful */  
	#ifdef DEBUG_MEM  
    logger("Link allocation %p",temp);  
    #endif  
      
	/* allocation successful */  
	/* fill structure with default values */  
    strcpy(temp->struct_id,"LINK"); 
     
	/* link not connected */  
	temp->node1=NULL;  
	temp->node2=NULL;  
	                          
	/* link has no capacity */                          
	temp->speed=0;  
	  
	/* link has no messages */  
	temp->no_messages=0;  
	                  
	/* averge message length */  
	temp->message_len=0;                  
	  
	/* the mean link delay on this link */  
	temp->delay=0;  
	                  
	/* link state */  
	temp->state=0;        
	  
	/* cost of the link */  
	temp->cost=0;   
	                            
	/* link is not connected into the network */  
	temp->prev=NULL;  
	temp->next=NULL;  
	}  
  
else  
	{                                   
	/* memory could not be allocated */	                            
	/* logger allocation unsuccessful */  
	#ifdef DEBUG_MEM  
	logger("Link allocation FAIL");  
	#endif  
	  
	printf("Out of memory allocating a link");  
	  
	exit(0);  
	}  
	  
return(temp);  
}	  
	  
/* Function distroy_link  
   
Function frees the memory allocated to a link structure   
   
Function takes a pointer to the link structure to distroy  
  
Function returns nothing   
  
Function uses nothing  
  
Function calls nothing  
  
Function called by   
  
Modification  
  
*/  
void distroy_link(LINK * this_link)  
{  
/* logger freed memory */  
#ifdef DEBUG_MEM  
logger("Link freed %p",this_link);  
#endif  
   
/* free the memory */  
free(this_link);  
  
return;  
} 
