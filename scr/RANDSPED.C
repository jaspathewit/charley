/* File contains get_rand_speed  
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
capacity get_rand_speed(unsigned);  
  
/* imported functions */  
extern unsigned get_rand_num(unsigned);  
  
/* local functions */                         
  
/* Function get_rand_speed  
  
Function produces a random speed   
  
Function takes the maximum speed allowed  
  
Function returns the random speed  
  
Function uses nothing  
  
Function calls   
  
Function called by  
  
Modifications  
  
*/  
  
capacity get_rand_speed(unsigned max_speed)  
{  
	capacity temp=0;  
	                   
/* get the random speed */  
temp=get_rand_num(max_speed);  
  
return(temp);  
  
} 
