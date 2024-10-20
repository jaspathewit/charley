/* File contains get_rand_mess_len  
  
(c) Mr J Hewitt 6-DEC-1994 */  
  
/* standard included files */  
#include <stdio.h>  
#include <stdlib.h>                                   
             
/* project in clude files */  
#include "network.h"  
  
/* global varibles */  
  
/* static varibles */  
  
/* exported functions */  
messlen get_rand_mess_len(unsigned);  
  
/* imported functions */  
extern unsigned get_rand_num(unsigned);  
  
/* local functions */                         
  
/* Function get_rand_mess_len  
  
Function produces a random mess_len   
  
Function takes the maximum mess_len allowed  
  
Function returns the random mess_len  
  
Function uses nothing  
  
Function calls   
  
Function called by  
  
Modifications  
  
*/  
  
messlen get_rand_mess_len(unsigned max_mess_len)  
{  
	messlen temp=0;  
	                   
/* get the random speed */  
temp=get_rand_num(max_mess_len);  
  
return(temp);  
  
} 
