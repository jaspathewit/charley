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
LINK * get_rand_link(NETWORK_PARAM *);  
  
/* imported functions */  
extern LINK * create_link(void);  
extern void distroy_link(LINK *);  
extern NODE * get_rand_node(NODE *,unsigned);  
extern capacity get_rand_speed(unsigned);  
extern LINK * copy_link(LINK *);  
extern LINK * select_rand_link(LINK *, unsigned);  
extern unsigned get_rand_num(unsigned);  
  
/* local functions */  
  
/* Function get_rand_link  
  
Function select a random link from all the possible links  
  
Function takes a pointer to the network parameters  
  
Function returns a pointer to a copy of the selected link  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
  
LINK * get_rand_link(NETWORK_PARAM * params)  
{  
	LINK * temp=NULL;  
	LINK * link_poss=NULL;  
	NODE * node_poss=NULL;  
     
/* loop until a link is selected */  
while(!link_poss)  
	{  
	/* select a random node */  
	node_poss=get_rand_node(params->node_list,params->no_nodes);  
  
	/* get a random link belonging to this node */  
	link_poss=select_rand_link(node_poss->allowed_links, get_rand_num(node_poss->no_links));  
  
	}  
  
/* copy the selected link into storage */  
temp=copy_link(link_poss);  
  
return(temp);  
  
} 
