#include <iostream>
using namespace std;
class SoSimple {
public:
	virtual void showSimpleInfo() {
		cout << "Base" << endl;
	}
};

class SoComplex : public SoSimple {
public:
	void showSimpleInfo() {
		cout << "Derived" << endl;
	}
};
int main() {
	SoSimple* a = new SoSimple();
	SoComplex * c = dynamic_cast<SoComplex*>(a);
	if (c == NULL)
		cout << "형변환 실패!" << endl;
	c->showSimpleInfo();
	return 0;
}