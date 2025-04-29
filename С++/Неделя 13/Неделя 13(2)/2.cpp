#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int array1[]{ 1,2,3,4,5,6,7 };

	const int size = sizeof(array1) / sizeof(array1[0]);
	
	int array2[size]{};

	int* ptr1 = array1;
	int* ptr2 = array2;

	cout << "Изначальный ptr1: ";
	for (int i = 0; i < size; i++) {
		cout << *(ptr1 + i) << " ";
	}

	cout << endl;

	for (int i = 0; i < size; i++) {
		*(ptr2 + i) = *(ptr1 + i);
	}

	int j = 0;
	for (int i = size - 1; i >= 0; i--) {
		*(ptr1 + j) = *(ptr2 + i);
		j++;
	}

	cout << "Изменённый ptr1: ";
	for (int i = 0; i < size; i++) {
		cout << *(ptr1 + i) << " ";
	}
	
	
	return 0;
}