//main.cpp

#include "TransactionChain.h"
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

void Add_chain(Transaction_Chain& chain);
void Find_chain(Transaction_Chain& chain);


int main(){
	int i = 0;
	char end;
	Transaction_Chain linked;
	Transaction_Chain &Link = linked;
	bool done = false;
	cout << "Welcome to the transaction-chain application:\n"
	<< "1. Add a transaction to the chain.\n"
	<< "2. Find a transaction with name of sender.\n"
	<< "3. Verify and print the chain.\n";
	while (done == false){
		cout << "Which operation do you want to make? (1, 2, 3):\n";
		cin >> i;
		switch (i){
			case 1:{
				Add_chain(Link);
				break;
			}
			case 2:{
				Find_chain(Link);
				break;
			}
			case 3:{
				linked.Verify();
				break;
			}
			default :{
				cout << "Wrong operation!\n";
				break;
			}
		}
		cout << "Do you want to end the opeartion? (y,n):\n";
		cin >> end;
		switch (end){
			case 'y':{
				done = true;
				break;
			}
			case 'n':{
				done = false;
				break;
			}
		        default:{
			        cout << "Wrong operation!\n";
				break;
		        }
		}
			
	}
	cout << "Thanks for using!\n";
	return 0; 
	
}

void Add_chain(Transaction_Chain& chain){
	string amount;
	int amountNum;
	string sender;
	string receiver;
	bool isint = true;
	do{
		cout << "Pleace enter the amount:\n";
		isint = true;
		cin >> amount;
		for (int i=0; i < amount.length(); i++){
			if (!isdigit(amount[i])){
				isint = false;
			}
		}
	}
	while (isint == false);
	amountNum = stoi(amount);
	cout << "Please enter sender's name:\n";
	cin >> sender;
	cout << "Please enter receiver's name:\n";
	cin >> receiver;
	chain.Add(amountNum, sender, receiver);
	cout <<"added\n";
	chain.Verify();
}

void Find_chain(Transaction_Chain& chain){
	string sender;
	cout << "Please enter sender's name:\n";
	cin >> sender;
	chain.Find(sender);
}
