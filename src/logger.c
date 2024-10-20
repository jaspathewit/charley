/* file contains functions to log messages to a log file */

/* (c) Mr J Hewitt 11 Oct 1994 */

/* included files */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

/* defined constants */
#define LINE_LEN 200
#define LOGSIZE 30000
#define TRUE 1
#define FALSE 0

/* exported functions */
void logger(const char *, ...);

/* local functions */
static FILE *open_log(char *);

static void update_log(char *, FILE *);

static char *make_log_line(char *);

static int write_log_line(char *, unsigned long, FILE *);

static void update_current_line(unsigned long, FILE *);

static unsigned long read_current_line(FILE *);

/* imported functions */
extern int fexist(char *);

/* imported globals */
extern char *log_file_name;

/* Function log

Function logs the text string to the log file

Function takes the text format string and a varible number of arguments. The format
string is identicle to that of printf


Function returns nothing */
void logger(const char *format, ...) {
	FILE *log_file = NULL;
	char buffer[LINE_LEN];
	va_list ptr;

	/* check if a logfile has been requested */
	if (log_file_name) {
		/* get pointer to start of the variables */
		va_start(ptr, format);

		/* make the string to log */
		vsprintf(buffer, format, ptr);

		/* open the log file */
		log_file = open_log(log_file_name);

		/* check if log file has been open ok*/
		if (log_file) {
			/* update the log file */
			update_log(buffer, log_file);

			/* close the log file */
			fclose(log_file);
		} else {
			/* cannot log error messages */
			printf("\nLog file not opened. Cannot log %s", buffer);
		}

		/* clear the argument pointer */
		va_end(ptr);
	}
}

/* Function update_log

Function writes the string into the correct possition in the file and updates the
possition

Function takes a pointer to the string to write

Function returns nothing*/
static void update_log(char *string, FILE *log_file) {
	unsigned long current_line = 0;
	char *log_line = NULL;

	/* obtain the current line from the file */
	current_line = read_current_line(log_file);

	/* create the line to write out */
	log_line = make_log_line(string);

	/* move to write this line to the file */
	if (write_log_line(log_line, current_line, log_file)) {
		/* recourd the next current line */
		update_current_line(current_line, log_file);
	}

	free(log_line);

	return;
}

/* Function read_current_line

Function reads the number in the first line of the file which gives the number of the current line

Function takes a pointer to the file

Function returns the number of the current line*/
static unsigned long read_current_line(FILE *log_file) {
	unsigned long temp = 0;

	/* move to the begining of the file */
	fseek(log_file, 0l,SEEK_SET);

	/* read the number */
	fscanf(log_file, "%ld", &temp);

	return (temp);
}


/* Function make log line

Function makes the log line that is to be placed in the log file

Function takes the string to place in the file

Function returns a pointer to the created string

Function uses the non-standard functions strdate and str time */
static char *make_log_line(char *string) {
	// char date[9];
	// char time[9];

	/* allocate some memory for this line */
	char *temp = (char *) malloc(LINE_LEN + 20);

	/* check memory was allocated */
	if (temp != NULL) {
		/*make the string*/
		snprintf(temp, LINE_LEN, "\n%s", string);

		if (strlen(temp) > LINE_LEN) {
			printf("\nlog Line too great");

			exit(0);
		}
	} else {
		printf("\nCannot log message %s. Out of memory", string);
	}

	return (temp);
}

/* Function write_log_line

Function writes the log line into the correct possition in the log file

Function takes the string to write and the possition to write it to and a pointer to the log file

Function returns TRUE if the line was written successfully FALSE if not */
static int write_log_line(char *log_line, unsigned long poss, FILE *log_file) {
	int success = FALSE;
	int count = 0;

	/* padd the log line to the correct number of places*/
	for (count = strlen(log_line) + 1; count < LINE_LEN; count++)
		*(log_line + count) = '\0';

	/* move to the approprite place in the file */
	fseek(log_file,LINE_LEN * poss,SEEK_SET);

	/* write the log_line */
	if (fwrite(log_line,LINE_LEN, 1, log_file) == 1) {
		/* record the success */
		success = TRUE;
	} else {
		printf("\nCannot log %s. Unable to write to log file", log_line);
		success = FALSE;
	}

	return (success);
}


/* function open_log

Function opens the log file it does not exist then it is created

Function takes the name of the log file to open

Function returns a pointer to the log file */
static FILE *open_log(char *filename) {
	FILE *log_file = NULL;
	static int fileExists = 0;

	/* test to see if the file exists */
	if (fileExists) {
		/* open the file */
		log_file = fopen(filename, "r+");
	} else {
		/* create the file */
		log_file = fopen(filename, "w+");

		/* place the next line number into it */
		update_current_line(0, log_file);

		/* record the file is opened */
		fileExists = TRUE;
	}
	return (log_file);
}


/* Function update_current_line

Function updates the current line in the file

Function takes the current line and a pinter to the log file to update

Function returns nothing*/
static void update_current_line(unsigned long current_line, FILE *log_file) {
	unsigned long new_line = 0;
	char *number = NULL;

	/* reserve some space for the number */
	number = (char *) malloc(LINE_LEN);

	/* space allocated */
	if (number) {
		/* calculate the new line number */
		new_line = (current_line + 1) % LOGSIZE;
		if (new_line == 0)
			new_line = 1;

		/* make the number into a string */
		sprintf(number, "%ld", new_line);

		/* write this new number into the log file */
		write_log_line(number, 0, log_file);
	} else {
		/* print out of memory */
		printf("\nCannot update log file. Out of memory");
	}

	free(number);

	return;
} 
