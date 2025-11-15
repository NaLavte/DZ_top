#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t size;
    static int objectCount; // статическая переменная для подсчета объектов

public:
    // Конструктор по умолчанию (длина 80 символов)
    String() : size(80) {
        data = new char[size + 1]; // +1 для нулевого символа
        std::memset(data, 0, size + 1);
        ++objectCount;
    }

    // Конструктор с заданным размером
    String(size_t length) : size(length) {
        data = new char[size + 1];
        std::memset(data, 0, size + 1);
        ++objectCount;
    }

    // Конструктор с инициализацией строкой
    String(const char* str) {
        size = std::strlen(str);
        data = new char[size + 1];
        std::strcpy(data, str);
        ++objectCount;
    }

    // Деструктор
    ~String() {
        delete[] data;
        --objectCount;
    }

    // Ввод строки
    void input() {
        std::cout << "Введите строку: ";
        // Используем std::cin.getline для безопасного ввода
        // В случае, если строка длиннее, чем выделенная память, нужно предусмотреть ограничение
        // Но так как размер может быть произвольным, используем динамическую выделенную память
        if (data != nullptr) {
            delete[] data;
        }
        data = new char[size + 1];
        std::cin.getline(data, size + 1);
    }

    // Вывод строки
    void display() const {
        std::cout << data << std::endl;
    }

    // Статическая функция для получения количества объектов
    static int getObjectCount() {
        return objectCount;
    }
};

// Инициализация статической переменной
int String::objectCount = 0;

int main() {
    String defaultStr; // Создается при помощи конструктора по умолчанию
    String customSizeStr(50); // Создается строка произвольного размера
    String initializedStr("Пример строки"); // Создается строка с инициализацией

    // Ввод и вывод
    defaultStr.input();
    defaultStr.display();

    customSizeStr.input();
    customSizeStr.display();

    initializedStr.display();

    // Количество созданных объектов
    std::cout << "Количество созданных объектов String: " << String::getObjectCount() << std::endl;

    return 0;
}