#include $(CUTTLEFISH_ROOT)/include/cuttlefish.mak
CC=gcc
CFLAGS=-ffast-math -mavx2 -O3 -fopenmp -ftree-vectorize -ftree-vectorizer-verbose=2  #$(CUTTLEFISH_CXXFLAGS)
LDFLAGS= #$(CUTTLEFISH_LDFLAGS) $(CUTTLEFISH_LDLIBS)

dgemm: dgemm.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o dgemm dgemm.c $(LDFLAGS)

clean:
	rm -rf dgemm *.o

