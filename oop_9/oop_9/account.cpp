/*
const ¸â¹öÇÔ¼ö
*/
#include "iostream"
#include "account.h"
#include "cstring"
#include "String.h"
using namespace std;
Account::Account(int accNum, String name, int balance)
{
	this->accNum = accNum;
	this->balance = balance;
	this->name = name;
}

void Account::showMyAccountInfo() const{
	cout << "========================" << endl;
	cout << "°èÁÂID: " << this->accNum << endl;
	cout << "ÀÌ¸§: " << this->name << endl;
	cout << "ÀÜ¾×: " << this->balance << endl;
}
int Account::getAccNum() const{
	return this->accNum;
}
int Account::getBalance() const{
	return this->balance;
}
int Account::withdraw(int m) {
	if (getBalance() < m)return 0;
	this->balance -= m;
	return 1;
}
void Account::deposit(int m) {
	this->balance += m;
}