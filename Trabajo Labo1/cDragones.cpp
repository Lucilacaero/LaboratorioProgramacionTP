
/*#include "cDragones.h"
#include <cstdlib> // Para rand() y srand()
int cDragones::DragonesVivos = 0;
int cDragones::DragonesMuertos = 0;
cDragones::cDragones(string nombre, string fecha_nac, string fuerza, int vida, bool muerto, string Ataque, bool Estado, int Entrenado, int PuntosDomado):cPersona(nombre, fecha_nac, fuerza, vida, muerto)
{
	this->Ataque = Ataque;
	this->Estado = Estado;
	this->Entrenado = Entrenado; 
	this->PuntosDomado = PuntosDomado; 
}

cDragones::~cDragones()
{
	DragonesVivos--;
	DragonesMuertos++;
}
*/
#include "cDragones.h"
#include <cstdlib> // Para rand() y srand()

int cDragones::DragonesVivos = 0;
int cDragones::DragonesMuertos = 0;
int cDragones::domados = 0;

cDragones::cDragones(string nombre, string fecha_nac, string fuerza, int vida, bool muerto, string ataque, bool estado, int entrenado, int puntosDomado)
	: cPersona(nombre, fecha_nac, fuerza, vida, muerto), Ataque(ataque), Estado(estado), Entrenado(entrenado), PuntosDomado(puntosDomado) {
	DragonesVivos++;
}

cDragones::~cDragones() {
	DragonesVivos--;
	DragonesMuertos++;
}