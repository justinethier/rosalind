// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem #1 - Counting Nucleotides
// http://rosalind.info/problems/dna/
//
#include <stdio.h>
#include <string.h>

// Neucleotide counts
struct ntc {
    int a;
    int c;
    int g;
    int t;
};

// Count individual nt's in the given data
struct ntc count_nt(char *data, int len){
    int i = 0;
    struct ntc result;
    memset(&result, 0, sizeof(result));

    for (i = 0; i < len; i++){
        switch(data[i]){
            case 'A': result.a++; break;
            case 'C': result.c++; break;
            case 'G': result.g++; break;
            case 'T': result.t++; break;
        }
    }

    return result;
}

int main(int argc, char **argv){
    char sample[] = "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC";
    char *data = sample;

    if (argc > 1) data = argv[1];
    struct ntc result = count_nt(data, strlen(data));
    printf("%d %d %d %d\n", result.a, result.c, result.g, result.t);

    return 0;
}
