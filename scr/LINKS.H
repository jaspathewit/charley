/* File contains structures and typedefs for the link structure   
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
  
/* project included files */  
  
/* define a structure that holds a link */  
typedef struct link_struct  
	{  
	char struct_id[20]; 
	/* which nodes the link connects */  
	struct node_struct * node1;  
	struct node_struct * node2;  
  
	/* the speed of this link */  
	unsigned long speed;  
	  
	/* the mean number of messages/s over this link */  
	float no_messages;  
	  
	/* the mean message length over this link */  
	float message_len;  
	  
	/* the link delay on this link */  
	float delay;  
	                
	/* the current state of this link */  
	unsigned state;	  
	  
	/* the cost of the link */  
	unsigned long cost;  
	  
	/* pointer to the next and previous links in the network */  
	struct link_struct * prev;  
	struct link_struct * next;  
	}LINK; 
