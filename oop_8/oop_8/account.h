//대입연산자 깊은 복사
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
	virtual void showMyAccountInfo() const;
	int getAccNum() const;
	int getBalance()const;
	int withdraw(int m);
	virtual void deposit(int m);
	Account& operator=(const Account&);
	virtual ~Account();

};
#endif