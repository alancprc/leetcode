all: test 1114 run

1114 : thread-1114-test.cpp thread-1114.h
	g++ -std=c++11 -pthread thread-1114-test.cpp -lgtest_main -lgtest -lpthread -o $@

test : thread-test.cpp
	g++ -std=c++11 -pthread thread-test.cpp -lgtest_main -lgtest -lpthread -o $@

run : test 1114
	./test
	./1114
