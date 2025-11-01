#include <iostream>

using namespace std;

bool contains(int* array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "RU");

    int M;
    int N;

    cout << "Введите размер массива A (M): ";
    cin >> M;
    cout << "введите размер массива B (N): ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Введите элементы массива A:\n";
    for (int i = 0; i < M; i++) {
        cout << "A[" << i + 1 << "]= ";
        cin >> A[i];
    }

    cout << "Введите элементы массива B:\n";
    for (int i = 0; i < N; i++) {
        cout << "B[" << i + 1 << "]= ";
        cin >> B[i];
    }

    int tempSize = M + N;
    int* temp = new int[tempSize];
    int count = 0;

    for (int i = 0; i < M; i++) {
        int current = A[i];
        if (contains(B, N, current) && !contains(temp, count, current)) {
            temp[count] = current;
            count++;
        }
    }

    int* C = new int[count];
    for (int i = 0; i < count; i++) {
        C[i] = temp[i];
    }

    int choice;
    do {
        cout << "Выбейте действие: " << endl;
        cout << "1. Удалить чётные элементы" << endl;
        cout << "2. Удалить нечётные элементы" << endl;
        cout << "2. не удалять" << endl;

        cin >> choice;

    } while (choice < 1 || choice>3);

    int new_count = 0;
    int* temp_filtered = new int[count];

    for (int i = 0; i < count; i++) {
        bool isEven = (C[i] % 2 == 0);

        if ((choice == 1 && !isEven) || (choice == 2 && isEven)) {
            temp_filtered[new_count++] = C[i];
        }
    }

    delete[]C;
    C = new int[new_count];
    count = new_count;

    for (int i = 0; i < count; i++) {
        C[i] = temp_filtered[i];
    }

    delete[]temp_filtered;

    cout << "Результат: ";
    if (count == 0) {
        cout << "Нет общих элементов";
    }
    else {
        for (int i = 0; i < count; i++) {
            cout << C[i] << " ";
        }
    }

    delete[]A;
    delete[]B;
    delete[]C;
    delete[]temp;
}