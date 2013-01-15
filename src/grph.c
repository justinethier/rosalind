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

struct fastaNode {
    char *label;
    char *data;
};

/**
 * TODO: develop a generic way to read FASTA data,
 and move to util lib
 */
struct fastaNodea **read_data(char *data){
    struct fastaNodea **result;
    char *line = NULL, id[80], max_id[80];
    int total = 0, gc = 0, i;
    FILE *fp;
    size_t len;
    ssize_t read;

    max_id[0] = '\0';

    fp = fopen(data, "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '>'){
            printf("%s\n", line);
        } else {
            printf("%s\n", line);
            //i = 0;
            //while (line[i] && i < read){
            //    // getline leaves whitespace, so skip it
            //    if (line[i] != ' ' &&
            //        line[i] != '\n' &&
            //        line[i] != '\r'){
            //        total++;
            //        if (line[i] == 'G' || line[i] == 'C') gc++;
            //    }

            //    i++;
            //}
        }

//        free(line);
// TODO: use strdup to copy data to a struct for storage?
    }

    fclose(fp);
    return NULL; // TODO: how to return data? 
    // maybe use the linkedlist that I put on github!
}

int main(int argc, char **argv){
    char sample[] = "data/grph.fas", *data = sample;
    if (argc > 1) 
        data = argv[1];
    read_data(data);

    return 0;
}

