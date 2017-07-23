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
	friend Point operator+ (const Point &, const Point &);
	friend Point operator- (const Point &, const Point &);
	friend Point& operator+= (Point &,Point &);
	friend bool operator== (const Point &,const Point &);
	friend bool operator!= (const Point &, const Point &);

};

Point operator+(const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}
Point operator-(const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}
Point& operator+=(Point &pos1, Point &pos2) {
	pos1.xpos += pos2.xpos;
	pos1.ypos += pos2.ypos;
	return pos1;
}
bool operator==(const Point &pos1, const Point &pos2) {
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	return false;
}
bool operator!=(const Point &pos1, const Point &pos2) {
	if (pos1 == pos2)
		return false;
	return true;
}
int main() {
	Point pos1(3, 4);
	Point pos2(2, 4);
	cout<<(pos1!=pos2)<<endl;
	//pos1.showPosition();
	return 0;
}