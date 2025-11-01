#include <iostream>

using namespace std;

bool primeNumbers(int num) {
    if (num <= 0) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
    }
    }
    return true;
}

int* deletePrimeNumbers(int* arr, int size, int& newSize) {
    int* temp = new int[size];
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (!primeNumbers(arr[i])) {
            temp[count] = arr[i];
            ++count;
        }
    }
    newSize = count;
    int* result = new int[newSize];
    for (int i = 0; i < newSize; ++i) {
        result[i] = temp[i];
    }
    delete[] temp;
    return result;
}

int main()
{
    int nes;
    int size = 10;
    int* array = new int[size] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int* b = deletePrimeNumbers(array, size,nes);

    for (int i = 0; i < nes; i++) {
        cout << *(b + i) << " ";
    }
}
