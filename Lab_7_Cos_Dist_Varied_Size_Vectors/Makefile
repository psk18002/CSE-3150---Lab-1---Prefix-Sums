CC = c++
CFLAGS= -g -I. -std=c++14
LFLAGS= -g
OFILES= Lab_7_main.o Lab_7.o
TEST_OFILES= Lab_7_test.o Lab_7.o

all: Lab_7 TEST

Lab_7: $(OFILES)
		$(CC) $(CFLAGS) $(OFILES) -o Lab_7_main

TEST: $(TEST_OFILES)
		$(CC) $(CFLAGS) $(TEST_OFILES) -o Lab_7_test

Lab_7_test.o : Lab_7_test.cpp Lab_7.h
		$(CC) -c $(CFLAGS) $<

Lab_7.o: Lab_7.cpp Lab_7.h
		$(CC) -c $(CFLAGS) $<

Lab_7_main.o : Lab_7_main.cpp
		$(CC) -c $(CFLAGS) $<

main: Lab_7
		./Lab_7_main

test: TEST
		./Lab_7_test

clean:
		rm -rf *.o *~