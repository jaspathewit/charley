/* File inserts a traffic rec into a linked list of traffic recs  
  
(c) Mr J Hewitt 6-DEC-1994 */  
  
/* standard included files */  
/*#include <stdio.h>  
#include <stdlib.h>*/  
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
TRAFFIC * add_traffic(TRAFFIC *,TRAFFIC *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function add_traffic  
  
Function adds a traffic rec into the traffic list  
  
Function takes a traffic pointer to the preceding traffic rec in the list and a pointer  
to the traffic rec to be added.  
  
Function returns a pointer to the inserted traffic rec.  
  
Function uses nothing  
  
Function calls nothing  
  
Function called by  
  
Modifications  
  
*/  
  
TRAFFIC * add_traffic(TRAFFIC * pre_traffic, TRAFFIC * traffic_to_add)  
{  
/* make this traffic rec point to the preceding traffic rec*/  
traffic_to_add->prev=pre_traffic;  
  
/* if not the first traffic rec in the list */  
if(pre_traffic)  
	{  
	/* make traffic_to_add point to pre_traffic's next traffic rec*/  
	traffic_to_add->next=pre_traffic->next;  
	  
	/* make pre_traffic point to traffic_to_add */  
	pre_traffic->next=traffic_to_add;  
	  
	}  
	  
/* if there is a traffic after traffic_to_add make it point to traffic_to_add */  
if(traffic_to_add->next)  
	{  
	/* make the next traffic point back to the traffic_to_add */  
	(traffic_to_add->next)->prev=traffic_to_add;  
	}  
			  
  
return(traffic_to_add);  
} 
