#include <iostream>
#include "BoundCheckArray.h"
#include "point.h"
using namespace std;

int main() {
	BoundCheckArray<int> intArr(5);
	for (int i = 0; i < 5; i++)
		intArr[i] = i * 5;
	for (int i = 0; i < 5; i++)
		cout << intArr[i] << endl;

	//°´Ã¼ ÀúÀå
	BoundCheckArray<Point> pointArr(3);
	pointArr[0] = Point(2, 4);
	pointArr[1] = Point(4, 2);
	pointArr[2] = Point(1,5);
	for (int j = 0; j < pointArr.getArrLen();j++)
		cout << pointArr[j];

	typedef Point* POINT_PTR;
	BoundCheckArray<POINT_PTR> ptrArr(3);
	ptrArr[0] = new Point(2, 4);
	ptrArr[1] = new Point(4, 2);
	ptrArr[2] = new Point(1, 5);
	for (int j = 0; j < ptrArr.getArrLen(); j++)
		cout << *ptrArr[j];
	delete ptrArr[0];
	delete ptrArr[1];
	delete ptrArr[2];

	return 0;
}