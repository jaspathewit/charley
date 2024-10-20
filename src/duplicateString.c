/* File contains dupstr */

/* (c) Mr J Hewitt 13-12-94 */

/* standard included files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/* global varibles */

/* static varibles */

/* exported functions */
char *dupstr(char *);

/* imported functions */
extern void logger(char *, ...);

/* local functions */

/* Function strdup

Function duplicates the contentce of a string into memory allocated with malloc

Function takes a pointer to the string to duplicate

Function returns a pointer to the duplicated string. NULL indicates out of memory.

Function uses nothing

Function calls

Function called by

Modifications

*/
char *dupstr(char *string) {
	char *temp = NULL;
	// unsigned length = 0;

	/* get some memory for the duplicated string */
	temp = (char *) calloc(strlen(string) + 1, sizeof(char));

	/* check allocated ok */
	if (temp != NULL) {
#ifdef DEBUG_MEM
		/*logger("Alloc %p",temp);*/
#endif

		/* copy the string into this memory */
		strcpy(temp, string);
	} else {
		/* out of memory */
		printf("\nOut of memory");
	}

	return (temp);
}
