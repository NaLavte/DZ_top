#include <iostream>

using namespace std;

int degree(int footing, int indicator) {
	int result = footing;
	for (int i = 1; i < indicator; i++) {
		result *= footing;
	}
	return result;
}

int ng(int num1, int num2) {
	int result = 1;
	int trash, trash2;
	num1 < num2 ? trash = num1 : trash = num1;
	num2 < num1 ? trash2 = num2 : trash2 = num2;
	for (int i = trash + 1; i < trash2; i++) {
		result = result + i;
	}
	return result - 1;
}

bool isPerfectNumber(int num) {
	if (num <= 1) return false;
	int sum = 1; // 1 всегда делитель
	int sqrtNum = static_cast<int>(std::sqrt(num));
	for (int i = 2; i <= sqrtNum; ++i) {
		if (num % i == 0) {
			sum += i;
			int otherDivisor = num / i;
			if (otherDivisor != i) {
				sum += otherDivisor;
			}
		}
	}
	return sum == num;
}
void findPerfectNumbersInInterval(int start, int end) {
	for (int i = start; i <= end; ++i) {
		if (isPerfectNumber(i)) {
			std::cout << i << " является совершенным числом.\n";
		}
	}
}

void map(int map, string letter) {
	cout << "_____";
	cout << "\n|   |\n| " << map << " |" << "\n| " << letter << " |" << "\n|   |";
	cout << "\n-----";
}

bool isLuckyNumber(int number) {
	if (number < 100000 || number > 999999) {
		return false; // число не шестизначное }
		int firstHalfSum = 0, secondHalfSum = 0;
		int firstHalf = number / 1000;
		int secondHalf = number % 1000;

		for (int i = 0; i < 3; ++i) {
			firstHalfSum += firstHalf % 10;
			secondHalfSum += secondHalf % 10;
			firstHalf /= 10;
			secondHalf /= 10;
		}
		return firstHalfSum == secondHalfSum;
	}
}

int main()
{
	int number;
	cout << "Введите шестизначное число: ";
	cin >> number;

	if (isLuckyNumber(number)) {
		cout << "Число является счастливым." << endl;
	}
	else {
		cout << "Число не является счастливым." << endl;
	}
	return 0;
}
