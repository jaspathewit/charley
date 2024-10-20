/* File contains make_rand_network  
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
LINK *make_rand_network(NETWORK_PARAM *);  
  
/* imported functions */  
extern LINK * get_rand_link(NETWORK_PARAM *);  
extern LINK * add_link(LINK *,LINK *);  
  
/* local functions */  
  
/* Function make_rand_network  
  
Function creates a random network with a number of links  
  
Function takes the network parameters  
  
Function returns a pointer to the created network  
  
Function uses nothing  
  
Function calls  
  
Function called by main  
  
Modifications  
  
*/  
  
LINK * make_rand_network(NETWORK_PARAM * params)  
{                          
	unsigned links=0;  
	unsigned count=0;  
	LINK * last_link=NULL;  
	LINK * this_link=NULL;  
                       
/* calculate the number of links to give this network */  
if(params->connectivity_req==1)  
	links=params->no_nodes;  
else  
	links=(params->no_nodes*params->connectivity_req)/2;  
                       
/* loop through the number of links to add */  
for(count=0;count<links;count++)  
	{  
	  
	/* create a link for this network */  
	if(!(this_link=get_rand_link(params)))  
		{  
		/* could not create link */  
		/* destroy_network(last_link);*/
  
		break;  
  
		}  
	else  
		{  
		/* set list pointers to NULL */  
		this_link->prev=NULL;  
      	this_link->next=NULL;      
      	  
      	/* add this link into the network */  
      	last_link=add_link(last_link,this_link);  
		}  
	}  
  
return(last_link);  
  
}  
