/*#include "cVickingos.h"

//enum Trabajar;
cVikingos::cVikingos(string nombre, string fecha_nac, string fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto): cPersona (nombre,fecha_nac, fuerza, vida, muerto)
{
	Trabajo= trabajo;
	Dragon = dragon;
	Dragon_Muerto= dragon_muerto;
}

cVikingos::~cVikingos()
{
}*/
#include "cVikingos.h"


cVikingos::cVikingos(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto)
	: cPersona(nombre, fecha_nac, fuerza, vida, muerto) {
	Trabajo = trabajo;
	Dragon = dragon; 
	Dragon_Muerto = dragon_muerto;
}

cVikingos::~cVikingos() {}
