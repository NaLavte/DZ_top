#include <iostream>
#include <string>

using namespace std;

int searchArr(int* arr, int size, int key) {
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return index;
		}
		index++;
	}
	cout << "Ключ не найден.";
	return 0;
}

int binarySearch(int arr[], int size, int key) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == key) {
			return mid;
			left = mid + 1;
			right = mid - 1;
		}
		return -1;
	}
}

int binaryToDecimal(const string& binaryStr) {
	int decimalNumber = 0;
	for (char bit : binaryStr) {
		decimalNumber = decimalNumber * 2 + (bit - '0');
	}
	return decimalNumber;
}

int main()
{}