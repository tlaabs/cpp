#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream&, Point& pt);
	friend istream& operator>>(istream&, Point& pt);
};

ostream& operator<<(ostream& ostm, Point & pt) {
	printf("[%d,%d]", pt.xpos, pt.ypos);
	return ostm;
}
istream& operator>> (istream& istm, Point& pt) {
	scanf("%d %d", &pt.xpos, &pt.ypos);
	return istm;
}


int main() {
	Point pos1;
	cout << "x,y좌표순으로 입력: ";
	cin >> pos1;
	cout << pos1;
	return 0;
}