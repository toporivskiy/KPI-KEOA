#include<iostream>
#include<cstdlib>
#include<stdio.h>

// ОБЪЯВЛЯЕМ СВОИ ЗНАЧЕНИЯ:
#define PI 3.14159265359
#define ABSOLUT(xTrue, xFalse) delta(trueRes, DataRes) //Какие переменные для точного значения (trueRes) и расчитаного методом (DataRes)
#define DELTA(xTrue, xFalse) epsilon(trueRes, DataRes) //Какие переменные для точного значения (trueRes) и расчитаного методом (DataRes)

using namespace std;


double epsilon(double xtrue, double xfalse) //Относительная погрешность
{
double epsilon;
if (xfalse != 0)
{
epsilon = abs(abs(xtrue - xfalse) / xfalse);
}
else epsilon = 0;
return epsilon;
}

double delta(double xtrue, double xfalse) //Абсолютная погрешность
{
double delta = abs(xtrue - xfalse);
return delta;
}

double countTrueNum(double epsilon) //Количество верных чисел
{
int n = 0;
do { n++; } while (epsilon <= 0.5*pow(10, -n));
return n;
}



int main(int argc, char* argv[])
{
setlocale(LC_ALL, "Russian");
float a, b;
int countK = 0, countN = 0;
const int size = 100;
cout << "Программа считает интеграл от ф-ции " << "FUNC(x)" << ", методом Гаусса, n=4.\nВведите пожалуйста границы интегрирования. а-нижняя, b - верхняя" << endl;
cout << "Введите а" << endl;
cin >> a;
cout << "Введите b" << endl;
cin >> b;
cout << endl;
double sCircle = PI*pow((b-a) / 2, 2); // Формула площади круга диаметром b-a
cout << sCircle << endl;
double DataRes = 0;
double Nx[size];
double Ny[size];
// Генерация псевдослучайных чисел
for (int i = 0; i < size; i++) {
		Nx[i] = a + 0.01 * (rand() % size+1); // Если size 10 то 0.1; Если size 100 то 0.01; и т.д.
		Ny[i] = a + 0.01 * (rand() % size+1); // ^
}
// Рассчитывание расстояние между случайной точкой и центра круга
for (int i = 0; i < size; i++) {
	double module = sqrt(fabs(pow((Nx[i] - (a + ((b - a) / 2))), 2) + pow((Ny[i] - (a + ((b - a) / 2))), 2)));
	if (module <= (b - a) / 2) // Если расстояние не больше то добавить количество попадающих в круг точек
		countK++;
}
countN = size; // Количество точек N (все случайно разбросаны)
double sPryam = pow((b-a), 2); // Площадь прямоугольник в котором мы разбрасывали точки N
DataRes = sPryam * countK/countN;
cout << endl << "Общее количество точек: " << countN << endl;
cout <<"Количество точек попадающих в круг: " << countK << endl;
cout << endl << "Результат вычисленный методом: " << DataRes << endl;
double trueRes = sCircle;
cout << "Точный результат: " << trueRes << endl;
cout << "\nАбсолютная погрешность: " << ABSOLUT(xTrue, xFalse) << endl; // Вывод абсолютной погрешности
cout << "Относительная погрешность: " << DELTA(xTrue, xFalse) * 100 << "%" << endl; // Вывод относительной погрешности
cout << "Количество верных чисел: " << countTrueNum(ABSOLUT(xTrue, xFalse)) << endl << endl; // Вывод Количества верных чисел
system("pause");
return 0;
}
