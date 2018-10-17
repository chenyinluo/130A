// CS 130A HW1
// TransactionChain.cpp
#include "TransactionChain.h"

#include <string>
#include <cstdlib> //for rand()
#include <iostream> //for time()
#include "picosha2.h"
using namespace std;

Transaction_Chain::Transaction_Chain(){
	this->tail = NULL;
}

string randomNonce(){
	string x;
	srand(time(NULL));
	x = char(rand()%26+97);
	return x;
}

void Transaction_Chain::Add(int amountMoney, string senderName, string receiverName){
	Transaction *addtion = new Transaction(amountMoney, senderName, receiverName);
	Transaction *tmp = this->tail;
	string counter = to_string(amountMoney);
	counter += senderName + receiverName;
	while (addtion->nonce == ""){
		string tmpNonce = randomNonce();
		string tmpValue = counter + tmpNonce;
		string tmpHash = picosha2::hash256_hex_string(tmpValue);
		char lastHash = tmpHash[tmpHash.length()-1];
		if (lastHash=='0'||lastHash=='1'||lastHash=='2'||lastHash=='3'||lastHash=='4'){
			addtion->nonce = tmpNonce;
		}
	}
	if (this->tail == NULL){
		this->tail = addtion;
	}
	else {
		string preCounter = to_string(tail->amount);
		preCounter += this->tail->sender + this->tail->receiver + this->tail->nonce;
		addtion->hash = picosha2::hash256_hex_string(preCounter);
		addtion->next = tmp;
		this->tail = addtion;
	}
	
}

void Transaction_Chain::Find(string senderName){
	Transaction *find = tail;
	cout<<"check point for Find 1\n";
	while (find != NULL){
		if (find->sender == senderName){
			find->printout();
		}
		find = find->next;
	}
}

bool Transaction_Chain::Verify(){
	Transaction *check = tail;
	while (check->next != NULL){
		string Counter = to_string(check->next->amount);
		Counter += check->next->sender;
		Counter += check->next->receiver;
		Counter += check->next->nonce;
		string temHash = picosha2::hash256_hex_string(Counter);
		if (check->hash != temHash){
			return false;
		}
		check = check->next;
	}
	if (check->hash != ""){
		return false;
	}
	check = tail;
	cout<<"Verify check done"<<endl;
	while (check != NULL){
		check->printout();
		check = check->next;
	}
	return true;
}
