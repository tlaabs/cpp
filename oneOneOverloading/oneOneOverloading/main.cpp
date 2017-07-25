#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0):xpos(x), ypos(y) {
	}
	Point(const Point& cpy) {
		cout << "constructor" << endl;
		xpos = cpy.xpos;
		ypos = cpy.ypos;
	}
	void showPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++() {
		xpos += 1;
		ypos += 1;
		return *this;
	}
	const Point operator++(int) {
		const Point retobj(*this);
	
		xpos += 1;
		ypos += 1;
		return retobj;
	}
};
class B {
private:
	int val;
public:
	void show() { cout << "show" << endl; }
};
int main() {
	Point p1(2, 5);
	Point cpy = p1++;
	//Point cpy = (p1++)++;
	cpy.showPosition();
	p1.showPosition();
	return 0;
}