/* File contains structures and typedefs for the route link structure   
  
(c) Mr J Hewitt 22-NOV-1994 */  
  
/* standard included files */  
  
/* project included files */  
  
/* define a structure that holds a link */  
typedef struct route_link_struct  
	{                                               
	char struct_id[20]; 
	 
	/* pointer to the actual link */  
	struct link_struct * link;  
	                
	/* pointer to the next and previous links in the network */  
	struct route_link_struct * prev;  
	struct route_link_struct * next;  
	}ROUTE_LINK; 
