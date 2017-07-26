#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__
#include "account.h"
typedef Account* ACCOUNT_PTR;
class AccountArray {
private:
	ACCOUNT_PTR * arr; //더블포인터
	int arrlen;
public:
	AccountArray(int len);
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int getArrLen() const { return arrlen; }
	~AccountArray() {
		delete[] arr;
	}
};
#endif