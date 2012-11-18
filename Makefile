all: dna rna revc gc hamm perm prot subs prob orf

dna: dna.c
	gcc dna.c -o dna
rna: rna.c rna_lib.c rna_lib.h
	gcc rna.c rna_lib.c -o rna
revc: revc.c
	gcc revc.c -o revc
gc: gc.c
	gcc gc.c -o gc -g
hamm: hamm.c
	gcc hamm.c -o hamm 
perm: perm.c
	gcc perm.c -o perm 
prot: prot.c prot_lib.c prot_lib.h
	gcc prot.c prot_lib.c -o prot 
subs: subs.c
	gcc subs.c -o subs 
prob: prob.c
	gcc prob.c -o prob 
orf: orf.c
	gcc orf.c rna_lib.c prot_lib.c -o orf 
clean:
	rm -f *.o a.out dna rna revc gc hamm perm prot subs prob orf
