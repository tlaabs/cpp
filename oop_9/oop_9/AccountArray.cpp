#include <iostream>
#include "AccountArray.h"
using namespace std;
AccountArray::AccountArray(int len) :arrlen(len) {
	arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& AccountArray::operator[](int idx) {
	if (idx < 0 || arrlen <= idx) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

ACCOUNT_PTR AccountArray::operator[](int idx) const {
	if (idx < 0 || arrlen <= idx) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}