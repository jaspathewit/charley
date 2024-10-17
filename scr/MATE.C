/* File contains mate   
   
(c) Mr J Hewitt 10-JAN-1994 */   
   
/* standard included files */   
#include <stdio.h>   
#include <stdlib.h>                                    
#include <math.h>   
             
/* project include files */   
#include "network.h"   
   
/* global varibles */   
   
/* static varibles */   
   
/* exported functions */   
POPULATION * mate(POPULATION *, NETWORK_PARAM * params);   
   
/* imported functions */    
extern POPULATION * create_population(unsigned);   
extern unsigned get_rand_num(unsigned);    
extern void distroy_network(NETWORK *);   
extern void logger(char *,...);   
extern void print_network(NETWORK *);   
extern NETWORK * copy_network(NETWORK *);   
extern float net_fitness(NETWORK *, NETWORK_PARAM *);   
extern LINK * select_rand_link(LINK *, unsigned);   
/*extern LINK * add_link(LINK *,LINK *);*/   
extern unsigned count_links(LINK *);   
extern LINK * copy_link(LINK *);   
extern void distroy_link(LINK *);   
extern LINK * get_rand_link(NETWORK_PARAM *);   
extern NETWORK * create_network(void);   
extern LINK * add_link(LINK *, LINK *);    
extern NODE *get_rand_node(NODE *, unsigned);   
extern void reset_links(LINK *);  
  
/* local functions */   
static unsigned reproduce(POPULATION *, POPULATION *,  unsigned , NETWORK_PARAM * );                          
static unsigned round(float);   
static void crossover(NETWORK * , NETWORK *, NETWORK_PARAM *);   
static NETWORK * mutate(NETWORK *, NETWORK_PARAM *);   
static NETWORK * adddel_mutation(NETWORK *,NETWORK_PARAM *);   
static NETWORK * link_mutation(NETWORK *, NETWORK_PARAM *);   
static NETWORK * dup_network(NETWORK *, NETWORK_PARAM *);   
static LINK * find_link_from(LINK *, NODE *);   
static unsigned get_index(NETWORK_PARAM *);   
/* Function mate   
   
Function mates the individuals the population of networks acording to their fitness values   
   
Function takes a pointer to the initial population and the number of networks in the population   
   
Function returns a pointer to the new population NULL if any error occured during the mating.   
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/   
   
POPULATION * mate(POPULATION * temp, NETWORK_PARAM * params)   
{                                                 
	POPULATION * new_pop=NULL;   
   
	unsigned no_partners=0;      
	float reproductive_capacity=0;   
	float fitness_residual=0;                
	unsigned count=0;   
/*	NETWORK * new_network=NULL;*/   
    unsigned no_offspring=0;   
       
/* create space for the new population */   
if(new_pop=create_population(params->population_size))   
  {  
    /* keep on reproducing until have produced the second generation */  
    while(no_offspring<params->population_size)  
      { 
 	/* carry out a reproduction */  
	no_offspring+=reproduce(new_pop, temp, no_offspring, params);       
	 
 
      }  
  }  
  
/* calculate the mean fitness for this population */  
new_pop->mean_fitness=new_pop->total_fitness/params->population_size;  
  
return(new_pop);   
}                                                                               
   
/* Function reproduce   
   
Function mates two members of the popwlation with probability determined by the revees function the new off spring are inserted into the population.  
   
Function takes a pointer to the new population pointer to the current population the current number off spring in the population and the network parameters.   
   
Function returns the number of offspring added to the new population   
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/   
   
static unsigned reproduce(POPULATION * new_pop, POPULATION * temp , unsigned no_offspring, NETWORK_PARAM * params )   
{                                                 
	unsigned count=0;   
	unsigned offspring_index=0;   
	NETWORK * network1=NULL;   
	NETWORK * network2=NULL;   
	unsigned index=0;  
  
logger("Reproducing the two networks");   
  
/* start offspring index from the current number of offspring */  
offspring_index=no_offspring;  
  
/* find index of the first network */  
index=get_index(params);  
  
/* get a copy of the first chosen network */     
if(!(network1=dup_network(temp->networks[index],params)))   
  {   
    /* out of memory copying this network */   
    count=0;    
  }   
/* check if cross over is to happen or straight copy */   
if(get_rand_num(100)<60 )   
  {   
    index=get_index(params);  
    /* get a copy of a random partner for network 1*/   
    if(!(network2=dup_network(temp->networks[index],params)))   
      {   
	/* out of memory copying this network */   
	distroy_network(network1);   
	count=0;    
      } 	   
  }  
else   
  {   
    /* do a straight copy */   
    if(!(network2=dup_network(temp->networks[index],params)))   
      {   
	/* out of memory copying this network */   
	count=0;   
      }   
  }   
		   		           
/* do the cross over on these two networks */   
crossover(network1,network2,params);   
	       
/* mutate the offspring */   
network1=mutate(network1,params);   
network2=mutate(network2,params);   
	          
/* update the number of links in each of the offspring */   
network1->no_links=count_links(network1->links);   
network2->no_links=count_links(network2->links);   
  
/* check that this offspring has some links */  
if(network1->links&&(offspring_index<params->population_size))  
  {  
    /* store the offsprings fitness */   
    network1->fitness=net_fitness(network1,params);   
	   
    /* add this fitness to the total fitness of the population */   
    new_pop->total_fitness+=network1->fitness;   
			   
    /* if this fitness is better than the previous best fitness then store it */   
    if(network1->fitness<new_pop->best_fitness||offspring_index==0)   
      new_pop->best_fitness=network1->fitness;   
		   
    /* if this fitness is worse than the previous worst fitness then store it */   
    if(network1->fitness>new_pop->worst_fitness||offspring_index==0)   
      new_pop->worst_fitness=network1->fitness;   
       
    /* put the generated offspring into the new_population */   
    new_pop->networks[offspring_index]=network1;   
    /* update the off spring index */   
    offspring_index++;   
    count++;  
  }  
else  
  {  
    /* no links in this off spring or not required*/  
    distroy_network(network1);  
  }  
  
/* check that this off spring has some links */  
if(network2->links&&(offspring_index<params->population_size))  
  {  
    network2->fitness=net_fitness(network2,params);   
  
    /* add this fitness to the total fitness of the population */   
    new_pop->total_fitness+=network2->fitness;   
		   
    /* if this fitness is better than the previous best fitness then store it */   
    if(network2->fitness<new_pop->best_fitness||offspring_index==0)   
      new_pop->best_fitness=network2->fitness;   
		   
    /* if this fitness is worse thcn the previous worst fitness then store it */   
    if(network2->fitness>new_pop->worst_fitness||offspring_index==0)   
      new_pop->worst_fitness=network2->fitness;                                         
	   
    /* put the generated offspring into the new_population */   
    new_pop->networks[offspring_index]=network2;   
    /* update the off spring index */   
    offspring_index++;  
    count++;     
  }  
else  
  {  
    /* this network has no links or not reqired */  
    distroy_network(network2);  
  }  
  
logger("Finished reproducing the networks");	   
	   
/* return the number of offspring added to the next generation */	   
return(count);   
   
}	  
       
/* Function get_index   
   
Function selects an index in the population the indexes are distributed according to the reeves distribution  
   
Function takes a pointer to the network parameters  
   
Function returns the index in the population  
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/   
  
static unsigned get_index(NETWORK_PARAM * params)  
{  
  
  float reeves=0;  
  unsigned long multiplier=0;  
  float rand_num=0;  
  unsigned index=0;  


/* return a reeves result 25 % of the time else random */

/* calculate the multiplier */  
multiplier=(params->population_size-1)*(params->population_size);  
  
/* calculate the random number */  
rand_num=(float)rand()/(float)RAND_MAX;  
   
reeves=(sqrt(1+(4*rand_num*multiplier))-1)/2;  
 
index=round(reeves);  
  
if(index>params->population_size-1)  
  {  
    printf("\nIllegal index %u",index);  
    exit(0);  
  }  
  
return(index);  
}  
  
  
  
   
/* Function cross_over   
   
Function selects a cross over point on the two net works and exchanges links between them   
   
Function takes a pointers to the two networks to crossover and the network parameters   
   
Function returns nothing   
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/   
   
static void crossover(NETWORK * network1, NETWORK * network2, NETWORK_PARAM * params)   
{                                                 
	LINK * link1=NULL;   
	LINK * link2=NULL;   
    LINK * link1_tail=NULL;   
    LINK * link2_tail=NULL;   
    NODE * temp_node=NULL;   
       
    unsigned cross_over_poss=0;   
                                            
/* get the cross over node for network 1 */    
cross_over_poss=get_rand_num(params->no_nodes);                                                                
temp_node=get_rand_node(params->node_list, cross_over_poss);   
   
/* find the first link in the network that belongs to this node */   
link1=find_link_from(network1->links, temp_node);   
   
/* get the cross over point for network 2*/                                                   
link2=find_link_from(network2->links, temp_node);   
                                     
/* split the network */   
if(link1)   
  {                                       
    /* remember the tail part of network 1 */   
    link1_tail=link1->prev;                                
	   
    /* make the two parts ready for cross over */   
    link1->prev=NULL;   
    if(link1_tail)   
      link1_tail->next=NULL;   
  } 
else 
  { 
    /* make the tail all of this network*/ 
    link1_tail=network1->links; 
  } 
 
/* do the same for network 2 */   
if(link2)   
  {                                       
    /* remember the tail part of network 1 */   
    link2_tail=link2->prev;                                
	   
    /* make the two parts ready for cross over */   
    link2->prev=NULL;   
    if(link2_tail)   
      link2_tail->next=NULL;   
  }   
else 
  { 
    /* make the tail all of this network*/ 
    link2_tail=network2->links; 
  }		   
/*graft the tail from link 2 onto the head of link 1 */   
/*graft the tail from link 1 onto the head of link 2 */   
                                     
/* cross over the linked lists at these points */    
/* check if link1 is null */   
if(!link1)   
	{   
	/* make this network just the tail of network2 */   
	network1->links=link2_tail;                                    
	}   
else   
	{   
	/* graft the tail of network 2 onto network 1 */   
	link1->prev= link2_tail;   
	if(link2_tail)   
		link2_tail->next=link1;    
	}   
   
/* check if link2 is null */   
if(!link2)   
	{   
	/* make this network just the tail of network1 */   
	network2->links=link1_tail;                                    
	}   
else   
	{	   
	/* graft the tail of network 2 onto network 1 */   
	link2->prev= link1_tail;   
	if(link1_tail)   
		link1_tail->next=link2;   
    }   
   
  
return;   
}   
   
/* Function round   
   
Function raunds a floating point number up or down  to an apropriat integer   
   
Function takes the floating point number to round   
   
Function returns the apropriate integer   
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/	                                                              
static unsigned round(float number)   
{   
	float result=0;   
	   
/* get the floored number */   
result=(float)floor(number);   
   
if((number-result)>0.5)   
	result=result+1;   
	   
return((unsigned)result);		   
   
}   
	                                   
/* Function mutate   
   
Function decides which mutation if any to perform and applies it to the given network   
   
Function takes a pointers to the network to mutate and the network parameters   
   
Function returns a pointer to the mutated network   
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/   
   
static NETWORK * mutate(NETWORK * network, NETWORK_PARAM * params)   
{                                                 
	NETWORK * temp=NULL;   
   
/* remember this network */   
temp=network;   
	   
/* check if addel mutation is to be applied to the network */   
if(get_rand_num(100*(1/params->addel_mutation))==1)   
	{   
	/* mutate the network */   
	temp=adddel_mutation(network,params);  
	}   
   
/* check if link mutation is to be applied to the network */   
if(get_rand_num(100*(1/params->link_mutation))==1)   
	{   
	/* mutate the network */   
	temp=link_mutation(network,params);   
	}   
   
return(temp);   
}   
   
/* Function adddel_mutation   
   
Function performs an addition / deletion mutation on the network   
   
Function takes a pointer to the network to mutate and the network parameters   
   
Function returns a pointer to the mutated network   
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/   
   
static NETWORK * adddel_mutation(NETWORK * network, NETWORK_PARAM * params)   
{                                                 
	LINK * temp=NULL;   
	LINK * link1=NULL;   
   
/* decide wether its and addition or deletion  */   
if(get_rand_num(100)>75)   
	{       
	   
	/* perform an addition to the network */   
	/* obtain a random allowed link */   
	link1=get_rand_link(params);	   
	       
    /* prepare this link for addition to the network */   
    link1->next=NULL;   
    link1->prev=NULL;   
       
    /* add this link to the network */   
    network->links=add_link(network->links,link1);   
         
    }   
else   
	{   
	/* else peform a deletion */       
    /* sellect the link to delete */  
  	link1=select_rand_link(network->links, get_rand_num(network->no_links));   
  	       
    /* check selected a link */   
    if(link1)   
    	{   
    	if(link1==network->links)   
    		{   
    		/* remember the new head */   
    		network->links=link1->prev;   
    		}   
    	   
    	/* unstitch this link */   
    	if(link1->prev)   
    		{   
    		(link1->prev)->next=link1->next;   
    		}   
    	   
    	if(link1->next)   
    		{   
    		(link1->next)->prev=link1->prev;   
    		}   
    	   
       	/* link unstitched 	*/   
    	distroy_link(link1);   
    	}                                   
     }   
    	   
/* return a pointer to the network */   
return(network);	           
           
}   
   
/* Function link_mutation   
   
Function performs a link mutation on the network   
   
Function takes a pointer to the network to mutate and the network parameters   
   
Function returns a pointer to the mutated network   
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/   
   
static NETWORK * link_mutation(NETWORK * network, NETWORK_PARAM * params)   
{                                                 
	LINK * temp=NULL;                  
	LINK * link1=NULL;   
	   
/* obtain a random allowed link */   
temp=get_rand_link(params);   
if(!temp)  
  {  
    printf("Selected a NUll allowed link for the link mutation");  
    exit(0);  
  }  
  
   
/* select a link in the current network */   
link1=select_rand_link(network->links, get_rand_num(network->no_links));   
   
/* check selected a link */   
if(link1)   
  {   
    /* favour the addition of lower cost links */
    if(get_rand_num(100)<75)
      {
	if(link1->cost>temp->cost)
	  {
	    /*copy the information into the selected link from the random allowed link */   
	    link1->node1=temp->node1;   
	    link1->node2=temp->node2;   
	    link1->speed=temp->speed;   
	    link1->cost=temp->cost;	   
	  }
      }
    else
      {
      /*copy the information into the selected link from the random allowed link */   
	link1->node1=temp->node1;   
	link1->node2=temp->node2;   
	link1->speed=temp->speed;   
	link1->cost=temp->cost;
      }
  }                         
       
/* distroy the tempory link */   
distroy_link(temp);       
       
/* return a pointer to the network */   
return(network);	           
           
}   
   
/* Function dup_network   
   
Function copys a network into a another network structure and sorts the links according to the nodes   
they connect   
   
Function takes a pointer to the network to copy and the network parameters   
   
Function returns a pointer to a copy of the network if network is null   
returns NULL   
   
Function uses nothing   
   
Function calls   
   
Function called by   
   
Modifications   
   
*/   
   
static NETWORK * dup_network(NETWORK * network, NETWORK_PARAM * params)   
{   
	NETWORK * temp=NULL;                      
	LINK * this_link=NULL;   
	LINK * poss_link=NULL;   
	NODE * this_node=NULL;  
	NODE * temp_node=NULL;  
   
/* check if the network is NULL */   
if(network)   
	{   
	  /* reset the state of all the links */  
	  reset_links(network->links);  
  
	/* create storage space for network copy */   
	if(temp=create_network())   
		{   
		   
		/* copy the factors */   
		temp->delay=network->delay;   
		temp->connectivity=network->connectivity;   
		temp->duplication=network->duplication;   
		temp->cost=network->cost;          
	   
		/* copy the monetory cost of this network */   
		temp->real_cost=network->real_cost;   
		   
		/* copy the fitness value for this network */   
		temp->fitness=network->fitness;   
		   
		/* copy the number of links in this network */   
		temp->no_links=network->no_links;   
		   
		/* start from the first node */   
		this_node=params->node_list;   
		while(this_node)   
			{	                                                                
			/* copy  and sort the links that make the network */   
			poss_link=network->links;   
		   
			/* copy the links contents of network to the new storage */   
			while(poss_link)   
				{   
				/* check if this link is connected to the node and has not already been copied */   
				if((poss_link->node1==this_node||poss_link->node2==this_node)&&poss_link->state==FALSE)   
					{   
					/* copy this link */   
					if(!(this_link=copy_link(poss_link)))   
						{   
						/* could not copy the link */   
						/*distroy the partial copy of the network */    
						distroy_network(temp);   
						temp=NULL;   
						break ;   
						}   
					/* set the linked list pointers to null	*/   
					this_link->prev=NULL;   
					this_link->next=NULL;   
					  
					/* check which way round this link goes */  
					if(this_link->node2==this_node)  
					  {  
					    /* swap round the nodes links */  
					    temp_node=this_link->node1;  
					    this_link->node1=this_link->node2;
					    this_link->node2=temp_node;
					  } 
					  
					/* add this copy of the link into the network */  
 					temp->links=add_link(temp->links,this_link);  
  
			    	/* mark this link as copied */   
			    	poss_link->state=TRUE;        
			    	}   
			        
				/* move on to the next link */   
				poss_link=poss_link->prev;   
				}   
			/* move on to the next node */   
			this_node=this_node->prev;   
			}   
		}   
	else   
		{   
		logger("Out of memory copying network");   
		printf("\nOut of memory copying network");   
		}	   
	}   
                              
/* return a pointer to the copy of the network */   
return(temp);   
   
}   
   
/* Function find_link_from   
   
Function finds the precedding link in the list of links that is originating from a particular node   
   
Function takes a pointer to the list of links to search and a pointer to the node that the link must come from   
   
Function returns a pointer to the matching link   
   
Function uses nothing   
   
Function calls    
   
Function called by    
   
Modifications   
   
*/   
   
static LINK * find_link_from(LINK * temp, NODE * temp_node)   
{   
	LINK * poss_link=NULL;   
   
/* start from the first link */   
poss_link=temp;   
   
while(poss_link)   
	{                           
	   
	/* check if this link originates from this node */   
	if(poss_link->node1==temp_node)   
		{   
		/* get out of the loop */   
		break;   
		}   
		   
	/* move on to the next link */   
	poss_link=poss_link->prev;   
	}                     
  
/* check that a link was found */	   
if(poss_link)   
	poss_link=poss_link->next;	   
   
return(poss_link);   
} 
