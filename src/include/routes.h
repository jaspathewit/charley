/* File contains structures and typedefs for the route structure   
  
(c) Mr J Hewitt 20-NOV-1994 */  
  
/* standard included files */  
  
/* project included files */  
  
/* define a structure that holds a route */  
typedef struct route_struct  
	{ 
	char struct_id[20];  
	struct node_struct * node1;  
	struct node_struct * node2;   
	struct route_link_struct * route;  
	unsigned long cost;  
	struct route_struct * prev;  
	struct route_struct * next;  
	}ROUTE_REC; 
