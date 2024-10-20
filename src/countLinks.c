/* File contains count_links  
  
(c) Mr J Hewitt 11-JAN-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */    
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
unsigned count_links(LINK *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function count_links  
  
Function counts the number of links in a given list of links  
  
Function takes a pointer to the list of links to count  
  
Function returns the number of links in the network  
  
Function uses nothing  
  
Function calls   
  
Function called by   
  
Modifications  
  
*/  
  
unsigned count_links(LINK * temp)  
{  
	LINK * poss_link=NULL;  
    unsigned count=0;  
      
/* start from the first link */  
poss_link=temp;  
  
while(poss_link)  
	{  
	/* count  this link */  
	count++;  
	  
	/* move on to the next link */  
	poss_link=poss_link->prev;  
	}  
  
return(count);  
}  
