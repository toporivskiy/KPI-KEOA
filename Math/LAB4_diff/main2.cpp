#include<iostream>
#include<math.h>
#include <Windows.h>
#include <cstdlib> // для exit()

#define FUNC(x) 1/pow(x, 2)

using namespace std;


float** init(int size);
long long int fact(int); //факториал
float* getFuncTable(float, float, int);
void showFuncTable(float *I, int n);


int neokoef(float x, float h, float *D)
{
	double c1, c2, c3, c4, c5;
	double neopoh1;
	{
		c1 = -1 * (1 / (4 * h));
		c2 = -1 * (5 / (6 * h));
		c3 = 1 * (3 / (2 * h));
		c4 = -1 * (1 / (2 * h));
		c5 = 1 * (1 / (12 * h));
		neopoh1 = c1*D[0] + c2*D[1] + c3*D[2] + c4*D[3] + c5*D[4];
		cout << "Первая производная: ";
		cout << neopoh1 << endl;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int size = 5; //Размер таблицы
	float h = 0.1; //шаг
	float first = (1.5); //Первый элемент
	float *a = new float[size];
	float x;
	cout << "Введите пожалуйста точку в которой посчитать производную" << endl;
	cin >> x;
	first = x - h;
	a = getFuncTable(first, h, size); //получить значение ф-ии в заданных иксах
	showFuncTable(a, size);
	neokoef(x, h, a);
	system("pause");
	return 0;
}

float** init(int size)
{
	float** res;
	res = new float*[size];
	for (int i = 0; i<size; i++)
	{
		res[i] = new float[size - i];
	}
	return res;
}

long long int fact(int a)
{
	long long int r = 1;
	for (int i = 1; i <= a; i++) r *= i;
	return r;
}




float* getFuncTable(float first, float h, int n)
{
	float *res = new float[n];
	float x = first;
	for (int i = 0; i<n; i++)
	{
		res[i] = FUNC(x);
		//res[i] = asin(x);
		x += h;
	}
	return res;
}

void showFuncTable(float *I, int n) {
	for (int i = 0; i<n; i++) {
		cout << "№ " << i + 1 << " Коэфициент = " << I[i] << endl;
	}
}
