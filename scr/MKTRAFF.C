/* File contains make_rand_traffic  
  
(c) Mr J Hewitt 7-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
TRAFFIC * make_rand_traffic(NODE *, NODE *, unsigned);  
  
/* imported functions */  
extern TRAFFIC * create_traffic(void);  
extern TRAFFIC * add_traffic(TRAFFIC *,TRAFFIC *);  
extern NODE * get_rand_node(NODE *,unsigned);  
extern messages get_rand_messages(unsigned);  
extern messlen get_rand_mess_len(unsigned);  
   
/* local functions */                         
  
/* Function make_rand_traffic  
  
Function creates a random traffic list  
  
Function takes a pointer to the node to attach the traffic list to,  
a pointer to the nodes in the network and the max number of destinations.  
  
Function returns a pointer to the traffic list  
  
Function uses nothing  
  
Function calls  
  
Function called by main  
  
Modifications  
  
*/  
  
TRAFFIC * make_rand_traffic(NODE * this_node, NODE * node_list, unsigned dest)  
{  
	unsigned count=0;  
	TRAFFIC * last_traffic=NULL;  
	TRAFFIC * this_traffic=NULL;  
  
/* loop through the number of traffic records to make */  
for(count=0;count<dest;count++)  
	{  
	  
	/* create a traffic record for this list */  
	if(!(this_traffic=create_traffic()))  
		{  
        /* could not create traffic */  
        /* distroy_traffic_list(last_traffic);*/  
          
        break;  
          
        }  
    else  
    	{                                    
		/* attach one end of this traffic list to this node */  
		this_traffic->node1=this_node;  
  
		/* get a random node to send the messages to */  
		this_traffic->node2=get_rand_node(node_list,20);  
  	  
		/* give this traffic record a random no messages */  
		this_traffic->no_messages=get_rand_messages(3);  
	  
		/* give this traffic record a random message len */  
		this_traffic->message_len=get_rand_mess_len(200);  
                  
		/* add this traffic rec into the traffic list */  
		last_traffic=add_traffic(last_traffic,this_traffic);  
    	}  
    }  
          
return(last_traffic);  
  
} 
