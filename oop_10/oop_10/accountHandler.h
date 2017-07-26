#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#include "account.h"
#include "normalAccount.h"
#include "highCreditAccount.h"
#include "BoundCheckArray.h"
enum {NORMAL =1, CREDIT};
class AccountHandler {
private:
	BoundCheckArray<Account*> acs;
	int index;
public:
	AccountHandler();
	~AccountHandler();
	void showMenu();
	void createAccount();
	void deposit(int accNum, int money);
	void withdraw(int accNum, int money);
	void showAllAccount();
	int getIdxFindAccount(int accNum);
};

#endif