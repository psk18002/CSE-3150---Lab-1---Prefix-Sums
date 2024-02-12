#Compiler
CC = g++

#SOURCE FILES
SRC = banner.cpp
FUNC_SRC = linked_list.cpp
HEADER = linked_list.h

TEST_SRC = unit_test_linked_list.cpp
TEST_HEADER = doctest.h

#EXECUTABLE NAMES
EXEC = linked_list_banner
TEST_EXEC = test_linked_list

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