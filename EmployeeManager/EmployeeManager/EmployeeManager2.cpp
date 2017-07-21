#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
	char name[100];
public:
	Employee(char *name) {
		strcpy(this->name, name);
	}
	void showYourName() const {
		cout << "name: " << name << endl;
	}
};

class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(char* name, int money) : Employee(name), salary(money) {
	}
	int getPay() const {
		return salary;
	}
	void showSalaryInfo() const {
		showYourName();
		cout << "salary: " << getPay() << endl << endl;
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}
	void addEmployee(Employee * emp) {
		empList[empNum++] = emp;
	}
	void showAllSalaryInfo() const {
		/*
		for (int i = 0; i < empNum; i++)
			empList[i]->showSalaryInfo();
			*/
	}
	void showTotalSalary() const {
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->getPay();
			*/
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main() {
	EmployeeHandler handler;

	handler.addEmployee(new PermanentWorker("KIM", 1000));
	handler.addEmployee(new PermanentWorker("LEE", 1500));
	handler.addEmployee(new PermanentWorker("JUN", 1500));
	
	handler.showAllSalaryInfo();
	handler.showTotalSalary();
	return 0;

}




















