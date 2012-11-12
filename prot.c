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

/*
UUU F   
UUC F   
UUA L   
UUG L   
UCU S   
UCC S   
UCA S   
UCG S   
UAU Y   
UAC Y   
UAA Stop
UAG Stop
UGU C   
UGC C   
UGA Stop
UGG W   
UUU F   
CUC L
CUA L
CUG L
CCU P
CCC P
CCA P
CCG P
CAU H
CAC H
CAA Q
CAG Q
CGU R
CGC R
CGA R
CGG R
AUU I
AUC I
AUA I
AUG M
ACU T
ACC T
ACA T
ACG T
AAU N
AAC N
AAA K
AAG K
AGU S
AGC S
AGA R
AGG R
GUU V
GUC V
GUA V
GUG V
GCU A
GCC A
GCA A
GCG A
GAU D
GAC D
GAA E
GAG E
GGU G
GGC G
GGA G
GGG G 
*/

/**
 * Encode the given codon (a nucleobase string of 3 chars) into an amino acid
 */
char encode_codon(char *codon)
{
    if (strncmp(codon, "GGG", 3) == 0) return 'G';

    return -1;
}

char *parse_codons()
{}

int main(int argc, char **argv)
{
    char sample[] = "TODO";
    char *data = sample;

    if (argc > 1){ 
        data = argv[1];
    }

    return 0;
}

