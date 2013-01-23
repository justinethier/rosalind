// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem
// http://rosalind.info/problems/lcs/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/util_lib.h"
#include "linked-list.h"

int find_substrings(char *s1, char *s2)
{
    int i, j, b = 0, tmp,
        l1 = strlen(s1), l2 = strlen(s2);
    char buffer[1024];

// TODO: trying to print all common substrings, but this
// just ends up being a mess
    for (i = 0; i < l1; i++){
        tmp = i;
        for (j = 0; j < l2; j++){
            // Special case, end of s1
            if (i == l1 && b > 0){
                buffer[b] = '\0';
                printf("[1] %s\n", buffer);
                b = 0;
                break;
            }

            if (s1[i] == s2[j]){
                buffer[b++] = s1[i++];
            } else {
                // No match, reset everything
                if (b > 0){
                    buffer[b] = '\0';
                    printf("[2] %s\n", buffer);
                    b = 0;
                }
            //    i = tmp;
            }

        }

        // TODO: attempt to handle case where last strings match (IE, "CA")
        if (b > 0){
            buffer[b] = '\0';
            printf("[3] %s\n", buffer);
            b = 0;
        }
        i = tmp;
    }

    return 0;
}

int main(int argc, char **argv)
{
    char a[] = "GATTACA", b[] = "TAGACCA";
    find_substrings(a, b);

//    char sample[] = "data/lcs.txt", *file = sample;
//    if (argc > 1) 
//        file = argv[1];
//    struct node *fdata = fasta_read_data(file);
//    struct node *m, *n;
//
//    m = fdata;
//    while (m){
//        struct fasta *mf = list_value(m);
//        n = fdata;
//        do {
//            struct fasta *nf = list_value(n);
//            if (mf && nf && 
//                o3_cmp(mf->seq, nf->seq) &&
//                strcmp(mf->label, nf->label) != 0){
//                printf("%s %s\n", nf->label, mf->label);
//            }
//            n = list_rest(n);
//        } while (n);
//        m = list_rest(m);
//    }
//
//    // Clean up
//    list_destroy(fdata, fasta_dealloc);
    return 0;
}

