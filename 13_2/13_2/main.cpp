#include <iostream>
#include "SmartPtr.h"
#include "point.h"
using namespace std;
int main() {
	SmartPtr<Point> sptr1(new Point(1, 2));
	sptr1->showPosition();
	sptr1->setPos(10, 20);
	sptr1->showPosition();
	return 0;
}