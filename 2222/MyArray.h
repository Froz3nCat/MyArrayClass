#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
class MyArray
{

private:
	int* MainString = nullptr;
	int size = 0;
	int start = 0;
	int end = 0;

	int partition(int *ms, int startPoint, int endPoint) {
		int pivot = ms[endPoint];
		int pIndex = startPoint;
		for (int i = startPoint; i < endPoint; i ++) {
			if (ms[i]<=pivot) {
				std::swap(ms[i], ms[pIndex]);
				pIndex++;
			}
			
		}
		std::swap(ms[pIndex], ms[endPoint]);
		return pIndex;
	}
	void QS(int *ms, int startPoint, int EndPoint) {
		if (startPoint >= EndPoint) {
			return;
		}
		int pivot = partition(ms, startPoint, EndPoint);
		QS(ms, startPoint, pivot - 1);
		QS(ms, pivot + 1, EndPoint);
	}

public:
	MyArray(int EndPos) {
		this->size = EndPos;
		this->start = 0;
		this->end = EndPos;
		this->MainString = new int[size+1];
	}

	MyArray(int StartPos, int EndPos) {
		if (StartPos >= EndPos) {
			throw std::exception("\nStart position is greater than end position");
		}
		if (StartPos == EndPos) {
			throw std::exception("\nStart position equals end position");
		}
		this->start = StartPos;
		this->end = EndPos;
		this->size = EndPos - StartPos;
		this->MainString = new int[size+1];
	}
	
	MyArray() {
		this->start = 0;
		this->end = 5;
		this->size = this->end - this->start;
	}

	const size_t getSize() { return size; }

	const int setValue(int where, int value) { 
		if (where < this->start || where >= this->end) {
			throw std::exception("\nout of range");
		}
		this->MainString[where-this->start] = value; 
	}

	const int getValue(int iter) {
		if (iter < this->start || iter >= this->end) {
			throw std::exception("\nvalue is not in range");
		}
		return this->MainString[iter - this->start];
	}
	void QuickSort() {
		QS(this->MainString, 0, size-1);
	}

	void Sort() {
		bool flag = true;
		int temp;

		while (flag) {
			flag = false;

				for (int j = 0; j < this->size-1; j++) {
					if (this->MainString[j] > this->MainString[j + 1]) {
						temp = MainString[j];
						MainString[j] = MainString[j + 1];
						MainString[j + 1] = temp;
						flag = true;
					}
				}
		}
	}
	
	const int BinarySearch(int value) {
		this->QS(this->MainString, 0, size - 1);
		bool flag = false;
		int TempStart = 0;
		int TempEnd = size;
		int mid;

		while (flag || TempStart <= TempEnd) {
			mid = (TempStart + TempEnd)/2;
			if (this->MainString[mid] == value) {
				flag = true;
				return this->start + mid;
			}
			if (this->MainString[mid] > value) {
				TempEnd = mid - 1;
			}
			else TempStart = mid + 1;
		}
		return -1;
	}

	MyArray operator + (MyArray &other) {
		
		MyArray NewObject(this->size + other.size);
		
		for (int i = 0; i < this->size; i++) {
			NewObject.MainString[i] = this->MainString[i];
		}
		for (int i = 0; i < other.size; i ++) {
			NewObject.MainString[i + this->size] = other.MainString[i];
		}
		return NewObject;
	}

	MyArray operator - (MyArray& other) {
		
		int tempsize = 0;
		int *tempArr = new int[this->size];
		int k = 0;

		for (int i = 0; i < this->size ; i++) {
			for (int j = 0; j < other.size; j++) {
				if (this->MainString[i] == other.MainString[j]) {
					k++; break;
				}
			}
			if (k == 0) {
				tempArr[tempsize] = this->MainString[i];
				tempsize++;
				
			}
			k = 0;
			std::cout << "end" << std::endl;
		}

		MyArray NewObject(tempsize);
		for (int i = 0; i < tempsize; i++) {
			NewObject.MainString[i] = tempArr[i];
		}
		
		delete[] tempArr;
		return NewObject;
	}

	

	bool operator == (MyArray& other) {
		if (this->size == other.size) {
			for (int i = 0; i < this->size; i++) {
				if (this->MainString[i] != other.MainString[i]) {
					return false;
				}
			}
			return true;
		}

		return false;
		
	}

	void Show() {
		std::cout << std::endl;

		for (int i = 0; i < this->size; i++) {
			std::cout <<"Iter "<<i<< " value: " << MainString[i] << std::endl;
		}
		std::cout << std::endl;
	}

	void Initialize() {
		for (int i = 0; i < this->size; i++) {
			std::cin >> this->MainString[i];
		}
	}
	
	~MyArray() {
		delete[] MainString;
	}

};