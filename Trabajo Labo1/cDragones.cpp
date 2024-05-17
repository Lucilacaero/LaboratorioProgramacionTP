#include "cDragones.h"
#include "cVickingos.h"
#include "cJinetes.h"

cDragones::cDragones() {
	Nombre= " ";
	sDescripcion Ficha;
	Estado= false; // domado o no
	
	Entrenado=0;
	PuntosDomado=0;
	Muerte= false;
	vida= 100;
	Ficha.color=" ";
	Ficha.peso= 0;
	//enum edad;
	Ficha.Ataque= FormaAtaque::Notiene;

};

bool cDragones::Domado() {
	if (Entrenado >= 100) {
		return true;
	}
}
int cDragones::Entrenar() {
	Entrenado++;
	return Entrenado;

}
int cDragones::PuntosDomados() {
	return PuntosDomado++;
}
bool cDragones::Baja() {
	if (vida <= 0)
		Muerte = true;
		return Muerte;
}

/*string Nombre;
sDescripcion Ficha;
bool Estado; // domado o no
enum FormaAtaque* Ataque;
int Entrenado;
int PuntosDomado;
bool Muerte;
*/