/* File contains make_rand_links  
  
(c) Mr J Hewitt 7-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
LINK * make_rand_links(NODE *, NODE *, unsigned);  
  
/* imported functions */  
extern LINK * create_link(void);  
extern LINK * add_link(LINK *,LINK *);  
extern unsigned get_rand_num(unsigned);  
extern NODE * get_rand_node(NODE *,unsigned);  
extern capacity get_rand_speed(unsigned);  
extern money get_rand_cost(unsigned);  
   
/* local functions */                         
  
/* Function make_rand_links  
  
Function creates a random link list containing a number of links  
  
Function takes a pointer to the nodde to attach these links to,  
a pointer to the nodes in the network and the maximum number of links,  
a node can have  
  
Function returns a pointer to the list of links  
  
Function uses nothing  
  
Function calls  
  
Function called by main  
  
Modifications  
  
*/  
  
LINK * make_rand_links(NODE * this_node, NODE * node_list, unsigned links)  
{  
	unsigned count=0;  
	LINK * last_link=NULL;  
	LINK * this_link=NULL;  
  
/* loop through the number of LINKS to make */  
for(count=0;count<links;count++)  
	{  
	  
	/* create a link for this list */  
	if(!(this_link=create_link()))  
		{  
        /* could not create link */  
        /* destroy_link_list(last_link);*/
          
        break;  
          
        }  
    else  
    	{                                    
		/* attach one end of this link to this node */  
		this_link->node1=this_node;  
  
		/* attach the other end to a random node */  
		this_link->node2=get_rand_node(node_list,20);  
  
		/* give this link a random speed */  
		this_link->speed=get_rand_speed(1000);  
		  
		/* give this link a random cost */  
		this_link->cost=get_rand_cost(1000);  
  
		/* add this link into the link_list */  
		last_link=add_link(last_link,this_link);  
    	}  
    }  
          
return(last_link);  
  
      } 
