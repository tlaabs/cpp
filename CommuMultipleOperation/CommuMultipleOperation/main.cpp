#include <iostream>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void showPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	//Point * 3
	Point operator*(int times) {
		Point pos(xpos*times, ypos*times);
		return pos;
	}
	//3 * Point
	friend Point operator*(int times, Point &ref);

};
Point operator*(int times, Point &ref) {
	return ref*times;
}
int main() {
	Point p1(2, 3);
	Point p2 = 5 * p1 * 3;
	p2.showPosition();
	return 0;
}