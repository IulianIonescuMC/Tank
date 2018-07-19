#include <iostream>
#include <time.h>
#include "GameTanc.h"
#include "Input.h"
#include "Output.h"

using namespace std;

//Declarari statice
Engine Unit::Motor;
char Tanc::cc;
unsigned char Zid::name = 177;
unsigned char Bomba::name;
Input intrare;
Output iesire(Tanc::Motor);

int main() {

	Tanc::Motor.init(50, 30);
	Tanc *t1 = new Tanc('a', 'd', 'w', 's', 'q', '+', 1, 1);
	Tanc *t2 = new Tanc('j', 'l', 'i', 'k', 'o', '#', 48, 28);
	Zid *Z[MaxNrLin*MaxNrCol];
	int poz = 0;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 30; j++) {
			if (i == 0 || j == 0 || i == 49 || j == 29) {
				Z[poz] = new Zid(i, j);
				poz = poz + 1;
			}
		}
	}
	for (int i = 1; i < 8; i++) {
		Z[poz] = new Zid(i, 3);
		poz = poz + 1;
	}
	for (int i = 10; i < 24; i++) {
		Z[poz] = new Zid(6, i);
		poz = poz + 1;
	}
	for (int i = 19; i < 30; i++) {
		Z[poz] = new Zid(12, i);
		poz = poz + 1;
	}
	for (int i = 1; i < 17; i++) {
		Z[poz] = new Zid(15, i);
		poz = poz + 1;
	}
	for (int i = 10; i < 20; i++) {
		Z[poz] = new Zid(i, 16);
		poz = poz + 1;
	}
	for (int i = 4; i < 21; i++) {
		Z[poz] = new Zid(22, i);
		poz = poz + 1;
	}
	for (int i = 15; i < 28; i++) {
		Z[poz] = new Zid(i, 21);
		poz = poz + 1;
	}
	for (int i = 24; i < 30; i++) {
		Z[poz] = new Zid(17, i);
	}
	for (int i = 24; i < 27; i++) {
		Z[poz] = new Zid(29, i);
		Z[poz] = new Zid(30, i);
		poz = poz + 1;
	}
	for (int i = 18; i < 29; i++) {
		Z[poz] = new Zid(i, 25);
		poz = poz + 1;
	}
	for (int i = 26; i < 31; i++) {
		Z[poz] = new Zid(i, 15);
		poz = poz + 1;
	}
	for (int i = 39; i < 46; i++) {
		Z[poz] = new Zid(i, 18);
		poz = poz + 1;
	}
	for (int i = 16; i < 46; i++) {
		Z[poz] = new Zid(34, i);
		poz = poz + 1;
	}
	for (int i = 25; i < 29; i++) {
		Z[poz] = new Zid(45, i);
		poz = poz + 1;
	}
	for (int i = 1; i < 8; i++) {
		Z[poz] = new Zid(32, i);
		poz = poz + 1;
	}
	for (int i = 4; i < 12; i++) {
		Z[poz] = new Zid(40, i);
		poz = poz + 1;
	}
	for (int i = 34; i < 44; i++) {
		Z[poz] = new Zid(i, 12);
		poz = poz + 1;
	}
	intrare.init();
	iesire.init();
	do {
		Tanc::cc = intrare.getc();
		Tanc::Motor.next();
		iesire.afisare();
	} while (Tanc::cc != 27);
	intrare.close();
	iesire.close();
	cout << endl;
	cout << "Olla world !!!";
	cout << endl;
	return 0;
}

/*
int info1, info2;
cout << "Dati lungimea labirintului : "; cin >> info1;
cout << endl;
cout << "Dati latimea labirintului : "; cin >> info2;
cout << endl;

Tanc::Motor.init(info1, info2);

Zid *Z[MaxNrLin*MaxNrCol];
Tanc *T[2];
int poz = 0;
int nrtc = 0;

for (int i = 0; i < info1; i++) {
for (int j = 0; j < info2; j++) {
if (i == 0 || j == 0 || i == info1 - 1 || j == info2 - 1) {
Z[poz] = new Zid(i, j);
poz = poz + 1;
}
else {
int dec;
cout << "Doriti sa pozitionati un tanc la pozitia (" << i << ", " << j << ") ? ";
cout << endl;
cout << "1 - Da";
cout << endl;
cout << "0 - Nu";
cout << endl;
cin >> dec;
if (dec == 1) {
if (nrtc != 2) {
if (nrtc == 0) {
T[nrtc] = new Tanc('a', 'd', 'w', 's', 'q', '+', i, j);
nrtc = nrtc + 1;
}
else {
if (nrtc == 1) {
T[nrtc] = new Tanc('j', 'l', 'i', 'k', 'o', '#', i, j);
nrtc = nrtc + 1;
}
}

}
else {
cout << "Ati pozitionat deja doua tancuri !!! ";
cout << endl;
}
}
else {
cout << "Doriti sa pozitionati un zid la pozitia (" << i << ", " << j << ") ? ";
cout << endl;
cout << "1 - Da";
cout << endl;
cout << "0 - Nu";
cout << endl;
cin >> dec;
if (dec == 1) {
Z[poz] = new Zid(i, j);
poz = poz + 1;
}
}
}
}
}

intrare.init();
iesire.init();
do {
Tanc::cc = intrare.getc();
Tanc::Motor.next();
iesire.afisare();
} while (Tanc::cc != 27);
intrare.close();
iesire.close();

cout << endl;
cout << "Olla world !!!";
cout << endl;
return 0;
*/