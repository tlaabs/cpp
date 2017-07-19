#include <iostream>
#include "accountHandler.h"
#include "account.h"
#include <cstring>
using namespace std;

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOWALL, EXIT };

int main() {
	AccountHandler hdlr;
	int accNum;
	char name[20];
	int balance;
	int money;

	for (;;) {
		int choice;
		hdlr.showMenu();
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
			hdlr.createAccount(accNum, name, balance);
			break;
		case DEPOSIT:
			cout << "[입 금]" << endl;
			cout << "계좌ID: ";
			cin >> accNum;
			cout << "입금액: ";
			cin >> money;
			hdlr.deposit(accNum, money);
			break;
		case WITHDRAW:
			cout << "[출 금]" << endl;
			cout << "계좌ID: ";
			cin >> accNum;
			cout << "출금액: ";
			cin >> money;
			hdlr.withdraw(accNum, money);
			break;
		case SHOWALL:
			hdlr.showAllAccount();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}

	}
}
