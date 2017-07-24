#include "iostream"
#include "highCreditAccount.h"
using namespace std;
HighCreditAccount::HighCreditAccount(int accNum, char* name, int balance, int rate,int grade):Account(accNum, name, balance) {
	this->rate = rate;
	this->grade = grade;
}

void HighCreditAccount::showMyAccountInfo() const {
	Account::showMyAccountInfo();
	cout << "������: " << rate << endl;
	switch (grade) {
	case A:
		cout << "�ſ���: A" << endl;
		break;
	case B:
		cout << "�ſ���: B" << endl;
		break;
	case C:
		cout << "�ſ���: C" << endl;
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