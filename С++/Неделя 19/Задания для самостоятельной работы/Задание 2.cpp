#include <iostream>

using namespace std;

struct Iron {
	string firm; // фирма
	string model; // модель
	string colour; // цвет
	string steamSupply; // подача пара да/нет
	int MINtemper; // минимальная температура
	int MAXtemper; // максимальная температура
	int power; // мощность 
};

void printIron(Iron entity) {
	cout << "Characteristics of the iron:" << endl;
	cout << "\tFirm: " << entity.firm << endl;
	cout << "\tModel: " << entity.model << endl;
	cout << "\tColour: " << entity.colour << endl;
	cout << "\tSteamSupply: " << entity.steamSupply << endl;
	cout << "\tMinimum temperature: " << entity.MINtemper << endl;
	cout << "\tMaximum temperature: " << entity.MAXtemper << endl;
	cout << "\tPower: " << entity.power << endl;
}

int main()
{
	Iron instance1{ "Teslo","PS2000A","Blue","Yes",30,60,120 };
	Iron instance2{ "Samsung","XS300S","Black","No",20,50,330 };

	printIron(instance1);
	cout << endl;
	printIron(instance2);
}