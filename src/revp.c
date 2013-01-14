// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem:
// http://rosalind.info/problems/revp/
//
#include <stdio.h>
#include <string.h>
#include "lib/dna_lib.h"

int main(int argc, char **argv){
    char sample[] = "TCAATGCATGCGGGTCTATATGCAT";
    char *data = sample;
    int i = 0, len, end;

    if (argc > 1) data = argv[1];

    end = strlen(data);
    for (i = 0; i < end; i++){
        for (len = 4; len < 14; len += 2){
            if (i + len <= end){
                if (dna_is_reverse_palindrome(data, i, len)){
                    printf("%d %d\n", i + 1, len);
                }
            }
        }
    }

    return 0;
}
