
#ifndef __DNA_LIB__
#define __DNA_LIB__

/**
 * Compute the complement of a single
 * component of a DNA string.
 */
char dna_complement(char dna);

/**
 * Allocate a new dna string that is the
 * reverse complement of the given DNA string
 */
char *dna_reverse_complement(char *dna);

/**
 * Check if a reverse-complement portion of a DNA string
 * is equal to the same part of the DNA string.
 */
int dna_is_reverse_palindrome(char *dna, int pos, int len);
#endif
