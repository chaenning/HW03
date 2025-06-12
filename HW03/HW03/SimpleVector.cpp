#include <iostream>

using namespace std;

template <typename T>
class SimpleVector {
private:

	T* data;
	int currentSize;
	int currentCapacity;

public:
	SimpleVector() 
		: data(new T[10]), currentCapacity(10), currentSize(0) {}

	SimpleVector(int x)
		: data(new T[x]), currentCapacity(x), currentSize(0) {
	}

	~SimpleVector() {
		delete[] data;
	}

	void push_back(const T& value) {
		data[currentSize++] = value;
	}

	void pop_back() {		
		if(currentSize > 0) --currentSize; 			
	}

	int size() {
		return currentSize;
	}

	int capacity() {
		return currentCapacity;
	}

	void print() {
		cout << "현재 원소 : ";
		for (int i = 0; i < currentSize; i++) {
			cout << data[i] << "  ";
		}
		cout << endl;
	}

};



int main() {
	SimpleVector<int> vector1;

	vector1.push_back(10);
	vector1.push_back(30);
	vector1.push_back(50);
	vector1.pop_back();
	vector1.push_back(70);

	vector1.print();


	cout << "size :" << vector1.size() << ", capacity :" << vector1.capacity() << endl;


	cout << endl <<"- - - - - - - - - - - -"<< endl;
	SimpleVector<string> vector2(20);
	vector2.push_back("안녕");
	vector2.push_back("하세요");
	vector2.push_back("테스트");
	vector2.push_back("삭제");
	vector2.pop_back();
	vector2.push_back("입니다.");

	vector2.print();
	cout << "size :" << vector2.size() << ", capacity :" << vector2.capacity() << endl;

	return 0;
}