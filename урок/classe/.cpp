#include <iostream>

class Student {
private:
	int age;
	int course;
	double averageScore;
	std::string fulName;

public:
	Student(int Age = 0, int Course = 0, double AverageScore = 0, const std::string& FulName = "") :age(Age), course(Course), averageScore(AverageScore), fulName(FulName) {};

	void printInfo() {
		std::cout << "Student:" << std::endl;
		std::cout << "\tAge [" << age << "]" << std::endl;
		std::cout << "\tCourse [" << course << "]" << std::endl;
		std::cout << "\tAverage score [" << averageScore << "]" << std::endl;
		std::cout << "\tFul name [" << fulName << "]" << std::endl;
	}

	void changeAge() {
		std::cout << "Enter the new age of the student: ";
		std::cin >> age;
	}
};

class Aspirant :Student {
private:
	int percentagePreparation;
	int ticketsLearned;
	
public:
	Aspirant(int PercentagePreparation = 0, int TicketsLearned = 0) :percentagePreparation(PercentagePreparation), ticketsLearned(TicketsLearned) {};
	void changePercentagePreparation() {
		std::cout << "Сhange the percentage of preparation: ";
		std::cin >> percentagePreparation;
	}
	void changeTicketsLearned() {
		std::cout << "Сhange the number of tickets learned: ";
		std::cin >> ticketsLearned;
	}
};

int main()
{
}