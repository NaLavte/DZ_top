#include <iostream>

using namespace std;

typedef double(*MenuFunction)();


double add();
double subtract();
double multiply();
double divide();
double power();
double squareRoot();
double factorial();
double sinFunc();
double cosFunc();
double exitProgram();

const char* menuItems[] = {
    "Сложение",
    "Вычитание",
    "Умножение",
    "Деление",
    "Квадратный корень",
    "Возвышение в степень",
    "Факториал",
    "Синус",
    "Косинус",
    "Выход из программы"
};

MenuFunction functions[] = {
    add,
    subtract,
    multiply,
    divide,
    power,
    squareRoot,
    factorial,
    sinFunc,
    cosFunc,
    exitProgram
};

const int MENU_ITEMS_COUNT = sizeof(menuItems) / sizeof(menuItems[0]);

double add() {
    double a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;
    return a + b;
}

double subtract() {
    double a, b;
    cout << "Введите уменьшаемое и вычитаемое: ";
    cin >> a >> b;
    return a - b;
}

double multiply() {
    double a, b;
    cout << "введите два множителя: ";
    cin >> a >> b;
    return a * b;
}

double divide() {
    double a, b;
    cout << "Введите делитель и делимое: ";
    cin >> a >> b;
    return a / b;
}

double power() {
    double base, exponent;
    cout << "Введите основание и степень: ";
    cin >> base >> exponent;
    return pow(base, exponent);
}

double squareRoot() {
    double a;
    cout << "Введите число которое надо возвести в степень: ";
    cin >> a;
    return sqrt(a);
}

double factorial() {
    double a, b=1;
    cout << "Введите число под факториалом: ";
    cin >> a;
    for (int i = 1; i <= a; i++) {
        b *= i;
    }
    return b;
}

double sinFunc() {
    double angle;
    cout << "Введите угол: ";
    cin >> angle;
    return sin(angle);
}

double cosFunc() {
    double angle;
    cout << "Введите угол: ";
    cin >> angle;
    return cos(angle);
}

double exitProgram() {
    exit(0);
}

int main()
{
    setlocale(LC_ALL, "RU");

    while (true) {
        cout << "\nМеню\n";

        for (int i = 0;i < MENU_ITEMS_COUNT; i++) {
            cout << i + 1 << ". " << menuItems[i] << endl;
        }

        int choice;
        cout << "\nВыберите действие: ";
        cin >> choice;

        if (choice<1 || choice>MENU_ITEMS_COUNT) {
            cout << "Неверный выбор!";
            continue;
        }

        double result = functions[choice - 1]();
        cout << "Результат: " << result << endl;
    }
    return 0;
}
