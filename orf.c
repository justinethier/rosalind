// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind - Transcription May Begin Anywhere
// http://rosalind.info/problems/orf/
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rna_lib.h"
#include "prot_lib.h"

int main(int argc, char **argv)
{
    char sample[] = "AGCCATGTAGCTAACTCAGGTTACATGGGGATGACCCCGCGACTTGGATTAGAGTCTCTTTTGGAATAAGCCTGAATGATCCGAGTAGCATCTCAG";
    char *data = sample;

    if (argc > 1){ 
        data = argv[1];
    }

    transcribe(data);

    int i = 0;
    while(data[i]){
        if (start_codon(data + i)){
            char *enc = parse_codons(data + i);
            if (enc){
                printf("%s\n", enc);
                free(enc);
            }
        }

        i += 3;
    }

    return 0;
}

