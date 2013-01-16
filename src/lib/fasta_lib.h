// Justin Ethier - Rosalind
// 2012
//

#ifndef __FASTA_LIB__
#define __FASTA_LIB__

/**
 * Dynamic strcat
 * Utility function from
 * http://stackoverflow.com/questions/419604/using-strcat-in-c
 */
char *dstrcat(char *buffer, char *addition);

/**
 * Remove trailing whitespace from a string
 */
char *trim_trail(char *buffer);

/**
 * A single element of fasta data
 */
struct fasta {
    char *label;
    char *seq;
};

/**
 * Print a fasta list to console
 */
void fasta_print(void *node);

/**
 * Free memory used by a fasta node (element)
 */
void fasta_dealloc(void *node);

/**
 * A generic way to read FASTA data
 */
struct node *fasta_read_data(char *filename);

#endif
