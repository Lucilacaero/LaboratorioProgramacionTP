#include "cVikingos.h"
#include <iostream>
#include <cstdlib>
using namespace std;

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
		danio = rand() % 100;}
	else if (Fuerza < 200) {
		danio = rand() % 200;}
	else if (Fuerza < 300) {
		danio = rand() % 300;}
	else if (Fuerza < 400) {
		danio = rand() % 400;	}
	else {danio = rand() % 500;}
	
	cout << "el vikingo ataca y genera un daño de " << danio;
	return danio;
}

void cVikingos::vida(int danio)
{
	Vida = Vida - danio;
	if(Vida < 0 || Vida ==0)
		cout<< "El vikingo murio"<< endl;
	//sacarlo de la lista
}
/*
int cVikingos::getvida()
{
	return Vida;
}
*/
void cVikingos::asignarDragon(cDragones* dragon) {
	if (dragon != nullptr && dragon->Domado()) {
		this->Dragon = dragon;
		
	}
	else {
		cout << "El dragon no está disponible o no está domado." << endl;
	}
}
