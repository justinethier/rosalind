// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem - The Mathematics of Chance
// http://rosalind.info/problems/prob/
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Calculate probability two randomly chosen symbols (A, T, C, G)
 * are the same.
 */
double prob(double gc)
{
    // Mult prob of symbol appearing by itself to get prob
    // of it appearing twice.
    // Mult by 2 since A/T and C/G have same prob.
    return ((gc / 2) * (gc / 2)) * 2 +
           (((1 - gc) / 2) * ((1 - gc) / 2)) * 2;
}

int main(int argc, char **argv)
{
    double data[20];
    int len = 3, i;

    data[0] = 0.23;
    data[1] = 0.31;
    data[2] = 0.75;

    if (argc > 2){ 
        len = argc - 1;
        for (i = 0; i < len; i++){
            data[i] = atof(argv[i + 1]);
        }
    }

    for (i = 0; i < len; i++){
        printf("%lf ", prob(data[i]));
    }

    return 0;
}

