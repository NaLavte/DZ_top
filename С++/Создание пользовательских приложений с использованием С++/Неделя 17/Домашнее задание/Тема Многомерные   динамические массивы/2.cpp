#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// функция для транспонирования матрицы
std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) return {};

    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

// структура для хранения контакта
struct Contact {
    std::string name;
    std::string phone;
};

// класс для управления списком контактов
class Directory {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const std::string& name, const std::string& phone) {
        contacts.push_back({ name, phone });
    }

    void modifyContact(const std::string& name, const std::string& newPhone) {
        for (auto& contact : contacts) {
            if (contact.name == name) {
                contact.phone = newPhone;
                std::cout << "Контакт обновлён.\n";
                return;
            }
        }
        std::cout << "Контакт не найден.\n";
    }

    void searchByName(const std::string& name) {
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                std::cout << "Телефон для " << name << ": " << contact.phone << "\n";
                found = true;
            }
        }
        if (!found) std::cout << "Контакт не найден.\n";
    }

    void searchByPhone(const std::string& phone) {
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.phone == phone) {
                std::cout << "Имя для " << phone << ": " << contact.name << "\n";
                found = true;
            }
        }
        if (!found) std::cout << "Контакт не найден.\n";
    }

    void displayAll() const {
        for (const auto& contact : contacts) {
            std::cout << "Имя: " << contact.name << ", Телефон: " << contact.phone << "\n";
        }
    }
};

int main() {
    // тестирование функции транспонирования
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    auto transposed = transposeMatrix(matrix);
    std::cout << "Транспонированная матрица:\n";
    for (const auto& row : transposed) {
        for (int val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }

    // работа с контактами 
    Directory dir;
    dir.addContact("Иван", "123456789");
    dir.addContact("Мария", "987654321");
    dir.displayAll();

    std::string name, phone;
    std::cout << "Введите имя для поиска: ";
    std::cin >> name;
    dir.searchByName(name);

    std::cout << "Введите номер для поиска: ";
    std::cin >> phone;
    dir.searchByPhone(phone);

    std::cout << "Введите имя для изменения: ";
    std::cin >> name;
    std::cout << "Введите новый номер: ";
    std::cin >> phone;
    dir.modifyContact(name, phone);
    dir.displayAll();

    return 0;
}