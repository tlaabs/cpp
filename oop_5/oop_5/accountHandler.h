#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#include "account.h"
class AccountHandler {
private:
	Account* acs[100];
	int index;
public:
	AccountHandler();
	~AccountHandler();
	void showMenu();
	void createAccount(int accNum, char *name, int balance);
	void deposit(int accNum, int money);
	void withdraw(int accNum, int money);
	void showAllAccount();
	int getIdxFindAccount(int accNum);
};

#endif