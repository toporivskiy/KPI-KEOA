#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "classes.h"
#include <iostream>
#include <cstring>
using namespace std;

//////////// CLASS ////////////
class Note {
//private:
public:
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
	const char *getName() const { return name; };
	int getOctave() const { return octave; };
	int getSustain() const { return sustain; };
	int getVelocity() const { return velocity; };
	void output() {
		cout << name << ", " << octave << ", " << sustain << ", " << velocity << endl;
	};
};
//////////// end CLASS ////////////

//////////// INHERITANCE CLASSES ////////////
/// class Frequency ///
class Frequency : public Note {
public:
	double freq;
public:
	// Constructors:
	Frequency() {
		freq = 0;
	};
	Frequency(const Frequency& obj) { // Constructor of copying
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);

		octave = obj.octave;
		sustain = obj.sustain;
		velocity = obj.velocity;
		freq = obj.freq;
	};
	Frequency(char *x, int octave, int sustain, int v, double freq) :
		/*Frequency::freq(freq),*/ Note(x, octave, sustain, v) {
		Frequency::freq = freq;

		name = new char[strlen(x) + 1];
		strcpy(name, x);

		Frequency::octave = octave;
		this->sustain = sustain;
		velocity = v;
		Frequency::freq = freq;
	};

	// Destructor:
	~Frequency() { freq = 0; };

	// Selectors:
	void setFreq(double freq) {
		Frequency::freq = freq;
	};
	void autoFreq() {
		if (name[0] ==  'A')
				Frequency::setFreq(440.0*getOctave());
			else if (name[0] == 'B')
				Frequency::setFreq(493.9*getOctave());
			else if (name[0] == 'C')
				Frequency::setFreq(523.3*getOctave());
			else if (name[0] == 'D')
				Frequency::setFreq(587.3*getOctave());
			else if (name[0] == 'E')
				Frequency::setFreq(659.3*getOctave());
			else if (name[0] == 'F')
				Frequency::setFreq(698.5*getOctave());
			else if (name[0] == 'G')
				Frequency::setFreq(784.0*getOctave());
	};

	// Modificators:
	//double getFreq() { return freq; }; // Not needed
	void output() {
		cout << freq << " Hz" << endl;
	};
};
/// end of class Frequency ///

/// class Image ///
class Image : public Note {
public:
	char *img;
public:
	// Constructors:
	Image() {
		img = new char[13];
	};
	Image(const Image& obj) { // Constructor of copying
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);

		octave = obj.octave;
		sustain = obj.sustain;
		velocity = obj.velocity;

		img = new char[strlen(obj.img) + 1];
		strcpy(img, obj.img);
	};
	Image(char *x, int octave, int sustain, int v, char *img) :
		/*Image::freq(freq),*/ Note(x, octave, sustain, v) {
		Image::img = img;

		name = new char[strlen(x) + 1];
		strcpy(name, x);

		Image::octave = octave;
		this->sustain = sustain;
		velocity = v;

		Image::img = new char[strlen(img) + 1];
		strcpy(Image::img, img);
	};

	// Destructor:
	~Image() { delete name; name = NULL; };

	// Selectors:
	void setImg(char *img) {
		strcpy(Image::img, img);
	};

	   // Modificators:
	//const char *getImg() const { return img; }; // Not needed
	void output() {
		if (name[0] == 'A')
				Image::setImg((char *) "| ' ' | ' '+' |");
			else if (name[0] == 'B')
				Image::setImg((char *) "| ' ' | ' ' '+|");
			else if (name[0] == 'C')
				Image::setImg((char *) "|+' ' | ' ' ' |");
			else if (name[0] == 'D')
				Image::setImg((char *) "| '+' | ' ' ' |");
			else if (name[0] == 'E')
				Image::setImg((char *) "| ' '+| ' ' ' |");
			else if (name[0] == 'F')
				Image::setImg((char *) "| ' ' |+' ' ' |");
			else if (name[0] == 'G')
				Image::setImg((char *) "| ' ' | '+' ' |");
		cout << img << endl;
	};
};
/// end of class Image ///
//////////// end INHERITANCE CLASS ////////////
#endif

