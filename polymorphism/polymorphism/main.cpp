#include <iostream>
using namespace std;

class First {
public:
	virtual void simpleFunc() { cout << "First" << endl; }
	void show() { cout << "first show()" << endl; };
	virtual ~First() {
		cout << "destroy First " << endl;
	}
};

class Second : public First {
public:
	virtual void simpleFunc() { cout << "Second" << endl; }
	void show() {
		cout << "show() called" << endl;
	}
	virtual ~Second() {
		cout << "deostroy Second " << endl;
	}
};

int main() {
	First * ptr = new Second();
	ptr->show();
	delete ptr;
}
