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

int o3_cmp(char *a, char *b)
{
    int blen = strlen(b);
    return a[0] == b[blen - 3] &&
           a[1] == b[blen - 2] &&
           a[2] == b[blen - 1];
}

int main(int argc, char **argv)
{
    char sample[] = "data/grph.fas", *file = sample;
    if (argc > 1) 
        file = argv[1];
    struct node *fdata = fasta_read_data(file);
    struct node *m, *n;

    m = fdata;
    while (m){
        struct fasta *mf = list_value(m);
        n = fdata;
        do {
            struct fasta *nf = list_value(n);
            if (mf && nf && 
                o3_cmp(mf->seq, nf->seq) &&
                strcmp(mf->label, nf->label) != 0){
                printf("%s %s\n", nf->label, mf->label);
            }
            n = list_rest(n);
        } while (n);
        m = list_rest(m);
    }

    // Clean up
    list_destroy(fdata, fasta_dealloc);
    return 0;
}

