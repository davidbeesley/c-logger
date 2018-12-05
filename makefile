CXXFLAGS= -Wall -pedantic -g
CHEADERS = Logger.h
CXXOBJS= Logger.o

main : main.o $(CHEADERS) $(CXXOBJS)
	gcc $(CXXFLAGS) -o main main.o $(CXXOBJS)

%.o : %.c  $(CHEADERS)
	gcc $(CXXFLAGS) -c  $<


clean:
	rm -f *.o
	rm -f test main

test: test.o $(CXXOBJS) $(CHEADERS)
	gcc $(CXXFLAGS) -o test test.o $(CXXOBJS)
	./test

logger: Logger.h Logger.c
	gcc $(CXXFLAGS) -c Logger.c
