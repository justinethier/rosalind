
#include <stdio.h>
#include <string.h>
#include "rna_lib.h"

int main(int argc, char **argv){
    char sample[] = "GATGGAACTTGACTACGTAAATT";
    char *data = sample;

    if (argc > 1) data = argv[1];
    rna_transcribe(data);
    printf("%s\n", data);

    return 0;
}
