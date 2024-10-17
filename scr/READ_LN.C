/* (c) Mr J Hewitt 28 July 1994 */  
  
/* included files */  
#include <stdio.h>  
#include <malloc.h>    
#include <string.h>    
#include "network.h"  
   
/* exported function declarations */  
char * read_ln(FILE *);               
  
/* local function declarations */  
  
/* imported functions declarations */  
extern char * inc_buffer(char *);  
  
/* Function read lines from a file and mimics the opperation of fgets. the lines */  
/* read are placed into a dynamically allocated buffer. The function returns a */  
/* pointer to this buffer if this buffer cannot be allocated then the function */  
/* returns NULL. The function takes a file pointer to the opened file */  
char * read_ln(FILE * file)  
{  
	char * buffer=NULL;                         
	char * success=NULL;  
	int read_poss=0;  
  
/* inc the buffer size */  
buffer=inc_buffer(buffer);  
  
/* while buffer increased in size */  
while(buffer)  
    {  
	/* read chars from the file into the buffer */  
	success=fgets(buffer+read_poss,BUFFER_INC,file);  
	  
	/* check if read anything from the file */  
	if(!success)  
		                                     
	    {  
		/* file error free the buffer allocated*/  
		free(buffer);  
/*		logger("Free %p",buffer);*/  
			  
		/* set buffer to null */  
		buffer=NULL;  
			  
		/* get out of the loop */  
		break;  
		}   
		  
	/* check if at the end of the line or file */  
	if(STRRET(buffer)||feof(file))  
		{  
		/* get out of the loop */  
		break;  
		}  
	  
	/* move on to the next read possition */  
	read_poss+=BUFFER_INC-1;  
	  
	/* increase the size of the buffer */  
	buffer=inc_buffer(buffer);			  
	}  
  
/* return the buffer */  
return(buffer);  
} 
