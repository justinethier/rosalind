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

int main(int argc, char **argv)
{
    char sample[] = "data/grph.fas", *file = sample;
    if (argc > 1) 
        file = argv[1];
    struct node *fdata = fasta_read_data(file);
    struct node *m, *n;

    printf("processing file data\n");
    m = fdata;
    while (m){
        struct fasta *mf = list_value(m);
        n = fdata;
        do {
            struct fasta *nf = list_value(n);
            if (mf && nf && strcmp(mf->label, nf->label) == 0){
                printf("%s", nf->label);
            }
            n = list_rest(n);
        } while (n);
        m = list_rest(m);
    }

    // Clean up
    list_destroy(fdata, fasta_dealloc);
    return 0;
}

