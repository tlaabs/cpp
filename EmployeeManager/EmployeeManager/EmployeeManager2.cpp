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
	virtual int getPay() const {}
	virtual void showSalaryInfo() const {}
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
	virtual void showSalaryInfo() const {
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
	void showAllSalaryInfo() const{
		for (int i = 0; i < empNum; i++)
			empList[i]->showSalaryInfo();
			
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

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(char *name, int pay) :Employee(name), workTime(0), payPerHour(pay) {}
	void addWorkTime(int time) {
		workTime += time;
	}
	int getPay() const {
		return workTime * payPerHour;
	}
	virtual void showsalaryInfo() const {
		showYourName();
		cout << "salary: " << getPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(char * name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
	void addSalesResult(int value) {
		salesResult += value;
	}
	int getPay() const {
		return PermanentWorker::getPay() +
			(int)(salesResult*bonusRatio);
	}
	virtual void showSalaryInfo() const {
		showYourName();
		cout << "salary : " << getPay() << endl << endl;
	}
};

int main() {
	EmployeeHandler handler;

	//정규직
	handler.addEmployee(new PermanentWorker("KIM", 1000));
	handler.addEmployee(new PermanentWorker("LEE", 1500));
	
	//임시직
	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->addWorkTime(5);
	handler.addEmployee(alba);

	//영업직
	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->addSalesResult(7000);
	handler.addEmployee(seller);

	handler.showAllSalaryInfo();

	handler.showTotalSalary();
	return 0;
	
	handler.showAllSalaryInfo();
	handler.showTotalSalary();
	return 0;

}




















