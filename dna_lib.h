
#ifndef __DNA_LIB__
#define __DNA_LIB__

/**
 * Compute the complement of a single
 * component of a DNA string.
 */
char dna_complement(char dna);

/**
 * Take a given DNA string and replace
 * it with it's reverse complement.
 */
char *dna_reverse_complement(char *dna);

#endif
