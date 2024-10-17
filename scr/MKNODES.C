/* File contains make_rand_nodes  
  
(c) Mr J Hewitt 7-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
NODE * make_rand_nodes(unsigned);  
  
/* imported functions */  
extern NODE * create_node(void);  
extern NODE * add_node(NODE *,NODE *);  
extern LINK * make_rand_links(NODE *, NODE *, unsigned);  
extern TRAFFIC * make_rand_traffic(NODE *, NODE *, unsigned);  
extern unsigned get_rand_num(unsigned);  
   
/* local functions */                         
static NODE * make_rand_node_list(unsigned);  
static NODE * add_allowed_link_list(NODE *, unsigned);  
static NODE * add_traffic_list(NODE *, unsigned);  
  
/* Function make_rand_nodes  
  
Function creates a random node list containing a number of nodes  
  
Function takes the number of nodes in the network  
  
Function returns a pointer to the list of nodes  
  
Function uses nothing  
  
Function calls  
  
Function called by main  
  
Modifications  
  
*/  
  
NODE * make_rand_nodes(unsigned nodes)  
{     
	NODE * node_list=NULL;  
  
/* make a random node list */  
node_list=make_rand_node_list(nodes);  
  
  
/* add in the allowed links for each node */  
node_list=add_allowed_link_list(node_list,5);  
  
/* add in the random traffic records */  
node_list=add_traffic_list(node_list,5);  
  
return(node_list);  
  
}  
  
/* Function make_rand_node_list  
  
Function creates a random node list containing a number of nodes without  
allowed links.  
  
Function takes the number of nodes in the network  
  
Function returns a pointer to the list of nodes  
  
Function uses nothing  
  
Function calls  
  
Function called by main  
  
Modifications  
  
*/  
  
static NODE * make_rand_node_list(unsigned nodes)  
{                                    
	char * temp=NULL;  
	unsigned count=0;  
	NODE * last_node=NULL;  
	NODE * this_node=NULL;  
  
/* loop through the number of nodes to make */  
for(count=0;count<nodes;count++)  
	{  
	  
	/* create a node for this network */  
	if(!(this_node=create_node()))  
		{  
        /* could not create node */  
        /* distroy_node_list(last_node);*/  
          
        break;  
          
        }  
    else  
    	{                                    
    	/* give this node a name */  
    	/* allocate a some memory for the name */  
    	temp=(char *)malloc(20);  
    	if(temp)  
    		{  
    		sprintf(temp,"Node %u",count);  
    		this_node->node_name=temp;  
    		}  
    	else  
    		{  
    		/* could not create node */  
       		/* distroy_node_list(last_node);*/  
            break;  
        	}  
        	              
       	/* add this node into the node_list */  
		last_node=add_node(last_node,this_node);  
		}  
    }  
          
return(last_node);  
  
}  
  
/* Function add_allowed_link_list  
  
Function attaches random link lists to each node in the node_list  
  
Function takes the node list and the max number of links for a node  
  
Function returns a pointer to the list of nodes  
  
Function uses nothing  
  
Function calls  
  
Function called by main  
  
Modifications  
  
*/  
  
static NODE * add_allowed_link_list(NODE * node_list, unsigned links)  
{  
	NODE * this_node=NULL;  
  
/* start from the first node */  
this_node=node_list;  
  
/* loop through each of the nodes */  
while(this_node)  
	{  
	/* make a random list of allowed links for this node */  
	this_node->allowed_links=make_rand_links(this_node,node_list,get_rand_num(links));  
  
	/* move on to the next node */  
	this_node=this_node->prev;  
	}  
  
/* return a pointer to the start of the nodes */  
return(node_list);  
  
}  
  
  
/* Function add_traffic_list  
  
Function attaches random traffic list to each node in the node_list  
  
Function takes the node list and the max number of traffic recs for a node  
  
Function returns a pointer to the list of nodes  
  
Function uses nothing  
  
Function calls  
  
Function called by   
  
Modifications  
  
*/  
  
static NODE * add_traffic_list(NODE * node_list, unsigned dest)  
{  
	NODE * this_node=NULL;  
  
/* start from the first node */  
this_node=node_list;  
  
/* loop through each of the nodes */  
while(this_node)  
	{  
	/* make a random traffic list for this node */  
	this_node->traffic=make_rand_traffic(this_node,node_list,get_rand_num(dest));  
  
	/* move on to the next node */  
	this_node=this_node->prev;  
	}  
  
/* return a pointer to the start of the nodes */  
return(node_list);  
  
} 
