//TransactionChain.h

#ifndef TRANSACTIONCHAIN_H
#define TRANSACTIONCHAIN_H


#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Transaction_Chain {

 public:
 	Transaction_Chain();
 	void Add(int amountMoney, string senderName, string receiverName);
 	void Find(string senderName);
 	bool Verify();

 private:
 	struct Transaction{
 		Transaction *next; //points previous transaction
 		int amount; //amount of money that has been transferred
 		string sender; //sender of money
 		string receiver; //receiver of money
 		string nonce; /*random string that will be used during 
 					hashing for the next transaction*/
 		string hash; //hash of content of previous transaction
 		Transaction(int amount, string sender, string receiver)://initialize
 		next(0), amount(amount), sender(sender), receiver(receiver), nonce(""),hash("") {}
 		void printout (){
		       
 		}
 	};
 	Transaction *tail;

};



#endif
