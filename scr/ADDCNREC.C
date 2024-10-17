/* File inserts a connectivity rec into the linked list of connectivity recs   
  
(c) Mr J Hewitt 20-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>  
             
/* project include files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
CONNECTIVITY_REC * add_con_rec(CONNECTIVITY_REC *,CONNECTIVITY_REC *);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function add_con_rec  
  
Function adds a connectivity record into the connectivity list  
  
Function takes a connectivity pointer to the preceding rec in the list and a pointer  
to the rec to be added.  
  
Function returns a pointer to the inserted connectivity_rec.  
  
Function uses nothing  
  
Function calls nothing  
  
Function called by  
  
Modifications  
  
*/  
  
CONNECTIVITY_REC * add_con_rec(CONNECTIVITY_REC * pre_con_rec, CONNECTIVITY_REC * con_rec_to_add)  
{  
/* make this con rec point to the preceding con_rec */  
con_rec_to_add->prev=pre_con_rec;  
  
/* if not the first con_rec in the list */  
if(pre_con_rec)  
	{  
	/* make con_rec_to_add point to pre_con_recs next con_rec */  
	con_rec_to_add->next=pre_con_rec->next;  
	  
	/* make pre_con_rec point to con_rec_to_add */  
	pre_con_rec->next=con_rec_to_add;  
	  
	}  
	  
/* if there is a con_rec after con_rec_to_add make it point to con_rec_to_add */  
if(con_rec_to_add->next)  
	{  
	/* make the next con_rec point bake to the con_rec_to_add */  
	(con_rec_to_add->next)->prev=con_rec_to_add;  
	}  
			  
  
return(con_rec_to_add);  
} 
