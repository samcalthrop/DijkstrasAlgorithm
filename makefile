IDIR =include
CC=g++ -std=c++20
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS=Components.h defs.h Functions.h Arc.h Vector2.h
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o Components.o Functions.o Arc.o Vector2.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

run: all
	./all
