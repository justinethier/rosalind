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
        ps = argv[1];
        pt = argv[2];
    }

    char *pos, *tmp = ps;
    while(pos = strstr(tmp, pt)){
        printf("%d ", pos - ps + 1);
        tmp = pos + 1;
    }
    printf("\n");

    return 0;
}

