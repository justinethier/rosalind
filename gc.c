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
    char sample[] = "gc.fas";
    char *data = sample;
    char *line, id[80];
    int total = 0, gc = 0, i;
    FILE *fp;
    size_t len;
    ssize_t read;

    id[0] = '\0';
    if (argc > 1) data = argv[1];

    fp = fopen(data, "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '>'){
            /*
            if (id[0]){
                printf("%s\n", id);
                // TODO: format # of decimal places
                // TODO: need to do this after the while
                printf("%lf\n", gc / ((double) total));
            }
            */

            //strncpy(id, line + 1, 1024);
            printf("%s\n", line);
        } else {
            /*
            i = 0;
            while (line[i]){
                total++;
                if (line[i] == 'G' || line[i] == 'C') gc++;
                i++;
            }
            */
        }

    // read info line '>', parse out the number
    // read line(s) containing DNA strand
    // upon next '>' or EOF, compute gc and maintain max
    //   may make sense to keep track of current count/total as we go
    //   that way we can use stack memory instead of worrying about
    //   heap allocation for the whole string (or can just say screw it
    //   since site limits strings to 1000 chars)
    }

    fclose(fp);
    free(line);
    return 0;
}
