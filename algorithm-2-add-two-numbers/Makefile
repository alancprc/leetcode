all: test run

.PHONY : run

test : test.cpp solution.h
	g++ -std=c++11 test.cpp -lgmock_main -lgmock -lgtest -lpthread -o $@

run : test
	perl -e  'system("./test") for 1..1;'
