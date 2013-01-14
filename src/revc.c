// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem #3
// http://rosalind.info/problems/revc/
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dna_lib.h"
#include "util_lib.h"

int main(int argc, char **argv){
    int i = 0;
    char sample[] = "AAAACCCGGT";
    char *data = sample;

    if (argc > 1) data = argv[1];

    char *result = dna_reverse_complement(data);
    printf("%s\n", result);

    free(result);
    return 0;
}
