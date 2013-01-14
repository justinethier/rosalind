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

int dna2idx(char dna){
    if (dna == 'A') return 0;
    if (dna == 'C') return 1;
    if (dna == 'G') return 2;
    return 3;
}
char idx2dna(int idx){
    char map[4] = {'A', 'C', 'G', 'T'};
    return map[idx];
}

char *createConsensus(int **pProfile, int len){
    char *pCons = (char *) malloc(sizeof(char) * (len + 1));
    int l, n, maxIdx, maxVal;

    for (l = 0; l < len; l++){
        maxIdx = 0;
        maxVal = -1;
        for (n = 0; n < 4; n++){
            if (pProfile[n][l] > maxVal){
                maxIdx = n;
                maxVal = pProfile[n][l];
            }
        }

        pCons[l] = idx2dna(maxIdx);
    }

    return pCons;
}

int main(int argc, char **argv){
    char **pData;
    int *pProfile[4];
    int num, len, n, l;

    if (argc > 1) {
        num = argc - 1;         // Number of DNA strings
        len = strlen(argv[2]);  // Length of each DNA string

        // Allocate and set memory
        pData = (char **) malloc(sizeof(char *) * num);
        for (n = 0; n < 4; n++){
            pProfile[n] = (int *) malloc(sizeof(int) * (len + 1));
            memset(pProfile[n], 0, sizeof(int) * (len + 1));
        }
        for (n = 0; n < num; n++){
            pData[n] = argv[n + 1];
        }

        // Process the data
        for (l = 0; l < len; l++){
            for (n = 0; n < num; n++){
                int idx = dna2idx(pData[n][l]);
                pProfile[idx][l]++;
            }
        }

        // Clean up and report
        char *pCons = createConsensus(pProfile, len);
        printf("%s\n", pCons);
        free(pCons);
        free(pData);
        for (n = 0; n < 4; n++){
            for (l = 0; l < len; l++){
                printf("%d", pProfile[n][l]);
            }
            printf("\n");

            free(pProfile[n]);
        }
    }

    return 0;
}

