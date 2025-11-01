#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int income, lateNum, codeRows, penalty, userChoice;
    float rowPrice, temp;
    penalty = 0;
    rowPrice = 0.5;
    cout << "Выберите пункт меню:\n";
    cout << "1 - доход и количество опозданий-> "
        "количество строк кода\n";
    cout << "2 - доход и количество кодовых строк -> "
        "количество опозданий\n";
    cout << "3 - количество опозданий и количество "
        "количество кодовых строк -> доход\n";
    cin >> userChoice;
    switch (userChoice)
    {
    case 1:
    {
        cout << "Входной доход, желаемый пользователем\n";
        cin >> income;
        cout << "Сколько раз пользователь опаздывал?\n";
        cin >> lateNum;
        codeRows = income / rowPrice;
        if (lateNum >= 3)
        {
            penalty = lateNum / 3 * 20;
            codeRows = codeRows + penalty / rowPrice;
        }
        cout << "количество строк кода: " << codeRows;
        cout << "\n";
        break;
    }
    case 2:
    {
        cout << "Входной доход, желаемый пользователем\n";
        cin >> income;
        cout << "Введите количество строк кода\n";
        cin >> codeRows;
        temp = codeRows * rowPrice;
        if (income >= temp)
        {
            cout << "Вам нельзя опаздывать!";
        }
        else
        {
            lateNum = (temp - income) / 20 * 3;
            cout << "Вам разрешается опаздывать ";
            cout << lateNum << " или " << lateNum + 1;
            cout << " или " << lateNum + 2 << " раз";
        }
        break;
    }
    case 3:
    {
        cout << "Введите количество строк кода\n";
        cin >> codeRows;
        cout << "Сколько раз пользователь опаздывал?\n";
        cin >> lateNum;
        temp = codeRows * rowPrice;
        if (lateNum >= 3)
        {
            penalty = lateNum / 3 * 20;
            if (penalty >= temp)
            {
                cout << "Ты ничего не получишь\n";
            }
            else
            {
                income = temp - penalty;
                cout << "You’ll get " << income;
                cout << "$\n";
            }
        }
        else
        {
            income = temp;
            cout << "Вы получите " << income << "$\n";
        }
        break;
    }
    default:
        cout << "Неправильный ввод!";
    }
    return 0;
}
