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
    *negative = *positive = *zero = 0;
    for (int i = 0; i < *size; i++) {
        if (array[i] < 0)
            *positive += 1;
        else if (array[i] > 0)
            *negative += 1;
        else
            *zero += 1;
    }
}

int* findSubset(int* A, int sizeA, int* B, int sizeB) {
    for (int i = 0; i <= sizeA - sizeB; i++) {
        bool isMatch = true;

        for (int j = 0; j < sizeB; j++) {
            if (A[i + j] != B[j]) {
                isMatch = false;
                break;
            }
        }

        if (isMatch) {
            return &A[i];
        }
    }

    return nullptr;
}

int* removeNegatives(int* array, int size, int& newSize) {
    int positiveCount = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] >= 0) {
            positiveCount++;
        }
    }

    int* newArray = new int[positiveCount];
    newSize = positiveCount;

    for (int i = 0, j = 0; i < size; i++) {
        if (array[i] >= 0) {
            newArray[j++] = array[i];
        }
    }

    return newArray;
}

int* addElements(int* arrayForAdd, int sizeForAdd, int* elementsToAdd, int addSize, int& newSize) {

    newSize = sizeForAdd + addSize;
    int* newArray = new int[newSize];

    if (sizeForAdd > 0) {
        copy(arrayForAdd, arrayForAdd + sizeForAdd, newArray);
    }

    if (addSize > 0) {
        copy(elementsToAdd, elementsToAdd + addSize, newArray + sizeForAdd);
    }

    return newArray;
}

void insertBlockAtIndex(int* arr, int& size, int capacity, int index, int* block, int blockSize) {
    if (index < 0 || index > size || size + blockSize > capacity) {
        cout << "Некорректный индекс или недостаточно места" << endl;
        return;
    }
    for (int i = size - 1; i >= index; i--) {
        arr[i + blockSize] = arr[i];
    }
    for (int i = 0; i < blockSize; i++) {
        arr[index + i] = block[i];
    }
    size += blockSize;
}

void deleteBlockFromIndex(int* arr, int& size, int index, int blockSize) {
    if (index < 0 || index >= size || index + blockSize > size) {
        cout << "Некорректный индекс или размер блока" << endl;
        return;
    }
    for (int i = index + blockSize; i < size; i++) {
        arr[i - blockSize] = arr[i];
    }
    size -= blockSize;
}

int main()
{
    setlocale(LC_ALL, "RU");
    
    const int capacity = 20;
    const int size = 5;
    
    int sum, p, newSize, zero, positive, negative, newSizel;
    int arrr[capacity] = { 1, 2, 3, 4, 5, 6, 7 };
    int* arr = new int[6] {-2, 5, -1, 0, 3, -4};
    int* arrayForAdd = new int[3] {1, 2, 3};
    int* elementsToAdd = new int[2] {4, 5};
    int numbers[size] = { -1, -2, 0, 4, 5 };
    int arrs[capacity] = { 1, 2, 3, 4, 5 };
    int A[] = { 2, 5, 3, 7, 2, 8, 5 };
    int B[] = { 7, 2, 8 };

    int BSize = sizeof(B) / sizeof(B[0]);
    

    int sizeForAdd = 3;
    int blockSize = 3;
    int addSize = 2;
    int sizent = 5;
    int sizes = 7;
    int index = 2;
    int ndex = 2;
    

    int* result = findSubset(A, 7, B, 3);
    arrayStats(numbers, &size, &sum, &p);
    getDiffNumbers(numbers, &size, &negative, &positive, &zero);
    int* newArr = removeNegatives(arr, 6, newSize);
    int* newArrForAdd = addElements(arrayForAdd, sizeForAdd, elementsToAdd, addSize, newSizel);
    insertBlockAtIndex(arrs, sizent, capacity, index, B, BSize);
    deleteBlockFromIndex(arrr, sizes, ndex, blockSize);


    cout << "Массив: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }


    cout << endl << "Сумма: " << sum << endl;

    cout << "negative = " << negative << endl;
    cout << "positive = " << positive << endl;
    cout << "zero = " << zero << endl << endl;

    cout << "Массив: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "Новый массив без отрицательных чисел: ";
    for (int i = 0; i < newSize; i++) {
        cout << newArr[i] << " ";
    }

    if (result) {
        cout << endl << endl << "Найдено в позиции: " << (result - A) << "\nЗначения: ";
        for (int i = 0; i < 3; i++) {
            cout << result[i] << " ";
        }
    }
    else {
        cout << endl << endl << "Подмножество не найдено";
    }

    cout << endl << endl << "Исходный массив после добавления элементов в конец массива: ";
    for (int i = 0; i < newSizel; i++)
    {
        cout << newArrForAdd[i] << " ";
    }
    cout << endl << endl;

    cout << "Массив после добавления элементов: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "Массив после удаления элементов: ";
    for (int i = 0; i < size; ++i) {
        cout << arrr[i] << " ";
    }

    delete[] arr;
    delete[] newArr;
}