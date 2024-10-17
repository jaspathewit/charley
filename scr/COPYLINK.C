/* File contains copy_link  
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>  
  
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
LINK * copy_link(LINK *);  
  
/* imported functions */  
extern LINK * create_link(void);  
extern void logger(char *,...);  
  
/* local functions */  
  
/* Function copy_link  
  
Function copy a link into a another link structure  
  
Function takes a pointer to the link to copy  
  
Function returns a pointer to a copy of the link if link is null  
returns NULL  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
  
LINK * copy_link(LINK * link)  
{  
	LINK * temp=NULL;  
  
/* check if the link is NULL */  
if(link)  
	{  
  
	/* create storage space for this link */  
	if(temp=create_link())  
		{  
  
		/* copy the contents of this link to the new storage */  
		temp->node1=link->node1;  
		temp->node2=link->node2;  
		temp->speed=link->speed;  
		/*temp->no_messages=link->no_messages;   
		temp->message_len=link->message_len;  
		temp->delay=link->delay;*/  
		temp->no_messages=0;   
		temp->message_len=0;  
		temp->delay=0;  
		temp->cost=link->cost;  
		temp->state=link->state;  
		temp->prev=link->prev;  
		temp->next=link->next;  
  
		}  
	else  
		{  
		logger("Out of memory copying link");  
		printf("\nOut of memory copying link");  
		}	  
	}  
  
/* return a pointer to the copy of the link */  
return(temp);  
  
} 
