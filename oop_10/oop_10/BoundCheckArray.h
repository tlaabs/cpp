#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__
#include <iostream>
using namespace std;

template <typename T>
class BoundCheckArray {
private:
	T* arr;
	int len;
	BoundCheckArray(const BoundCheckArray&) {}
	BoundCheckArray& operator=(const BoundCheckArray&) {}
public:
	BoundCheckArray(int len);
	T& operator[](int n);
	T operator[](int n) const;
	void showAll() const;
	int getArrLen() const;
	~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray(int len):len(len) {
	arr = new T[len];
}
template <class T>
T& BoundCheckArray<T>::operator[](int n) {
	if (n < 0 || n >= len) {
		cout << "잘못된 범위" << endl;
		exit(1);
	}
	return arr[n];
}
template <class T>
T BoundCheckArray<T>::operator[](int n) const{
	if (n < 0 || n >= len) {
		cout << "잘못된 범위" << endl;
		exit(1);
	}
	return arr[n];
}
template <class T>
void BoundCheckArray<T>::showAll() const{
	for (int i = 0; i < len; i++)
		cout << arr[i] << endl;
}
template <class T>
int BoundCheckArray<T>::getArrLen() const {
	return len;
}
template <class T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[] arr;
}
#endif