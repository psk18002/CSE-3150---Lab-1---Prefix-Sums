CC = c++
CFLAGS= -g -I. -std=c++14
LFLAGS= -g
OFILES= Lab_8_main.o Lab_8.o
TEST_OFILES= Lab_8_test.o Lab_8.o

all: Lab_8 TEST

Lab_8: $(OFILES)
		$(CC) $(CFLAGS) $(OFILES) -o Lab_8_main

TEST: $(TEST_OFILES)
		$(CC) $(CFLAGS) $(TEST_OFILES) -o Lab_8_test

Lab_8_test.o : Lab_8_test.cpp Lab_8.h
		$(CC) -c $(CFLAGS) $<

Lab_8.o: Lab_8.cpp Lab_8.h
		$(CC) -c $(CFLAGS) $<

Lab_8_main.o : Lab_8_main.cpp
		$(CC) -c $(CFLAGS) $<

main: Lab_8
		./Lab_8_main

test: TEST
		./Lab_8_test

clean:
		rm -rf *.o *~