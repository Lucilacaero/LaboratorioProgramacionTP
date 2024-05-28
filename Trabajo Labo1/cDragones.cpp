#include "cDragones.h"
#include <cstdlib> // Para rand() y srand()
int cDragones::DragonesVivos = 0;
int cDragones::DragonesMuertos = 0;

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
	if (Entrenado >= 10) 
		return true;
	else
	return false;
}
int cDragones::Entrenar() {
	Entrenado = rand()%MaxEntrenamiento + Entrenado; // usar lo del resultado, si es aprobado sumar mas sino menos etc.
	return Entrenado;

}
int cDragones::PuntosDomados() {
	return PuntosDomado++;
}
void cDragones::Puntosvida()
{
	vida = vida - rand() % 10;
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



int cDragones::Dragonesmuertos()
{
	if (Muerte = true) {
	
		return cDragones::DragonesMuertos;

	}
	return 0;
}

bool cDragones::getEstado()
{
	if (Estado == true)
		return true;
	else
		return false;
}

bool cDragones::getMuerte()
{
	return Muerte;
}
