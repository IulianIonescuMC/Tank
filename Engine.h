#ifndef ENGINE_H_
#define ENGINE_H_

#define MaxNrLin 100
#define MaxNrCol 100
#define MaxNrUnit 10000
#define MaxNrMess 10000

class Unit;

class Engine {
	friend class Unit;

	Unit * unitTabela[MaxNrLin][MaxNrCol];
	Unit * unitVector[MaxNrUnit];

	int NrCol, NrLin, NrUnit;

	public:
		void init(int, int);
		int getNrLin();
		int getNrCol();
		int getNrUnit();
		int validxy(int, int);		 //test:parametrii reprezinta o valoare valida pe UnitTabela 
		int validpoz(int);           //test:e pe UnitVector
		Unit* getunitxy(int, int);
		Unit* getunitpoz(int);       //return adresa unitatii de pe poz data in UnitVector
		void next();                 
};

class Unit {
	friend class Engine;

	int alive;
	int x, y, pozitie;
	int message[MaxNrMess];
	int NrMess;
	void reactiune();

	protected:
		Unit(int, int);   //Constructor  !!!
		virtual ~Unit();  //Destructor   !!!

		void die();
		void move(int, int);
		void sendMes(int, Unit&);
		virtual void action() = 0;				//Actiunea unei unitati
		virtual void behaviour(int) = 0;		//Comportamentul la o actiune

	public:
		static Engine Motor;
		int getX();
		int getY();
		virtual void * getTip() = 0;     //Informatii despre unitate
};

#endif // !ENGINE_H_