#pragma once
#include "cPersona.h"
#include "cDragones.h"
#include <string>
using namespace std;
enum Posicion { Entrenador, Guerrero, Agricultor, Pescador, Herrero, Jinete };

class cDragones;

class cVikingos : protected cPersona {
protected:
	Posicion Trabajo;
	cDragones* Dragon;
	int Dragon_Muerto;

public:
	cVikingos(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto);
	~cVikingos();
	int atacar();
	void vida(int danio);
	
	int getvida();
	void asignarDragon(cDragones* dragon);
};

