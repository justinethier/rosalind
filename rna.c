
#include <stdio.h>
#include <string.h>

/**
 * Convert the given DNA string to an RNA string, by
 * replacing occurrences of T with U
 *
 * This function modifies the given string.
 */
void transcribe(char *DNA, int len){
    int i;
    for (i = 0; i < len; i++){
        if (DNA[i] == 'T') 
            DNA[i] = 'U';
    }
}

int main(int argc, char **argv){
    char sample[] = "GATGGAACTTGACTACGTAAATT";
    char *data = sample;

    if (argc > 1) data = argv[1];
    transcribe(data, strlen(data));
    printf("%s\n", data);

    return 0;
}
