#ifndef __NORAML_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "account.h"
#include "String.h"
class NormalAccount : public Account {
private:
	int rate;
public:
	NormalAccount(int accNum, String name, int balance, int rate);
	virtual void showMyAccountInfo() const;
	virtual void deposit(int m);
};
#endif