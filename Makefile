# 
# Justin Ethier
#
# Makefile for my solutions to the Rosalind project:
# http://rosalind.info
#
# Copyright 2012
#
CC=gcc
CFLAGS=-g
ODIR=build
SRC=src
LIBSRC=src/lib

_OBJ = util_lib.o fasta_lib.o dna_lib.o rna_lib.o prot_lib.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_EXE = dna rna revc gc hamm perm prot subs prob orf revp cons grph
EXE = $(patsubst %,$(ODIR)/%,$(_EXE))

$(ODIR)/%.o: $(LIBSRC)/%.c
	mkdir -p $(ODIR)
	$(CC) -c $< -o $@ $(CFLAGS)

all: $(OBJ) $(EXE)

# TODO: trying to make below less complex
#$(EXE): $(SRC)/%.c $(OBJ)
#	$(CC) $< -o $@

$(ODIR)/dna: $(SRC)/dna.c
	mkdir -p $(ODIR)
	$(CC) src/dna.c -o $(ODIR)/dna $(CFLAGS)
$(ODIR)/rna: $(SRC)/rna.c $(OBJ)
	$(CC) src/rna.c $(ODIR)/rna_lib.o -o $(ODIR)/rna $(CFLAGS)
$(ODIR)/revc: $(SRC)/revc.c $(OBJ)
	$(CC) -c $(SRC)/revc.c -o $(ODIR)/revc.o $(CFLAGS)
	$(CC) $(ODIR)/revc.o $(ODIR)/dna_lib.o $(ODIR)/util_lib.o -o $(ODIR)/revc $(CFLAGS)
$(ODIR)/gc: $(SRC)/gc.c
	$(CC) $(SRC)/gc.c -o $(ODIR)/gc  $(CFLAGS)
$(ODIR)/hamm: $(SRC)/hamm.c
	$(CC) $(SRC)/hamm.c -o $(ODIR)/hamm  $(CFLAGS)
$(ODIR)/perm: $(SRC)/perm.c
	$(CC) $(SRC)/perm.c -o $(ODIR)/perm  $(CFLAGS)
$(ODIR)/prot: $(SRC)/prot.c $(OBJ)
	$(CC) -c $(SRC)/prot.c -o $(ODIR)/prot.o $(CFLAGS)
	$(CC) $(ODIR)/prot.o $(ODIR)/prot_lib.o -o $(ODIR)/prot  $(CFLAGS)
$(ODIR)/subs: $(SRC)/subs.c
	$(CC) $(SRC)/subs.c -o $(ODIR)/subs  $(CFLAGS)
$(ODIR)/prob: $(SRC)/prob.c
	$(CC) $(SRC)/prob.c -o $(ODIR)/prob  $(CFLAGS)
$(ODIR)/orf: $(SRC)/orf.c $(OBJ)
	$(CC) -c $(SRC)/orf.c -o $(ODIR)/orf.o $(CFLAGS)
	$(CC) $(ODIR)/orf.o $(ODIR)/dna_lib.o $(ODIR)/rna_lib.o $(ODIR)/prot_lib.o $(ODIR)/util_lib.o -o $(ODIR)/orf  $(CFLAGS)
$(ODIR)/revp: $(SRC)/revp.c $(OBJ)
	$(CC) -c $(SRC)/revp.c -o $(ODIR)/revp.o $(CFLAGS)
	$(CC) $(ODIR)/revp.o $(ODIR)/util_lib.o $(ODIR)/dna_lib.o -o $(ODIR)/revp  $(CFLAGS)
$(ODIR)/cons: $(SRC)/cons.c $(OBJ)
	$(CC) -c $(SRC)/cons.c -o $(ODIR)/cons.o  $(CFLAGS)
	$(CC) $(ODIR)/cons.o $(ODIR)/util_lib.o $(ODIR)/dna_lib.o -o $(ODIR)/cons  $(CFLAGS)
$(ODIR)/grph: $(SRC)/grph.c $(OBJ)
	$(CC) -c $(SRC)/grph.c -o $(ODIR)/grph.o  $(CFLAGS)
	$(CC) ../linked-list/build/linked-list.o $(ODIR)/fasta_lib.o $(ODIR)/grph.o $(ODIR)/util_lib.o -o $(ODIR)/grph  $(CFLAGS)

# Specifically test the cons program
tcons: $(ODIR)/cons
	$(ODIR)/cons ATCCAGCT GGGCAACT ATGGATCT AAGCAACC TTGGAACT ATGCCATT ATGGCACT

# Unit test suite (still TBD)
test: $(OBJ) $(EXE) $(SRC)/tests/test_lib.c
	$(CC) -c $(SRC)/tests/test_lib.c -o $(ODIR)/test_lib.o  $(CFLAGS)
	$(CC) ../linked-list/build/linked-list.o $(ODIR)/fasta_lib.o $(ODIR)/util_lib.o $(ODIR)/test_lib.o -o $(ODIR)/test_lib  $(CFLAGS)
	$(ODIR)/test_lib

.PHONY: clean

clean:
	rm -rf $(ODIR)
