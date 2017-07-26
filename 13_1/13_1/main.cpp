#include <iostream>
using namespace std;

template <class T>
void swapData(T& p1, T& p2) {
	T tmp = p1;
	p1 = p2;
	p2 = tmp;
}

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void showPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};


int main() {
	Point a(2, 5);
	Point b(3, 1);
	swapData<Point>(a, b);
	a.showPosition();
	b.showPosition();
	return 0;
}

