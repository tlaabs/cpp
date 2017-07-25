#include <iostream>
using namespace std;

class SortRule {//추상클래스
public:
	virtual bool operator()(int num1, int num2) const = 0;//순수가상 함수
};

class AscendingSort : public SortRule {
public:
	bool operator()(int num1, int num2) const {
		if (num1 > num2)
			return true;
		else
			return false;
	}
};

class DescendingSort : public SortRule {
public:
	bool operator()(int num1, int num2) const {
		if (num1 < num2)
			return true;
		else
			return false;
	}
};

class DataStorage {
private:
	int * arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) :idx(0), MAX_LEN(arrlen) {
		arr = new int[MAX_LEN];
	}
	void addData(int num) {
		if (MAX_LEN <= idx) {
			cout << "더 이상 저장이 불가능합니다." << endl;
			return;
		}
		arr[idx++] = num;
	}
	void showAllData() {
		for (int i = 0; i < idx; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}
	void sortData(const SortRule& functor) {
		for (int i = 0; i < (idx - 1); i++) {
			for (int j = 0; j < (idx - 1) - i; j++) {
				if (functor(arr[j], arr[j + 1])) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	~DataStorage() {
		delete[] arr;
	}
};

int main() {
	DataStorage storage(6);
	storage.addData(40);
	storage.addData(30);
	storage.addData(50);
	storage.addData(10);
	
	storage.sortData(DescendingSort());
	storage.showAllData();

	return 0;
}