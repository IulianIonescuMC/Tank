#include <iostream>
#include "Engine.h"

using namespace std;

//Initializare
void Engine::init(int Nc, int Nl) {
	if (Nc > MaxNrCol) {
		cout << "Matrix colum exedded";
		return;
	}

	if (Nl > MaxNrLin) {
		cout << "Matrix lines excedded";
		return;
	}

	else {
		this->NrCol = Nc;
		this->NrLin = Nl;
		this->NrUnit = 0;
		for (int i = 0; i < Nc; i++) {       //matrice de NULL
			for (int j = 0; j < Nl; j++) {
				unitTabela[i][j] = NULL;
			}
		}
	}
}

//GET - uri
int Engine::getNrLin() {
	return NrLin;
}

int Engine::getNrCol() {
	return NrCol;
}

int Engine::getNrUnit() {
	return NrUnit;
}

Unit* Engine::getunitxy(int x, int y) {
	return unitTabela[x][y];
}

Unit* Engine::getunitpoz(int poz) {
	return unitVector[poz];
}

//Verificare de pozitie
int Engine::validxy(int x, int y) {
	if (x >= 0 && x < NrCol && y >= 0 && y < NrLin) {
		return 1;
	}
	return 0;
}

//Validarea pozitiei
int Engine::validpoz(int p) {
	if (p >= 0 && p < NrUnit) {
		return 1;
	}
	return 0;
}

//Urmatoarea miscare
void Engine::next() {
	for (int i = 0; i < NrUnit; i++) {
		unitVector[i]->action();
	}

	for (int i = 0; i < NrUnit; i++) {
		unitVector[i]->reactiune();
	}

	for (int i = 0; i < NrUnit; i++) {
		if (unitVector[i]->alive == 0) {
			unitTabela[unitVector[i]->getX()][unitVector[i]->getY()] = NULL;
			delete unitVector[i];
			for (int j = i; j < NrUnit; j++) {
				unitVector[j] = unitVector[j + 1];
			}
			NrUnit--;
		}
	}
}

//Reactiunea
void Unit::reactiune() {
	for (int i = 0; i < NrMess; i++) {
		if (alive == 1) {
			this->behaviour(message[i]);
		}
	}
	NrMess = 0;
}

//Constructor
Unit::Unit(int x, int y) {
	this->x = x;
	this->y = y;

	if (Motor.validxy(x, y) == 0 || Motor.NrUnit == MaxNrUnit) {
		cout << "Nu s-a creat unitatea";
		return;
	}

	NrMess = 0;
	alive = 1;
	Motor.unitVector[Motor.NrUnit] = this;
	Motor.NrUnit++;
	Motor.unitTabela[x][y] = this;
}

//Destructor
Unit::~Unit() {
	if (message) {
		//se sterg mesajele oricum
	}
}

//Distrugere unitate
void Unit::die() {
	alive = 0;
}

//Miscare
void Unit::move(int dx, int dy) {
	int tempx = x + dx;
	int tempy = y + dy;
	Motor.unitTabela[tempx][tempy] = this;
	Motor.unitTabela[x][y] = NULL;
	x = tempx;
	y = tempy;
}

//Transmitere mesaje
void Unit::sendMes(int pm, Unit& pu) {
	if (pu.NrMess == MaxNrMess) {
		return;
	}
	else {
		pu.message[pu.NrMess] = pm;
		pu.NrMess = pu.NrMess + 1;
	}
}

//GET - uri
int Unit::getX() {
	return x;
}

int Unit::getY() {
	return y;
}
