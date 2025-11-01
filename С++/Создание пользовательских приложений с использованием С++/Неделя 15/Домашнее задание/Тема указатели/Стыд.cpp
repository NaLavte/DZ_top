#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int findMax(const int* arr, int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int findMin(const int* arr, int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal)
            minVal = arr[i];
    }
    return minVal;
}

double findAvg(const int* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

typedef double (*FuncPtr)(const int*, int);

double Action(const int* A, const int* B, int sizeA, int sizeB, FuncPtr func) {
    combined.insert(combined.end(), B, B + sizeB);
    return func(combined.data(), combined.size());
}

int main() {
    int sizeA, sizeB;
    cout << "Введите размер массива A: ";
    cin >> sizeA;
    cout << "Введите размер массива B: ";
    cin >> sizeB;

    int* A = new int[sizeA];
    int* B = new int[sizeB];

    cout << "Введите элементы массива A:\n";
    for (int i = 0; i < sizeA; ++i) {
        cin >> A[i];
    }
    cout << "Введите элементы массива B:\n";
    for (int i = 0; i < sizeB; ++i) {
        cin >> B[i];
    }

    int choice;
    cout << "Выберите операцию:\n";
    cout << "1 - Максимум (max)\n";
    cout << "2 - Минимум (min)\n";
    cout << "3 - Среднее (avg)\n";
    cin >> choice;

    FuncPtr func = nullptr;

    switch (choice) {
        case 1:
            {
                auto maxFunc = [](const int* arr, int size) -> double {
                    return findMax(arr, size);
                };
                double result = Action(A, B, sizeA, sizeB, [maxFunc](const int* arr, int size) -> double {
                    return maxFunc(arr, size);
                });
                cout << "Результат: " << result << endl;
            }
            break;
        case 2:
            {
                auto minFunc = [](const int* arr, int size) -> double {
                    return findMin(arr, size);
                };
                double result = Action(A, B, sizeA, sizeB, [minFunc](const int* arr, int size) -> double {
                    return minFunc(arr, size);
                });
                cout << "Результат: " << result << endl;
            }
            break;
        case 3:
            {
                auto avgFunc = [](const int* arr, int size) -> double {
                    return findAvg(arr, size);
                };
                double result = Action(A, B, sizeA, sizeB, [avgFunc](const int* arr, int size) -> double {
                    return avgFunc(arr, size);
                });
                cout << "Результат: " << result << endl;
            }
            break;
        default:
            cout << "Некорректный выбор." << endl;
            break;
    }

    delete[] A;
    delete[] B;
    return 0;
}