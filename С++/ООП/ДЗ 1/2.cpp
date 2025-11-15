#include <iostream>

using namespace std;

class Data {
private:
    string surname; // фамилия
    string name; // имя
    string patronymic; // отчество
    int homePhone; // Домашний телефон
    int businessPhone; // Рабочий телефон
    int mobilePhone; // Мобильный телефон
    string contactInformation; // Контактная информация
public:
    Data() {};
    Data(string s, string n, string p, int h, int b, int m, string c) :surname(s), name(n), patronymic(p), homePhone(h), businessPhone(b), mobilePhone(m), contactInformation(c) {}
    
    Data add() {
        Data a;

        cout << "Ваше имя: ";
        cin >> a.name;

        cout << "Ваше фамилию: ";
        cin >> a.surname;

        cout << "Ваше отчество: ";
        cin >> a.patronymic;

        cout << "Ваше домашний телефон: ";
        cin >> a.homePhone;

        cout << "Ваше рабочий телефон: ";
        cin >> a.businessPhone;

        cout << "Ваше мобильный телефон: ";
        cin >> a.mobilePhone;

        cout << "Ваше контактную информацию: ";
        cin >> a.name;

        return a;
    }

};

int main()
{}