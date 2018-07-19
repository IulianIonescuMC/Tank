#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Output.h"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

Output::Output(Engine& pm) :Motor(pm) {
}

static int pictvect[MaxNrUnit][2], npict;

void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor);
}

void Output::init() {
	npict = 0;
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = false;
	lpCursor.dwSize = 1;
	SetConsoleCursorInfo(console, &lpCursor);
	system("cls");
	for (int i = 0; i < Motor.getNrUnit(); i++) {
		if (Motor.getunitpoz(i) != NULL) {
			if (*((char*)Motor.getunitpoz(i)->getTip()) != (char)177) {
				pictvect[npict][0] = Motor.getunitpoz(i)->getX();
				pictvect[npict][1] = Motor.getunitpoz(i)->getY();
				npict++;
			}
		}
	}
	for (int i = 0; i < Motor.getNrUnit(); i++) {
		gotoxy(Motor.getunitpoz(i)->getX(), Motor.getunitpoz(i)->getY());
		cout << *((char*)Motor.getunitpoz(i)->getTip());
	}
}

void Output::close() {
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = true;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
	system("cls");
}
void Output::afisare() {
	for (int i = 0; i < npict; i++) {
		gotoxy(pictvect[i][0], pictvect[i][1]);
		cout << " ";
	}
	npict = 0;
	for (int i = 0; i < Motor.getNrUnit(); i++) {
		if (Motor.getunitpoz(i) != NULL) {
			if (*((char*)Motor.getunitpoz(i)->getTip()) != (char)177) {
				pictvect[npict][0] = Motor.getunitpoz(i)->getX();
				pictvect[npict][1] = Motor.getunitpoz(i)->getY();
				npict++;
			}
		}
	}
	for (int i = 0; i < npict; i++) {
		gotoxy(pictvect[i][0], pictvect[i][1]);
		cout << *(char*)Motor.getunitxy(pictvect[i][0], pictvect[i][1])->getTip();
	}
}
