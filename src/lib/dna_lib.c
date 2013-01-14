#include <string.h>
#include <stdlib.h>
#include "dna_lib.h"
#include "util_lib.h"

/**
 * Compute the complement of a single
 * component of a DNA string.
 */
char dna_complement(char dna)
{
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
char *dna_reverse_complement(char *dna)
{
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

/**
 * Check if a reverse-complement portion of a DNA string
 * is equal to the same part of the DNA string.
 */
int dna_is_reverse_palindrome(char *dna, int pos, int len)
{
    int i, ii;
//    printf("checking rev pal for %d %d\n", pos + 1, len);
    for (i = pos, ii = pos + len - 1; i < ii; i++, ii--){
//        printf("i = %d [%c], e = %d [%c]\n", i, dna[i], ii, dna[ii]);
        if (dna[i] != dna_complement(dna[ii]))
            return 0;
    }

    return 1;
}
