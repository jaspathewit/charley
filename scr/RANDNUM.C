/* File contains get_rand_num  
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project include files */  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
unsigned get_rand_num(unsigned);  
  
/* imported functions */  
  
/* local functions */                         
  
/* Function get_rand_num  
  
Function produces a random number between 0 and a given limit  
  
Function takes the maximum number that can be returned  
  
Function returns a random number  
  
Function uses nothing  
  
Function calls nothing  
  
Function called by make_rand_node  
  
Modifications  
  
*/  
  
unsigned get_rand_num(unsigned max_num)  
{  
	unsigned temp;  
	  
/* get the random number */  
temp=((double)rand()/(double)RAND_MAX)*max_num+1;  
  
return(temp);  
} 
