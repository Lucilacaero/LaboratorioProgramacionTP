#pragma once
#include "cVikingos.h"
#include "cDragones.h"
#include <string>



class cJinetes : protected cVikingos {
private:
	string Resultado;
	string NombreDragon;
public:
	
	cJinetes(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon);
	~cJinetes();
	//friend void asignarnombre(cJinetes& jinete, cDragones& dragon);
	friend void cDragones::setNombre(cJinetes*& jinete); 
	void entrenarDragon();
	friend cJinetes* aleatorio(list <cJinetes*> jinetes);
}; 