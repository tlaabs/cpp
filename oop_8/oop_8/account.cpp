/*
const ¸â¹öÇÔ¼ö
*/
#include "iostream"
#include "account.h"
#include "cstring"
using namespace std;
Account::Account(int accNum, char* name, int balance)
{
	this->accNum = accNum;
	this->balance = balance;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Account::Account(const Account& copy):accNum(copy.accNum), balance(copy.balance) {
	this->name = new char[strlen(copy.name) + 1];
	strcpy(this->name, copy.name);
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
Account& Account::operator=(const Account& ref) {
	delete name;
	this->accNum = ref.accNum;
	this->balance = ref.balance;
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
	return *this;
}
Account::~Account() {
	delete[]name;
}