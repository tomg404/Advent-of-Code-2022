SOURCE_NAME := sol.cpp
EXEC_NAME := main.o
PARAMS := -W -Wall -Wextra -g
STANDARD := c++20

INPUT := input
TEST_INPUT := test

all: build

.PHONY : build
build: $(SOURCE_NAME)
	clang++ -std=$(STANDARD) $(SOURCE_NAME) -o $(EXEC_NAME) $(PARAMS) 

.PHONY : build run
run: $(EXEC_NAME)
	./$(EXEC_NAME) $(INPUT)

.PHONY : test
test: build $(EXEC_NAME)
	./$(EXEC_NAME) $(TEST_INPUT)

.PHONY : clean
clean:
	rm $(EXEC_NAME)

