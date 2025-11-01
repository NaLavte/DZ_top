#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool isValid(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

bool knightsTourUtil(int x, int y, int movei, vector<vector<int>>& board) {
    if (movei == N * N) {
        return true;
    }

    for (int k = 0; k < 8; k++) {
        int next_x = x + dx[k];
        int next_y = y + dy[k];

        if (isValid(next_x, next_y, board)) {
            board[next_x][next_y] = movei;
            if (knightsTourUtil(next_x, next_y, movei + 1, board))
                return true;
            board[next_x][next_y] = -1;
        }
    }
    return false;
}

bool knightsTour(int start_x, int start_y, vector<vector<int>>& board) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    board[start_x][start_y] = 0;

    if (knightsTourUtil(start_x, start_y, 1, board))
        return true;
    else
        return false;
}

void printSolution(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout.width(2);
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    int x, y;

    cout << "Введите координаты клетки (от 0 до 7)(если указать 0:0 то будет работать быстрее):" << endl;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    if (x < 0 || x >= N || y < 0 || y >= N) {
        cout << "Некорректные координаты." << endl;
        return 1;
    }

    vector<vector<int>> board(N, vector<int>(N, -1));

    if (knightsTour(x, y, board)) {
        cout << "Путь коня, обойдя весь доска:" << endl;
        printSolution(board);
    }
    else {
        cout << "Невозможно найти полный маршрут начиная с данной клетки." << endl;
    }

    return 0;
}










// я не знаю что это вообще за задача такая 😭