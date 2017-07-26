#include <iostream>
using namespace std;

template <class T>
T sumArray(T arr[], int len) {
	T sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}
int main() {
	float farr[3];
	farr[0] = 1.3;
	farr[1] = 2.3;
	farr[2] = 3.3;
	cout << sumArray<float>(farr, 3) << endl;
	return 0;
}