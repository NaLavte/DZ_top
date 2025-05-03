#include <iostream>

using namespace std;

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

    int C_size = N + M;
    int* C = new int[C_size];

    for (int i = 0; i < M; i++) {
        C[i] = A[i];
    }
    
    for (int i = 0; i < N; i++) {
        C[M + i] = B[i];
    }

    cout << "Результат: ";
    for (int i = 0; i < C_size; i++) {
        cout << C[i] << " ";
    }

    delete[]A;
    delete[]B;
    delete[]C;
}