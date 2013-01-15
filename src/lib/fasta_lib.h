// Justin Ethier - Rosalind
// 2012
//

#ifndef __FASTA_LIB__
#define __FASTA_LIB__

// Dynamic strcat
// Utility function from
// http://stackoverflow.com/questions/419604/using-strcat-in-c
char *dstrcat(char *buffer, char *addition);

struct fasta {
    char *label;
    char *seq;
};

void fasta_print(void *node);
void fasta_dealloc(void *node);

/**
 * A generic way to read FASTA data
 */
struct node *read_data(char *filename);

#endif
