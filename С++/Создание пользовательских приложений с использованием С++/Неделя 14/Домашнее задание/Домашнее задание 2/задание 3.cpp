#include <iostream>

using namespace std;

void distributeElements(int* arr, int size, int*& positives, int& posSize, int*& negatives, int& negSize, int*& zeros, int& zeroSize) {
    posSize = 0;
    negSize = 0;
    zeroSize = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) ++posSize;
        else if (arr[i] < 0) ++negSize;
        else ++zeroSize;
    }

    positives = new int[posSize];
    negatives = new int[negSize];
    zeros = new int[zeroSize];

    int pIndex = 0, nIndex = 0, zIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            positives[pIndex++] = arr[i];
        }
        else if (arr[i] < 0) {
            negatives[nIndex++] = arr[i];
        }
        else {
            zeros[zIndex++] = arr[i];
        }
    }
}

int main() {
    int staticArray[] = { 1, -2, 0, 4, -5, 0, 3 };
    int size = sizeof(staticArray) / sizeof(staticArray[0]);

    int* positives = nullptr;
    int* negatives = nullptr;
    int* zeros = nullptr;

    int posSize = 0, negSize = 0, zeroSize = 0;

    distributeElements(staticArray, size, positives, posSize, negatives, negSize, zeros, zeroSize);

    cout << "Массив: ";
    for (int i = 0; i < size; ++i) {
        cout << staticArray[i] << " ";
    }

    cout << "\nПоложительные элементы: ";
    for (int i = 0; i < posSize; ++i) {
        cout << positives[i] << " ";
    }
    cout << "\nОтрицательные элементы: ";
    for (int i = 0; i < negSize; ++i) {
        cout << negatives[i] << " ";
    }
    cout << "\nНулевые элементы: ";
    for (int i = 0; i < zeroSize; ++i) {
        cout << zeros[i] << " ";
    }
    cout << endl;

    delete[] positives;
    delete[] negatives;
    delete[] zeros;

    return 0;
}