#include <iostream>
using namespace std;

template <class T1, class T2>
void showData(double num) {
	cout << (T1)num << ", " << (T2)num << endl;
}

int main() {
	showData<char, int>(65.2);
	showData<double, int>(65.2);

	return 0;
}