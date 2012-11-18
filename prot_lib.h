#ifndef __prot_lib__
#define __prot_lib__
/**
 * Encode the given codon (a nucleobase string of 3 chars) into an amino acid
 */
char encode_codon(char *codon);

/**
 * Parse the given RNA string and encode it to a protein string.
 * This function allocates and returns a new string.
 */
char *parse_codons(char *s);

#endif
