#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "classes.h"
#include <iostream>
#include <cstring>
using namespace std;

//////////// CLASS ////////////
class Note {
private:
	char *name;
	int octave, sustain, velocity;
public:
	// Constructors:
	Note() {
		name = new char[3];

		octave = 0;
		sustain = 0;
		velocity = 0;
	};
	Note(const Note& obj) { // Constructor of copying
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);

		octave = obj.octave;
		sustain = obj.sustain;
		velocity = obj.velocity;
	};
	Note(char *x, int octave, int sustain, int v) {
		name = new char[strlen(x) + 1];
		strcpy(name, x);

		Note::octave = octave;
		this->sustain = sustain;
		velocity = v;
	};

	// Destructor:
	~Note() { delete name; name = NULL; octave = 0; sustain = 0; velocity = 0; };

	// Selectors:
	void setName(char *); // A, B, C, D, E, F, G, H, A#, C#, D#, E#, F#, G#, Ab, Cb, Db, Eb, Fb, Gb
	void setOctave(int); // 1, 2, 3, 4, 5, -1, -2, -3, -4
	void setSustain(int); // 1+ ms
	void setVelocity(int); // 0-127
	void setAll(char *, int, int, int);

						   // Modificators:
	const char *getName() { return name; };
	int getOctave() { return octave; };
	int getSustain() { return sustain; };
	int getVelocity() { return velocity; };
	void printAll() {
		cout << name << "," << octave << "," << sustain << "," << velocity << endl;
	};
};
//////////// end CLASS ////////////

#endif

