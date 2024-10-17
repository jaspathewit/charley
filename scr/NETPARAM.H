/* File contains structures network param structure   
  
(c) Mr J Hewitt 19-DEC-1994 */  
  
/* standard included files */  
  
/* project included files */  
  
/* define a structure that holds a network parameter */  
typedef struct network_param_struct  
	{  
	char struct_id[20]; 
	 
	/* set run time parameters */  
	unsigned population_size;  
	unsigned no_generations;  
	  
	/* the required connectivity */  
	unsigned connectivity_req;       
	  
	/* the acceptable delay */  
	float acceptable_delay;     
	  
	/* the transloaction mutataion rate */  
	float addel_mutation;  
	  
	/* the link mutation rate */  
	float link_mutation;  
	  
	/* setup penalties */                              
	unsigned connectivity_penalty;  
	unsigned satlink_penalty;  
	unsigned no_route_penalty;  
	  
	/* the number of nodes in the network */  
	unsigned no_nodes;  
		                       
	/* a pointer to the nodes in the network */  
	struct node_struct *node_list;  
	  
	}NETWORK_PARAM; 
