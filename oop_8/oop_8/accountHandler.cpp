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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::createAccount() {
	int accNum;
	char name[20];
	int balance;

	int type, rate, grade;
	Account* ptr;
	
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> type;
	cout << "����ID: ";
	cin >> accNum;
	cout << "�̸�: ";
	cin >> name;
	cout << "�ܾ�: ";
	cin >> balance;
	cout << "������: ";
	cin >> rate;
	switch (type) {
	case NORMAL:
		ptr = new NormalAccount(accNum, name, balance, rate);
		break;
	case CREDIT:
		cout << "�ſ���(1toA, 2toB, 3toC): ";
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