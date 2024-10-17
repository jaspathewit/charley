/* File contains make_rand_link  
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>  
  
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
LINK * select_rand_link(LINK *, unsigned);  
  
/* imported functions */  
extern unsigned get_rand_num(unsigned);  
  
/* local functions */  
  
/* Function select_rand_link  
  
Function select a random link from the possible links allowed by this node  
  
Function takes a pointer to the allowed link list and a random number that  
indicates whch link to select.  
  
Function returns a pointer to the link selected. if thier are no links in the list NULL is returned.  
NULL is returned if random link is 0  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
  
LINK * select_rand_link(LINK * links, unsigned rand_link)  
{  
	LINK * start=NULL;  
	LINK * temp=NULL;  
	unsigned count=0;                                                            
  
/* remember the start of the link list*/  
start=links;  
  
/* check that there are some links to select from */  
if(links)  
	{  
	/* check if the rand link is zero */  
	if(rand_link)  
		{  
  
		/* start from the begining */  
		temp=start;  
  
		/* loop round the nodes this number of times */  
		while(count<=rand_link)  
			{  
			/* move on to the next link */  
			temp=temp->prev;  
	  
			if(!temp)  
				{  
				/* reached the end of the list wrap round */  
				temp=start;  
				}  
		  
			count++;  
			}  
		}  
	}  
	  
return(temp);  
  
} 
