#include "point.h"
#include <iostream>
using namespace std;
Point::Point(int x, int y) :xpos(x), ypos(y) {
}

ostream& operator<< (ostream& ostm, const Point& ref) {
	ostm << '[' << ref.xpos << ", " << ref.ypos << ']' << endl;
	return ostm;
}