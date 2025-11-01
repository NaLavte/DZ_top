#include <iostream>

using namespace std;

struct WashingMachine {
	string firm; // фирма
	string colour; // цвет
	int width; // ширина
	int length; // длина
	int height; // высота
	int power; // мощность
	int spinSpeed; // скорость отжима
	int HeatTemp; // температура нагрева
};

void printWashingMachine(WashingMachine entity) {
	cout << "Firm: " << entity.firm << endl;
	cout << "Colour: " << entity.colour << endl;
	cout << "Width: " << entity.width << endl;
	cout << "Length: " << entity.length << endl;
	cout << "Height: " << entity.height << endl;
	cout << "Power: " << entity.power << endl;
	cout << "SpinSpeed: " << entity.spinSpeed << endl;
	cout << "Heating Temperature: " << entity.HeatTemp << endl;
}


int main()
{
	WashingMachine instance1{ "Tesla","Blue",130,100,140,600,800,30 };
	WashingMachine instance2{ "apple","pastel red",200,150,170,800,1000,70 };
	WashingMachine instance3{ "Samsung","brown raspberry",120,140,130,500,700,50 };
	
	printWashingMachine(instance2);
	cout << endl;
	printWashingMachine(instance1);
}