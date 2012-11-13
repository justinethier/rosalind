// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem - Finding a Motif in DNA
// http://rosalind.info/problems/subs/
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){
    char s[] = "ACGTACGTACGTACGT", t[] = "GTA";
    char *ps = s, *pt = t;

    if (argc > 2){ 
        s = argv[1];
        t = argv[2];
    }

    //dist = hamm_dist(data1, data2);
    //printf("%d\n", dist);

    return 0;
}

