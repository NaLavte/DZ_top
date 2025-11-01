#include <iostream>

using namespace std;

int* allocateMemory(int size) {
	return new int[size];
}

void initializeArray(int* arr, int size, int value) {
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteArray(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

int* appendElement(int* arr, int& size, int value) {
    int* new_arr = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        new_arr[i] = arr[i];
    }
    new_arr[size] = value;
    delete[] arr;
    ++size;
    return new_arr;
}

int* insertElement(int* arr, int& size, int index, int value) {
    if (index < 0 || index > size) return arr; // некорректный индекс
    int* new_arr = new int[size + 1];
    for (int i = 0; i < index; ++i) {
        new_arr[i] = arr[i];
    }
    new_arr[index] = value;
    for (int i = index; i < size; ++i) {
        new_arr[i + 1] = arr[i];
    }
    delete[] arr;
    ++size;
    return new_arr;
}

int* deleteElement(int* arr, int& size, int index) {
    if (index < 0 || index >= size) return arr; // некорректный индекс
    int* new_arr = new int[size - 1];
    for (int i = 0; i < index; ++i) {
        new_arr[i] = arr[i];
    }
    for (int i = index + 1; i < size; ++i) {
        new_arr[i - 1] = arr[i];
    }
    delete[] arr;
    --size;
    return new_arr;
}

int main()
{
    
}
