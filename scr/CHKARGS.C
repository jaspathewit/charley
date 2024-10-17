/* File contains check_args */  
/* (C) J Hewitt 19-DEC-1994 */  
  
/* included files */     
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>    
#include "network.h"  
  
/* exported functions */  
int check_args(int, char * []);  
	  
/* local functions */  
static void print_help(void);    
  
/* imported functions */  
extern int is_path(char *);  
  
/* global varible to hold a pointert to the log file name */  
  
/* function check_args  
  
Function checks the command line arguments  
  
Function takes the number of arguments and a pointer to an array  
of arguments passed to the program   
  
Function returns True if there are two arguments and both are valid valid file names */  
  
int check_args(int no_args, char *args[])  
{  
	int success=TRUE;          
	int count=0;  
	  
/* check correct number of args */  
if((no_args!=3)&&(no_args!=2))  
	{  
	/* record failure */  
	success=FALSE;  
	  
	/* print out the help message */  
	print_help();  
	}  
else  
	{  
	/* loop through all the arguments */  
	for(count=1;count<no_args;count++)  
		{  
	  
		/* check argument is valid file name */  
		if(!is_path(args[count]))  
			{  
			/* record failure */  
			success=FALSE;  
	  
			/* print out the help message */  
			print_help();  
		  
			/* get out of the loop */  
			break;  
			}                   
		}  
	}		  
		  
return(success);  
}  
  
/* Function print_help  
  
Function prints out the help message about using xlate program  
  
Function takes nothing  
  
Function returns nothing  
  
Function may need modifying for future use */  
  
static void print_help()  
{  
  
printf("\nIf you don't know how to use this program please reffer to the documentation");
printf("\nincluded in the report CHARLEY a Genetic Algorithm for the Design of Mesh");
printf("\nNetworks (c) Mr J Hewitt. May 1995");  
  
return;  
} 
