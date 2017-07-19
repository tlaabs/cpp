#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
class Account {
private:
	int accNum;
	char *name;
	int balance;
public:
	Account(int accNum, char* name, int balance);
	Account(const Account& copy);
	void showMyAccountInfo() const;
	int getAccNum() const;
	int getBalance()const;
	int withdraw(int m);
	void deposit(int m);
	~Account();

};
#endif