/* File contains copy_route_link  
  
(c) Mr J Hewitt 22-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>  
  
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
ROUTE_LINK * copy_route_link(ROUTE_LINK *);  
  
/* imported functions */  
extern ROUTE_LINK * create_route_link(void);  
extern void logger(char *,...);  
  
/* local functions */              
  
/* Function copy_route_link  
  
Function copies the route_link information the two list pointers are set to NULL  
  
Function takes a pointer to a route_link  
  
Function returns a pointer to the duplicated link  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
ROUTE_LINK * copy_route_link(ROUTE_LINK * route_link)  
{  
  
	ROUTE_LINK * temp_route_link=NULL;  
  
/* check there is a route_link to duplicate */  
if(route_link)  
	{  
	/* copy route_link pointed to by link_poss */	  
	if(temp_route_link=create_route_link())  
		{  
		/* copy the route_link information */  
		temp_route_link->link=route_link->link;  
	  
		temp_route_link->prev=route_link->prev;  
		temp_route_link->next=route_link->next;  
	    }  
	else  
		{  
		logger("Out of memory copying route link");  
		printf("\nOut of memory copying route link");  
		}      
	}  
	  
/* return pointer to the copied route */	  
return(temp_route_link);  
  
} 
