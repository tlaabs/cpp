#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
class Account {
private:
	int accNum;
	char *name;
	int balance;
public:
	Account(int accNum, char* name, int balance);
	void showMyAccountInfo() const;
	int getAccNum() const;
	int getBalance();
	int withdraw(int m);
	void deposit(int m);
	~Account();

};
#endif