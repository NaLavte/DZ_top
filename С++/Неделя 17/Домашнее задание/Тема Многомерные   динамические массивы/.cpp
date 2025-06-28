#include <iostream>
#include <vector>

// Функция для добавления столбца в указанную позицию
void InsertColumn(std::vector<std::vector<int>>& matrix, int colIndex, const std::vector<int>& newColumn) {
    int rows = matrix.size();
    if (rows == 0 || newColumn.size() != rows || colIndex < 0 || colIndex > matrix[0].size()) {
        std::cerr << "Некорректные параметры" << std::endl;
        return;
    }
    for (int i = 0; i < rows; ++i) {
        matrix[i].insert(matrix[i].begin() + colIndex, newColumn[i]);
    }
}

// Функция для удаления столбца по номеру
void DeleteColumn(std::vector<std::vector<int>>& matrix, int colIndex) {
    int rows = matrix.size();
    if (rows == 0 || colIndex < 0 || colIndex >= matrix[0].size()) {
        std::cerr << "Некорректные параметры" << std::endl;
        return;
    }
    for (int i = 0; i < rows; ++i) {
        matrix[i].erase(matrix[i].begin() + colIndex);
    }
}

// Функция для циклического сдвига строк и/или столбцов
void ShiftMatrix(std::vector<std::vector<int>>& matrix, int rowShift, int colShift) {
    int M = matrix.size();
    int N = M > 0 ? matrix[0].size() : 0;
    if (M == 0 || N == 0) return;

    // Функция для циклического сдвига вектора
    auto cyclicShift = [](std::vector<int>& vec, int shift) {
        int size = vec.size();
        if (size == 0) return;
        shift = shift % size;
        if (shift < 0) shift += size;
        std::rotate(vec.begin(), vec.begin() + (size - shift), vec.end());
        };

    // Сдвиг строк
    for (int i = 0; i < M; ++i) {
    cyclicShift(matrix[i], rowShift);
    }


    // Сдвиг столбцов
    if (colShift != 0) {
        for (int j = 0; j < N; ++j) {
            std::vector<int> column(M);
            for (int i = 0; i < M; ++i) {
                column[i] = matrix[i][j];
            }
            cyclicShift(column, colShift);
            for (int i = 0; i < M; ++i) {
                matrix[i][j] = column[i];
            }
        }
    }
}