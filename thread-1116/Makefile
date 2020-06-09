all: 1116 run

1116 : ./print-zero-even-odd.h ./print-zero-even-odd-test.cpp
	g++ -std=c++11 ./print-zero-even-odd-test.cpp -lgtest_main -lgtest -lpthread -o $@

run : 1116
	perl -e  'system("./1116") for 1..1;'
