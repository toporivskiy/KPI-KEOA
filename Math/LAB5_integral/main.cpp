#include<iostream>
#include <cstdlib> 

#define FUNC(x) 1/pow(x, 2)
#define INTEGRAL(a, b) (-1/b)-(-1/a)

using namespace std;

float** init(int size);
float* getZerosLejandr(int);
float* getKoefsA(int n);

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



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	float a, b;
	int size = 4;
	float *Lej = new float[size];
	float *KoefsA = new float[size];
	float *MatrX = new float[size];
	float *MatrY = new float[size];
	float *KoefsC = new float[size];
	float *KoefsRes = new float[size];
	Lej = getZerosLejandr(size);
	KoefsA = getKoefsA(size);
	cout << "Программа считает интеграл от ф-ции " << "FUNC(x)" << ", методом Гаусса, n=4.\nВведите пожалуйста границы интегрирования. а-нижняя, b - верхняя" << endl;
	cout << "Введите а" << endl;
	cin >> a;
	cout << "Введите b" << endl;
	cin >> b;
	cout << endl;
	float DataRes = 0;
	for (int i = 0; i<size; i++) {
		MatrX[i] = (b + a) / 2 + ((b - a)*Lej[i]) / 2;
		KoefsC[i] = ((b - a) / 2)*KoefsA[i];
		MatrY[i] = FUNC(MatrX[i]);
		cout << MatrY[i] << endl;
		//MatrY[i] = sqrt(1+2*MatrX[i]);
		KoefsRes[i] = MatrY[i] * KoefsC[i];
		cout << " DOB = " << KoefsRes[i] << endl;
		DataRes += KoefsRes[i];
		cout << " SUM = " << DataRes << endl;
	}
	cout << endl << "Результат вычисленный методом: " << DataRes << endl;
	float trueRes = INTEGRAL(a, b);
	cout << "Точный результат: " << trueRes << endl;
	free(Lej);
	free(KoefsA);
	free(MatrX);
	free(MatrY);
	free(KoefsC);
	free(KoefsRes);
	cout << "\nАбсолютная погрешность: " << fabs(delta(trueRes, DataRes)) << endl; // Вывод абсолютной погрешности
	cout << "Относительная погрешность: " << fabs(epsilon(trueRes, DataRes)) * 100 << "%" << endl << endl; // Вывод относительной погрешности
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

float* getZerosLejandr(int n) {
	float *data = new float[n];
	switch (n) {
	case 3:data[0] = -0.7745;
		data[1] = 0.0;
		data[2] = 0.7745;
		break;
	case 4:data[0] = -0.8611;
		data[1] = -0.3399;
		data[3] = 0.8611;
		data[2] = 0.3399;
		break;
	}
	return data;
}

float* getKoefsA(int n) {
	float *data = new float[n];
	switch (n) {
	case 3:data[0] = 0.5555;
		data[1] = 0.8888;
		data[2] = 0.5555;
		break;
	case 4:data[0] = 0.3478;
		data[1] = 0.6521;
		data[2] = 0.6521;
		data[3] = 0.3478;
		break;
	}
	return data;
}


