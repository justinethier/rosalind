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
#include "../../linked-list/linked-list.h"

// Dynamic strcat
// Utility function from
// http://stackoverflow.com/questions/419604/using-strcat-in-c
char *dstrcat(char *buffer, char *addition)
{
    int len = 0;
    if (buffer) len = strlen(buffer);

    buffer = realloc(buffer, len + strlen(addition) + sizeof(char));
    if (!buffer)
      return NULL;
    strcat(buffer, addition);
    return buffer;
}

struct fasta {
    char *label;
    char *seq;
};

void fasta_print(void *node){
    struct fasta *data = (struct fasta *)node;
    if (data){
        printf(">%s%s", data->label, data->seq);
    }
}
void fasta_dealloc(void *node){
    struct fasta *data = (struct fasta *)node;
    if (data){
        if (data->label) free(data->label);
        if (data->seq) free(data->seq);
        free(data);
    }
}

/**
 * TODO: develop a generic way to read FASTA data,
 and move to util lib
 */
struct node *read_data(char *filename){
    struct node *result = list();
    struct fasta *data = NULL;
    char *line = NULL, *buffer = NULL, *linep;
    FILE *fp;
    size_t len;
    ssize_t read;

    fp = fopen(filename, "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '>'){

            if (data){ // Not first record, add prev to list
                data->seq = buffer;
                
                list_add(result, data);
                buffer = NULL;
                data = NULL;
            }

            data = (struct fasta *)malloc(sizeof(struct fasta));
            linep = line + 1; // Skip '>'
            data->label = strdup(linep);
//            printf("%s", data->label);
        } else {
            buffer = dstrcat(buffer, line);

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
    }

    if (data){ // Add the last record to the list
        data->seq = buffer;
        list_add(result, data);
    }
//    printf("list len = %d\n", list_length(result));
    list_print(result, fasta_print);

    fclose(fp);
    free(line);
    return result;
}

int main(int argc, char **argv){
    char sample[] = "data/grph.fas", *data = sample;
    if (argc > 1) 
        data = argv[1];
    read_data(data);

    return 0;
}

