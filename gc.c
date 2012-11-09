// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem #4 - Identifying Genomes Quickly
// http://rosalind.info/problems/gc/
//
#include <stdio.h>
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

    if (argc > 1) data = argv[1];

    // TODO: open "data" file
    // read info line '>', parse out the number
    // read line(s) containing DNA strand
    // upon next '>' or EOF, compute gc and maintain max
    //   may make sense to keep track of current count/total as we go
    //   that way we can use stack memory instead of worrying about
    //   heap allocation for the whole string (or can just say screw it
    //   since site limits strings to 1000 chars)

    return 0;
}
