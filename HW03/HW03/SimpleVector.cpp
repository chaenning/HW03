#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

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
		delete[] data;
	}

	void push_back(const T& value)
	{
		if (currentSize >= currentCapacity)
		{
			if (0 < currentCapacity)
			{
				int newCapacity = currentCapacity + 5;
				T* tmpData = new T[newCapacity];
				for (int i = 0; i < currentSize; ++i)
				{
					tmpData[i] = data[i];
				}
				currentCapacity = newCapacity;
				delete[] data;
				data = tmpData;
			}
		}
		data[currentSize++] = value;
	}


	void pop_back() {
		if (currentSize > 0) --currentSize;
	}

	int size() {
		return currentSize;
	}

	int capacity() {
		return currentCapacity;
	}


	void resize(int newCapacity) {
		if (newCapacity < 0) {
			cout << "양수를 입력하세요";
			return;
		}

		T* tmpData = new T[newCapacity];

		int tmp = (newCapacity < currentSize) ? newCapacity : currentSize; // newCapacity가 원래 size보다 작은 경우 처리

		for (int i = 0; i < tmp; i++) {
			tmpData[i] = data[i];
		}

		delete[] data;
		data = tmpData;

		currentSize = tmp;
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
	vector2.resize(5);
	cout << "size :" << vector2.size() << ", capacity :" << vector2.capacity() << endl;
	vector2.print();
	return 0;
}