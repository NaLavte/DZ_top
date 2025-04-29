#include <iostream>

using namespace std;

int main() // это работает на сломанных костылях
{
	setlocale(LC_ALL, "RU");

	int array1[]{ 1,2,3,4 };
	int array2[]{ 5,6,7,8 };

	int size1 = sizeof(array1) / sizeof(array1[0]);
	int size2 = sizeof(array2) / sizeof(array2[0]);

	int* ptr1 = array1;
	int* ptr2 = array2;

	for (int i = 0; i < size2; i++) {
		*(ptr1 + (i + size1)) = *(ptr2 + i);
	}

	for (int i = 0; i < 8; i++) {
		cout << *(ptr1 + i);
	}
	
	return 0;
}