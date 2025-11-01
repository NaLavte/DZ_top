#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

struct Employee {
    string surname;
    string name;
    int age;

    void input() {
        cout << "Введите фамилию: ";
        cin >> surname;
        cout << "Введите имя: ";
        cin >> name;
        cout << "Введите возраст: ";
        cin >> age;
    }

    void display() const {
        cout << "Фамилия: " << surname << ", Имя: " << name << ", Возраст: " << age << endl;
    }
};

// Функции для работы с файлами
void saveToFile(const vector<Employee>& employees, const string& filename) {
    ofstream ofs(filename);
    for (const auto& emp : employees) {
        ofs << emp.surname << ' ' << emp.name << ' ' << emp.age << '\n';
    }
    ofs.close();
}

vector<Employee> loadFromFile(const string& filename) {
    vector<Employee> employees;
    ifstream ifs(filename);
    if (!ifs) {
        cout << "Файл не найден, будет создан новый.\n";
        return employees;
    }
    Employee emp;
    while (ifs >> emp.surname >> emp.name >> emp.age) {
        employees.push_back(emp);
    }
    ifs.close();
    return employees;
}

// Функции поиска и фильтрации
vector<Employee> findBySurnameInitial(const vector<Employee>& employees, char initial) {
    vector<Employee> result;
    for (const auto& emp : employees) {
        if (!emp.surname.empty() && tolower(emp.surname[0]) == tolower(initial)) {
            result.push_back(emp);
        }
    }
    return result;
}

vector<Employee> findByAge(const vector<Employee>& employees, int age) {
    vector<Employee> result;
    for (const auto& emp : employees) {
        if (emp.age == age) {
            result.push_back(emp);
        }
    }
    return result;
}

int main() {
    string filename;
    cout << "Введите имя файла для загрузки/сохранения: ";
    cin >> filename;

    vector<Employee> employees = loadFromFile(filename);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить сотрудника\n";
        cout << "2. Редактировать сотрудника\n";
        cout << "3. Удалить сотрудника\n";
        cout << "4. Поиск по фамилии (начинается на букву)\n";
        cout << "5. Вывести всех сотрудников\n";
        cout << "6. Вывести сотрудников по возрасту\n";
        cout << "7. Сохранить и выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee emp;
                emp.input();
                employees.push_back(emp);
                break;
            }
            case 2: {
                string surname;
                cout << "Введите фамилию сотрудника для редактирования: ";
                cin >> surname;
                auto it = find_if(employees.begin(), employees.end(),
                                  [&](const Employee& e) { return e.surname == surname; });
                if (it != employees.end()) {
                    cout << "Введите новые данные:\n";
                    it->input();
                } else {
                    cout << "Сотрудник не найден.\n";
                }
                break;
            }
            case 3: {
                string surname;
                cout << "Введите фамилию сотрудника для удаления: ";
                cin >> surname;
                auto it = remove_if(employees.begin(), employees.end(),
                                    [&](const Employee& e) { return e.surname == surname; });
                if (it != employees.end()) {
                    employees.erase(it, employees.end());
                    cout << "Удалено.\n";
                } else {
                    cout << "Сотрудник не найден.\n";
                }
                break;
            }
            case 4: {
                char initial;
                cout << "Введите первую букву фамилии: ";
                cin >> initial;
                auto result = findBySurnameInitial(employees, initial);
                if (!result.empty()) {
                    for (const auto& emp : result) {
                        emp.display();
                    }
                } else {
                    cout << "Не найдено сотрудников с такой буквой.\n";
                }
                break;
            }
            case 5:
                for (const auto& emp : employees) {
                    emp.display();
                }
                break;
            case 6: {
                int age;
                cout << "Введите возраст: ";
                cin >> age;
                auto result = findByAge(employees, age);
                if (!result.empty()) {
                    for (const auto& emp : result) {
                        emp.display();
                    }
                } else {
                    cout << "Нет сотрудников с таким возрастом.\n";
                }
                break;
            }
            case 7:
                saveToFile(employees, filename);
                cout << "Данные сохранены. Выход.\n";
                break;
            default:
                cout << "Неверный выбор.\n";
        }
    } while (choice != 7);

    return 0;
}