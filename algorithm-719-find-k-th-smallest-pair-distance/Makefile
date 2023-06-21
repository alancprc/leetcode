all: test run

.PHONY : run

test : test.cpp solution.h print-time.cpp
	g++ -std=c++11 -O2 -fsanitize=address test.cpp -lgmock_main -lgmock -lgtest -lpthread -o $@

run : test
	perl -e  'system("./test") for 1..1;'
