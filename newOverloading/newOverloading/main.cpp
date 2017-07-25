#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point &pos);

	static void * operator new (size_t size) {
		cout << "operator new : " << size << endl;
		void * adr = new char[size];
		return adr;
	}
	static void * operator new[] (size_t size) {
		cout << "operator new[] : " << size << endl;
		void * adr = new char[size];
		return adr;
	}
	static void operator delete(void * addr) {
		cout << "operator delte ()" << endl;
		delete[]addr;
	}
	
	~Point() {
		cout << "destroy" << endl;
	}
};

ostream& operator<<(ostream& os, const Point &pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main() {
	Point *ptr = new Point(3, 4);
	cout << *ptr;
	delete ptr;
	Point *ptr2 = new Point[3];
	
	return 0;
}