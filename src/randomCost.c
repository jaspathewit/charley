/* File contains get_rand_cost  
  
(c) Mr J Hewitt 6-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
money get_rand_cost(unsigned);  
  
/* imported functions */  
extern unsigned get_rand_num(unsigned);  
  
/* local functions */                         
  
/* Function get_rand_cost  
  
Function produces a random cost   
  
Function takes the maximum cost allowed  
  
Function returns the random cost  
  
Function uses nothing  
  
Function calls   
  
Function called by  
  
Modifications  
  
*/  
  
money get_rand_cost(unsigned max_cost)  
{  
	money temp=0;  
	                   
/* get the random speed */  
temp=get_rand_num(max_cost);  
  
return(temp);  
  
} 
