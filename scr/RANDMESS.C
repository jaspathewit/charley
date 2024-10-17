/* File contains get_rand_messages  
  
(c) Mr J Hewitt 6-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
messages get_rand_messages(unsigned);  
  
/* imported functions */  
extern unsigned get_rand_num(unsigned);  
  
/* local functions */                         
  
/* Function get_rand_messages  
  
Function produces a random messages   
  
Function takes the maximum messages allowed  
  
Function returns the random messages  
  
Function uses nothing  
  
Function calls   
  
Function called by  
  
Modifications  
  
*/  
  
messages get_rand_messages(unsigned max_messages)  
{  
	messages temp=0;  
	                   
/* get the random speed */  
temp=get_rand_num(max_messages);  
  
return(temp);  
  
} 
