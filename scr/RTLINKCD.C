/* File contains functions that create and distroy route link structures  
  
(c) Mr J Hewitt 22-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
#include <string.h>
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
ROUTE_LINK * create_route_link(void);  
void distroy_route_link(ROUTE_LINK *);  
  
/* imported functions */  
extern void logger(char *,...);  
  
/* local functions */                         
  
/* Function create_route_link  
  
Function creates an empty route_link structure  
  
Function takes nothing  
  
Function returns a pointer to the created route_link. NULL indicates out of memory.  
  
Function uses nothing  
  
Function calls nothing  
  
Function called  
  
Modifications  
  
*/  
  
ROUTE_LINK * create_route_link(void)  
{  
	ROUTE_LINK * temp=NULL;  
	                   
/* try and allocate memory for the link structure */  
if(temp=(ROUTE_LINK *)malloc(sizeof(ROUTE_LINK)))  
	{                                    
	/* logger allocation successful */  
    #ifdef DEBUG_MEM  
	logger("Rtlink allocation %p",temp);  
	#endif  
	  
	/* allocation successful */  
	/* fill structure with default values */  
	strcpy(temp->struct_id,"ROUTE_LINK"); 
	 
    /* route link does not point at a link */    
    temp->link=NULL;  
	                            
	/* link is not connected into the network */  
	temp->prev=NULL;  
	temp->next=NULL;  
	}  
  
else  
	{                                   
	/* memory could not be allocated */	                            
	/* logger allocation unsuccessful */  
	#ifdef DEBUG_MEM  
	logger("Rtlink allocation FAIL");  
	#endif  
	  
	printf("Out of memory allocating a link");  
	  
	exit(0);  
	  
	}  
	  
return(temp);  
}	  
	  
/* Function distroy_route_link  
   
Function frees the memory allocated to a route_link structure   
   
Function takes a pointer to the route_link structure to distroy  
  
Function returns nothing   
  
Function uses nothing  
  
Function calls nothing  
  
Function called by   
  
Modification  
  
*/  
void distroy_route_link(ROUTE_LINK * this_route_link)  
{  
/* logger freed memory */  
#ifdef DEBUG_MEM  
logger("Rtlink freed %p",this_route_link);  
#endif  
/* free the memory */  
free(this_route_link);  
  
return;  
} 
