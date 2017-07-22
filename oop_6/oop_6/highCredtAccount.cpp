#include "iostream"
#include "highCreditAccount.h"
using namespace std;
HighCreditAccount::HighCreditAccount(int accNum, char* name, int balance, int rate,int grade):Account(accNum, name, balance) {
	this->rate = rate;
	this->grade = grade;
}

void HighCreditAccount::showMyAccountInfo() const {
	Account::showMyAccountInfo();
	cout << "이자율: " << rate << endl;
	switch (grade) {
	case A:
		cout << "신용등급: A" << endl;
		break;
	case B:
		cout << "신용등급: B" << endl;
		break;
	case C:
		cout << "신용등급: C" << endl;
		break;
	}
	cout << "========================" << endl;
}
void HighCreditAccount::deposit(int m) {
	int insentive;
	switch (grade) {
	case A:
		insentive = 7;
		break;
	case B:
		insentive = 4;
		break;
	case C:
		insentive = 2;
		break;
	}
	int total = m + (m * ((rate+insentive) / 100.0));
	Account::deposit(total);
}
HighCreditAccount::~HighCreditAccount() {
}