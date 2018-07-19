#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "GameTanc.h"

// OUTPUT
class Output {
	Engine & Motor;

	public:
		Output(Engine & pm);
		void init();
		void close();
		void afisare();
};

#endif // !OUTPUT_H_
