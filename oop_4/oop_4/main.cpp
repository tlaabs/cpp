#include <iostream>
#include "account.h"
#include <cstring>
using namespace std;

void showMenu();
void createAccount(int accNum, char *name, int balance);
void deposit(int accNum, int money);
void withdraw(int accNum, int money);
void showAllAccount();

int getIdxFindAccount(int accNum);

Account* acs[100];
int index = -1;

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOWALL, EXIT };

int main() {
	int accNum;
	char name[20];
	int balance;
	int money;

	for (;;) {
		int choice;
		showMenu();
		cout << "선택: ";
		cin >> choice;

		switch (choice) {
		case CREATE:
			cout << "계좌ID: ";
			cin >> accNum;
			cout << "이름: ";
			cin >> name;
			cout << "잔액: ";
			cin >> balance;
			createAccount(accNum, name, balance);
			break;
		case DEPOSIT:
			cout << "[입 금]" << endl;
			cout << "계좌ID: ";
			cin >> accNum;
			cout << "입금액: ";
			cin >> money;
			deposit(accNum, money);
			break;
		case WITHDRAW:
			cout << "[출 금]" << endl;
			cout << "계좌ID: ";
			cin >> accNum;
			cout << "출금액: ";
			cin >> money;
			withdraw(accNum, money);
			break;
		case SHOWALL:
			showAllAccount();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}

	}
}

void showMenu() {
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void createAccount(int accNum, char *name, int balance) {
	index++;
	acs[index] = new Account(accNum, name, balance);
}

void deposit(int accNum, int money) {
	int idx = getIdxFindAccount(accNum);
	acs[idx]->deposit(money);
	cout << "입금완료" << endl;
}

int getIdxFindAccount(int accNum) {
	int idx = -1;
	for (int i = 0; i <= index; i++) {
		if (acs[i]->getAccNum() == accNum) {
			idx = i;
			break;
		}
	}
	return idx;
}

void withdraw(int accNum, int money) {
	int idx = getIdxFindAccount(accNum);
	if (acs[idx]->withdraw(money) == 0) {
		cout << "잔액이 부족합니다." << endl;
	}
	else {
		cout << "출금완료" << endl;
	}
}

void showAllAccount() {
	for (int i = 0; i <= index; i++)
		acs[i]->showMyAccountInfo();
}