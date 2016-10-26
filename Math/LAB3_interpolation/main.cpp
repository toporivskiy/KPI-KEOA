#include<iostream>
#include<math.h>
#include<stdio.h>
#define FUNC(x) (1/(pow(x, 2)))

using namespace std;

inline float q(float x, float x0, float h) { return (x - x0) / h; }

//!
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
float** T(float** a, int size)
{
	float** res;
	res = init(size);
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size - i; j++)
		{
			res[i][j] = a[j][i];
		}
	}
	return res;
}
float* getFuncTable(float first, float h, int n)
{
	float *res = new float[n];
	float x = first;
	for (int i = 0; i<n; i++)
	{
		res[i] = FUNC(x);
		x += h;
	}
	return res;
}
void showDiffTable(float first, float h, float** a, int size)
{
	printf("X\tY\tDelta1\tDelta2\tDelta3\tDelta4\n");
	for (int i = 0; i<size; i++)
	{
		printf("%3.2f\t", first + h*i);
		for (int j = 0; j<size - i; j++)
		{
			printf("%3.2f\t", a[i][j]);
		}
		cout << "\n";
	}
}
float** getDiffTable(float *a, int size)
{
	float** res;
	res = init(size);
	res[0] = a;
	for (int i = 1; i<size; i++)
	{
		for (int j = 0; j <= size - i; j++)
		{
			res[i][j] = res[i - 1][j + 1] - res[i - 1][j];
		}
	}
	return T(res, size);
}
long long int fact(int a)
{
	long long int r = 1;
	for (int i = 1; i <= a; i++)
		r *= i;
	return r;
}
float Q(float x, float x0, float h, int n)
{
	float res = q(x, x0, h);
	for (int i = 1; i<n; i++)
	{
		res = res*(q(x, x0, h)*q(x, x0, h) - i*i);
	}
	return res;
}
//!



int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 5; // Размер таблицы
				  //cout << "Введите размер таблицы:\n";
				  //cin >> size;
	float h=0.2; // Шаг
	//cout << "Введите шаг:\n";
	//cin >> h;
	float first = 1; // Первый элемент
	//cout << "Введите первый элемент:\n";
	//cin >> first;
	cout << &endl;
	float *a = new float[size];
	a = getFuncTable(first, h, size); // Получить значение функции в заданных x
	float x;
	float **y;
	y = getDiffTable(a, size); // Получить таблицу разностей
	showDiffTable(first, h, y, size); // Вывести ее
	cout << "\nВведите значение аргумента, для вычисления: \n";
	cin >> x;
	int mid = ceil((float)(size / 2)); // Нулевой элемент
	float x0 = first + h*mid;
	float P = y[mid][0]; // Присвоить первому элементу полинома
	float temp1, temp2, temp3;
	for (int n = 1; n <= mid; n++)
	{
		temp1 = Q(x, x0, h, n) / fact(2 * n - 1);
		temp2 = (y[-n + mid][2 * n - 1] + y[-n + mid][2 * n]/2) ;
		temp3 = Q(x, x0, h, n) / fact(2 * n -1);
		P += (temp1)*(y[-n + mid][2 * n - 1]/ 2)+(temp3)*(y[-n + mid][2 * n] / 2);
														   //cout << (temp1)*(temp2) << "\n";
														   //cout << (temp3)*(y[-n + mid][2 * n]) << "\n";
	}
	cout << "Рассчитаное значение:  " << P << "\n";
	cout << "Реальное значение:  " << FUNC(x) << "\n"; //вывести реальное значение (библиотечное)
	cout << "Абсолютная погрешность:  " << fabs(P - FUNC(x)) << "\n"; //абсолютная погрешность
	cout << "Относительная погрешность:  " << fabs(P - FUNC(x)) / P * 100 << "%\n"; //относительная погрешность

	system("pause");
	return 0;
}
