#include <iostream>
#include <string>

using namespace std;

struct Car {
	string colour; // цвет
	string model; // модель
	string number; // номер
};

// Задание 1.0
void printCar(Car car) {
	cout << "\nМодель машины - [" << car.model << "]\n"
			"Номер машины - [" << car.number << "]\n"
			"Цвет машины - [" << car.colour << "]\n";
}

void cinCar(Car* car) {
	int choice;
	string newElement;
	cout << "\n1. Модель машины,\n"
		"2. Номер машины,\n"
		"3. Цвет машины,\n"
		"Что вы хотите изменить: ";
	cin >> choice;
	if (choice == 1) {
		cout << "На какую модель вы хотите её изменить: ";
		cin >> newElement;
		car->model = newElement;
	}
	else if (choice == 2) {
		cout << "На какой номер вы хотите изменить: ";
		cin >> newElement;
		car->number = newElement;
	}
	else {
		cout << "На какой цвет вы хотите изменить: ";
		cin >> newElement;
		car->colour = newElement;
	}
}

// Задание 1.1
void editCar(Car* car, int size) {
	int choice, index;
	string newElement;

	cout << "Какую машину по индексу вы хотите редактировать: ";
	cin >> index;

	if (index < 0 || index > size) {
		cout << "\nНеправильно введён индекс!";
		return;
	}

	cout << "\n1. Модель машины,\n"
		"2. Номер машины,\n"
		"3. Цвет машины,\n"
		"Что вы хотите изменить: ";
	cin >> choice;

	if (choice < 1 || choice > 3) {
		cout << "\nНеправильно введено действие!";
		return;
	}

	if (choice == 1) {
		cout << "На какую модель вы хотите её изменить: ";
		cin >> newElement;
		car->model = newElement;
	}
	else if (choice == 2) {
		cout << "На какой номер вы хотите изменить: ";
		cin >> newElement;
		car->number = newElement;
	}
	else {
		cout << "На какой цвет вы хотите изменить:";
		cin >> newElement;
		car->colour = newElement;
	}
}

void coutCar(Car* car, int size) {
	for (int i = 0; i < size; i++) {
		cout << "\nМашина - " << i + 1 << 
			"\n\tМодель машины - [" << car[i].model << "]\n"
			"\tНомер машины - [" << car[i].number << "]\n"
			"\tЦвет машины - [" << car[i].colour << "]\n";
	}
}

void searchNum(Car* car, int size) {
	string num;
	cout << "Машину с каким номером вы хотите найти: ";
	cin >> num;
	for (int i = 0; i < size; i++) {
		if (car[i].number == num) {
			cout << "Индекс машины с номером [" << num << "] = " << i;
			return;
		}
	}
	cout << "Машина не найдена!";
}


int main()
{    
	Car car{ "Blo","Tesla","A000AA" };

	// Задание 1
	int counter = 0;
	do{
		cout << "\n1. Печать машины\n"
			"2. Изменить деталь машины\n"
			"3. Перейти к заданию 1.1\n"
			"Что вы хотите сделать: ";
		cin >> counter;

		if (counter < 1 || counter > 3) {
			cout << "\nНеправильно введено действие!";
			return 1;
		}

		switch (counter) {
		case 1:
			printCar(car); break;
		case 2:
			cinCar(&car); break;
		}
	} while (counter < 3);


	// Задание 2
	const int size = 10;
	Car car2[size] = {
		{"Красный", "A", "A000AA"},
		{"Синий", "B", "FD876G"},
		{"Черный", "C", "Z305OL"},
		{"Белый", "D", "A287TH"},
		{"Серый", "E", "V345KT"},
		{"Зеленый", "F", "A123QW"},
		{"Желтый", "G", "M567NG"},
		{"Фиолетовый", "H", "J432UF"},
		{"Розовый", "I", "O987LK"},
		{"Коричневый", "J", "J768GD"}
	};

	counter = 0;

	do {
		cout << "\n1. Печать всех машин\n"
			"2. Редактировать машину\n"
			"3. Поиск машины по номеру \n"
			"4. Выход\n"
			"Что вы хотите сделать: ";
		cin >> counter;

		if (counter < 1 || counter > 5) {
			cout << "\nНеправильно введено действие!\n";
			return 1;
		}

		switch (counter) {
		case 1:
			coutCar(car2, size); break;
		case 2:
			editCar(car2, size); break;
		case 3:
			searchNum(car2, size); break;
		}
	} while (counter < 4);
}