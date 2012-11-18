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
#include "prot_lib.h"


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

