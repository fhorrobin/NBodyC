# Makefile for NBdodyC Project

CC = gcc
CFLAGS = -lm -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wcast-qual -Wswitch-default -Wswitch-enum  -Wconversion -Wunreachable-code -std=c11

ifndef PROGRAM
	PROGRAM = build/main.x
endif

ODIR = build/obj
SDIR = source
IDIR = includes

SOURCES = $(notdir $(wildcard $(SDIR)/*.c))

DEPS = $(wildcard $(IDIR)/*.h)

_OBJ = $(SOURCES:c=o)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
OBJ += $(patsubst %,$(ODIR)/%,main.o)

defualt: $(PROGRAM)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: main.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROGRAM): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ $(SDIR)/*~  $(IDIR)/*~ $(PROGRAM) *.x *.txt build/*.x

.PHONY: all
all: clean $(PROGRAM)
