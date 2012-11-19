all: util_lib dna_lib rna_lib prot_lib dna rna revc gc hamm perm prot subs prob orf

util_lib: util_lib.c util_lib.h
	gcc -c util_lib.c -o util_lib.o
dna_lib: dna_lib.c dna_lib.h util_lib
	gcc -c dna_lib.c -o dna_lib.o
rna_lib: rna_lib.c rna_lib.h
	gcc -c rna_lib.c -o rna_lib.o
prot_lib: prot_lib.c prot_lib.h
	gcc -c prot_lib.c -o prot_lib.o

dna: dna.c
	gcc dna.c -o dna
rna: rna.c rna_lib.c rna_lib.h
	gcc rna.c rna_lib.c -o rna
revc: revc.c dna_lib util_lib
	gcc -c revc.c -o revc.o
	gcc revc.o dna_lib.o util_lib.o -o revc
gc: gc.c
	gcc gc.c -o gc -g
hamm: hamm.c
	gcc hamm.c -o hamm 
perm: perm.c
	gcc perm.c -o perm 
prot: prot.c prot_lib
	gcc -c prot.c -o prot.o
	gcc prot.o prot_lib.o -o prot 
subs: subs.c
	gcc subs.c -o subs 
prob: prob.c
	gcc prob.c -o prob 
orf: orf.c dna_lib rna_lib prot_lib util_lib
	gcc -c orf.c -o orf.o
	gcc orf.o dna_lib.o rna_lib.o prot_lib.o util_lib.o -o orf 

clean:
	rm -f *.o a.out dna rna revc gc hamm perm prot subs prob orf
