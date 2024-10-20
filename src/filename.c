/*  
  
File contains functions for processing filenames and paths  
  
(c) Mr J Hewitt 27-07-93  
  
*****************************************************************************/
/* included files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* defined constants */
#define TRUE 1
#define FALSE 0
#define NUL '\0'

#define PERIOD_CHAR '.'
#define SLASH_CHAR '\\'
#define COLON_CHAR ':'
#define UNDER_CHAR '_'
#define STAR_CHAR '*'
#define QUERY_CHAR '?'

#define FILE_NAME 1
#define REL_DIR 2
#define SLASH 3
#define MASK_NAME 4
#define STRING_END 5
#define DRIVE 6
#define ERROR 7

/* exported functions */
int is_filename(char *);

int is_drive(char *);

int is_path(char *);

int is_mask(char *);

void get_directory(char *, char *);

/* local functions */
static int lex(char **);

static int isdrive(char **);

static int ismask_name(char **);

static int isfile_name(char **);

static int isrel_dir(char **);

static int isslash(char **);

static int isstring_end(char **);

static int iscolon(char);

static int isfile_id(char **);

static int isfile_ext(char **);

static int isperiod(char);

static int ismask_id(char **);

static int ismask_ext(char **);

static int valid_file_char(char);

static int valid_mask_char(char);

static int valid_drive_char(char);


/*
Function is_path

Function validates if a string is a valid path

Function takes a pointer to the string

Function returns 1 if the string is a valid path 0 if not

Production rules:

path => [drive] [slash] [directory_list] string_end

directory_list => dir_name [( slash dir_name )]

dir_name => file_name | rel_dir

*/
int is_path(char *string) {
    char *poss = NULL;
    int success = TRUE;
    int token = 0;

    /* start from the begining */
    poss = string;

    /* get the first token */
    token = lex(&poss);

    /* check for drive */
    if (token == DRIVE) {
        /* get the next token */
        token = lex(&poss);
    }
    /* check for slash */
    if (token == SLASH) {
        /* get the next token */
        token = lex(&poss);
    }

    while ((token == FILE_NAME || token == REL_DIR) && (token != STRING_END)) {
        /* get the next token */
        token = lex(&poss);

        /* check for slash */
        if (token == SLASH) {
            /* get the next directory */
            token = lex(&poss);

            /* check followed by a file_name of rel_dir */
            if ((token != FILE_NAME) && (token != REL_DIR)) {
                /* record failure */
                return (FALSE);
            }
        } else {
            /* not a slash end of directory list */
            break;
        }
    }

    /* check for string end */
    if (token != STRING_END) {
        /* record failure */
        success = FALSE;
    }

    return (success);
}


/* ismask

Function validates if a string is a valid file mask

Function takes a pointer to the string

Function returns 1 if the string is a valid mask 0 if not

Production rules:

mask => [drive] [slash] [directory_list] [slash] mask_name string_end

directory_list => dir_name [( slash dir_name )]

dir_name => file_name | rel_dir

*/

int is_mask(char *string) {
    char *poss;
    int success;
    int token;

    /* start from the begining */
    poss = string;

    /* get the first token */
    token = lex(&poss);

    /* check for drive */
    if (token == DRIVE) {
        /* get the next token */
        token = lex(&poss);
    }
    /* check for slash */
    if (token == SLASH) {
        /* get the next token */
        token = lex(&poss);
    }

    /* loop through the directory list */
    while (token == FILE_NAME || token == REL_DIR) {
        /* get the next token */
        token = lex(&poss);

        /* check for slash */
        if (!(token == SLASH)) {
            /* not a slash end of directory list */
            break;
        }
        /* get the next token */
        token = lex(&poss);
    }

    /* check for the mask_id */
    if (token == MASK_NAME) {
        /* get the next token */
        token = lex(&poss);


        /* check for string end */
        if (token == STRING_END) {
            /* valid mask */
            success = TRUE;
        } else {
            /* not valid mask */
            success = FALSE;
        }
    } else {
        /* no mask in the mask */
        success = FALSE;
    }

    return (success);
}


/*

Function is_drive

Function validates if a string is a valid drive

Function takes a pointer to the string

Function returns 1 if the string is a valid drive 0 if not

Production rules:

valid_drive => drive string_end

*/
int is_drive(char *string) {
    char *poss;
    int success;
    int token;


    /* start from the begining */
    poss = string;

    /* get the first token */
    token = lex(&poss);

    /* check for drive */
    if (token == DRIVE) {
        /* get the next token */
        token = lex(&poss);

        /* check for string end */
        if (token == STRING_END) {
            /* valid file_name */
            success = TRUE;
        } else {
            /* not valid */
            success = FALSE;
        }
    } else {
        /* not valid */
        success = FALSE;
    }

    return (success);
}

/*

Function is_filename

Function validates if a string is a valid filename

Function takes a pointer to the string

Function returns 1 if the string is a valid filename 0 if not

Note function uses a recursive grammer to determine if the name is valid

Production rules:

valid_filename =>  file_name string_end

*/

int is_filename(char *string) {
    char *poss;
    int success;
    int token;

    /* start from the begining */
    poss = string;

    /* get the first token */
    token = lex(&poss);

    /* check for filename */
    if (token == FILE_NAME) {
        /* get the next token */
        token = lex(&poss);

        /* check for string end */
        if (token == STRING_END) {
            /* valid file_name */
            success = TRUE;
        } else {
            /* not valid */
            success = FALSE;
        }
    } else {
        /* not valid */
        success = FALSE;
    }

    return (success);
}


/* lex

Function processes string input and returns the tokens that are in it

Function takes a pointer to a pointer to the string to process

Function returns the next token
		DRIVE alpha :
                FILE_NAME string of alphanums +_ upto 8 chars in length .
                	string of alphanums +_ upto 3 chars in length
                REL_DIR string of . upto 2 in length
                SLASH \
                MASK_NAME string of alphanums + ?* upto 8 chars in length .
                	string of alphanums + ?* upto 3 chars in length
                STRING_END '\0'
		ERROR unkown token encountered

Note

*/

static int lex(char **poss) {
    int token;

    /* is it a drive */
    if (isdrive(poss)) {
        /* token is a drive */
        token = DRIVE;
    } else {
        /* is it a mask_name */
        if (ismask_name(poss) == 1) {
            /* token is a file_name */
            token = MASK_NAME;
        } else {
            /* is token a file_name */
            if (isfile_name(poss)) {
                /* token is a file id */
                token = FILE_NAME;
            } else {
                /* is it a rel_dir */
                if (isrel_dir(poss)) {
                    /* token is a relative directory */
                    token = REL_DIR;
                } else {
                    /* is token a slash */
                    if (isslash(poss)) {
                        /* token is a slash */
                        token = SLASH;
                    } else {
                        /* is token string end */
                        if (isstring_end(poss)) {
                            /* token is string end */
                            token = STRING_END;
                        } else {
                            /* token is an error */
                            token = ERROR;
                        }
                    }
                }
            }
        }
    }
    return (token);
}

/* isdrive

Function determines if the string is a drive

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a drive

Note

Production rules

drive => valid_drive_char :

*/

static int isdrive(char **poss) {
    int success;
    char *temp_poss;

    /* start from the beginning */
    temp_poss = *poss;

    /* valid drive letter */
    success = valid_drive_char(*temp_poss);

    /* if valid drive char */
    if (success) {
        /* move on one char */
        temp_poss++;

        /* validate the colon */
        success = iscolon(*temp_poss);

        /* successful */
        if (success) {
            /* move on one char */
            temp_poss++;

            /* go to next token */
            *poss = temp_poss;
        }
    }
    return (success);
}

/* isfile_name

Function determines if the string is a file_name

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a file name

Note

Production rules

file_name => file_id [period [file_ext]]

*/

static int isfile_name(char **poss) {
    char *temp_poss;
    int success;
    int temp;

    /* start from the begining */
    temp_poss = *poss;

    /* try and find the file id */
    success = isfile_id(&temp_poss);

    /* if file_id */
    if (success) {
        /* process the period */
        temp = isperiod(*temp_poss);

        /* if there is a period */
        if (temp) {
            /* move on one char */
            temp_poss++;

            /* try to process the file extenson */
            success = isfile_ext(&temp_poss);
        }
    }

    /* if successful */
    if (success) {
        /* goto the next token */
        *poss = temp_poss;
    }

    return (success);
}

/* ismask_name

Function determines if the string is a mask_name

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a mask name

Note

Production rules

mask_name => mask_id [period [mask_ext]]

*/

static int ismask_name(char **poss) {
    char *temp_poss;
    int success;
    int temp;

    /* start from the beginning */
    temp_poss = *poss;


    /* try and find the mask id */
    success = ismask_id(&temp_poss);

    /* if mask_id */
    if (success) {
        /* process the period */
        temp = isperiod(*temp_poss);

        /* if there is a period */
        if (temp) {
            /* move on one char */
            temp_poss++;

            /* we already have a mask id so this can be */
            /* a mask_ext or file_ext */

            /* try to process the mask extension */
            success = ismask_ext(&temp_poss);

            /* if not successful */
            if (!success) {
                /* try to process the file_ext */
                success = isfile_ext(&temp_poss);
            }
        }
    } else {
        /* try to process the file_id */
        success = isfile_id(&temp_poss);

        /* if there is a file id */
        if (success) {
            /* there must be a period and a valid mask_ext */
            success = isperiod(*temp_poss);

            /* if there is a period */
            if (success) {
                /* move on one char */
                temp_poss++;

                /* must be a mask_ext */
                success = ismask_ext(&temp_poss);
            }
        }
    }

    /* if successful */
    if (success) {
        /* goto the next token */
        *poss = temp_poss;
    }

    return (success);
}

/* isfile_ext

Function determines if the string is a file extension

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a file extension

Note

*/

static int isfile_ext(char **poss) {
    char *temp_poss;
    int no_chars = 0;
    int success;

    /* start from the begining */
    temp_poss = *poss;

    /* loop through the chars */
    while (valid_file_char(*temp_poss) && no_chars <= 3) {
        /* move on one char*/
        temp_poss++;

        /* inc the no of chars */
        no_chars++;
    }

    /* check the number of chars */
    if (no_chars <= 3) {
        /* goto next token */
        *poss = temp_poss;

        /* success */
        success = TRUE;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}

/* ismask_ext

Function determines if the string is a mask extension

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a mask extension

Note

*/

static int ismask_ext(char **poss) {
    int temp;
    char *temp_poss;
    int no_chars = 0;
    int success;
    int mask_char_found = FALSE;

    /* start from the begining */
    temp_poss = *poss;

    /* loop through the chars */
    while ((temp = valid_mask_char(*temp_poss)) && no_chars <= 3) {
        /* move on one char */
        temp_poss++;

        /* check if this char is one of the special mask chars */
        if (temp == 2) {
            /* found a mask char */
            mask_char_found = TRUE;
        }

        /* inc the no of chars */
        no_chars++;
    }

    /* check the number of chars */
    if (no_chars <= 3 && mask_char_found) {
        /* move on to the next token */
        *poss = temp_poss;


        /* success */
        success = TRUE;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}

/* isfile_id

Function determines if the string is a file id

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a file id

Note

*/

static int isfile_id(char **poss) {
    char *temp_poss;
    int no_chars = 0;
    int success;

    /* start from the begining */
    temp_poss = *poss;

    /* loop through the chars */
    while (valid_file_char(*temp_poss) && no_chars <= 8) {
        /* move on one char */
        temp_poss++;

        /* inc the no of chars */
        no_chars++;
    }

    /* check the number of chars */
    if (no_chars > 0 && no_chars <= 8) {
        /* goto next token */
        *poss = temp_poss;

        /* success */
        success = TRUE;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}

/* ismask_id

Function determines if the string is a mask id

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a mask id

Note

*/

static int ismask_id(char **poss) {
    int temp;
    char *temp_poss;
    int no_chars = 0;
    int success;
    int mask_char_found = FALSE;

    /* start from the begining */
    temp_poss = *poss;

    /* loop through the chars */
    while ((temp = valid_mask_char(*temp_poss)) && no_chars <= 8) {
        /* check if this char is one of the special mask chars */
        if (temp == 2) {
            /* found a mask char */
            mask_char_found = TRUE;
        }
        /* move on one char */
        temp_poss++;


        /* inc the no of chars */
        no_chars++;
    }

    /* check the number of chars and found a mask char */
    if (no_chars > 0 && no_chars <= 8 && mask_char_found) {
        /* move on to the next token */
        *poss = temp_poss;

        /* success */
        success = TRUE;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}


/* isperiod

Function determines if the string is a period

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a period

Note

*/

static int isperiod(char letter) {
    int success;

    /* is it a period */
    if (letter == PERIOD_CHAR) {
        /* success */
        success = TRUE;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}


/* isslash

Function determines if the string is a slash

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a slash

Note

*/

static int isslash(char **poss) {
    char *temp_poss;
    int success;

    /* start from the begining */
    temp_poss = *poss;

    if (*temp_poss == SLASH_CHAR) {
        /* success */
        success = TRUE;

        /* move on one char */
        temp_poss++;

        /* goto next token */
        *poss = temp_poss;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}

/* iscolon

Function determines if the string is a colon

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a colon

Note

*/

static int iscolon(char letter) {
    int success;

    /* if it is a colon */
    if (letter == COLON_CHAR) {
        /* success */
        success = TRUE;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}

/* isstring_end

Function determines if the string is a string_end

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a string_end

Note

*/

static int isstring_end(char **poss) {
    char *temp_poss;
    int success;

    /* start from the begining */
    temp_poss = *poss;

    if (*temp_poss == NUL) {
        /* success */
        success = TRUE;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}


/* isrel_dir

Function determines if the string is a rel_dir

Function takes a pointer to a pointer to the string to process

Function returns true if the string contains a rel_dir

Note

*/

static int isrel_dir(char **poss) {
    char *temp_poss;
    int success;

    /* start from the begining */
    temp_poss = *poss;

    if (isperiod(*temp_poss)) {
        /* move on one char */
        temp_poss++;

        /* success */
        success = TRUE;

        /* process the next possible period */
        if (isperiod(*temp_poss)) {
            /* its a period move on one char */
            temp_poss++;
        }
        /* move on to the next token */
        *poss = temp_poss;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}

/* valid_file_char

Function determines if the char is a valid file char

Function takes a char

Function returns true if the char is valid

Note

*/

static int valid_file_char(char letter) {
    int success;

    if (isalnum(letter) || letter == UNDER_CHAR) {
        /* success */
        success = TRUE;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}

/* valid_drive_char

Function determines if the char is a valid drive char

Function takes a char

Function returns true if the char is valid

Note

*/

static int valid_drive_char(char letter) {
    int success;

    if (isalpha(letter)) {
        /* success */
        success = TRUE;
    } else {
        /* failure */
        success = FALSE;
    }

    return (success);
}

/* valid_mask_char

Function determines if the char is a valid mask char

Function takes a char

Function returns 1 if the char file char 2 if special mask char

Note

*/

static int valid_mask_char(char letter) {
    int success;

    if (letter == STAR_CHAR || letter == QUERY_CHAR) {
        /* success */
        success = 2;
    } else {
        /* check if char a file char */
        if (valid_file_char(letter)) {
            /* valid file char */
            success = TRUE;
        } else {
            /* failure */
            success = FALSE;
        }
    }
    return (success);
}

/*
Function get_directory

Function takes a valid path or mask and removes the filename / directory or
mask

Function takes a pointer to the string holding the "path" and a pionter to
string to hold the directory

Function returns nothing

*/

void get_directory(char *path, char *directory) {
    int poss;

    /* set the directory to nothing */
    *directory = NUL;

    /* copy path into directory */
    strcpy(directory, path);

    /* find the end of the string */
    poss = strlen(directory);

    /* loop through the string backwards*/
    while (poss) {
        /* check if the char is a \ */
        if (directory[poss] == SLASH_CHAR) {
            /* set that possition to '\0' */
            directory[poss + 1] = NUL;

            /* get out of the loop */
            break;
        } else {
            /* check for drive letter */
            if (directory[poss] == COLON_CHAR) {
                /* set the possition 1 in front to '\0' */
                directory[poss + 1] = NUL;

                /* get out of the loop */
                break;
            }
        }

        /* move back one */
        poss--;
    }

    /* check if there was not a : or \ before the start */
    if (poss == 0) {
        /* set the directory to nul */
        *directory = NUL;
    }

    return;
} 
