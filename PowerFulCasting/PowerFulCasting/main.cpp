#include <iostream>
using namespace std;

class Car {
private:
	int fuelGauge;
public:
	Car(int fuel) :fuelGauge(fuel) {}
	void showCarState()const {
		cout << "�ܿ� ���ᷮ: " << fuelGauge << endl;
	}
};

class Truck : public Car {
private:
	int freightWeight;
public:
	Truck(int fuel, int weight) :Car(fuel), freightWeight(weight) {}
	void showTructState() const {
		showCarState();
		cout << "ȭ���� ����: " << freightWeight << endl;
	}
};
int main() {
	//dynamic_cast : ���� Ŭ������ ������ -> ����Ŭ������ ������
	//static_cast : dynamic_cast �߰��� ����->������ �����ϰ�, but å���� �ʰ�.
	//�ӵ��� static_cast�� �� ����
	Car * c1 = new Truck(100, 20);
	Truck * d1 = static_cast<Truck*>(c1);
	Car * c2 = new Car(10);
	Truck * d2 = static_cast<Truck*>(c2); //����ϸ� �ȵ�����
	Truck * t1 = new Truck(10, 200);
	Car * d3 = dynamic_cast<Car*>(t1);
	return 0;
}