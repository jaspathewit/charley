/* File contains structures and typedefs for the connectivity_list   
  
(c) Mr J Hewitt 7-NOV-1994 */  
  
/* standard included files */  
  
/* project included files */  
  
/* define a type that holds a connectivity structure */  
typedef struct connectivity_rec  
	{  
	char struct_id[20];             
	struct node_struct * node1;  
	struct node_struct * node2;  
	unsigned connectivity;  
	struct connectivity_rec * next;  
	struct connectivity_rec * prev;  
	}CONNECTIVITY_REC; 
