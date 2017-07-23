#include <iostream>
using namespace std;

typedef struct Data {
	int data;
	void(*showData)(Data *);
	void(*add)(Data *, int);
}Data;

void showData(Data* THIS) { cout << "Data: " << THIS->data << endl; }
void add(Data* THIS, int num) { THIS->data += num; }

int main() {
	Data obj1 = { 15,showData,add };
	Data obj2 = { 7,showData,add };

	obj1.add(&obj1, 17);
	obj2.add(&obj2, 9);
	obj1.showData(&obj1);
	return 0;
}