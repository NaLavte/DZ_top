#include <iostream>

class Pet {
public:
    virtual void Sound()const = 0; //  издает звук животного 
    virtual void Show()const = 0; // отображает имя животного
    virtual void Type()const = 0; // отображает название его подвида
};

class Dog :public Pet {
private:
    std::string breed; // порода
    std::string voice; // голос
    std::string name; // имя
public:
    void Sound()const override {
        std::cout << voice;
    }
    void Show()const override {
        std::cout << voice;
    }
    void Type()const override {
        std::cout << breed;
    }
};

class Cet :public Pet {
private:
    std::string breed; // порода
    std::string voice; // голос
    std::string name; // имя
public:
    void Sound()const override {
        std::cout << voice;
    }
    void Show()const override {
        std::cout << voice;
    }
    void Type()const override {
        std::cout << breed;
    }
};

class Parrot :public Pet {
private:
    std::string breed; // порода
    std::string voice; // голос
    std::string name; // имя
public:
    void Sound()const override {
        std::cout << voice;
    }
    void Show()const override {
        std::cout << voice;
    }
    void Type()const override {
        std::cout << breed;
    }
};

class Hamster :public Pet {
private:
    std::string breed; // порода
    std::string voice; // голос
    std::string name; // имя
public:
    void Sound()const override {
        std::cout << voice;
    }
    void Show()const override {
        std::cout << voice;
    }
    void Type()const override {
        std::cout << breed;
    }
};

int main() 
{
    
}