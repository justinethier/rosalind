// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem #3
// http://rosalind.info/problems/revc/
//
#include <stdio.h>
#include <string.h>

char dna_complement(char dna){
    if (dna == 'A') dna = 'T';
    else if (dna == 'T') dna = 'A';
    else if (dna == 'C') dna = 'G';
    else if (dna == 'G') dna = 'C';

    return dna;
}

/**
 * Reverse a string, from K & R
 */   
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main(int argc, char **argv){
    int i = 0;
    char sample[] = "AAAACCCGGT";
    char *data = sample;

    if (argc > 1) data = argv[1];

    reverse(data);
    while (data[i]){
        data[i] = dna_complement(data[i]);
        i++;
    }

    printf("%s\n", data);

    return 0;
}
