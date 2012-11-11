// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem #4 - Identifying Genomes Quickly
// http://rosalind.info/problems/gc/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Calculage the GC-content of a DNA strand
 */
double gc_content(char *data){
    int i, total = 0, gc = 0;

    while(data[i]){
        total++;

        if (data[i] == 'G' || 
            data[i] == 'C'){
            gc++;
        }
    }

    return gc / ((double) total);
}

int main(int argc, char **argv){
    char sample[] = "gc.fas", *data = sample, *line = NULL, id[80], max_id[80];
    int total = 0, gc = 0, i;
    double max_gc = 0.0;
    FILE *fp;
    size_t len;
    ssize_t read;

    max_id[0] = '\0';
    if (argc > 1) data = argv[1];

    fp = fopen(data, "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '>'){
            if (!max_id[0]){
                // First one, initialize to first id
                strncpy(max_id, line + 1, 80);
            } else {
                // Prev record finished, see if it is new max
                if (max_gc < (100 * gc / ((double) total))) {
                    max_gc = (100 * gc / ((double) total));
                    strncpy(max_id, id, 80);
                }
            }

            // Initialize data
            strncpy(id, line + 1, 80);
            total = gc = 0;
        } else {
            i = 0;
            while (line[i] && i < read){
                if (line[i] != ' ' &&
                    line[i] != '\n' &&
                    line[i] != '\r'){
                    total++;
                    if (line[i] == 'G' || line[i] == 'C') gc++;
                }

                i++;
            }
        }
    }

    if (max_gc < (100 * gc / ((double) total))) {
        max_gc = (100 * gc / ((double) total));
        strncpy(max_id, id, 80);
    }

    fclose(fp);
    free(line);

    printf("%s", max_id);
    printf("%f\n", max_gc);

    return 0;
}
