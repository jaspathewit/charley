/* File contains structures and typedefs for the network structure   
  
(c) Mr J Hewitt 21-DEC-1994 */  
  
/* standard included files */  
  
/* project included files */  
  
typedef struct network_struct  
	{  
	char struct_id[20]; 
	 
	struct link_struct * links;  
	float delay;  
	float connectivity;  
	float duplication;  
	float cost;  
	float real_cost;  
	float fitness;  
	unsigned no_links;  
	}NETWORK; 
