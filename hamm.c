// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem #5 - Evolution as a Sequence of Mistakes
// http://rosalind.info/problems/hamm/
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Compute the hamming distance between two strings of equal length
 */
int hamm_dist(char *a, char *b){
    int dist = 0, i = 0;

    assert(strlen(a) == strlen(b));

    while(a[i]){
        if (a[i] != b[i])
            dist++;
        i++;
    }

    return dist;
}

int main(int argc, char **argv){
    char sample1[] = "GAGCCTACTAACGGGAT", sample2[] = "CATCGTAATGACGGCCT";
    char *data1 = sample1, *data2 = sample2;
    int dist;

    if (argc > 2){ 
        data1 = argv[1];
        data2 = argv[2];
    }

    dist = hamm_dist(data1, data2);
    printf("%d\n", dist);

    return 0;
}

