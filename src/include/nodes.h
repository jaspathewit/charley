/* File contains structures and typedefs for the node structure   
  
(c) Mr J Hewitt 20-NOV-1994 */  
  
/* standard included files */  
  
/* project included files */  
  
/* define a structure that holds a route */  
typedef struct node_struct  
	{   
	char struct_id[20]; 
	char * node_name;  
	unsigned state;
	unsigned hops;       
	unsigned no_links;  
	struct link_struct * allowed_links;  
	struct traffic_struct * traffic;  
	struct node_struct * prev;  
	struct node_struct * next;  
	}NODE; 
