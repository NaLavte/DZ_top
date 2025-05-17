#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int MTS = 3;
    int Tele1 = 4;
    int beelini = 2;
    int conversationDuration;
    int fromWhichOperator;
    int toWhichOperator;
   
    cout << "Напишите цифру оператора с какого вы звоните - \n1. MTS,\n2. Tele1,\n3. Beelini.\n";
    cin >> fromWhichOperator;
    cout << endl;

    cout << "Напишите цифру оператора на какой вы звоните - \n1. MTS,\n2. Tele1,\n3. Beelini.\n";
    cin >> toWhichOperator;
    cout << endl;

    cout << "Введите продолжительность разговора в минутах: ";
    cin >> toWhichOperator;
    cout << endl;

    if (fromWhichOperator == toWhichOperator) {
        cout << "Стоимость звонка равна: 0";
    }
    else if (fromWhichOperator == 1) {
        cout << "Стоимость звонка равна: " << toWhichOperator * MTS;
    }
    else if (fromWhichOperator == 2) {
        cout << "Стоимость звонка равна: " << toWhichOperator * Tele1;
    }
    else if (fromWhichOperator == 3) {
        cout << "Стоимость звонка равна: " << toWhichOperator * beelini;
    }

    cout << endl;
}
