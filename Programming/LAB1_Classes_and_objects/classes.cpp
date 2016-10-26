//
// Powered by Andrew Toporivskiy
// 16.09.2016
//


#include "classes.h"
#include <iostream>
#include <cstring>
using namespace std;




// Initializations of modificators:
void Note::setName(char *name) {
	strncpy(Note::name, name, 2);
	//*name = ('G');
};

void Note::setOctave(int octave) {
	this->octave = octave;
};

void Note::setSustain(int sustain) {
	this->sustain = sustain;
};

void Note::setVelocity(int v) {
	velocity = v;
};

void Note::setAll(char *name, int octave, int sustain, int v) {
	setName(name);
	setOctave(octave);
	setSustain(sustain);
	setVelocity(v);
}