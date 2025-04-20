CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

MAIN_TARGET = Main
MAIN_OBJS = main.o SquareMat.o

TEST_TARGET = Test
TEST_OBJS = test.o SquareMat.o

all: main

main: $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) -o $(MAIN_TARGET) $(MAIN_OBJS)

test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

main.o: main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test.o: test.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp

clean:
	rm -f *.o $(MAIN_TARGET) $(TEST_TARGET)

run: Main
	./Main

run_tests: Test
	./Test

valgrind_main: Main
	valgrind --leak-check=full ./Main

valgrind_test: Test
	valgrind --leak-check=full ./Test
