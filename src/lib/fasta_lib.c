// Justin Ethier - Rosalind
// 2012
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fasta_lib.h"
#include "../../../linked-list/linked-list.h"

/**
 * Dynamic strcat
 * Utility function from
 * http://stackoverflow.com/questions/419604/using-strcat-in-c
 */
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

/**
 * Remove trailing whitespace from a string
 */
char *trim_trail(char *buffer)
{
    if (!buffer) return buffer;
    
    int len = strlen(buffer);
    while(len > 0 && isspace(buffer[len - 1])){
        buffer[len - 1] = '\0';
        len++;
    }

    return buffer;
}

// // Trim whitespace from a string
// // Based on squeeze function from:
// // http://stackoverflow.com/questions/1458131/remove-extra-white-space-from-inside-a-c-string
// char *squeeze(char *str)
// {
//   int r; /* next character to be read */
//   int w; /* next character to be written */
// 
//   r=w=0;
//   while (str[r])
//   {
//     if (isspace(str[r]) || iscntrl(str[r]))
//     {
//       if (w > 0 && !isspace(str[w-1]))
//         str[w++] = ' ';
//     }
//     else
//       str[w++] = str[r];
//     r++;
//   }
//   str[w] = 0;
//   return str;
// }

void fasta_print(void *node){
    struct fasta *data = (struct fasta *)node;
    if (data){
        printf(">%s\n%s\n", data->label, data->seq);
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
 * A generic way to read FASTA data
 */
struct node *fasta_read_data(char *filename){
    struct node *result = list();
    struct fasta *data = NULL;
    char *line = NULL, *buffer = NULL, *linep;
    FILE *fp;
    size_t len;
    ssize_t read;

    fp = fopen(filename, "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '>'){
            // Not first record, add prev to list
            if (data){ 
                data->seq = buffer;
                
                list_add(result, data);
                buffer = NULL;
                data = NULL;
            }

            // Create a new record
            data = (struct fasta *)malloc(sizeof(struct fasta));
            linep = line + 1; // Skip '>'
            linep = trim_trail(linep); // Skip trailing whitespace
            data->label = strdup(linep);
//            printf("%s", data->label);
        } else {
            buffer = trim_trail(dstrcat(buffer, line));
        }
    }

    // Add the last record to the list
    if (data){ 
        data->seq = buffer;
        list_add(result, data);
    }
//    printf("list len = %d\n", list_length(result));
//    list_print(result, fasta_print);

    fclose(fp);
    free(line);
    return result;
}

