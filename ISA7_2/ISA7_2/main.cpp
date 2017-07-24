#include <iostream>
#include <cstring>
using namespace std;
class Book {
private:
	char * title;
	char * isbn;
	int price;
public:
	Book() {}
	Book(char* _title, char* _isbn, int _price):price(_price) {
		title = new char[strlen(_title) + 1];
		strcpy(title, _title);
		isbn = new char[strlen(_isbn) + 1];
		strcpy(isbn, _isbn);
	}
	Book(const Book &cpy):price(cpy.price) {
		cout << "Book copy constructor" << endl;
		title = new char[strlen(cpy.title) + 1];
		strcpy(title, cpy.title);
		isbn = new char[strlen(cpy.isbn) + 1];
		strcpy(isbn, cpy.isbn);
	}
	Book& operator=(Book& ref) {
		delete[] title;
		delete[] isbn;
		cout << "Book operator=" << endl;
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
	}
	void showBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	virtual ~Book() {
		cout << "destory Book" << endl;
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book {
private:
	char * DRMKey;//보안관련 키
public:
	EBook() {}
	EBook(char* _title, char* _isbn, int _price, char* _DRMKey) :Book(_title, _isbn, _price) {
		DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy(DRMKey, _DRMKey);
	}
	EBook(const EBook &cpy):Book(cpy){
		cout << "EBook copy constructor" << endl;
		//Book(cpy);//부모 복사생성자
		DRMKey = new char[strlen(cpy.DRMKey) + 1];
		strcpy(DRMKey, cpy.DRMKey);
	}
	EBook& operator=(EBook& ref) {
		delete[] DRMKey;
		cout << "EBook operator=" << endl;
		Book::operator=(ref);
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}
	void showEBookInfo() {
		showBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	virtual ~EBook() {
		cout << "destory EBook" << endl;
		delete[] DRMKey;
	}
};
int main() {
	Book book("좋은 c++", "555-12345-890-0", 20000);
	//book.showBookInfo();
	//cout << endl;
	EBook ebook("좋은 c++ ebook", "555-12345-890-1", 10000, "fdx9w0801f");
	//ebook.showEBookInfo();
	//cout << "------------------" << endl;
	//453p
	//Book b1 = book;//복사 생성자
	//b1.showBookInfo();
	//Book b2;
	//b2 = book;//대입연산자 오버로딩
	//b2.showBookInfo();
	//ebook
	cout << "------------------" << endl;
	EBook b3 = ebook;//복사 생성자
	b3.showBookInfo();
	EBook b4;
	b4 = ebook;//대입연산자 오버로딩
	b4.showEBookInfo();

	return 0;
}