all:main

main: main.o TransactionChain.o
	g++ main.o TransactionChain.o -o main

main.o: main.cpp
	g++ -g -c main.cpp

TransactionChain.o: TransactionChain.cpp
	g++ -g -c TransactionChain.cpp

clean:
	rm -rf *o main