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

int cVikingos::Dragonesmuertos(bool Muerte)
{
	if (Muerte == true) {
		delete dragon;
		Dragon_Muerto++;
		
	}
	return 0;
}

bool cVikingos::Dragones_terminados(cDragones & _dragon)
{
	return true;
}//es para ver si es positivo o negativo la cantidad de dragones muertos
void cVikingos::Atacar_dragones(cDragones&_dragon){ 
	//aca manda un cout y que genere como una "batalla" 
	//en la que aleatoriamente se infrinja da;o al dragon y al vikingo
	//Dragonesmuertos();
	
	dragon->Puntosvida();
	if (dragon->Baja() == true) {
		Dragonesmuertos(cDragones::getMuerte);
	}
	else
	vida = vida - rand() % 10;
	//Crear una funcion en vikingos y en dragones para que se resten puntos de vida.
}
int cVikingos::Salud() {
	return 2;
}// si llega a 0 muere

