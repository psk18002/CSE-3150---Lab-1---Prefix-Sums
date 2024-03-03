CC = g++
CFLAGS = -g -I. -std=c++14
LFLAGS = -g
OFILES = adjMat.o expensiveDEP.o main_graph.o
TEST_OFILES = adjMat.o expensiveDEP.o test_graph.o

all: MAIN TEST

MAIN: $(OFILES)
		$(CC) $(CFLAGS) $(OFILES) -o main_graph

TEST: $(TEST_OFILES)
		$(CC) $(CFLAGS) $(TEST_OFILES) -o test_graph

adjMat.o: adjMat.cpp adjMat.h
		$(CC) -c $(CFLAGS) $<

expensiveDEP.o: expensiveDEP.cpp expensiveDEP.h
		$(CC) -c $(CFLAGS) $<

main_graph.o: main_graph.cpp
		$(CC) -c $(CFLAGS) $<

test_graph.o: test_graph.cpp
		$(CC) -c $(CFLAGS) $<

main: MAIN
		./main_graph

test: TEST
		./test_graph

clean:
		rm -rf *.o *~