#include <iostream>
#include "account.h"
#include "accountHandler.h"
using namespace std;
 AccountHandler::AccountHandler() :index(-1) {}
 AccountHandler::~AccountHandler() {
	 for (int i = 0; i < index; i++)
		 delete acs[i];
 }
void AccountHandler::showMenu() {
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::createAccount(int accNum, char *name, int balance) {
	index++;
	acs[index] = new Account(accNum, name, balance);
}

void AccountHandler::deposit(int accNum, int money) {
	int idx = getIdxFindAccount(accNum);
	acs[idx]->deposit(money);
	cout << "입금완료" << endl;
}

int AccountHandler::getIdxFindAccount(int accNum) {
	int idx = -1;
	for (int i = 0; i <= index; i++) {
		if (acs[i]->getAccNum() == accNum) {
			idx = i;
			break;
		}
	}
	return idx;
}

void AccountHandler::withdraw(int accNum, int money) {
	int idx = getIdxFindAccount(accNum);
	if (acs[idx]->withdraw(money) == 0) {
		cout << "잔액이 부족합니다." << endl;
	}
	else {
		cout << "출금완료" << endl;
	}
}

void AccountHandler::showAllAccount() {
	for (int i = 0; i <= index; i++)
		acs[i]->showMyAccountInfo();
}