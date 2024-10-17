/* file contains function for obtaining values from an initilisation file */  
/* (c) J Hewitt July 1994 */   
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>    
#include <malloc.h>  
#include "network.h"  
  
/* definitions */       
#define PERIOD '.'  
#define TAB "\t"  
#define TABC '\t'  
#define EMPTYC '\0'  
#define EQUALSC '='  
  
  
/* exported functions */  
char * ini_value(FILE *, char *);                     
  
/* function declarations for local functions */  
static char *get_header(char *);  
static int find_header(FILE *, char *);  
static char *get_value(FILE *, char *);  
static char *get_value_line(FILE *, char *);  
static char *get_sub_expression(char *, int);  
static char *find_sub_expression(FILE *,char *, int);  
static int count_tabs(char *);      
  
/* function declarations for imported functions */  
extern char *read_ln(FILE *);      
extern char * dupstr(char *);  
extern void logger(char *,...);  
  
/* Function ini_value   
                     
Function takes a pointer to the file that the value is to be found in   
a search string that indicates where in the file the information is to   
found.   
  
The search string is formated as follows  
  
Header_name.element_name(.element_name)  
  
The file is formatted as follows  
  
[Header_name]  
      element_name= value   
            element_name=value  
              
each sub layer is prefixed with a tab  
  
Function returns a string containing the value of this element  
or NULL to indicate the information could not be found in the file  
or an out of memory condition occured. */  
  
char * ini_value(FILE *file,char *search_string)  
{           
	char *value=NULL;  
	int temp=TRUE;  
		  
/* check if to search from the begining of the file */  
if(*search_string!=PERIODC)  
	{	     
	/* move to the start of the file */  
	fseek(file,0l,SEEK_SET);  
      
    /* find the header */  
    temp=find_header(file,search_string);  
    }  
      
	/* found the header */  
if(temp)  
  {   
	  
    /* get the value */  
    value=get_value(file,search_string);  
     
    /* check if the vaule returned is a null */ 
    if(value) 
      { 
 
	/* if this value is terminated by a CR remove it */  
	if(STRRET(value))  
	  RMCR(value);  
      }  
    else 
      {  
	/* print could not find the element */ 
	logger("INI Element %s not found",search_string);   
      }  
  } 
 
return(value);  
}                                                     
                                           
/* Function find_header  
                                           
Function looks through a file until a line is found that contains the header  
dicription.  
  
Function takes the file pointer of the file to search and the search string  
  
Function returns TRUE if the header is found FALSE if not */  
  
static int find_header(FILE * file, char * search_string)  
{  
  
	/* buffer to look through the file */  
	char *buffer=NULL;  
	char *header=NULL;         
	int success=FALSE;  
	  
/* get the header to look for */  
header=get_header(search_string);  
  
/* check header returned */  
if(header)  
	{  
  
	/* look through the file */		  
	buffer=read_ln(file);  
  
	while(buffer)  
		{    
		/* check if this line contains the header */ 
		if(strncmp(buffer,header,strlen(header))==0)  
			{              
			/* record success and get out of the loop */  
			success=TRUE;  
			break;  
			}  
		                     
		/* get the next line */  
		free(buffer);	       
/*		logger("Free %p",buffer);*/  
		buffer=read_ln(file);  
	  
		}  
  
	/* clear the header*/   
	free(buffer);   
/*	logger("Free %p",buffer);*/  
	  
	free(header);  
/*	logger("Free %p",header);*/  
	  
	}		    
	  
return(success);  
}		  
  
/* function get_value  
		  
Function looks through the file from the current possition till  
the correct sub element is found  
  
Function takes the file and the search_string.  
  
Function returns a pointer to the value a NULL pointer indicates the  
value could not be found*/  
  
static char *get_value(FILE * file, char * search_string)  
{                                                         
	char *value=NULL;  
	char *buffer=NULL;  
    char *poss=NULL;  
		  
/* find the line that contains the value required */   
if(buffer=get_value_line(file,search_string))  
	{  
                 
	/* get the possition of the equals */                 
	poss=strchr(buffer,EQUALSC);                                       
      
    /* allocate storage for the value len of poss*/ 
    value=calloc(strlen(poss),sizeof(char));  
/*    logger("Alloc %p",value);*/  
                                              
	/* check if allocated */  
	if(value)  
		{  
        /* get the value part of this line */  
		strcpy(value,poss+1);  
		}  
	else  
		{  
		/* report out of memory */  
		logger("Out of memory trying to make space for a ini value");  
		printf("\nOut of memory");  
		}                                    
	}  
/* clear the buffer */  
free(buffer);   
/*logger("Free %p",buffer);*/  
  
return(value);	  
}  
  
/* Function get_value_line   
  
Function looks through the file until the line containing the sub  
expresion is found   
  
Function takes the file to look through, and the search_string for  
the value line.  
  
Function returns a pointer to the value line a NULL pointer indicates  
that the value line could not be found */  
  
static char *get_value_line(FILE * file, char * expression)  
{  
	int no_tabs=1;  
	char * sub_expression=NULL;  
	char * poss=NULL;  
	char * value_line=NULL;           
	  
/* move to the first period */  
poss=strchr(expression,PERIOD);	    
  
/* loop through all the sub expressions */       
while(poss!=NULL)  
	{  
	   
	/* get the sub expression */  
	sub_expression=get_sub_expression(poss,no_tabs);   
	  
	/* find this sub expression */   
	free(value_line);  
/*	logger("Free %p",value_line);*/  
	  
	value_line=find_sub_expression(file,sub_expression,no_tabs);  
	  
	/* move on to the next sub_expression */  
	free(sub_expression);   
/*	logger("Free %p",sub_expression);*/  
	  
	poss=strchr(poss+1,PERIOD);  
	no_tabs++;  
	}  
	  
return(value_line);  
  
}		  
  
		                                                
/* Function find_sub_expression  
  
Function run through the file from the current searching for the  
sub expression  
  
Function takes a pointer to the file to search and the sub expresssion  
to search for.  
  
Function returns a pointer to the matching line if found, if not found  
returns NULL */  
  
static char * find_sub_expression(FILE * file,char *sub_expression, int no_tabs)  
{  
	char * buffer=NULL;  
	  
  
/* read the line from the file */  
buffer=read_ln(file);  
	  
while((buffer)&&count_tabs(buffer)>=no_tabs)  
	{  
		  
	/* check if this sub_expression starts this line */ 
	if(strncmp(buffer,sub_expression,strlen(sub_expression))==0)  
		{  
				  
		return(buffer);  
		}  
		  
	/* get the next line */   
	free(buffer);     
/*	logger("Free %p",buffer);*/  
	  
	buffer=read_ln(file);  
	  
	}  
	  
/* line not found */  
free(buffer);  
/*logger("Free %p",buffer);*/  
		  
return(NULL);	  
}		  
  
/* Function count_tabs  
		  
Function counts the number of tab characters at the start of a line  
  
Function takes the line to count the tabs in  
  
Function returns the number of tabs at the start of the line */  
  
static int count_tabs(char * line)  
{  
  
	char *poss;  
	int no_tabs=0;  
	  
/* start from the beginning */  
poss=line;  
  
/* move through the line counting the tabs */  
while(*poss==TABC)  
	{  
	no_tabs++;   
	        
	/* move on one char */        
	poss++;  
	}  
	  
return(no_tabs);  
  
}  
  
                                      
/* Function get_sub_expresion   
                                      
Function extracts the first expresion from the search string  
  
Function takes the search string and the number of preceeding tabs  
  
Function returns a pointer to the sub_expression  
  
Function uses the non-portable _strdup */  
  
static char * get_sub_expression(char * expression, int no_tabs)  
{     
	char * sub_expression;                   
	char * temp_expression;  
	char * poss;  
	int count;  
	  
/* make a copy of the search string */  
temp_expression=dupstr(expression+1);  
  
/*logger("Alloc %p",temp_expression);*/  
  
/* temp expression allocated */  
if(temp_expression)  
    {  
	/* make the next . the string terminator */  
	poss=strchr(temp_expression,PERIOD);	  
                                   
	/* check that this is not the last expresion */  
	if(poss!=NULL)  
		/* make the next period the end of the string */  
		*poss=EMPTYC;  
      
    /* allocate space for the sub expression len temp_expression + no_tabs + 1 */  
    sub_expression=calloc(strlen(temp_expression)+no_tabs+1,sizeof(char));  
/*    logger("Alloc %p",sub_expression);*/  
      
    /* check allocated */  
    if(sub_expression)  
        {            
		/* make the sub_expression */  
		*sub_expression=EMPTYC;  
   
		/* add in the correct number of tabs */  
		for(count=1;count<=no_tabs;count++)    
			{  
			strcat(sub_expression,TAB);             
   			}  
        strcat(sub_expression,temp_expression);  
          
        }  
    else  
    	{  
    	/* report out of memory */  
    	logger("Out of memory trying to make space for ini search expresion");  
    	printf("\nOut of memory");  
        }  
  
    /* free the temp_expression */  
    free(temp_expression);      
/*    logger("Free %p",temp_expression);*/  
        }  
else  
	{  
    /* report out of memory */  
    logger("Out of memory trying to copy current search expression");  
    printf("\nOut of memory");  
    }  
  
return(sub_expression);  
}	  
  
  
/* function get_header  
	  
Function extracts the header from the search string  
  
Function takes the search string.  
  
Function returns a pointer to the header a NULL pointer indicates  
out of memory */  
  
static char * get_header(char * search_string)  
{     
	char * temp=NULL;                   
	char * header=NULL;  
	char * poss=NULL;  
	  
/* make a copy of the search string */  
temp=dupstr(search_string);  
/*logger("Alloc %p",temp);*/  
  
/* check temp string allocated */  
if(temp)  
	{  
  
	/* make the first . the string terminator */  
	poss=strchr(temp,PERIOD);	  
  
	*poss=EMPTYC;  
                    
	/* allocate space for the header, length of temp + 3*/ 
	header=(char *)calloc(strlen(temp)+3,sizeof(char));  
/*	logger("Alloc %p",header);*/  
	  
	/* check allocated ok */  
	if(header)  
		{  
		/* make the header */                                         
		strcpy(header,"[");  
		strcat(header,temp);  
		strcat(header,"]");  
        }                              
    else  
    	{  
    	/* report out of memory */   
    	logger("Out of memory while trying to make space for header to search for");  
    	printf("\nOut of memory");  
    	}      
    /* clear the temp string */  
    free(temp);  
/*   logger("Free %p",temp);    */  
    }            
      
return(header);  
} 
