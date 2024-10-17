/* File contains net_delay  
  
(c) Mr J Hewitt 13-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
#include <math.h>  
            
/* project include files */  
#include "network.h"  
  
/* global varibles */  
extern unsigned long DEBUG; 
 
/* static varibles */  
  
/* exported functions */  
float net_delay(NETWORK *, NETWORK_PARAM *);  
  
/* imported functions */  
extern ROUTE_REC *net_routes(LINK *, NODE *);  
extern ROUTE_REC * find_route_rec(NODE *, NODE *, ROUTE_REC *);  
extern void delete_routes(ROUTE_REC *);            
extern void reset_links(LINK * );  
extern void logger(char *,...);  
  
/* local functions */                         
static void calc_flows(NODE *, ROUTE_REC *);  
static void add_flow(ROUTE_REC *, messages, messlen);  
static void calc_link_delays(LINK *);  
static float calc_route_delay(ROUTE_REC *);  
static float calc_mean_mess_delay(NODE *, ROUTE_REC *, NETWORK_PARAM *);   
  
/* Function net_delay  
  
Function calculates the mean message delay for the given network  
  
Function takes a pointer to the network, the network parameters  
  
Function returns a float that indicates the mean message delay for a network  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
float net_delay(NETWORK * temp,NETWORK_PARAM * params)  
{  
	float mess_delay=0;  
	ROUTE_REC * routes=NULL;  
  
#ifdef DEBUG_MEM  
logger("Started calculating delay");  
#endif                    
  
/* find the routes that message in the network use */  
if(routes=net_routes(temp->links,params->node_list))  
	{   
	 
	DEBUG++; 
	 
	/* reset the status flags for all the links in the network */  
	reset_links(temp->links);  
	  
	/* calculate the flow on each link in the network */  
	calc_flows(params->node_list,routes);  
      
	/* calculate the mean link delays in the network */  
	calc_link_delays(temp->links);  
      
	/* calculate the delay penalty for the network */  
	mess_delay=calc_mean_mess_delay(params->node_list,routes,params);  
  	}  
  
/* delete the route records for this network */  
delete_routes(routes);  
   	        
return(mess_delay);  
}  
  
/* Function calc_flows  
  
Function takes the number of messages and the average message len  
produced by each node to other nodes and adds them to the total no messages  
and message length to the total  
  
Function takes a pointer to the list of nodes in the network  
and a pointer to the routes from each node to the next  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static void calc_flows(NODE * node_list, ROUTE_REC * routes)  
{  
	NODE * this_node=NULL;  
	TRAFFIC * this_traffic=NULL;  
	ROUTE_REC * this_route=NULL;  
	  
/* start from the first node */  
this_node=node_list;  
  
/* loop through all the nodes */  
while(this_node)  
	{  
	/* start from the begining */  
	this_traffic=this_node->traffic;  
	  
	/* loop through all the traffic records */  
	while(this_traffic)  
		{  
		/* get the route that connects these two nodes together */  
		this_route=find_route_rec(this_node,this_traffic->node2,routes);  
		  
		/* add this traffic flow to this route */  
		add_flow(this_route,this_traffic->no_messages, this_traffic->message_len);  
		  
		/* move on to the next traffic flow */  
		this_traffic=this_traffic->prev;  
		}  
	/* move on to the next node */  
	this_node=this_node->prev;  
	}	   
		  
return;  
  
}  
		  
/* Function add_flow  
  
Function takes a route and adds the number of messages and average message len to it  
  
Function takes a pointer to the route and the flow to add to the links  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
                                                                        
*/  
static void add_flow(ROUTE_REC * route_rec, messages no_messages, messlen message_len)  
{  
	ROUTE_LINK * this_route=NULL;  
	  
/* start from the first record in this route */  
this_route=route_rec->route;  
  
/* loop through all the links in this route */  
while(this_route)  
	{  
	/* add the number of messages to this link */  
	this_route->link->no_messages+=no_messages;  
	                                               
	/* add the message length multiplied by the number of messages */  
	this_route->link->message_len+=(no_messages*message_len);  
	  
	/* move on to the next link in this route */  
	this_route=this_route->prev;  
	}  
		   
return;  
}  
  
/* Function calc_link_delays  
  
Function takes calculates the link delay for each link in the network.  
If the flow along a link is greater than the capasity of the link then the link is marked as beinfg unable to carry the traffic  
  
Function takes a pointer to the list of links in the network  
  
Function returns nothing  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static void calc_link_delays(LINK * temp)  
{  
	LINK * this_link=NULL;  
	float link_delay=0;  
	float no_mess_per_sec=0;  
	messlen length=0;  
	  
/* start from the first link */  
this_link=temp;  
  
/* loop through all the links */  
while(this_link)  
	{  
	/* calculate the mean link delay if any messages are sent down this link */  
	if(this_link->no_messages)  
		{	  
	      
	    /* calculate the mean message length */  
		length=this_link->message_len/this_link->no_messages;  
          
		/* calculate the number of messages this link can cope with in one sec */  
	   	no_mess_per_sec=(float)this_link->speed/length;  
          
       	/* check this link has high enough capacity */  
    	if(no_mess_per_sec<=this_link->no_messages)  
    		{  
    		/* link is saturated calculate the links delay as 99.9% of the saturated flow*/  
    		link_delay=1/((this_link->speed/(0.999*this_link->speed))-1);  
	    	  
	    	/* mark this link as saturated */  
	    	this_link->state=TRUE;  
	    	  
    		}  
    	else  
    		{  
    		/* calculate the link delay */                         
    		link_delay=1/(no_mess_per_sec-this_link->no_messages);  
    		}  
    	  
	    /* store this link delay in this link */  
    	this_link->delay=link_delay;  
        }  
   	/* move on to the next link */  
	this_link=this_link->prev;  
	}	   
		  
return;  
  
}  
  
/* Function calc_mean_mess_delay  
  
Function calculates the delay_peanlty for the network  
  
Function takes a pointer to the list of nodes in the network  
and a pointer to the routes from each node to the next and the network parameters  
  
Function returns the delay penalty of the network  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static float calc_mean_mess_delay(NODE * node_list, ROUTE_REC * routes, NETWORK_PARAM * params)  
{  
	NODE * this_node=NULL;  
	TRAFFIC * this_traffic=NULL;  
	ROUTE_REC * this_route=NULL;  
	float mess_delay=0;  
	float total_messages=0;  
	float route_delay=0;  
	float total_traffic=0;  
	float thwarted_traffic=0;  
	  
/* start from the first node */  
this_node=node_list;  
  
/* loop through all the nodes */  
while(this_node)  
	{  
	/* start from the begining of the traffic recs*/  
	this_traffic=this_node->traffic;  
	  
	/* loop through all the traffic records */  
	while(this_traffic)  
		{  
		/* get the route that connects these two nodes together */  
		this_route=find_route_rec(this_node,this_traffic->node2,routes);  
		  
		/* check route record was found only not found if traffic  
		is sent to the same node is it came from !!! */  
		if(this_route)  
			{			  
			/* get the route delay for this route */  
			route_delay=calc_route_delay(this_route);  
		      
		    /* check if there is a viable route for this traffic */  
		    if(route_delay<=0)  
		      {  
			/* there is no viable route for this traffic */  
			thwarted_traffic+=this_traffic->no_messages*this_traffic->message_len; 
		      }  
		      
		    /* convert the calculated route delay to the abs value */  
		    route_delay=fabs(route_delay);  
		      
		    /* check if route exists */  
		    if(route_delay!=0)  
		      {  
		    	/* calculate the mean message delay */  
		       	/* multiply it by the number of messages on this route and add it to the message delay */  
		       	mess_delay+=this_traffic->no_messages*route_delay;  
			/* add the number of messages to the total number of messages in the network */  
			total_messages+=this_traffic->no_messages;  
		      }  
									  
		    /* add this traffic to the total amount of traffic */  
		    total_traffic+=this_traffic->no_messages*this_traffic->message_len;  
		    }	  
					  
		/* move on to the next traffic flow */  
		this_traffic=this_traffic->prev;  
						  
		}  
	/* move on to the next node */  
	this_node=this_node->prev;  
	}	   
  
/* calculate the mean message delay compared to the acceptable message delay*/  
if(total_messages)  
	{  
	/* find the mean message delay */  
	mess_delay=mess_delay/total_messages;  
	  
	/* if the accepatble delay satisfied set mess delay to 0 */  
	if(mess_delay<params->acceptable_delay)  
		{  
		mess_delay=0;  
		}  
	else  
		{  
		/* claculate the normalised message delay */	  
    	mess_delay=((mess_delay-params->acceptable_delay)/mess_delay);  
    	}  
    }  
 else  
 	{  
 	/* no messages in the network or no viable routes */  
 	mess_delay=1;  
 	}  
 	     
/* calculate the thwarted message penalty*/  
thwarted_traffic=(thwarted_traffic/total_traffic);  
  
/*printf("\n%f %f",10*mess_delay,10*thwarted_traffic);*/ 
  
/* return the delay penalty */  
  
return(10*mess_delay+10*thwarted_traffic);  
  
}  
  
/* Function calc_route_delay  
  
Function takes a route and sums the link delays in it. If no viable route exists the function returns a negative number 
  
Function takes a pointer to the route  
  
Function returns the route delay. -1 indicates that no viable route exists  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
static float calc_route_delay(ROUTE_REC * route_rec)  
{  
	ROUTE_LINK * this_route=NULL;  
	float route_delay=0;  
	int multiplier=1;  
	      
/* if there is a route */  
if(route_rec->route)  
    {  
	/* start from the first record in this route */  
	this_route=route_rec->route;      
	  
	/* loop through all the links in this route */  
	while(this_route)  
		{                 
		/* check if this link is saturated */  
		if(this_route->link->state)  
			{  
			/* this is not a viable route for this traffic */  
			multiplier=-1;  
			}  
		  
		/* add the link delay to the route delay */  
		route_delay+=this_route->link->delay;  
	                                               
		/* move on to the next link in this route */  
		this_route=this_route->prev;  
		}  
	}  
else  
	{  
	/* return a route delay of zero */  
	route_delay=0;  
	}		   
	                      
route_delay*=multiplier;	                      
  
return(route_delay);  
} 
