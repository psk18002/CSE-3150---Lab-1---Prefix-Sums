#COMPILER
CC = g++

#SOURCE FILES
SRC = Lab\ 1Main.cpp
FUNC_SRC = Lab\ 1.cpp
HEADER = Lab\ 1.h

TEST_SRC = Lab\ 1\ Test.cpp
TEST_HEADER = doctest.h

#EXECUTABLE NAMES
EXEC = Lab_1_Main
TEST_EXEC = Lab_1_Test

#MAIN EXECUTABLE BUILD
$(EXEC): $(SRC) $(FUNC_SRC) $(HEADER)
	$(CC) $(SRC) $(FUNC_SRC) -o $(EXEC)

#TEST EXECUTABLE BUILD
$(TEST_EXEC): $(TEST_SRC) $(FUNC_SRC) $(HEADER) $(TEST_HEADER)
	$(CC) $(TEST_SRC) $(FUNC_SRC) -o $(TEST_EXEC)

# Run tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Clean up generated files
clean:
	rm -f $(EXEC) $(TEST_EXEC)