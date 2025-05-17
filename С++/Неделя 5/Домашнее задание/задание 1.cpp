#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    char X;
    int symbol;

    cout << "Введите символ который хотите распознать: ";
    cin >> X;

    symbol = (int)X;

    if(((symbol >= 65) && (symbol <= 90)) ||
        ((symbol >= 97) && (symbol <= 122)))
    {
        cout << "Это буква.";
    }
    else if ((symbol >= 48) && (symbol <= 57))
    {
        cout << "Это цифра.";
    }
    else if ((symbol == 33) || ((symbol >= 44) &&
        (symbol <= 46)) || (symbol == 58) ||
        (symbol == 59) || (symbol == 63))
        {
            cout << "Это знак препинания.";
    }
    else
    {
        cout << "Неизвестный символ";
    }
}
