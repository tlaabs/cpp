//���뿹�ݰ���, �ſ�ŷڰ��� �߰�
#include <iostream>
#include "accountHandler.h"
#include "account.h"
#include <cstring>
using namespace std;

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOWALL, EXIT };

int main() {
	AccountHandler hdlr;
	int accNum;
	int money;

	for (;;) {
		int choice;
		hdlr.showMenu();
		cout << "����: ";
		cin >> choice;

		switch (choice) {
		case CREATE:
			hdlr.createAccount();
			break;
		case DEPOSIT:
			cout << "[�� ��]" << endl;
			cout << "����ID: ";
			cin >> accNum;
			cout << "�Աݾ�: ";
			cin >> money;
			hdlr.deposit(accNum, money);
			break;
		case WITHDRAW:
			cout << "[�� ��]" << endl;
			cout << "����ID: ";
			cin >> accNum;
			cout << "��ݾ�: ";
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
