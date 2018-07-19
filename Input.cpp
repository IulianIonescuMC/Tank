#include <iostream>
#include <conio.h>
#include <windows.h>

#include "Input.h"

using namespace std;

//Inceput joc
void Input::init() {
	cout << "Start game !!!";
};

//Final joc
void Input::close() {
	cout << "Game over !!!";
};

//Taste de control
char Input::getc() {
	Sleep(120);
	if (_kbhit()) {
		char kbcode = _getch();
		switch (kbcode) {
			//Comenzi jucator I

		case 'a':
			return 'a';
			break;
		case 'd':
			return 'd';
			break;
		case 'w':
			return 'w';
			break;
		case 's':
			return 's';
			break;
		case 'q':
			return 'q';
			break;
			//Comenzi jucator II

		case 'j':
			return 'j';
			break;
		case 'l':
			return 'l';
			break;
		case 'i':
			return 'i';
			break;
		case 'k':
			return 'k';
			break;
		case 'o':
			return 'o';
			break;
			//Comanda iesire

		case 27:
			return 27;
			break;
		}
	}
	return '0';
}
