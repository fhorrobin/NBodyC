# Makefile for NBdoyC Project

CC = gcc
CFLAGS = -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wcast-qual -Wswitch-default -Wswitch-enum  -Wconversion -Wunreachable-code -std=c11

ifndef PROGRAM
	PROGRAM = main.x
endif

ODIR = obj
SDIR = source
IDIR = includes

SOURCES = $(notdir $(wildcard $(SDIR)/*.c))

DEPS = $(wildcard $(IDIR)/*.h)

_OBJ = $(SOURCES:c=o)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROGRAM): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ $(SDIR)/*~  $(IDIR)/*~ $(PROGRAM) *.x *.txt

.PHONY: all
all: clean $(PROGRAM)
