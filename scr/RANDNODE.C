/* File contains get_rand_node  
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
NODE * get_rand_node(NODE *,unsigned);  
  
/* imported functions */  
extern unsigned get_rand_num(unsigned);  
  
/* local functions */  
  
/* Function get_rand_node  
  
Function creates a random node  
  
Function takes the number of nodes in the network number indicating range form which to  
to select node from  
  
Function returns a pointer to the selected node  
  
Function uses nothing  
  
Function calls 
  
Function called by  
  
Modifications  
  
*/  
  
NODE * get_rand_node(NODE * nodes,unsigned max_node)  
{  
	NODE * start=NULL;  
	NODE * temp=NULL;  
	static unsigned rand_node=0;  
	unsigned count=0;  
  
/* remember the start of the node list*/  
start=nodes;  
  
/* start from the begining */  
temp=nodes;  
  
/* obtain a random node */  
rand_node=get_rand_num(max_node);  
  
/* loop round the nodes this number of times */  
while(count<=rand_node)  
	{  
	/* move on to the next node */  
	temp=temp->prev;  
	   
	/* if the node has no allowed links move on to the next node */  
	if(temp&&!temp->allowed_links)  
		{  
		/* move on to the next node */  
		temp=temp->prev;  
	    }  
	      
	if(!temp)  
		{  
		/* reached the end of the list wrap round */  
		temp=start;  
		}  
		  
	count++;  
	}  
	  
rand_node++;  
if(!temp) 
  { 
    printf("\nselected a null random node"); 
    exit(0); 
  } 
  
return(temp);  
} 
