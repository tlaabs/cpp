#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T max(T a, T b) {
	cout << "Template function" << endl;
	return a > b ? a : b;
}
template <>
char* max(char* a, char* b) {
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}
template<>
const char* max(const char* a, const char* b) {
	cout << "const char* max(const char* a, const char* b) " << endl;
	return strcmp(a, b) > 0 ? a : b;
}
int main() {
	cout << max(11, 15) << endl;
	cout << max("Simple", "Best");
}