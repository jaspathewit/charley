/* File contains functions that create and distroy connectivity records  
  
(c) Mr J Hewitt 20-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
#include <string.h>
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
CONNECTIVITY_REC * create_con_rec(void);  
void distroy_con_rec(CONNECTIVITY_REC *);  
  
/* imported functions */  
extern void logger(char *,...);
  
/* local functions */                         
  
/* Function create_con_rec  
  
Function creates an empty connectivity rec structure  
  
Function takes nothing  
  
Function returns a pointer to the created connectivity struct. NULL indicates out of memory.  
  
Function uses nothing  
  
Function calls nothing  
  
Function called  
  
Modifications  
  
*/  
  
CONNECTIVITY_REC * create_con_rec(void)  
{  
	  
	CONNECTIVITY_REC * temp=NULL;  
  
/* try and allocate memory for the link structure */  
if(temp=(CONNECTIVITY_REC *)malloc(sizeof(CONNECTIVITY_REC)))  
	{  
	/* logger allocation successful */  
	#ifdef DEBUG_MEM  
    logger("Con rec allocation %p",temp);  
    #endif  
      
	/* allocation successful */  
	/* fill structure with default values */  
	strcpy(temp->struct_id,"CONN_REC"); 
	temp->node1=NULL;  
	temp->node2=NULL;  
	temp->connectivity=0;  
	temp->prev=NULL;  
	temp->next=NULL;  
	  
	}  
  
else  
	{                                   
	/* memory could not be allocated */	                            
	/* logger allocation unsuccessful */  
	#ifdef DEBUG_MEM  
	logger("Con rec allocation FAIL");  
	#endif  
  
	printf("Out of memory allocating a connectivity record");  
	  
	exit(0);  
	}  
	  
return(temp);  
}	  
	  
/* Function distroy_con_rec  
   
Function frees the memory allocated to a connectivity rec  
   
Function takes a pointer to the structure to distroy  
  
Function returns nothing   
  
Function uses nothing  
  
Function calls nothing  
  
Function called by   
  
Modification  
  
*/  
void distroy_con_rec(CONNECTIVITY_REC * this_node)  
{  
/* logger freed memory */  
#ifdef DEBUG_MEM  
logger("Con rec freed %p",this_node);  
#endif  
  
	  
/* free the memory */  
free(this_node);  
  
return;  
} 
