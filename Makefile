all: dna rna

dna: dna.c
	gcc dna.c -o dna
rna: rna.c
	gcc rna.c -o rna
clean:
	rm -f *.o a.out dna rna
