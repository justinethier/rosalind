// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind - The Genetic Code
// http://rosalind.info/problems/prot/
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Encode the given codon (a nucleobase string of 3 chars) into an amino acid
 */
char encode_codon(char *codon)
{
    if (strncmp(codon, "UUU", 3) == 0) return 'F';
    if (strncmp(codon, "UUC", 3) == 0) return 'F';
    if (strncmp(codon, "UUA", 3) == 0) return 'L';
    if (strncmp(codon, "UUG", 3) == 0) return 'L';
    if (strncmp(codon, "UCU", 3) == 0) return 'S';
    if (strncmp(codon, "UCC", 3) == 0) return 'S';
    if (strncmp(codon, "UCA", 3) == 0) return 'S';
    if (strncmp(codon, "UCG", 3) == 0) return 'S';
    if (strncmp(codon, "UAU", 3) == 0) return 'Y';
    if (strncmp(codon, "UAC", 3) == 0) return 'Y';
    if (strncmp(codon, "UAA", 3) == 0) return '\0'; // Stop
    if (strncmp(codon, "UAG", 3) == 0) return '\0'; // Stop
    if (strncmp(codon, "UGU", 3) == 0) return 'C';
    if (strncmp(codon, "UGC", 3) == 0) return 'C';
    if (strncmp(codon, "UGA", 3) == 0) return '\0'; // Stop
    if (strncmp(codon, "UGG", 3) == 0) return 'W';
    if (strncmp(codon, "CUU", 3) == 0) return 'L';
    if (strncmp(codon, "CUC", 3) == 0) return 'L';
    if (strncmp(codon, "CUA", 3) == 0) return 'L';
    if (strncmp(codon, "CUG", 3) == 0) return 'L';
    if (strncmp(codon, "CCU", 3) == 0) return 'P';
    if (strncmp(codon, "CCC", 3) == 0) return 'P';
    if (strncmp(codon, "CCA", 3) == 0) return 'P';
    if (strncmp(codon, "CCG", 3) == 0) return 'P';
    if (strncmp(codon, "CAU", 3) == 0) return 'H';
    if (strncmp(codon, "CAC", 3) == 0) return 'H';
    if (strncmp(codon, "CAA", 3) == 0) return 'Q';
    if (strncmp(codon, "CAG", 3) == 0) return 'Q';
    if (strncmp(codon, "CGU", 3) == 0) return 'R';
    if (strncmp(codon, "CGC", 3) == 0) return 'R';
    if (strncmp(codon, "CGA", 3) == 0) return 'R';
    if (strncmp(codon, "CGG", 3) == 0) return 'R';
    if (strncmp(codon, "AUU", 3) == 0) return 'I';
    if (strncmp(codon, "AUC", 3) == 0) return 'I';
    if (strncmp(codon, "AUA", 3) == 0) return 'I';
    if (strncmp(codon, "AUG", 3) == 0) return 'M';
    if (strncmp(codon, "ACU", 3) == 0) return 'T';
    if (strncmp(codon, "ACC", 3) == 0) return 'T';
    if (strncmp(codon, "ACA", 3) == 0) return 'T';
    if (strncmp(codon, "ACG", 3) == 0) return 'T';
    if (strncmp(codon, "AAU", 3) == 0) return 'N';
    if (strncmp(codon, "AAC", 3) == 0) return 'N';
    if (strncmp(codon, "AAA", 3) == 0) return 'K';
    if (strncmp(codon, "AAG", 3) == 0) return 'K';
    if (strncmp(codon, "AGU", 3) == 0) return 'S';
    if (strncmp(codon, "AGC", 3) == 0) return 'S';
    if (strncmp(codon, "AGA", 3) == 0) return 'R';
    if (strncmp(codon, "AGG", 3) == 0) return 'R';
    if (strncmp(codon, "GUU", 3) == 0) return 'V';
    if (strncmp(codon, "GUC", 3) == 0) return 'V';
    if (strncmp(codon, "GUA", 3) == 0) return 'V';
    if (strncmp(codon, "GUG", 3) == 0) return 'V';
    if (strncmp(codon, "GCU", 3) == 0) return 'A';
    if (strncmp(codon, "GCC", 3) == 0) return 'A';
    if (strncmp(codon, "GCA", 3) == 0) return 'A';
    if (strncmp(codon, "GCG", 3) == 0) return 'A';
    if (strncmp(codon, "GAU", 3) == 0) return 'D';
    if (strncmp(codon, "GAC", 3) == 0) return 'D';
    if (strncmp(codon, "GAA", 3) == 0) return 'E';
    if (strncmp(codon, "GAG", 3) == 0) return 'E';
    if (strncmp(codon, "GGU", 3) == 0) return 'G';
    if (strncmp(codon, "GGC", 3) == 0) return 'G';
    if (strncmp(codon, "GGA", 3) == 0) return 'G';
    if (strncmp(codon, "GGG", 3) == 0) return 'G';

    printf("ERROR: Unexpected codon %c%c%c\n", codon[0], codon[1], codon[2]);
    assert(1);

    return -1;
}

/**
 * Parse the given RNA string and encode it to a protein string.
 * This function allocates and returns a new string.
 */
char *parse_codons(char *s)
{
    int j = 0, len = strlen(s);
    char *i = s, *result = (char *)malloc(sizeof(char) * len);

    assert( len % 3 == 0);

    while (i && j * 3 < len) {
        result[j] = encode_codon(i);

        // Quit if a stop char was encountered
        if (result[j] <= 0)
            break;

        i += 3;
        j++;
    }

    result[j] = '\0';

    return result;
}

int main(int argc, char **argv)
{
    char sample[] = "AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA";
    char *data = sample;

    if (argc > 1){ 
        data = argv[1];
    }

    char *enc = parse_codons(data);
    printf("%s\n", enc);
    free(enc);

    return 0;
}

