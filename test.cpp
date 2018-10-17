

#include "TransactionChain.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main() {
	Transaction_Chain* t = new Transaction_Chain();
	printf("pass0\n");
	t->Add(10, "tom", "jerry");
	printf("pass1\n");
	t->Add(20, "lcy", "lyr");
	printf("pass2\n");
	t->Add(200, "aaa", "bbb");
	printf("pass3\n");
	t->printChain();

	delete t;
	return 0;
}