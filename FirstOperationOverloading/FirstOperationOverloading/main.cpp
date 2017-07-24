#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y= 0) : xpos(x),ypos(y){}
	Point(const Point &copy) {
		xpos = copy.xpos;
		ypos = copy.ypos;
		cout << "&copy called" << endl;
	}
	void showPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator+(const Point &ref) {
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		cout << "operator+ obj addr : " << &pos << endl;
		return pos;
	}
};

int main() {
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);
	cout << "main obj addr : " << &pos3 << endl;
	pos3.showPosition();
	return 0;
}