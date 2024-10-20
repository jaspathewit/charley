/* File inserts a link into the linked list of links that defines a network   
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
/*#include <stdio.h>  
#include <stdlib.h>*/  
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
LINK * add_link(LINK *,LINK *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function add_link  
  
Function adds a link into the network  
  
Function takes a link pointer to the preceding link in the network and a pointer  
to the link to be added.  
  
Function returns a pointer to the inserted link.  
  
Function uses nothing  
  
Function calls nothing  
  
Function called by  
  
Modifications  
  
*/  
  
LINK * add_link(LINK * pre_link, LINK * link_to_add)  
{  
/* make this link point to the preceding link */  
link_to_add->prev=pre_link;  
  
/* if not the first link in the network */  
if(pre_link)  
	{  
	/* make link_to_add point to pre_links next link */  
	link_to_add->next=pre_link->next;  
	  
	/* make pre_link point to link_to_add */  
	pre_link->next=link_to_add;  
	  
	}  
	  
/* if there is a link after link_to_add make it point to link_to_add */  
if(link_to_add->next)  
	{  
	/* make the next link point bake to the link_to_add */  
	(link_to_add->next)->prev=link_to_add;  
	}  
			  
  
return(link_to_add);  
} 
