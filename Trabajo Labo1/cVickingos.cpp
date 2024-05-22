#include "cVickingos.h"
#include "cDragones.h"
//enum Trabajar;



cVikingos::cVikingos(string Nombre, string Apellido,Posicion trabajo, int Dragon_Muerto, int vida, cDragones* dragon)
{
	this->Nombre= Nombre;
	this->Apellido = Apellido;
	this->trabajo = trabajo;
	this->Dragon_Muerto= Dragon_Muerto;
	this->vida= vida;
	this->dragon= dragon;

}

cVikingos::~cVikingos()
{
}

bool cVikingos::Dragones_terminados(cDragones & _dragon)
{
	return true;
}//es para ver si es positivo o negativo la cantidad de dragones muertos
void cVikingos::Atacar_dragones(cDragones&_dragon){
}
int cVikingos::Salud() {
	return 2;
}// si llega a 0 muere

