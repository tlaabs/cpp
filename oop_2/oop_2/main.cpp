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
		cout << "����: ";
		cin >> choice;

		switch (choice) {
		case CREATE:
			cout << "����ID: ";
			cin >> accNum;
			cout << "�̸�: ";
			cin >> name;
			cout << "�ܾ�: ";
			cin >> balance;
			createAccount(accNum, name, balance);
			break;
		case DEPOSIT:
			cout << "[�� ��]" << endl;
			cout << "����ID: ";
			cin >> accNum;
			cout << "�Աݾ�: ";
			cin >> money;
			deposit(accNum, money);
			break;
		case WITHDRAW:
			cout << "[�� ��]" << endl;
			cout << "����ID: ";
			cin >> accNum;
			cout << "��ݾ�: ";
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void createAccount(int accNum, char *name, int balance) {
	index++;
	acs[index] = new Account(accNum, name, balance);
}

void deposit(int accNum, int money) {
	int idx = getIdxFindAccount(accNum);
	acs[idx]->deposit(money);
	cout << "�ԱݿϷ�" << endl;
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
		cout << "�ܾ��� �����մϴ�." << endl;
	}
	else {
		cout << "��ݿϷ�" << endl;
	}
}

void showAllAccount() {
	for (int i = 0; i <= index; i++)
		acs[i]->showMyAccountInfo();
}