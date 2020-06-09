all: 1115 run

1115 : ./thread-1115-print-foo-bar-alternately.h ./thread-1115-print-foo-bar-alternately-test.cpp
	g++ -std=c++11 ./thread-1115-print-foo-bar-alternately-test.cpp -lgtest_main -lgtest -lpthread -o $@

run : 1115
	perl -e  'system("./1115") for 1..100;'
