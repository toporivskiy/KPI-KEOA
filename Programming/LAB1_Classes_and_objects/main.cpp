//
// Powered by Andrew Toporivskiy
// 14.09.2016
//


#include "classes.h"
#include <iostream>
#include <cstring>
#include <conio.h>
//#define 
using namespace std;

int main() {
	cout << "Press any note: " << endl;
	unsigned char notecode;
	Note A, B, C, D, E, F, G;
	while (1) {
		notecode = _getch(); // Код символа
		switch (notecode)
		{
		case 97: {
			A.setAll("A", 1, 17, 127);
			A.printAll();
			//cout << "A" << endl;
		}
			break;
		case 98:{
			B.setAll("B", 1, 17, 127);
			B.printAll();
			//cout << "B" << endl;
		}
			break;
		case 99: {
			C.setAll("C", 1, 17, 127);
			C.printAll();
			//cout << "C" << endl;
		}
			break;
		case 100: {
			D.setAll("D", 1, 17, 127);
			D.printAll();
			//cout << "D" << endl;
		}
			break;
		case 101: {
			E.setAll("E", 1, 17, 127);
			E.printAll();
			//cout << "E" << endl;
		}
			break;
		case 102: {
			F.setAll("F", 1, 17, 127);
			F.printAll();
			//cout << "F" << endl;
		}
			break;
		case 103: {
			G.setAll("G", 1, 17, 127);
			G.printAll();
			//cout << "G" << endl;
		}
			break;
		default:
			//printf("%d \n", (int)notecode);
			cout << "Some other note." << endl;
		}
		//if (notecode == 27)
		//	break;

		/*
		if (keycode == 27)
			break;
		else if (keycode == 37)
			printf("LEFT");
		else if (keycode == 80)
			printf("DOWN");
		else
			printf("%d", (int)keycode);
			*/
	};
	return 0;
}
