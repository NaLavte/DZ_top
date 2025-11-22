#include <iostream>

class Passport {
private:
	std::string name;
	std::string surname;
	std::string patronymic;
	int birthday;
	int monthBirth;
	int yearBirth;
public:
	Passport(const std::string& Name = "", const std::string& Surname = "", const std::string& Patronymic = "", int Birthday = 0, int MonthBirth = 0, int YearBirth = 0) {};

	void print() {
		std::cout << "Passport:" << std::endl;
		std::cout << "\tFull name [" << name << " " << surname << " " << patronymic << "]" << std::endl;
		std::cout << "\tDate of issue of the passport [" << birthday << "." << monthBirth << "." << yearBirth << "]" << std::endl;
	}
};

class ForeignPassport {
private:
	int numberVisas;
	int passportNumber;
public:
	ForeignPassport(int NumberVisas = 0, int PassportNumber = 0) :numberVisas(NumberVisas), passportNumber(PassportNumber) {};

	void print() {
		std::cout << "Foreign passport:" << std::endl;
		std::cout << "\tNumber visas [" << numberVisas << std::endl;
		std::cout << "\tPassport number [" << passportNumber << std::endl;
	}
};

int main()
{
}