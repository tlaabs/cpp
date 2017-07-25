#include <iostream>
using namespace std;

class Number {
private:
	int num;
	int b;
public:
	Number(int n) : num(n) {}
	void showData() { cout << num << endl; }
	Number& operator=(int a) {
		cout << "o";
		return *this;
	}
	Number * operator->() {
		return this;
	}
	Number& operator*() {
		return *this;
	}
};

int main() {
	Number num(20);
	(*num) = 30;
	num->showData();
	return 0;
}