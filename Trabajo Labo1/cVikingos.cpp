#include "cVikingos.h"


cVikingos::cVikingos(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto)
	: cPersona(nombre, fecha_nac, fuerza, vida, muerto) {
	Trabajo = trabajo;
	Dragon = dragon; 
	Dragon_Muerto = dragon_muerto;
}

cVikingos::~cVikingos() {}

int cVikingos::atacar()
{// en el caso de los vikingos asumo que la fuerza va hasta 500, de los dragones hasta 1000 
	int danio = 0;
	if (Fuerza < 100) {
		danio = rand() % 10;}
	else if (Fuerza < 200) {
		danio = rand() % 20;}
		else if (Fuerza < 300) {
			danio = rand() % 30;}
		else if (Fuerza < 400) {
		danio = rand() % 40;	}
						else {danio = rand() % 50;}
	
	cout << "el vikingo ataca y genera un daño de " << danio;
	return danio;
}
