#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 3;

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 0)
                cout << "  " ;
            else
                cout << cell << " ";
        }
        cout << "\n";
    }
}

pair<int,int> findPosition(const vector<vector<int>>& board, int value) {
    for (int i=0; i<SIZE; ++i)
        for (int j=0; j<SIZE; ++j)
            if (board[i][j] == value)
                return {i,j};
    return {-1,-1};
}

bool canMove(const pair<int,int>& tilePos, const pair<int,int>& zeroPos) {
    int dx = abs(tilePos.first - zeroPos.first);
    int dy = abs(tilePos.second - zeroPos.second);
    return (dx + dy) == 1; // соседние ячейки
}

bool isFinished(const vector<vector<int>>& board) {
    int count = 1;
    for (int i=0; i<SIZE; ++i) {
        for (int j=0; j<SIZE; ++j) {
            if (i==SIZE-1 && j==SIZE-1)
                continue; // последние пустая ячейка
            if (board[i][j] != count++)
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> board = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0} // 0 — пустая ячейка
    };

    cout << "Игра «Пятнашки\" (упрощенная версии)\n";

    while (true) {
        printBoard(board);
        if (isFinished(board)) {
            cout << "Поздравляем! Вы собрали пазл!\n";
            break;
        }
        cout << "Введите число, которое хотите переместить (или 0 для выхода): ";
        int moveNum;
        cin >> moveNum;
        if (moveNum == 0) break;

        auto tilePos = findPosition(board, moveNum);
        auto zeroPos = findPosition(board, 0);

        if (tilePos.first == -1) {
            cout << "Неверный ввод. Такой числовой ячейки нет.\n";
            continue;
        }

        if (canMove(tilePos, zeroPos)) {
            swap(board[tilePos.first][tilePos.second], board[zeroPos.first][zeroPos.second]);
        } else {
            cout << "Этот номер недоступен для перемещения.\n";
        }
    }

    return 0;
}