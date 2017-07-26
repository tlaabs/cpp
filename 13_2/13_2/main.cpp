#include <iostream>
<<<<<<< HEAD
#include "SmartPtr.h"
#include "point.h"
using namespace std;
int main() {
	SmartPtr<Point> sptr1(new Point(1, 2));
	sptr1->showPosition();
	sptr1->setPos(10, 20);
	sptr1->showPosition();
=======
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
>>>>>>> 89d296fd31a8e4e12b9e1b7ceb9f8ca66a7e51d8
	return 0;
}