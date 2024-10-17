/* (c) Mr J Hewitt 28 July 1994 */  
  
/* included files */  
#include <stdio.h>  
#include <stdlib.h>
#include <malloc.h>    
#include <string.h>    
#include "network.h"  
  
/* exported function declarations */  
char * inc_buffer(char *);  
  
/* imported function declarations */  
extern void logger(char *,...);  
  
/* Function increases the size of memory allocated to the buffer */  
/* Function takes a pointer to the currently allocated block */  
/* function returns a pointer to the extended block or NULL if the */  
/* block could not be extended. Function uses non-portable _msize */  
/* to obtain the current size of memory allocated */  
char * inc_buffer(char * buffer)  
{  
	char * temp=NULL;  
	unsigned block_size=0;  
  
if(buffer==NULL)  
	{  
	block_size=0;  
    }  
else  
	{  
	printf("\nAttempted to inc size of buffer\nNot valid in UNIX"); 
        exit(0); 
	/*block_size=_msize(buffer);*/ 
	}  
  
/* extend the buffer */	             
temp=(char *)realloc(buffer,block_size+BUFFER_INC);  
/*logger("Realloc %p",temp);*/  
   
/* check if there is enough memory for "reallocation" */  
if(!temp)  
	{      
	/* print out of memory */   
	logger("Out of memory trying to increases the buffer size");  
	printf("\nOut of memory");  
	  
	/* remove the current contents of the buffer */  
	free(buffer);  
	/*logger("Free %p",buffer);*/  
	}  
  
return(temp);	  
} 
