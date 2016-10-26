#include <string.h>
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <conio.h>
#include <locale.h>
#include <stdio.h>

#define FUNC(x) (1/(pow(x, 2)))

using namespace std;

double x, fx; // Глобальные переменные, в которые записывается значение х и функции. Потом на основе их ставится точка.
int z;

double Taylor(double a, double Eps); // Функция вычисления ряда тейлора


void Initialize()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 800); // Определяет размер разрешенной области экрана
}

void Draw()
{
	double Gx = 0, Gy = 0;
	double Gr[2];
	int i;
	int GradY = 35, GradX = 35;

	// Ось ОУ
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(400, 770);
	glVertex2i(400, 20);
	glEnd();

	// Ось ОХ
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(20, 365);
	glVertex2i(770, 365);
	glEnd();


	// Стрелки на осях
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(390, 750);
	glVertex2i(400, 770);
	glVertex2i(410, 750);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(750, 375);
	glVertex2i(770, 365);
	glVertex2i(750, 355);
	glEnd();

	// Именование осей
	glRasterPos2i(780, 365);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 'X');

	glRasterPos2i(400, 780);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 'Y');


	glRasterPos2i(390, 350);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '0');

	glRasterPos2i(400 + GradX * 5, 350);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');

	//// Разметочные деления

	// По ОХ
	for (i = 1; i<11; i++)
	{
		glBegin(GL_LINES);
		glVertex2i(400 + GradX*i, 375);
		glVertex2i(400 + GradX*i, 355);
		glEnd();
	}

	for (i = 1; i<11; i++)
	{
		glBegin(GL_LINES);
		glVertex2i(400 - GradX*i, 375);
		glVertex2i(400 - GradX*i, 355);
		glEnd();
	}


	// ПО ОУ
	for (i = 0; i <= 10; i++)
	{
		glBegin(GL_LINES);
		glVertex2i(390, 400 + GradY*i);
		glVertex2i(410, 400 + GradY*i);
		glEnd();
	}

	for (i = 1; i <= 10; i++)
	{
		glBegin(GL_LINES);
		glVertex2i(390, 400 - GradY*i);
		glVertex2i(410, 400 - GradY*i);
		glEnd();
	}

	// Построение графика справа от ОУ (II четверть)
	
	Gr[0] = 0.0;
	Gr[1] = 1.0;
	Gx = 0; Gy = 0;
	while (Gx<5 && Gy>-15)
	{
		Gy = FUNC(Gx);
		glBegin(GL_LINES);
		glVertex2i(400 + Gr[0] * GradX * 5, 365 + Gr[1] * GradY * 5);
		glVertex2i(400 + Gx*GradX * 5, 365 + Gy*GradY * 5);
		glEnd();
		Gx = Gx + 0.001;
		Gr[0] = Gx;
		Gr[1] = Gy;
	}

	// Построение графика слева от ОУ (I четверть)
	Gr[0] = 0.0;
	Gr[1] = 1.0;
	Gx = 0; Gy = 0;
	while (Gx>-5 && Gy>-15)
	{

		Gy = FUNC(Gx);
		glBegin(GL_LINES);
		glVertex2i(400 + Gr[0] * GradX * 5, 365 + Gr[1] * GradY * 5);
		glVertex2i(400 + Gx*GradX * 5, 365 + Gy*GradY * 5);
		glEnd();
		Gx = Gx - 0.001;
		Gr[0] = Gx;
		Gr[1] = Gy;
	}

	// Постановка точки и прописовка креста
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(400 + (x*GradX + 2) * 5, 365 + (fx*GradY + 2) * 5);
	glVertex2i(400 + (x*GradX - 2) * 5, 365 + (fx*GradY - 2) * 5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(400 + (x*GradX + 2) * 5, 365 + (fx*GradY - 2) * 5);
	glVertex2i(400 + (x*GradX - 2) * 5, 365 + (fx*GradY + 2) * 5);
	glEnd();

	glFlush();
}


int main(int argc, char **argv)
{
	double E;

	setlocale(LC_ALL, "");
	cout << "Программа считает значение функции (1/x^2), которая была разложена в ряд Тейлора в заданой точке" << "\n";
	cout << "Пожалуйста, введите  значение х и необходимую точность Epsilone" << "\n";

	do {
	cout << "x = ";
	cin >> x;
		if (x <= 0 || x >= 1) cout << "Значение аргумента должно лежать 0 < x < 1" << "\n";
	} while (x <= 0 || x >= 1);

	do {
		cout << "\n" << "Точность = ";
		cin >> E;
		if (E <= 0 || E >= 1) cout << "Значение аргумента должно лежать 0 < Epsilone < 1" << "\n";
	} while (E <= 0 || E >= 1);
	cout << &endl;
	
	fx = Taylor(x, E);

	cout << "\nРезультат функции : " << fx << "\a";
	cout << "\nРезультат функции вычисленого компютером : " << FUNC(x);
	cout << "\nАбсолютная погрешность: " << FUNC(x) - fx << "\n";
	cout << "Относительная погрешность: " << ((FUNC(x) - fx) / fabs(fx)) * 100 << "%" << "\n";
	cout << "\n\nДля отображения графика нажмите пробел\nДля завершения программы нажмите любую кнопку кроме пробела\a";

	if (_getch() == 32) {

		// Функции подключения графики
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(800, 800);
		glutInitWindowPosition(350, 20);
		glutCreateWindow("График Функции");
		Initialize();
		glutDisplayFunc(Draw);
		glutMainLoop();
	}
}

double Taylor(double a, double Eps)
{
	double power, power2, summ = 0, last = 0, n = 0, res = 0;

	do
	{
		res = summ;
		//last = pow((-1),n+1)*n*pow((x-1),n-1);
		last = pow((-1), n)*(1+n)*pow((-1+a),n);
		cout << n + 1 << " слагаемое" << " = " << last << "\n";
		summ += last;
		n++;

	} while (last>Eps);

	return res;
}








/*
double Taylor(double a, double Eps) {
	double res = a, n = Eps;
	int sign = 1;
	for (int i = 1; fabs(n) >= Eps; i++) {
		n = sign*(pow((-1), n)*(1 + n)*pow((-1 + a), n));
		res += n;
		sign = sign;
		cout << "member " << i << ": " << n << "\n";
	}
	return res;
}*/

/*#include <Windows.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES 
#include <math.h>
#include <iostream>
#include <GL/glut.h>

using namespace std;


#define AXER 1100
#define AXEL 0
#define AXET 0
#define AXEB 600
#define AXEX (AXEB+AXET)/2
#define AXEY (AXEL+AXER)/2
#define RANG AXEY/10
#define SIZE 50 // константы для координатной плоскости

long long int fact(int); // Factorial
float my_func(float, float); // Calculate function с заданной точностью раскладывая в ряд Тейлора

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Фон чорний та прозорий 
	glClear(GL_COLOR_BUFFER_BIT);         // Очищення буферу кольору 

										  // Малювання серії відрізків, що є графіком функції  
	glBegin(GL_LINE_STRIP);      // Кожна пара вершини задає відрізок  
	glColor3f(1.0f, 1.0f, 0.0f); // Жовтий колір  
	for (float x1 = -10; x1 <= 10; x1 += 0.1) {
		float sum = 0.0;
		for (float n = 0.0; n < 10.0; n++) {
			sum += pow(-1, (n + 1)) * n * pow((x1 - 1), (n - 1));
		}
		float y1 = sum / 10;
		glVertex2f(x1 / 10, y1);
	}
	glEnd();

	glFlush(); // Виконати малювання
}
int main(int argc, char* argv[])
{
	float x, e;
	float X, Y;

	HDC hDC = GetDC(GetConsoleWindow());
	Rectangle(hDC, 0, 0, AXER + 100, AXEB + 100); //рисуем координатную плоскость
	HPEN Pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN Pen2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN Pen3 = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, AXEL, AXEX, NULL);
	LineTo(hDC, AXER, AXEX);
	MoveToEx(hDC, AXEY, AXET, NULL);
	LineTo(hDC, AXEY, AXEB);
	SelectObject(hDC, Pen3);
	for (x = 0; x<20 * SIZE; x += SIZE) // Помечаем на координате x целые числа 
	{
		MoveToEx(hDC, AXEY + x, AXEX, NULL);
		LineTo(hDC, AXEY + x, AXEX + 4);
		MoveToEx(hDC, AXEY - x, AXEX, NULL);
		LineTo(hDC, AXEY - x, AXEX + 4);
	}
	for (x = 0; x<20 * SIZE; x += SIZE) // Помечаем на координате y целые числа 
	{
		MoveToEx(hDC, AXEY, AXEX + x, NULL);
		LineTo(hDC, AXEY - 4, AXEX + x);
		MoveToEx(hDC, AXEY, AXEX - x, NULL);
		LineTo(hDC, AXEY - 4, AXEX - x);
	}
	SelectObject(hDC, Pen2);
	for (x = -RANG; x <= RANG; x += 0.001f) // Рисуем график 1/(x^2)
	{
		MoveToEx(hDC, SIZE*x + AXEY, -SIZE*(1 / (pow(x,2))) + AXEX, NULL); 
		LineTo(hDC, SIZE*x + AXEY, -SIZE*(1 / (pow(x, 2))) + AXEX);
	}
	//////////////////////////////////////////////////////////
	/*
	glutInit(&argc, argv);    // Ініціалізація GLUT 
	glutCreateWindow("Test"); // Створення вікна із заданим ім'ям 
	glutInitWindowSize(320, 320); // Ширина та висота вікна 
	glutInitWindowPosition(0, 0); // Положення вікна 
	glutDisplayFunc(display); // Реєстрація функції зворотного                           
							  // виклику для малювання вікна 

	glutMainLoop();           // Вхід у цикл обробки подій GLUT 
	*/
	//////////////////////////////////////////////////////////
	/*
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	for (float x1 = -5; x1 <= 5; x1 += 0.1) {
		float sum = 0.0;
		for (float n = 0.0; n < 5.0; n++) {
			sum += pow(-1, (n + 1)) * n * pow((x1 - 1), (n - 1));
		}
		float y1 = sum / 5;
		glVertex2f(x1 / 5, y1);
	}
	glEnd();
	glFlush();

	///////////////////////////////////////////////////////////
	cout << "Enter X:" << endl;
	cin >> Y;
	cout << "Enter accurasy:" << endl;
	cin >> e;
	//while (fabs(Y)>M_PI)
		//Y = Y>0 ? Y - M_PI : Y + M_PI;
	X = my_func(Y, e);
	cout << "Counted value\t" << X << "\n";
	cout << "True value\t" << (1 / (pow(Y, 2))) << "\n";
	cout << "Absolute measurement error\t" << fabs(X - (1 / (pow(Y, 2)))) << "\n"; //абсолютная погрешность
	cout << "Relative measurement error\t" << fabs(X - (1 / (pow(Y, 2)))) / X * 100 << "%\n"; //относительная погрешность
	X = -X*SIZE + AXEX;
	Y = Y*SIZE + AXEY;
	SelectObject(hDC, Pen3); //обозначаем расчитанную точку
	MoveToEx(hDC, Y, AXEX, NULL);
	LineTo(hDC, Y, X);
	MoveToEx(hDC, AXEY, X, NULL);
	LineTo(hDC, Y, X);
	Rectangle(hDC,Y-3,X-3,Y+3,X+3);
	getchar(); getchar();
	return 0;
}

long long int fact(int a) {
	long long int r = 1;
	for (int i = 1; i <= a; i++) r *= i;
	return r;
}


float my_func(float x, float e) {
	double f = x, n = e;
	int sign = -1;
	cout << "member 1: " << f << "\n";
	for (int i = 2; fabs(n) >= e; i++) {
		n = sign*(pow(x, 2 * i - 1) / fact(2 * i - 1));
		f += n;
		sign = -sign;
		cout << "member " << i << ": " << n << "\n";
	}
	return f;
}



/*
#include <GL/glut.h> // Файл заголовку для підтримки бібліотеки GLUT
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

// Функція, що викликатиметься для малювання сцени
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Фон чорний та прозорий 
	glClear(GL_COLOR_BUFFER_BIT);         // Очищення буферу кольору 

	// Малювання серії відрізків, що є графіком функції  
	glBegin(GL_LINE_STRIP);      // Кожна пара вершини задає відрізок  
	glColor3f(1.0f, 1.0f, 0.0f); // Жовтий колір  
	for (float x = -M_PI; x <= M_PI; x += 0.1) {  
		float y = (1 / (pow(x, 2))) / M_PI;   glVertex2f(x / M_PI, y); 
	} 
	glEnd(); 

	glFlush(); // Виконати малювання
} 

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);    // Ініціалізація GLUT 
	glutCreateWindow("Test"); // Створення вікна із заданим ім'ям 
	glutInitWindowSize(320, 320); // Ширина та висота вікна 
	glutInitWindowPosition(0, 0); // Положення вікна 
	glutDisplayFunc(display); // Реєстрація функції зворотного                           
							  // виклику для малювання вікна 

	glutMainLoop();           // Вхід у цикл обробки подій GLUT 

	return 0;
}
*/

/*
#include <GL/glut.h> // Файл заголовку для підтримки бібліотеки GLUT 

// Функція, що викликатиметься для малювання сцени 
void display() {  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Фон чорний та прозорий  
glClear(GL_COLOR_BUFFER_BIT);         // Очищення буферу кольору 

// Малювання червоного квадрату розміром 1x1  
glBegin(GL_QUADS);       // Кожні 4 вершини задають чотирикутник   
glColor3f(1.0f, 0.0f, 0.0f); // Червоний колір   
glVertex2f(-0.5f, -0.5f);   
glVertex2f( 0.5f, -0.5f);   
glVertex2f( 0.5f,  0.5f);   
glVertex2f(-0.5f,  0.5f);  
glEnd(); 

glFlush(); // Виконати малювання 
} 

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);    // Ініціалізація GLUT 
	glutCreateWindow("Test"); // Створення вікна із заданим ім'ям 
	glutInitWindowSize(320, 320); // Ширина та висота вікна 
	glutInitWindowPosition(0, 0); // Положення вікна 
	glutDisplayFunc(display); // Реєстрація функції зворотного                           
							  // виклику для малювання вікна 
	
	glutMainLoop();           // Вхід у цикл обробки подій GLUT 

	return 0;
}
*/
