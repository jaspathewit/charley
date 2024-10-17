/* file contains function to detect if a file exists */  
  
/* (c) Mr J Hewitt 11 Oct 1994 */  
  
/* included files */  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <dos.h>  
  
  
/*#include "xlate.h"*/  
  
/* defined constants */  
#define TRUE 1  
#define FALSE 0  
  
/* exported functions */  
int fexist(char *);    
  
/* local functions */       
  
/* imported functions */  
  
/* imported globals */  
  
/* Function fexist  
  
Function test if a file exists  
  
Function takes the name of the file to test for  
  
Function returns TRUE if the file exist FALSE if not*/  
int fexist(char * filename)  
{  
	struct find_t file_info;  
	int success=FALSE;      
	int temp=0;  
  
/* try to find the file */  
temp=_dos_findfirst(filename,_A_NORMAL,&file_info);  
  
  
if(temp==0)  
  
	{  
	/* we found one */  
	success=TRUE;  
	}  
  
return(success);  
}