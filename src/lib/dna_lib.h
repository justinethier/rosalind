
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

#endif
