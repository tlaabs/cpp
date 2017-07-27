#include <iostream>
using namespace std;

class Car {
private:
	int fuelGauge;
public:
	Car(int fuel) :fuelGauge(fuel) {}
	void showCarState()const {
		cout << "잔여 연료량: " << fuelGauge << endl;
	}
};

class Truck : public Car {
private:
	int freightWeight;
public:
	Truck(int fuel, int weight) :Car(fuel), freightWeight(weight) {}
	void showTructState() const {
		showCarState();
		cout << "화물의 무게: " << freightWeight << endl;
	}
};
int main() {
	//dynamic_cast : 유도 클래스의 포인터 -> 기초클래스의 포인터
	//static_cast : dynamic_cast 추가로 기초->유도도 가능하게, but 책임은 너가.
	//속도는 static_cast가 더 빠름
	Car * c1 = new Truck(100, 20);
	Truck * d1 = static_cast<Truck*>(c1);
	Car * c2 = new Car(10);
	Truck * d2 = static_cast<Truck*>(c2); //허용하면 안되지만
	Truck * t1 = new Truck(10, 200);
	Car * d3 = dynamic_cast<Car*>(t1);
	return 0;
}