all: dna rna revc

dna: dna.c
	gcc dna.c -o dna
rna: rna.c
	gcc rna.c -o rna
revc: revc.c
	gcc revc.c -o revc
clean:
	rm -f *.o a.out dna rna revc
