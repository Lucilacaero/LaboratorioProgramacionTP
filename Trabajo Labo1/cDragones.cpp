#include "cDragones.h"
#include "cVickingos.h"
#include "cJinetes.h"

cDragones::cDragones() {
	Nombre= " ";
	Estado= false; // domado o no
	
	Entrenado=0;
	PuntosDomado=0;
	Muerte= false;
	vida= 10;
	Ficha.color=" ";
	Ficha.peso= 0;
	//enum edad;
	Ficha.Ataque= FormaAtaque::Notiene;

};

bool cDragones::Domado() {
	if (Entrenado >= 10) {
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
cDragones::~cDragones() {
	DragonesVivos--;
	DragonesMuertos++;
}
void cDragones::Altanombre(string NombreDragon) {
	if (Estado == true)//cambiar estos if por try/catch 
		this->Nombre = NombreDragon;

}