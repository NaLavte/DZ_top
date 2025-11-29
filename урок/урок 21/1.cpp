#include <iostream>

class Employer {
protected:
    int salary;
    std::string name;
    std::string surname;
    std::string post;

public:
    Employer(int salary, const std::string& name, const std::string& surname, const std::string& post) :name(name), surname(surname), post(post), salary(salary) {};

    virtual void Print() const {
        std::cout << "Name [" << name << "]" << std::endl;
        std::cout << "Surname [" << surname << "]" << std::endl;
        std::cout << "Post [" << post << "]" << std::endl;
        std::cout << "Salary [" << salary << "]" << std::endl;
    }
};

class President : public Employer {
private:
    std::string numberSubordinates;
public:
    President(int salary, const std::string& name, const std::string& surname, const std::string& post, const std::string& numberSubordinates) : Employer(salary, name, surname, post), numberSubordinates(numberSubordinates) {};

    void Print() const override {
        std::cout << "Name [" << name << "]" << std::endl;
        std::cout << "Surname [" << surname << "]" << std::endl;
        std::cout << "Post [" << post << "]" << std::endl;
        std::cout << "Salary [" << salary << "]" << std::endl;
        std::cout << "Number of subordinates [" << numberSubordinates << "]" << std::endl;
    }
};

class Manager :public  Employer {
private:
    int numberTasks;
public:
    Manager(int salary, const std::string& name, const std::string& surname, const std::string& post, int numberTasks) : Employer(salary, name, surname, post), numberTasks(numberTasks) {};

    void Print() const override {
        std::cout << "Name [" << name << "]" << std::endl;
        std::cout << "Surname [" << surname << "]" << std::endl;
        std::cout << "Post [" << post << "]" << std::endl;
        std::cout << "Salary [" << salary << "]" << std::endl;
        std::cout << "Number of tasks [" << numberTasks << "]" << std::endl;
    }
};

class Worker :public Employer {
private:
    int workingHours;
public:
    Worker(int salary, const std::string& name, const std::string& surname, const std::string& post, int workingHours) : Employer(salary, name, surname, post), workingHours(workingHours) {};

    void Print() const override {
        std::cout << "Name [" << name << "]" << std::endl;
        std::cout << "Surname [" << surname << "]" << std::endl;
        std::cout << "Post [" << post << "]" << std::endl;
        std::cout << "Salary [" << salary << "]" << std::endl;
        std::cout << "Working hours [" << workingHours << "]" << std::endl;
    }
};

int main()
{
}