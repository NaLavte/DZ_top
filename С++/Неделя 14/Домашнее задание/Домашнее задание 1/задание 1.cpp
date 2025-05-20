#include <iostream>

using namespace std;

bool contains(int* array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return false;
        }
    }
    return true;
}

int main()
{
	setlocale(LC_ALL, "RU");

    int M, N;

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
        if (contains(B, N, current)) {
            temp[count] = current;
            count++;
        }
    }

    int* C = new int[count];
    for (int i = 0; i < count; i++) {
        C[i] = temp[i];
    }

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
