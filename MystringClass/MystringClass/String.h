#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>
using namespace std;
class String {
private:
	char* str;
public:
	String();
	String(char*);
	String(const String&);
	String& operator=(const char*);
	String operator+(const String&);
	void operator+=(const String&);
	bool operator==(const String&);
	friend ostream& operator<<(ostream&, String&);
	friend istream& operator>>(istream&, String&);
	~String();
};

#endif