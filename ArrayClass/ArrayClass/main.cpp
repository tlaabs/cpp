#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray {
private:
	int * arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray &cpy) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray &ref) {}

public:
	BoundCheckIntArray(int len) :arrlen(len) {
		arr = new int[len];
	}
	int& operator[](int idx){
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exeception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int operator[](int idx) const{
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exeception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int getArrLen() const { return arrlen; }
	~BoundCheckIntArray() {
		delete[]arr;
	}
};

void showAllData(const BoundCheckIntArray& ref){
	int len = ref.getArrLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;
}

int main() {
	BoundCheckIntArray arr(5);
	for (int i= 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	/*for (int i = 0; i < 6; i++)
		cout << arr[i] << endl;*/

	/*BoundCheckIntArray cpy1(5);
	cpy1 = arr;
	BoundCheckIntArray cpy2 = arr;*/

	showAllData(arr);
	return 0;
}