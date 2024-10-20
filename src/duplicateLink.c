/* File contains net_dup_link  
  
(c) Mr J Hewitt 9-FEB-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>  
  
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
float net_dup_link(NETWORK *);  
  
/* imported functions */  
  
/* local functions */  
  
/* Function net_dup_link  
  
Function returns the the value of the duplicate link factor for a network  
  
Function takes a network to evaluate  
  
Function returns the duplicate link function  
  
Function uses nothing  
  
Function calls  
  
Function called by  
  
Modifications  
  
*/  
  
float net_dup_link(NETWORK * temp)  
{  
	LINK * start_poss=NULL;  
	LINK * poss=NULL;  
	float dup_link=0;  
  
/* start from the beginning of the linked list */  
start_poss=temp->links;  
  
/* for each link in the network count the number of duplications */  
while(start_poss)  
	{  
  
	/* start from the next link */  
	poss=start_poss->prev;  
  
	/* loop through the links in the net work */  
	while(poss)  
		{  
  
		/* compare the two networks */  
		if(start_poss->node1==poss->node1||start_poss->node1==poss->node2)  
			{  
			if(start_poss->node2==poss->node2||start_poss->node2==poss->node1)  
				{  
				if(start_poss->cost==poss->cost)  
					{  
					if(start_poss->speed==poss->speed)  
						{  
						/* these two links are the same */  
						/* add one to the dup link factor */  
						dup_link+=1;  
						}  
					}  
				}  
			}  
		/* move on to the next link */  
		poss=poss->prev;  
		}  
	/* move on to the next loop */  
	start_poss=start_poss->prev;  
  
	}  
  
/* if the network is a null or only one link */  
if(!start_poss||temp->no_links==1)  
	{  
	dup_link=0;  
	}  
else  
	{	  
	/* devide the dup_link value by the max obtainable for this network */  
	dup_link/=((temp->no_links*(temp->no_links+1))/2)-1;  
	}  
  
return(dup_link);  
} 
