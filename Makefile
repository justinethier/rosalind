all: dna rna revc gc hamm

dna: dna.c
	gcc dna.c -o dna
rna: rna.c
	gcc rna.c -o rna
revc: revc.c
	gcc revc.c -o revc
gc: gc.c
	gcc gc.c -o gc -g
hamm: hamm.c
	gcc hamm.c -o hamm 
clean:
	rm -f *.o a.out dna rna revc gc hamm
