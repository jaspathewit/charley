/* File contains structures and typedefs for the population structure   
  
(c) Mr J Hewitt 21-DEC-1994 */  
  
/* standard included files */  
  
/* project included files */  
  
/* define a structure that holds a population */  
typedef struct population_struct  
	{   
	char struct_id[20]; 
	struct network_struct ** networks;  
	double total_fitness;  
	double mean_fitness;  
	float best_fitness;  
	float worst_fitness;       
	}POPULATION; 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
