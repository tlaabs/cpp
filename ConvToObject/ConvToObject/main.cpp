#include <iostream>
using namespace std;

class Number {
private:
	int num;
public:
	Number(int n = 0): num(n) {
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref) {
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	/*Number& operator=(const int d) {
		cout << "operator=() int" << endl;
		num = d;
		return *this;
	}*/
	operator int() {//����ȯ ������ �����ε�
		cout << "����ȯ ������ �����ε�" << endl;
		return num;
	}
	void showNumber() { cout << num << endl; }
};

int main() {
	Number num;
	num = 30;
	Number num2 = num + 20;
	num2.showNumber();
	return 0;
}