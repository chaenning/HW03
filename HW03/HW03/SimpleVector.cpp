﻿#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

	void release() {
		delete[] data;
		data = nullptr;
	}

public:
	SimpleVector()
		: data(new T[10]), currentCapacity(10), currentSize(0) {
	}

	SimpleVector(int x)
		: data(new T[x]), currentCapacity(x), currentSize(0) {
	}

	SimpleVector(const SimpleVector& other)
		: data(new T[other.currentCapacity]), currentSize(other.currentSize), currentCapacity(other.currentCapacity) {

		for (int i = 0; i < currentSize; ++i) {
			data[i] = other.data[i];
		}
	}

	~SimpleVector() {
		release();
	}

	void push_back(const T& value)
	{
		if (currentSize >= currentCapacity)
		{
			resize(currentCapacity + 5);
		}
		data[currentSize++] = value;
	}


	void pop_back() {
		if (currentSize > 0) --currentSize;
	}

	int size() const {
		return currentSize;
	}

	int capacity() const {
		return currentCapacity;
	}


	void resize(int newCapacity) {
		if (newCapacity < currentCapacity) {
			return;
		}

		T* tmpData = new T[newCapacity];

		for (int i = 0; i < currentSize; i++) {
			tmpData[i] = data[i];
		}

		release();
		data = tmpData;
		currentCapacity = newCapacity;
	}

	void sortData() {
		// 오름차순 정렬
		sort(data, data + currentSize);
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
	// 힙 메모리 누수를 감지하는 코드
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	SimpleVector<int> vector1;

	vector1.push_back(10);
	vector1.push_back(30);
	vector1.push_back(50);
	vector1.pop_back();
	vector1.push_back(70);

	vector1.print();

	cout << "size :" << vector1.size() << ", capacity :" << vector1.capacity() << endl;

	cout << endl << "- - - - - - - - - - - -" << endl;
	SimpleVector<string> vector2(5);
	vector2.push_back("안녕");
	vector2.push_back("하세요");
	vector2.push_back("테스트");
	vector2.push_back("삭제");
	vector2.pop_back();
	vector2.push_back("입니다.");

	vector2.print();
	cout << "size :" << vector2.size() << ", capacity :" << vector2.capacity() << endl;

	vector2.push_back("벡터 크기를 늘려볼게요.");
	vector2.push_back("얍!");
	vector2.print();
	cout << "size :" << vector2.size() << ", capacity :" << vector2.capacity() << endl;
	cout << "벡터 정렬" << endl;
	vector2.sortData();
	vector2.print();
	cout << "벡터 사이즈 변경" << endl;
	vector2.resize(20);
	cout << "size :" << vector2.size() << ", capacity :" << vector2.capacity() << endl;
	vector2.print();
	return 0;
}