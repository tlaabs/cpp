#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) :bullet(bnum) {}
	Gun(Gun &cpy) {
		cout << "Gun copy constructor" << endl;
		this->bullet = cpy.bullet;
	}
	void shut() {
		cout << "BANG!" << endl;
		bullet--;
	}
};

class Police {
private:
	int handcuffs;
	Gun * pistol;
public:
	Police(int bnum = 0, int bcuff = 0) :handcuffs(bcuff) {
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	//복사생성자
	Police(Police &cpy) {
		delete pistol;
		cout << "constructor of Police" << endl;
		this->handcuffs = cpy.handcuffs;
		pistol = new Gun(*(cpy.pistol));//복사생성자
	}
	//대입연산자 오버로딩
	Police& operator=(const Police& ref) {
		cout << "Police& operator=" << endl;
		this->handcuffs = ref.handcuffs;
		pistol = new Gun(*(ref.pistol));
		return *this;
	}
	void putHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void shut() {
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->shut();
	}
	void showAddrInfo() {
		cout << "addr : " << &pistol << endl;
	}
	~Police() {
		if (pistol != NULL)
			delete pistol;
	}
};

int main() {
	Police pman1(5, 3);
	Police pman2 = pman1;//복사생성자
	pman1.showAddrInfo();
	pman2.showAddrInfo();

	Police pman3(4, 5);
	Police pman4;
	pman4 = pman3; // 대입 연산자 오버로딩
	return 0;
}