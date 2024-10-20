/* File contains structures and typedefs for the traffic structure   
  
(c) Mr J Hewitt 6-DEC-1994 */  
  
/* standard included files */  
  
/* project included files */  
  
/* define a structure that holds a traffic record */  
typedef struct traffic_struct  
	{   
	char struct_id[20]; 
	 
	/* which nodes the traffic flows between */  
	struct node_struct * node1;  
	struct node_struct * node2;  
  
	/* the mean number of messages/s */  
	float no_messages;  
	                           
	/* the mean message length */  
	float message_len;  
	  
	/* pointer to the next and previous traffic records */  
	struct traffic_struct * prev;  
	struct traffic_struct * next;  
	}TRAFFIC; 
