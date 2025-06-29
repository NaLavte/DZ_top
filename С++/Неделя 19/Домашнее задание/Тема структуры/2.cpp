#include <iostream>
#include <string>

using namespace std;

// Перечисление для типа живой сущности
enum Type { Птица, Скотоводство, Человек };

// Структура для характеристик, в зависимости от типа
struct Characteristics {
    union {
        float speed_flight;  // Для птицы 
        bool is_hoof;        // Для скота 
        int IQ;              // Для человека
    };
};

// Основная структура "Живая сущность"
struct LivingEntity {
    float speed;             // Скорость передвижения
    Type type;               // Тип (птица, скот, человек)
    string color;            // Цвет 
    Characteristics characteristic; // Характеристика, зависит от типа
};

// Функции для ввода, вывода, редактирования и поиска
void inputEntity(LivingEntity& entity);
void printEntity(const LivingEntity& entity);
void editEntities(LivingEntity entities[], int size);
void printAll(const LivingEntity entities[], int size);
void searchByCharacteristic(const LivingEntity entities[], int size, float value);

int main() {
    // Создаем один экземпляр и запрашиваем информацию 
    LivingEntity entity;
    inputEntity(entity);
    printEntity(entity);

    // Создаем массив из 10 элементов
    const int size = 10;
    LivingEntity entities[size];

    // Инициализация массива случайными данными (или можно запрашивать у пользователя)
    for (int i = 0; i < size; i++) {
        inputEntity(entities[i]);
    }

    // Редактирование данных 
    editEntities(entities, size);
    // Печать всего списка 
    printAll(entities, size);
    // Поиск по характеристике (например, по скорости)
    float searchValue;
    cout << "Введите значение характеристики для поиска: ";
    cin >> searchValue;
    searchByCharacteristic(entities, size, searchValue);

    return 0;
}

void inputEntity(LivingEntity& entity) {
    cout << "Введите скорость передвижения: ";
    cin >> entity.speed;

    cout << "Введите тип (0 - птица, 1 - скот, 2 - человек): ";
    int t;
    cin >> t;
    entity.type = static_cast<Type>(t);

    cout << "Введите цвет: ";
    cin >> ws;
    getline(cin, entity.color);

    switch (entity.type) {
    case Птица:
        cout << "Введите скорость полета: ";
        cin >> entity.characteristic.speed_flight;
        break;
    case Скотоводство:
        cout << "Является парнокопытным? (1 - да, 0 - нет): ";
        cin >> entity.characteristic.is_hoof;
        break;
    case Человек:
        cout << "Введите уровень IQ: ";
        cin >> entity.characteristic.IQ;
        break;
    }
}

void printEntity(const LivingEntity& entity) {
    cout << "Скорость передвижения: " << entity.speed << endl;
    cout << "Тип: ";
    switch (entity.type) {
    case Птица:
        cout << "Птица" << endl;
        cout << "Скорость полета: " << entity.characteristic.speed_flight << endl;
        break;
    case Скотоводство:
        cout << "Скот" << endl;
        cout << "Парнокопытный: " << (entity.characteristic.is_hoof ? "да" : "нет") << endl;
        break;
    case Человек:
        cout << "Человек" << endl;
        cout << "Уровень IQ: " << entity.characteristic.IQ << endl;
        break;
    }
    cout << "Цвет: " << entity.color << endl;
}

void editEntities(LivingEntity entities[], int size) {
    int index;
    cout << "Введите индекс редактируемой сущности (0 - " << size - 1 << "): ";
    cin >> index;
    if (index >= 0 && index < size) {
        inputEntity(entities[index]);
    }
    else {
        cout << "Некорректный индекс." << endl;
    }
}

void printAll(const LivingEntity entities[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Энтити " << i << ":" << endl;
        printEntity(entities[i]);
        cout << "------------------------" << endl;
    }
}

void searchByCharacteristic(const LivingEntity entities[], int size, float value) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        bool match = false;
        switch (entities[i].type) {
        case Птица:
            if (entities[i].characteristic.speed_flight == value)
                match = true;
            break;
        case Скотоводство:
            if (entities[i].characteristic.is_hoof == static_cast<bool>(value))
                match = true;
            break;
        case Человек:
            if (entities[i].characteristic.IQ == static_cast<int>(value))
                match = true;
            break;
        }
        if (match) {
            cout << "Найденная сущность:" << endl;
            printEntity(entities[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Никаких совпадений не найдено." << endl;
    }
}