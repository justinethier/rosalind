#include "rna_lib.h"

/**
 * Convert the given DNA string to an RNA string, by
 * replacing occurrences of T with U
 *
 * This function modifies the given string.
 */
void rna_transcribe(char *dna){
    int i = 0;
    while (dna[i]) {
        if (dna[i] == 'T') 
            dna[i] = 'U';
        i++;
    }
}

