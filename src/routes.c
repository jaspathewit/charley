/* File contains net_routes  
  
(c) Mr J Hewitt 20-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */    
#include "network.h"  
  
/* global varibles */  
extern unsigned long DEBUG; 
  
/* static varibles */  
  
/* exported functions */  
ROUTE_REC * net_routes(LINK *,NODE *);  
  
/* imported functions */  
extern ROUTE_REC * create_route_rec(void);  
extern ROUTE_LINK * create_route_link(void);  
extern void destroy_route_link(ROUTE_LINK *);
extern ROUTE_REC * add_route_rec(ROUTE_REC *,ROUTE_REC *);  
extern void reset_links(LINK *);  
extern ROUTE_LINK * add_route_link(ROUTE_LINK *, ROUTE_LINK *);  
extern void reset_nodes(NODE *);  
extern LINK * copy_link(LINK *);  
extern ROUTE_LINK * copy_route_link(ROUTE_LINK *);  
extern void delete_route_links(ROUTE_LINK *);  
extern ROUTE_REC * find_route_rec(NODE *, NODE *, ROUTE_REC *);  
  
extern void logger(char *,...);
  
/* local functions */                         
static ROUTE_REC * add_route_recs(NODE *, NODE *, ROUTE_REC *);  
static ROUTE_REC * find_routes(NODE *, NODE *, LINK *, ROUTE_REC *);  
static LINK * find_link(LINK *,NODE *);  
static unsigned long calc_route_cost(ROUTE_LINK *, ROUTE_LINK *);  
static NODE * find_routed_node(NODE *, NODE *, ROUTE_REC *);   
static ROUTE_LINK * copy_route(ROUTE_LINK *);  
static ROUTE_REC * locate_route_rec(NODE *, NODE *, LINK *, ROUTE_REC *);  
static ROUTE_LINK * update_route_rec(ROUTE_LINK * , ROUTE_LINK *);  
  
/* Function net_routes  
  
Function calculates the fastest route between each node in the network  
  
Function takes a pointer to the network and the list of nodes in the network  
  
Function returns a pointer to the routes list  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
ROUTE_REC * net_routes(LINK * temp,NODE * node_list)  
{  
	ROUTE_REC * last_route_rec=NULL;  
    NODE * start_node=NULL;  
  
/* start from the begining of the nodes list */  
start_node=node_list;  
  
/* find routes between all nodes */  
while(start_node)  
	{  
  
	/* add empty records to the routes list from this node to all others */  
	last_route_rec=add_route_recs(start_node,node_list,last_route_rec);  
  
    /* find the best cost routes from start node to all other nodes */  
	last_route_rec=find_routes(start_node,node_list, temp, last_route_rec);  
      
    /* reset links */  
	reset_links(temp);  
      
    /* reset the nodes */  
    reset_nodes(node_list);  
      
	/* move on to the next node */  
	start_node=start_node->prev;  
  
	}                 
	 
return(last_route_rec);  
}  
  
/* Function add_route_recs  
  
  
Function adds empty route recs from this node to all others in the network  
  
Function takes a pointer to this node the node list and the current last  
route record  
  
Function returns a pointer to the extended route list  
  
Function used nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static ROUTE_REC * add_route_recs(NODE * this_node,NODE * node_list,ROUTE_REC *cur_last_route_rec)  
{  
  
	NODE * node_poss=NULL;  
  
	ROUTE_REC * this_route_rec=NULL;  
	ROUTE_REC * last_route_rec=NULL;  
  
#ifdef DEBUG_MEM  
logger("finding routes for node %s",this_node->node_name);  
#endif  
  
/* start from the beginning of all the nodes */  
node_poss=node_list;  
  
/* add the records on to the current end of the list */  
last_route_rec=cur_last_route_rec;  
  
while(node_poss)  
	{  
  
	/* check that the node is not the starting node */  
	if(this_node!=node_poss)  
		{  
		/* make some storage for this route record */  
		this_route_rec=create_route_rec();  
  
		this_route_rec->node1=this_node;  
		this_route_rec->node2=node_poss;  
  
		this_route_rec->cost=0;  
  
		this_route_rec->route=NULL;  
  
		/* store this record */  
		last_route_rec=add_route_rec(last_route_rec,this_route_rec);  
  
		}  
  
	/* move on to the next node */  
	node_poss=node_poss->prev;  
	}  
  
return(last_route_rec);  
  
}  
  
/* Function find_routes  
  
  
Function finds routes from a node to all other nodes  
  
Function takes a pointer to this node the node list the list of links makeing  
the network and the last route record  
  
Function returns a pointer to the route list  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static ROUTE_REC * find_routes(NODE * this_node,NODE * node_list, LINK * network, ROUTE_REC *last_route_rec)  
{  
  
	NODE * node_poss=NULL;  
    ROUTE_REC * route_rec_poss=NULL;  
    ROUTE_LINK * current_route=NULL;  
    ROUTE_LINK * temp_route_link=NULL;  
  	LINK * temp=NULL;  
    unsigned long cost;  
  
/* start from this node */  
node_poss=this_node;  
  
/* loop through all nodes */  
while(node_poss)  
	{  
	/* mark this node as used */  
	node_poss->state=1;  
     
   	/* get the first link from this node */  
	temp=find_link(network, node_poss);  
   
 	/* loop through all links from this node */  
	while(temp)  
		{         
		/* make a route_link that points to this link */  
		temp_route_link=create_route_link();  
        temp_route_link->link=temp;  
                                         
        /* locate the route record for these two nodes */  
        route_rec_poss=locate_route_rec(this_node,node_poss,temp,last_route_rec);                        
          
        /* check if this route is better than the current route */  
		cost=calc_route_cost(current_route,temp_route_link);  
          
        if(cost>route_rec_poss->cost)  
			{  
			/* update the route record *//* remove the old route */  
			delete_route_links(route_rec_poss->route);  
            route_rec_poss->route=update_route_rec(current_route,temp_route_link);  
			route_rec_poss->cost=cost;  
			}                                
		  
		/* delete the temp route link */  
		destroy_route_link(temp_route_link);
                      
		/* get the next link from this node */  
		temp=find_link(network, node_poss);       
		}   
	/* delete the current route */              
	delete_route_links(current_route);  
   
	/* move on to an unused node which has a route */  
	node_poss=find_routed_node(this_node, node_list, last_route_rec);   
		  
	if(node_poss)  
		{  
          
		/* find the corresponding route_record */  
		route_rec_poss=find_route_rec(this_node,node_poss,last_route_rec);  
         
		/* make this route the current_route */  
		current_route=copy_route(route_rec_poss->route);  
 		}  
	}  
  
return(last_route_rec);  
  
}  
  
/* Function find_link  
  
Function attempts to find a link that is connected to this node  
that has not been previously used  
  
Function takes a pointer to the network a pointer to the node to search from  
  
Function returns   
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static LINK * find_link(LINK * temp,NODE * poss)  
{  
  
	LINK * connected_link=NULL;  
	LINK * net_poss=NULL;  
  
/* start from the first link in the network */  
net_poss=temp;  
  
/* search through all the links in the network */  
while(net_poss)  
	{  
	/* check if this link has been used before */  
	if(!net_poss->state)  
		{  
	    	  
		/* check if this link is connected to the required node */  
		if((net_poss->node1)==poss)  
			{  
			/* mark this link as used */  
			net_poss->state=1;  
  
			/* return a pointer to this link */  
			connected_link=net_poss;  
  
			/* get out of the loop */  
			break;  
			}  
	  
  
		/* check if this link is connected to the required node */  
		if((net_poss->node2)==poss)  
			{  
			/* mark this link as used */  
			net_poss->state=1;  
  
			/* return a pointer to this link */  
			connected_link=net_poss;  
  
			/* get out of the loop */  
			break;  
			}       
		}	  
	/* move on to the next link */  
	net_poss=net_poss->prev;  
	}  
	  
/*return any found link */  
return(connected_link);  
                                      
}  
  
  
/* Function locate_route_rec  
  
Function finds the route rec that starts from one node and ends at another node  
  
Function takes a pointer to the starting node, a pointer to a link from this node and  
a pointer to the route records to search  
  
Function returns a pointer to the route record  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static ROUTE_REC * locate_route_rec(NODE * from_node, NODE * inter_node, LINK * temp, ROUTE_REC * route_recs)  
{  
  
	ROUTE_REC * required_rec=NULL;       
	  
/* find the route record where this link route ends depending on which way round the link is */  
if(temp->node1==inter_node)  
		{  
		required_rec=find_route_rec(from_node,temp->node2,route_recs);  
		}  
	else  
		{  
		required_rec=find_route_rec(from_node,temp->node1,route_recs);  
		}  
  
/*return the route record */  
return(required_rec);  
                                      
}  
  
/* Function find_routed_node  
  
Function attempts to find a node that has not been used and has a route to it  
from another node  
  
Function takes a pointer to the node the route must originate from and the  
current list of routes  
  
Function returns a pointer to the node  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static NODE * find_routed_node(NODE * this_node, NODE * node_list, ROUTE_REC * routes)  
{  
  
	NODE * node_poss=NULL;  
	NODE * unvisited_node=NULL;  
	ROUTE_REC * temp=NULL;  
  
/* start from the first node */  
node_poss=node_list;  
  
/* search through all nodes */  
while(node_poss)  
	{  
	  
	/* check that the from and to nodes are not the same */  
	if(this_node!=node_poss)  
		{  
		/* check if this node has been visited before */  
		if(!node_poss->state)  
			{  
  
			/* find the route record belonging to this node */  
			temp=find_route_rec(this_node,node_poss,routes);  
  
			/* check if this node has a route */  
			if(temp->route)  
				{  
  
				/* return a pointer to this node */  
				unvisited_node=node_poss;  
  
				/* get out of the loop */  
				break;  
				}  
			}  
		}	  
	/* move on to the next node */  
	node_poss=node_poss->prev;  
	}  
/*return any found link */  
return(unvisited_node);  
                                      
}  
  
/* Function calc_route_cost  
  
Function calculates the cost of a route  
from another node  
  
Function takes a pointer to a route and a link to be added to the route  
  
Function returns a cost  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static unsigned long calc_route_cost(ROUTE_LINK * the_route, ROUTE_LINK * added_route_link)  
{  
  
	ROUTE_LINK * route_link_poss=NULL;  
	unsigned count=0;  
	unsigned long cost=0;  
  
/* start from the first node */  
route_link_poss=the_route;  
  
/* loop through all the links in this route */  
while(route_link_poss)  
	{  
	/* add the speed of this link to the cost */  
	cost+=route_link_poss->link->speed;  
  
	/* move on to the next link */  
	route_link_poss=route_link_poss->prev;  
  
	/* count this link */  
	count++;  
  
	}  
  
/* add in the extra link */  
cost+=added_route_link->link->speed;  
  
/* find average speed */  
cost=cost/(count+1);  
  
return(cost);  
  
}  
  
  
/* Function copy_route  
  
Function copy the route links that form a route  
  
Function takes a pointer to a route  
  
Function returns a pointer to the copied route  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static ROUTE_LINK * copy_route(ROUTE_LINK * the_route)  
{  
  
	ROUTE_LINK * route_link_poss=NULL;  
	ROUTE_LINK * last_route_link=NULL;  
	ROUTE_LINK * this_route_link=NULL;  
  
#ifdef DEBUG_MEM  
logger("Copying route links %p",the_route);  
#endif  
  
/* start from the first link */  
route_link_poss=the_route;  
  
/* loop through all the route records in this route */  
while(route_link_poss)  
	{  
	/* copy link pointed to by link_poss */	  
	if(!(this_route_link=copy_route_link(route_link_poss)))  
		{  
		/* memory not allocated */  
		/* delete any allocated route links */  
		/* set last rout link to NULL*/  
		  
		break;  
		}  
			  
	/* set the next and prev pointers on the copy to  NULL */  
	this_route_link->prev=NULL;  
	this_route_link->next=NULL;  
	  
	/* add this link into the copy of the route */   
	last_route_link=add_route_link(last_route_link,this_route_link);  
	  
	/* move on to the next link */  
	route_link_poss=route_link_poss->prev;  
  
	}                                     
#ifdef DEBUG_MEM  
logger("Finished copying route links");      
#endif	  
	  
	  
/* return pointer to the copied route */	  
return(last_route_link);  
  
}  
  
  
  
/* Function update_route_rec  
  
Function updates a route record with a new route and cost  
  
Function takes a pointer currect route and the extra link to add  
  
Function returns a pointer to copied route   
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static ROUTE_LINK * update_route_rec(ROUTE_LINK * route, ROUTE_LINK * link)  
{  
	ROUTE_LINK * temp_route=NULL;  
	ROUTE_LINK * temp_link=NULL;  
    ROUTE_LINK * route_copy=NULL;  
  
/* make a copy of the link */  
temp_link=copy_route_link(link);  
                                             
/* make a copy of the route */  
temp_route=copy_route(route);  
  
/* add the link to the copy of the route to make the new route*/  
route_copy=add_route_link(temp_route,temp_link);  
  
/* return pointer to the route record */	  
return(route_copy);  
} 
