all: count_nt rna

count_nt: count_nt.c
	gcc count_nt.c -o count_nt
rna: rna.c
	gcc rna.c -o rna
clean:
	rm -f *.o a.out count_nt rna
