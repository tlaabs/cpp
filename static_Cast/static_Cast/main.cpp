#include <iostream>
using namespace std;

int main() {
	const int num = 4;
	int* ptr =(int*)(&num);
	*ptr = 20;
	
	cout <<&num<<" " <<num << endl;
	cout << ptr << " " <<*ptr << endl;
	return 0;
}