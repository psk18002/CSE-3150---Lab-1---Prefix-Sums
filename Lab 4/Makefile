#COMPILER
CC = g++

#EXECUTABLE NAMES
EXEC = Lab_4_Main
TEST = Lab_4_Test

#SOURCE FILES
SRC = Lab\ 4\ Main.cpp
FUNC_SRC = Lab\ 4.cpp
HEADER = Lab\ 4.h

TEST_SRC = Lab\ 4\ Test.cpp
TEST_HEADER = doctest.h

#MAIN EXECUTABLE BUILD
$(EXEC): $(SRC) $(FUNC_SRC) $(HEADER)
	$(CC) $(SRC) $(FUNC_SRC) -o $(EXEC)

#TEST EXECUTABLE BUILD
$(TEST): $(TEST_SRC) $(FUNC_SRC) $(HEADER) $(TEST_HEADER)
	$(CC) $(TEST_SRC) $(FUNC_SRC) -o $(TEST)

# Run tests
test: $(TEST)
	./$(TEST)

#Run Main
main: ${EXEC}
	./${EXEC}

# Clean up generated files
clean:
	rm -f $(EXEC) $(TEST_EXEC)