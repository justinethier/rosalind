// Justin Ethier - Rosalind
// 2012
//
// Solution for Rosalind problem #5 - Rearrangements Power Large-Scale Genomic Changes
// http://rosalind.info/problems/perm/
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return the number of permutations of length n
 */
int num_perm(int n){
    int i, result;
    for (result = i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

/**
 * Permutation algorithm from: http://www.bearcave.com/random_hacks/permute.html
 * Print out a single permutation
 */
void print_perm(const char *v, const int size)
{
  int i = 0;
  if (v != 0) {
    for (i = 0; i < size; i++) {
      printf("%c ", v[i] );
    }
    printf("\n");
  }
}

/**
 * Permutation algorithm from: http://www.bearcave.com/random_hacks/permute.html
 * Find all permutations and print them out
 *
 * @param v - Array containing all possible items
 * @param start - Index to start at
 * @param n - Number of items to "take"
 */
void permute(char *v, const int start, const int n)
{  
  int i;

  if (start == n-1) {
    print_perm(v, n);
  }
  else {
    for (i = start; i < n; i++) {
      char tmp = v[i];
      
      v[i] = v[start];
      v[start] = tmp;
      permute(v, start+1, n);
      v[start] = v[i];
      v[i] = tmp;
    }
  }
}

int main(int argc, char **argv){
    char sample[] = "3";
    char *data = sample;
    int num;

    if (argc > 1){ 
        data = argv[1];
    }

    num = num_perm( atoi(data) );
    printf("%d\n", num);

    char v[] = {'1', '2', '3', '4', '5', '6', '7'};
    permute(v, 0, atoi(data));

    return 0;
}

