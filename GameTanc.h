#ifndef GAMETANC_H_
#define GAMETANC_H_

#include "Engine.h"

// ZID
class Zid :public Unit {
	static unsigned char name;

	protected:
		void action();
		void behaviour(int);

	public:
		Zid(int, int);		//Constructor !!!
		void * getTip();
};

// BOMBA
class Bomba :public Unit {
	static unsigned char name;
	int dirX, dirY;

	protected:
		void action();
		void behaviour(int );

	public:
		Bomba(int, int, int, int);
		void * getTip();
};

// TANC
class Tanc :public Unit {
	unsigned char name;
	char stg, drp, sus, jos, foc;
	char pc;

	protected:
		void action();
		void behaviour(int);
	public:
		static char cc;
		Tanc(char, char, char, char, char, char, int, int);
		void * getTip();
};

#endif // !GAMETANC_H_