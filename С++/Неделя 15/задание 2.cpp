#include <iostream>

using namespace std;

void sumArrays(int* arrayA, int* arrayB, int* arrayC, int size) {
    for (int i = 0; i < size; i++) {
        arrayC[i] = arrayA[i] + arrayB[i];
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    const int size = 4;

    int A[size]{ 1,2,3,4 };
    int B[size]{ 10,20,30,40 };
    int C[size]{};
    
    sumArrays(A, B, C, size);

    cout << "Массив С: ";
    for (int i = 0; i < size; i++) {
        cout << C[i] << " ";
    }
}
