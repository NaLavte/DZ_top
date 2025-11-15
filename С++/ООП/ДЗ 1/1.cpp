#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator; // числитель
    int denominator; // знаменатель
public:
    Fraction(int Numerator, int Denominator) :numerator(Numerator), denominator(Denominator) {}
    void addition(Fraction a, int b) {
        b = b * a.numerator;
        a.denominator = a.denominator + b;
    }

    void subtraction(Fraction a, int b) {
        b = b * a.numerator;
        a.denominator = a.denominator - b;
    }

    void multiplication(Fraction a, int b) {
        a.denominator = a.denominator * b;
    }

    void division(Fraction a, int b) {
        int c = a.denominator;
        a.denominator = a.numerator;
        a.numerator = c;
        a.numerator = a.numerator * b;

    }
};
int main()
{
}