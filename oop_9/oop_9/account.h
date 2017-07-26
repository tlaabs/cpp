//대입연산자 깊은 복사
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "String.h"
class Account {
private:
	int accNum;
	String name;
	int balance;
public:
	Account(int accNum, String name, int balance);
	virtual void showMyAccountInfo() const;
	int getAccNum() const;
	int getBalance()const;
	int withdraw(int m);
	virtual void deposit(int m);
};
#endif