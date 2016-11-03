#include<iostream>
#include<math.h>
#include<conio.h>

#define M_PI 3.14159265358979323846 // Число ПИ - 20 знаков после запятой
#define FUNC(x) (1/(pow(x, 2))) // Макрос функции

using namespace std;

double epsilon(double xtrue, double xfalse) //Относительная погрешность
{
	double epsilon;
	if (xfalse != 0)
	{
		epsilon = abs(xtrue - xfalse) / xfalse;
	}
	else epsilon = 0;
	return epsilon;
}

double delta(double xtrue, double xfalse) //Абсолютная погрешность
{
	double delta = abs(xtrue - xfalse);
	return delta;
}

void func_runge(double x, double h, int k)
{
	double temp0, temp, real;

	real = (-2) / pow(x, 3);

	temp0 = (FUNC(x) - FUNC(x - h)) / (h); // Производная методом левых разностей

	cout << "\nРеальное значение производной функции: (1/x^2)'(" << x << ")=" << real << endl; // Табличное значение производной
	cout << "\nЗначение производной функции посчитаное методом левых разностей: " << temp0 << endl; // Значение посчитанное методом левых разностей
	temp = temp0 + ((temp0 - (FUNC(x) - FUNC(x - k*h)) / (k*h)) / (pow(k, 1) - 1)); // Производная методом Рунге-Ромберга
	cout << "Значение производной апроксимированное методом Рунге-Ромберга: " << temp << endl; //значение методом Рунге-Ромберга
	cout << "\nАбсолютная погрешность: " << fabs(delta(real, temp)) << endl; // Вывод абсолютной погрешности
	cout << "Относительная погрешность: " << fabs(epsilon(real, temp)) * 100 << "%" << endl << endl; // Вывод относительной погрешности
}
////////////////////

void main(void)
{
	setlocale(LC_ALL, "Russian");
	double x, h, k; // Вводим точку в которой ищем производную, шаг, множитель шага
	cout << "Введите точку в которой необходимо посчитать производную: ";
	cin >> x;
	cout << "Введите шаг: ";
	cin >> h;
	cout << "Введите множитель шага: ";
	cin >> k;
	func_runge(x, h, k); // находим приближенное значение методом Рунге-Ромберга
	system("pause");
}
