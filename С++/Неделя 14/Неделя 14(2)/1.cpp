#include <iostream>

using namespace std;

void arrayStats(int* array, const int* size, int* sum, int* p) {
    *sum = 0;
    *p = 1;
    for (int i = 0; i < *size; i++) {
        *sum += array[i];
        *p *= array[i];
    }
}

void getDiffNumbers(int* array, const int* size, int* negative, int* positive, int* zero) {
    for (int i = 0; i < *size; i++) {
        if (array[i] < 0)
            *positive += 1;
        else if (array[i] > 0)
            *negative += 1;
        else
            *zero += 1;
    }
}

/*void subset(int* A, int* B, int sizeA, int sizeB) {
    for (int i = 0; i < sizeB;i++) {
        for (int j = 0; j < sizeA; j++) {
            if(B[i])
        }
    }
}*/

int main()
{
    setlocale(LC_ALL, "RU");

    const int size = 5;
    int negative = 0;
    int positive = 0;
    int zero = 0;
    int numbers[] = { -1, -2, 0, 4, 5};
    int sum, p;

    cout << "Массив: ";
    for (int i = 0; i < 5 ; i++) {
        cout << numbers[i] << " ";
    }

    arrayStats(numbers, &size, &sum, &p);

    

    cout << endl << "Сумма: " << sum << endl;

    getDiffNumbers(numbers, &size, &negative, &positive, &zero);

    cout << "negative = " << negative << endl;
    cout << "positive = " << positive << endl;
    cout << "zero = " << zero << endl;

}