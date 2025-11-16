#include <iostream>
#include <vector>

class Book {
private:
	std::string author;
	std::string name;
	std::string publisher;
	int year;
	int pagesCount;
public:
	explicit Book(const std::string& aut = "", const std::string& nam = "", const std::string& pub = "", int yea = 0, int NumPag = 0) {
		this->author = aut;
		this->name = nam;
		this->publisher = pub;
		this->year = yea;
		this->pagesCount = NumPag;
	};

	const std::string& getAuthor()const {
		return author;
	}

	const int getYear()const {
		return year;
	}

	const std::string& getPublisher()const {
		return publisher;
	}

	static void showBooksToAuthor(const Book books[], int size, const std::string& author) {
		for (int i = 0; i < size; i++) {
			if (books[i].getAuthor() == author) {
				books[i].showBook();
			}
		}
	}

	static void showBooksToPublisher(const Book books[], int size, const std::string& publisher) {
		for (int i = 0; i < size; i++) {
			if (books[i].getPublisher() == publisher) {
				books[i].showBook();
			}
		}
	}

	static void showBooksToYear(const Book books[], int size, int year) {
		for (int i = 0; i < size; i++) {
			if (books[i].getYear() > year) {
				books[i].showBook();
			}
		}
	}

	void showBook() const {
		std::cout << author << " " << name << " " << publisher << " " << year << " " << pagesCount << std::endl;
	}
};

class Worker {
private:
	std::string NNP;
	std::string post;
	int yearCommencementWork;
	int salary;
public:
	explicit Worker(const std::string& nnp, const std::string& Post, int YearCommencementWork, int Salary) {
		this->NNP = nnp;
		this->post = Post;
		this->yearCommencementWork = YearCommencementWork;
		this->salary = Salary;
	}
	
	const int getSalary()const {
		return salary;
	}

	const int getYearCommencementWork()const {
		return yearCommencementWork;
	}

	const std::string getPost()const {
		return post;
	}

	static void experiencedEmployees(const Worker worker[], int size, int year) {
		for (int i = 0; i < size; i++) {
			if (2025 - worker[i].getYearCommencementWork() > year) {
				worker[i].print();
			}
		}
	}

	static void salarySurpasses(const Worker worker[], int size, int salary) {
		for (int i = 0; i < size; i++) {
			if (worker[i].getSalary() > salary) {
				worker[i].print();
			}
		}
	}

	static void assignmentPosition(const Worker worker[], int size, std::string post) {
		for (int i = 0; i < size; i++) {
			if (worker[i].getPost() == post) {
				worker[i].print();
			}
		}
	}
	
	void print()const {
		std::cout << "Initials [" << NNP << "], post [" << post << "], year admission to work [" << yearCommencementWork << "], salary [" << salary << "]" << std::endl;
	}
};

int main()
{
	Worker worker1("John Davey Harris", "Engineer", 2012, 1200);
	Worker worker2("Anna Sergeevna Aggeeva", "Designer", 2024, 43000);
	Worker worker3("Ton Tim Nob", "Designer", 2001, 10000);
	Worker worker4("Monkey D. Luffy", "Programmer", 2004, 55500);

	const int size = 4;
	Worker workers[size] = { worker1, worker2, worker3, worker4};

	Worker::assignmentPosition(workers, size, "Designer");
}