//
// Powered by Andrew Toporivskiy
// 22.09.2016
//


#include "classes.h"
#include <iostream>
#include <cstring>
#include <conio.h> 
using namespace std;

int main() {
	cout << "Press any note: " << endl;
	unsigned char notecode;
	Note note;
	Frequency frequency;
	Image image;
	while (1) {
		notecode = _getch(); // Код символа
		switch (notecode)
		{
		case 97: {
			note.setAll("A", 1, 17, 127);
			cout << "Enter octave: \n";
			int o;
			cin >> o;
			note.setOctave(o);
			note.output();
			frequency.setName((char *)note.getName());
			frequency.setOctave((int)note.getOctave());
			frequency.setSustain((int)note.getSustain());
			frequency.setVelocity((int)note.getVelocity());
			frequency.autoFreq();
			frequency.output();
			image.setName((char *)note.getName());
			image.setOctave((int)note.getOctave());
			image.setSustain((int)note.getSustain());
			image.setVelocity((int)note.getVelocity());
			image.output();
			cout << endl;
		}
			break;
		case 98:{
			note.setAll("B", 1, 17, 127);
			note.output();
			frequency.setName((char *)note.getName());
			frequency.setOctave((int)note.getOctave());
			frequency.setSustain((int)note.getSustain());
			frequency.setVelocity((int)note.getVelocity());
			frequency.autoFreq();
			frequency.output();
			image.setName((char *)note.getName());
			image.setOctave((int)note.getOctave());
			image.setSustain((int)note.getSustain());
			image.setVelocity((int)note.getVelocity());
			image.output();
			cout << endl;
		}
			break;
		case 99: {
			note.setAll("C", 1, 17, 127);
			note.output();
			frequency.setName((char *)note.getName());
			frequency.setOctave((int)note.getOctave());
			frequency.setSustain((int)note.getSustain());
			frequency.setVelocity((int)note.getVelocity());
			frequency.autoFreq();
			frequency.output();
			image.setName((char *)note.getName());
			image.setOctave((int)note.getOctave());
			image.setSustain((int)note.getSustain());
			image.setVelocity((int)note.getVelocity());
			image.output();
			cout << endl;
		}
			break;
		case 100: {
			note.setAll("D", 1, 17, 127);
			note.output();
			frequency.setName((char *)note.getName());
			frequency.setOctave((int)note.getOctave());
			frequency.setSustain((int)note.getSustain());
			frequency.setVelocity((int)note.getVelocity());
			frequency.autoFreq();
			frequency.output();
			image.setName((char *)note.getName());
			image.setOctave((int)note.getOctave());
			image.setSustain((int)note.getSustain());
			image.setVelocity((int)note.getVelocity());
			image.output();
			cout << endl;
		}
			break;
		case 101: {
			note.setAll("E", 1, 17, 127);
			note.output();
			frequency.setName((char *)note.getName());
			frequency.setOctave((int)note.getOctave());
			frequency.setSustain((int)note.getSustain());
			frequency.setVelocity((int)note.getVelocity());
			frequency.autoFreq();
			frequency.output();
			image.setName((char *)note.getName());
			image.setOctave((int)note.getOctave());
			image.setSustain((int)note.getSustain());
			image.setVelocity((int)note.getVelocity());
			image.output();
			cout << endl;
		}
			break;
		case 102: {
			note.setAll("F", 1, 17, 127);
			note.output();
			frequency.setName((char *)note.getName());
			frequency.setOctave((int)note.getOctave());
			frequency.setSustain((int)note.getSustain());
			frequency.setVelocity((int)note.getVelocity());
			frequency.autoFreq();
			frequency.output();
			image.setName((char *)note.getName());
			image.setOctave((int)note.getOctave());
			image.setSustain((int)note.getSustain());
			image.setVelocity((int)note.getVelocity());
			image.output();
			cout << endl;
		}
			break;
		case 103: {
			note.setAll("G", 1, 17, 127);
			note.output();
			frequency.setName((char *)note.getName());
			frequency.setOctave((int)note.getOctave());
			frequency.setSustain((int)note.getSustain());
			frequency.setVelocity((int)note.getVelocity());
			frequency.autoFreq();
			frequency.output();
			image.setName((char *)note.getName());
			image.setOctave((int)note.getOctave());
			image.setSustain((int)note.getSustain());
			image.setVelocity((int)note.getVelocity());
			image.output();
			cout << endl;
		}
			break;
		default:
			//printf("%d \n", (int)notecode);
			cout << "Some other note." << endl;
		}
		//if (notecode == 27)
		//	break;
	}
	return 0;
}