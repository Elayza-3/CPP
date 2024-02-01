#include<iostream>
#include<cmath>


using namespace std;

int main() {
	setlocale(LC_ALL,"RUS");

	cout << "1.Сложение" << endl
		<< "2.Вычитание" << endl
		<< "3.Умножение" << endl
		<< "4.Деление" << endl
		<< "5.Возведение в степень" << endl
		<< "6.Нахождения квадратного корня" << endl
		<< "7.Нахождение 1 процента от числа" << endl
		<< "8.Найти факториал числа" << endl
		<< "9.Выйти из программы." << endl;

	string cmd;
	int value_1, value_2;

	do {
		cout << "Номер команды: ";
		cin >> cmd;

		if (cmd == "1") {
			cout << "Введите первое число для сложения: ";
			cin >> value_1;
			cout << "Введите второе число для сложения: ";
			cin >> value_2;

			cout << value_1 << " + " << value_2 << " = " << value_1+value_2 << endl;
		}
		else if (cmd == "2") {
			cout << "Введите первое число для вычитания: ";
			cin >> value_1;
			cout << "Введите второе число для вычитания: ";
			cin >> value_2;

			cout << value_1 << " - " << value_2 << " = " << value_1 - value_2 << endl;
		}
		else if (cmd == "3") {
			cout << "Введите первое число для умножения: ";
			cin >> value_1;
			cout << "Введите второе число для умножения: ";
			cin >> value_2;

			cout << value_1 << " * " << value_2 << " = " << value_1 * value_2 << endl;
		}
		else if (cmd == "4") {
			cout << "Введите первое число для деления: ";
			cin >> value_1;
			cout << "Введите второе число для деления: ";
			cin >> value_2;

			cout << value_1 << " / " << value_2 << " = " << value_1 / value_2 << endl;
		}
		else if (cmd == "5") {
			cout << "Введите число: ";
			cin >> value_1;
			cout << "Введите степень: ";
			cin >> value_2;

			cout << value_1 << " ^ " << value_2 << " = " << pow(value_1,value_2) << endl;
		}
		else if (cmd == "6") {
			cout << "Введите число: ";
			cin >> value_1;

			cout << "корень(" << value_1 << ") = " << pow(value_1, 0.5)<< endl;
		}
		else if (cmd == "7") {
			cout << "Введите число: ";
			cin >> value_1;

			cout << value_1 << "% = " << value_1/100 << endl;
		}
		else if (cmd == "8") {
			cout << "Введите число: ";
			cin >> value_1;

			int num = 1;
			for (int i = 1; i <= value_1; i++) {
				num *= i;
			}

			cout << value_1 << "! = " << num << endl;
		}

	} while (cmd != "9");

	return 0;
}