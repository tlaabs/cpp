#include <iostream>
#include "account.h"
#include "accountHandler.h"
using namespace std;
 AccountHandler::AccountHandler() :index(-1),acs(100) {}
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

void AccountHandler::createAccount() {
	int accNum;
	char name[20];
	int balance;

	int type, rate, grade;
	Account* ptr;
	
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> type;
	cout << "계좌ID: ";
	cin >> accNum;
	cout << "이름: ";
	cin >> name;
	cout << "잔액: ";
	cin >> balance;
	cout << "이자율: ";
	cin >> rate;
	switch (type) {
	case NORMAL:
		ptr = new NormalAccount(accNum, name, balance, rate);
		break;
	case CREDIT:
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> grade;
		ptr = new HighCreditAccount(accNum, name, balance, rate, grade);
		break;
	}

	index++;
	acs[index] = ptr;
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