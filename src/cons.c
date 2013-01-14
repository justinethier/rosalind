// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem:
// http://rosalind.info/problems/cons/
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){
    char **ps, num = argc - 1;

    printf("%d\n", num);

    ps = (char **) malloc(sizeof(char *) * argc - 1);
    int i;
    for (i = 0; i < num; i++){
        ps[i] = argv[i + 1];
        printf("%s\n", ps[i]);
    }

    return 0;
}

