/*
const ����Լ�
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
	cout << "����ID: " << this->accNum << endl;
	cout << "�̸�: " << this->name << endl;
	cout << "�ܾ�: " << this->balance << endl;
	cout << "========================" << endl;
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
Account::~Account() {
	delete[]name;
}