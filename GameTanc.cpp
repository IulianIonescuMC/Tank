#include <iostream>
#include "GameTanc.h"

using namespace std;

//Zidul nu face nimic !!!
void Zid::action() {};

void Zid::behaviour(int a) {};

Zid::Zid(int x, int y) :Unit(x, y) {
}

void* Zid::getTip() {
	return &name;
}

//Bomba
//Actiunea bombei
void Bomba::action() {
	int xn = getX() + dirX;
	int yn = getY() + dirY;
	if (Motor.validxy(xn, yn) == 0) {
		die();
	}
	else {
		if (Motor.getunitxy(xn, yn) == NULL) {
			move(dirX, dirY);
		}
		else {
			sendMes(1, *Motor.getunitxy(xn, yn));
			die();
		}
	}
}

void Bomba::behaviour(int a) {
	if (a == 1) {
		die();
	}
}

//Constructor bomba
Bomba::Bomba(int x, int y, int dirx, int diry) :Unit(x, y) {
	this->dirX = dirx;
	this->dirY = diry;
	name = '*';
}

void* Bomba::getTip() {
	return &name;
}

//Tanc
//Actiune tanc
void Tanc::action() {
	if (cc == stg) {
		if (Motor.validxy(getX() - 1, getY()) == 1 && Motor.getunitxy(getX() - 1, getY()) == NULL) {
			move(- 1,0);
		}
		pc = cc;
	}

	if (cc == drp) {
		if (Motor.validxy(getX() + 1, getY()) == 1 && Motor.getunitxy(getX() + 1, getY()) == NULL) {
			move( 1, 0);
		}
		pc = cc;
	}

	if (cc == sus) {
		if (Motor.validxy(getX(), getY() - 1) == 1 && Motor.getunitxy(getX(), getY() - 1) == NULL) {
			move(0 ,- 1);
		}
		pc = cc;
	}

	if (cc == jos) {
		if (Motor.validxy(getX(), getY() + 1) == 1 && Motor.getunitxy(getX(), getY() + 1) == NULL) {
			move(0, 1);
		}
		pc = cc;
	}

	if (cc == foc) {
		int bx, by;
		if (pc == stg) {
			bx = getX() - 1;
			by = getY();
			if (Motor.validxy(bx, by) == 1) {
				if (Motor.getunitxy(bx, by) == NULL) {
					new Bomba(bx, by, -1, 0);
				}
				else {
					sendMes(1, *Motor.getunitxy(bx, by));
				}
			}
		}

		if (pc == drp) {
			bx = getX() + 1;
			by = getY();
			if (Motor.validxy(bx, by) == 1) {
				if (Motor.getunitxy(bx, by) == NULL) {
					new Bomba(bx, by, 1, 0);
				}
				else {
					sendMes(1, *Motor.getunitxy(bx, by));
				}
			}
		}

		if (pc == sus) {
			bx = getX();
			by = getY() - 1;
			if (Motor.validxy(bx, by) == 1) {
				if (Motor.getunitxy(bx, by) == NULL) {
					new Bomba(bx, by, 0, -1);
				}
				else {
					sendMes(1, *Motor.getunitxy(bx, by));
				}
			}
		}

		if (pc == jos) {
			bx = getX();
			by = getY() + 1;
			if (Motor.validxy(bx, by) == 1) {
				if (Motor.getunitxy(bx, by) == NULL) {
					new Bomba(bx, by, 0, 1);
				}
				else {
					sendMes(1, *Motor.getunitxy(bx, by));
				}
			}
		}
	}
}

void Tanc::behaviour(int a) {
	if (a == 1) {
		die();
	}
}

//Constructor tanc
Tanc::Tanc(char stg, char dr, char sus, char jos, char foc, char nume, int x, int y) :Unit(x, y) {
	this->stg = stg;
	this->drp = dr;
	this->sus = sus;
	this->jos = jos;
	this->foc = foc;
	this->name = nume;
}

void* Tanc::getTip() {
	return &name;
}