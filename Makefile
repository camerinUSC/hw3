CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

OBJS = llrec.o
TEST_OBJS = llrec-test.o $(OBJS)

llrec-test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o llrec-test $(TEST_OBJS)

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp


clean:
	rm -f *.o llrec-test *~

.PHONY: clean 