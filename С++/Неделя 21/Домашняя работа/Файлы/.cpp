#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Задание 1: Удаление последней строки файла
void removeLastLine(const string& inputFile, const string& outputFile) {
    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cerr << "Не удалось открыть файл " << inputFile << endl;
        return;
    }

    vector<string> lines;
    string line;
    while (getline(fin, line)) {
        lines.push_back(line);
    }
    fin.close();

    if (!lines.empty()) {
        lines.pop_back();  // Удаляем последнюю строку
    }

    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cerr << "Не удалось открыть файл " << outputFile << endl;
        return;
    }

    for (size_t i = 0; i < lines.size(); ++i) {
        fout << lines[i];
        if (i != lines.size() - 1) {
            fout << "\n";
        }
    }
    fout.close();
}

// Задание 2: Поиск длины самой длинной строки
size_t lengthOfLongestLine(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return 0;
    }
    string line;
    size_t maxLength = 0;
    while (getline(fin, line)) {
        if (line.length() > maxLength) {
            maxLength = line.length();
        }
    }
    fin.close();
    return maxLength;
}

// Задание 3: Подсчет количества вхождений слова
int countWordOccurrences(const string& filename, const string& word) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return 0;
    }
    string line;
    int count = 0;
    while (getline(fin, line)) {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != string::npos) {
            // Проверка, чтобы считать только целое слово 
            bool isStartOK = (pos == 0 || !isalnum(line[pos - 1]));
            bool isEndOK = (pos + word.length() >= line.size() || !isalnum(line[pos + word.length()]));
            if (isStartOK && isEndOK) {
                ++count;
            }
            pos += word.length();
        }
    }
    fin.close();
    return count;
}

// Задание 4: Замена слова в файле
void replaceWordInFile(const string& filename, const string& searchWord, const string& replaceWord) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return;
    }

    vector<string> lines;
    string line;

    while (getline(fin, line)) {
        size_t pos = 0;
        while ((pos = line.find(searchWord, pos)) != string::npos) {
            // Проверка, чтобы заменить только целое слово
            bool isStartOK = (pos == 0 || !isalnum(line[pos - 1]));
            bool isEndOK = (pos + searchWord.length() >= line.size() || !isalnum(line[pos + searchWord.length()]));
            if (isStartOK && isEndOK) {
                line.replace(pos, searchWord.length(), replaceWord);
                pos += replaceWord.length();
            }
            else {
                pos += searchWord.length();
            }
        }
        lines.push_back(line);
    }
    fin.close();

    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Не удалось открыть файл для записи " << filename << endl;
        return;
    }
    for (size_t i = 0; i < lines.size(); ++i) {
        fout << lines[i];
        if (i != lines.size() - 1) {
            fout << "\n";
        }
    }
    fout.close();
}

// Вызов функций (пример использования)
int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    // Задание 1 
    removeLastLine(inputFile, outputFile);

    // Задание 2 
    size_t maxLength = lengthOfLongestLine(inputFile);
    cout << "Длина самой длинной строки: " << maxLength << endl;

    // Задание 3 
    string wordToCount;
    cout << "Введите слово для подсчета встреч: ";
    cin >> wordToCount;
    int count = countWordOccurrences(inputFile, wordToCount);
    cout << "Количество вхождений слова \"" << wordToCount << "\": " << count << endl;

    // Задание 4 
    string searchWord, replaceWord;
    cout << "Введите слово для поиска: ";
    cin >> searchWord;
    cout << "Введите слово для замены: ";
    cin >> replaceWord;
    replaceWordInFile(inputFile, searchWord, replaceWord);
    cout << "Заменено все вхождения слова \"" << searchWord << "\" на \"" << replaceWord << "\"." << endl;

    return 0;
}