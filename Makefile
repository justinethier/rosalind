# 
# Justin Ethier
#
# Makefile for my solutions to the Rosalind project:
# http://rosalind.info
#
# Copyright 2012
#
CC=gcc
ODIR=build
SRC=src
LIBSRC=src/lib

_OBJ = util_lib.o dna_lib.o rna_lib.o prot_lib.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_EXE = dna rna revc gc hamm perm prot subs prob orf revp
EXE = $(patsubst %,$(ODIR)/%,$(_EXE))

$(ODIR)/%.o: $(LIBSRC)/%.c
	mkdir -p $(ODIR)
	$(CC) -c $< -o $@

all: $(OBJ) $(EXE)

# TODO: trying to make below less complex
#$(EXE): $(SRC)/%.c $(OBJ)
#	$(CC) $< -o $@

$(ODIR)/dna: $(SRC)/dna.c
	mkdir -p $(ODIR)
	$(CC) src/dna.c -o $(ODIR)/dna
$(ODIR)/rna: $(SRC)/rna.c $(OBJ)
	$(CC) src/rna.c $(ODIR)/rna_lib.o -o $(ODIR)/rna
$(ODIR)/revc: $(SRC)/revc.c $(OBJ)
	$(CC) -c $(SRC)/revc.c -o $(ODIR)/revc.o
	$(CC) $(ODIR)/revc.o $(ODIR)/dna_lib.o $(ODIR)/util_lib.o -o $(ODIR)/revc
$(ODIR)/gc: $(SRC)/gc.c
	$(CC) $(SRC)/gc.c -o $(ODIR)/gc -g
$(ODIR)/hamm: $(SRC)/hamm.c
	$(CC) $(SRC)/hamm.c -o $(ODIR)/hamm 
$(ODIR)/perm: $(SRC)/perm.c
	$(CC) $(SRC)/perm.c -o $(ODIR)/perm 
$(ODIR)/prot: $(SRC)/prot.c $(OBJ)
	$(CC) -c $(SRC)/prot.c -o $(ODIR)/prot.o
	$(CC) $(ODIR)/prot.o $(ODIR)/prot_lib.o -o $(ODIR)/prot 
$(ODIR)/subs: $(SRC)/subs.c
	$(CC) $(SRC)/subs.c -o $(ODIR)/subs 
$(ODIR)/prob: $(SRC)/prob.c
	$(CC) $(SRC)/prob.c -o $(ODIR)/prob 
$(ODIR)/orf: $(SRC)/orf.c $(OBJ)
	$(CC) -c $(SRC)/orf.c -o $(ODIR)/orf.o
	$(CC) $(ODIR)/orf.o $(ODIR)/dna_lib.o $(ODIR)/rna_lib.o $(ODIR)/prot_lib.o $(ODIR)/util_lib.o -o $(ODIR)/orf 
$(ODIR)/revp: $(SRC)/revp.c $(OBJ)
	$(CC) -c $(SRC)/revp.c -o $(ODIR)/revp.o
	$(CC) $(ODIR)/revp.o $(ODIR)/util_lib.o $(ODIR)/dna_lib.o -o $(ODIR)/revp 

.PHONY: clean

clean:
	rm -rf $(ODIR)
