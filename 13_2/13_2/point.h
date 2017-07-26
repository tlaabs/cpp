#ifndef __POINT_H__
#define __POINT_H__
#include <iostream>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0);
	void showPosition()const;
	void setPos(int, int);
	friend ostream& operator<<(ostream&, const Point&);
};
#endif