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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::createAccount(int accNum, char *name, int balance) {
	index++;
	acs[index] = new Account(accNum, name, balance);
}

void AccountHandler::deposit(int accNum, int money) {
	int idx = getIdxFindAccount(accNum);
	acs[idx]->deposit(money);
	cout << "�ԱݿϷ�" << endl;
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
		cout << "�ܾ��� �����մϴ�." << endl;
	}
	else {
		cout << "��ݿϷ�" << endl;
	}
}

void AccountHandler::showAllAccount() {
	for (int i = 0; i <= index; i++)
		acs[i]->showMyAccountInfo();
}