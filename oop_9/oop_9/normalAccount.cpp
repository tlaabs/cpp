#include "iostream"
#include "normalAccount.h"
using namespace std;
#include "String.h"
NormalAccount::NormalAccount(int accNum, String name, int balance, int rate):Account(accNum,name,balance) {
	this->rate = rate;
}

void NormalAccount::showMyAccountInfo() const {
	Account::showMyAccountInfo();
	cout << "ÀÌÀÚÀ²: " << rate << endl;
	cout << "========================" << endl;
}
void NormalAccount::deposit(int m) {
	int total = m + (m * (rate / 100.0));
	Account::deposit(total);
}