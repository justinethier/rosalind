// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem
// http://rosalind.info/problems/grph/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/util_lib.h"
#include "lib/fasta_lib.h"
#include "../../linked-list/linked-list.h"

int main(int argc, char **argv){
    char sample[] = "data/grph.fas", *file = sample;
    if (argc > 1) 
        file = argv[1];
    struct node *data = fasta_read_data(file);

    // TODO: process file data

    // Clean up
    list_destroy(data, fasta_dealloc);
    return 0;
}

