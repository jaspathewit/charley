/* File contains delete_links  
  
(c) Mr J Hewitt 22-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
void delete_links(LINK *);  
  
/* imported functions */  
void distroy_link(LINK *);  
  
/* local functions */                         
  
/* Function delete_links  
  
Function deletes all the links in a link list  
  
Function takes a pointer to the list of links to distroy  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls nothing  
  
Function called  
  
Modifications  
  
*/  
  
void delete_links(LINK * the_links)  
{  
	LINK * temp_link=NULL;  
	LINK * link_poss=NULL;  
	                   
/* start from the begining of this route */  
link_poss=the_links;  
  
/* loop through all the links */  
while(link_poss)  
	{  
	/* get the possition of the next link */  
	temp_link=link_poss->prev;  
	  
	/* free the memory for this link */  
	distroy_link(link_poss);  
	  
	/* move on to the next link */  
	link_poss=temp_link;  
	  
	}  
	  
return;  
  
} 
