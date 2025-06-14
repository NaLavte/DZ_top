#include <iostream>

using namespace std;

struct Boiler {
	string firm; // фирма 
	string colour; // цвет
	int power; // мощность 
	int volume; // объем
	int HeaTemp; // температура нагрева
};

void printBoiler(Boiler entity) {
	cout << "Boiler Characteristics:" << endl;
	cout << "\tFirm: " << entity.firm << endl;
	cout << "\tColour: " << entity.colour << endl;
	cout << "\tPower: " << entity.power << endl;
	cout << "\tVolume: " << entity.volume << endl;
	cout << "\tHeating temperature: " << entity.HeaTemp << endl;
}

int main()
{
	Boiler instance1{ "Teslo","Blue",200,50,30 };
	Boiler instance2{ "Samsung","Black",30,3,15 };

	printBoiler(instance1);
	cout << endl;
	printBoiler(instance2);
}