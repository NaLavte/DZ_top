#include <iostream>
#include <string>

// Задание 1
void removeCharAt(std::string& str, size_t index) {
    if (index < str.length()) {
        str.erase(index, 1);
    }
}

// задание 2
void removeAllOccurrences(std::string& str, char ch) {
    str.erase(std::remove(str.begin(), str.end(), ch), str.end());
}

// Задание 3
void insertCharAt(std::string& str, size_t position, char ch) {
    if (position <= str.length()) {
        str.insert(str.begin() + position, ch);
    }
    else {
        std::cout << "Позиция выходит за границы строки." << std::endl;
    }
}

// Задание 4
void replaceDotsWithExclamation(std::string& str) {
    for (char& ch : str) {
        if (ch == '.') {
            ch = '!';
        }
    }
}

// Задание 5
int countCharacterOccurrences(const std::string& str, char target) {
    int count = 0;
    for (char ch : str) {
        if (ch == target) {
            count++;
        }
    }
    return count;
}

// Задание 6
void analyzeString(const std::string& str, int& letters, int& digits, int& others) {
    letters = 0;
    digits = 0;
    others = 0;

    for (char ch : str) {
        if (std::isalpha(ch)) {
            letters++;
        }
        else if (std::isdigit(ch)) {
            digits++;
        }
        else {
            others++;
        }
    }
}

int main() {

}
