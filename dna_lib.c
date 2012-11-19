#include <string.h>
#include <stdlib.h>
#include "dna_lib.h"
#include "util_lib.h"

/**
 * Compute the complement of a single
 * component of a DNA string.
 */
char dna_complement(char dna){
    if (dna == 'A') dna = 'T';
    else if (dna == 'T') dna = 'A';
    else if (dna == 'C') dna = 'G';
    else if (dna == 'G') dna = 'C';

    return dna;
}

/**
 * Allocate a new dna string that is the
 * reverse complement of the given DNA string
 */
char *dna_reverse_complement(char *dna){
    int i = 0, len = strlen(dna);
    char *result = (char *)malloc((len+1)*sizeof(char));

    strncpy(result, dna, len); 
    reverse(result);
    while (result[i]){
        result[i] = dna_complement(result[i]);
        i++;
    }

    return result;
}
