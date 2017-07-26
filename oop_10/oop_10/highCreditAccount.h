#ifndef __NORAML_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "account.h"
#include "String.h"
enum Grade {A=1,B,C};
class HighCreditAccount : public Account {
private:
	int rate;
	int grade;
public:
	HighCreditAccount(int accNum, String name, int balance, int rate,int grade);
	virtual void showMyAccountInfo() const;
	virtual void deposit(int m);
};
#endif