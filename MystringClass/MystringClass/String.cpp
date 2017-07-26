#include "String.h"
#include <cstring>
String::String() {}
String::String(char* s) {
	str = new char[strlen(s) + 1];
	strcpy(str, s);
}
String& String::operator=(const char* s) {
	delete[] str;
	str = new char[strlen(s) + 1];
	strcpy(str, s);
	return *this;
}
String::String(const String& cpy) {
	str = new char[strlen(cpy.str) + 1];
	strcpy(str, cpy.str);
}

String String::operator+(const String& ref) {
	char* tmp;
	tmp = new char[strlen(this->str) + strlen(ref.str) + 1];
	strcpy(tmp, str);
	strcat(tmp, ref.str);
	String tmpString(tmp);
	delete tmp;
	return tmpString;
}
void String::operator+=(const String& ref) {
	char* tmp = new char[strlen(str) + 1];
	strcpy(tmp, str);
	delete str;

	str = new char[strlen(this->str) + strlen(ref.str) + 1];
	strcpy(str,tmp);
	strcat(str, ref.str);
	delete tmp;
}

bool String::operator==(const String& ref) {
	if (strcmp(str, ref.str))
		return false;
	return true;
}

ostream& operator<<(ostream& ostm, String& ref) {
	ostm << ref.str;
	return ostm;
}
istream& operator >> (istream& istm, String& ref) {
	char in[255];
	cin >> in;
	ref.str = new char[strlen(in) + 1];
	strcpy(ref.str, in);
	return istm;
}

String::~String() {
	delete[] str;
}