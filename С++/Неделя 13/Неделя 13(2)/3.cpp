#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int array1[15]{ 1,2,3,4,5, };
	int array2[]{ 6,7,8,9 };

	int* ptr1 = array1;
	int* ptr2 = array2;

	//int size1 = sizeof(array1) / sizeof(array1[0]);
	int size1 = 5;
	int size2 = sizeof(array2) / sizeof(array2[0]);

	cout << "Изначальный ptr1: ";
	for (int i = 0; i < size1; i++) {
		cout << *(ptr1 + i) << " ";
	}
	cout << endl << "Изначальный ptr2: ";
	for (int i = 0; i < size2; i++) {
		cout << *(ptr2 + i) << " ";
	}

	int j = size1;
	for (int i = size2 - 1; i >= 0; i--) {
		*(ptr1 + size1) = *(ptr2 + i);
		size1++;
	}

	cout << endl << "Изменённый ptr1: ";
	for (int i = 0; i < size1; i++) {
		cout << *(ptr1 + i) << " ";
	}

	return 0;
}