#include "cDragones.h"
#include "cJinetes.h"
#include <iostream>
#include <random> 
#include <cstdlib>
using namespace std;
int cDragones::DragonesVivos = 0;
int cDragones::DragonesMuertos = 0;
int cDragones::domados = 0;
// void cDragones::operator=() {

//}
cDragones::cDragones(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, unsigned int id, string ataque, bool estado, int entrenado)
	: cPersona(nombre, fecha_nac, fuerza, vida, muerto) {
	Id = id;
	Ataque = ataque;
	Estado = estado;
	Entrenado = entrenado;
	DragonesVivos++;
}

cDragones::~cDragones() {
	DragonesVivos--;
	DragonesMuertos++;
}


	//GETTERS

int cDragones::getvida() {
	return Vida;
}

unsigned int cDragones::getfuerza()
{
	return Fuerza;
}

int cDragones::getEntrenado()
{
	return Entrenado; 
}

bool cDragones::getMuerto()
{
	return Muerto;
}

unsigned int cDragones::getid()
{
	return Id;
}

string cDragones::getnombre() {
	return Nombre;
}


//SETTERS



void cDragones::setEntrenado(int entrenado)
{
	this->Entrenado = entrenado;
}

void cDragones::setNombre(cJinetes*& jinete)
{
	try {
		// el puntero jinete no debe se nulo
		if (jinete == nullptr) {
			throw invalid_argument("Error: jinete es un puntero nulo"); //un tipo de error definido
		}
		this->Nombre = jinete->NombreDragon;
	}
	catch (const invalid_argument& e) {
		cerr << e.what() << endl; // cerr = cout error
	}

}

cDragones* aleatorio( list<cDragones*> dragones)
{
		if (dragones.empty()) {
			throw out_of_range("La lista está vacía");
		}
		list<cDragones*>::iterator it = dragones.begin();
		advance(it, rand() % dragones.size());
		return *it;
	
}
  

//Otras funciones importantes y no tanto



bool cDragones::Domado() {
	if (Entrenado >= 100) {
		Estado = true;
		domados++;
	}
	return Estado;

}


void cDragones::formaDeAtaque() {
	if (Ataque == "no tiene" || Ataque == " ") {
		if (Entrenado < 100)
			Ataque = "No tiene";
		else if (Entrenado < 200 && Entrenado >100)
			Ataque = "Garras y colmillos";
		else if (Entrenado < 400 && Entrenado >200)
			Ataque = "Ataques fisicos";
		else if (Entrenado < 800 && Entrenado >400)
			Ataque = "Respirar fuego";
		else if (Entrenado < 1600 && Entrenado >800)
			Ataque = "Cargas aereas";
		else if (Entrenado < 3200 && Entrenado >1600)
			Ataque = "Proyectiles";

	}
}


int cDragones::danio() {
	return 0;
}
void cDragones::vida(int danio)
{
	Vida = Vida - danio;
	if (Vida < 0 || Vida == 0) {
		cout << "El dragon murio" << endl;
		Muerto = true;
	}
	//sacarlo de la lista 
}

int cDragones::atacar()
{

	//para calcular el danio que puede causar un dragon voy a tomar en cuenta la fueerza del dragon y su tipo de ataque
	/* si su fuerza es alta (de 1500 a 1000 puntos)
	si su ataque es el 1 y 2 danio es de 900 a 1000 puntos
	si su ataque es el 3 y 4 danio es de 1000 a 1250 puntos
	si su ataque es el 5 y 6 danio es de 1250 a 1500 puntos

	si su fuerza es media (de 1000 a 500 puntos)
	si su ataque es el 1 y 2 danio es de 500 a 750 puntos
	si su ataque es el 3 y 4 danio es de 750 a 900 puntos
	si su ataque es el 5 y 6 danio es de 900 a 1000 puntos

	si su fuerza es media (de 1000 a 500 puntos)
	si su ataque es el 1 y 2 danio es de 0 a 250 puntos
	si su ataque es el 3 y 4 danio es de 250 a 500 puntos
	si su ataque es el 5 y 6 danio es de 750 a 500 puntos */
	int daniio = 0;
	int max = 0;
	int min = 0;
	if (Fuerza < 1500 && Fuerza > 1000) {

		//Notiene, Garrasycolmillos, Ataquesfisicos, Respirarfuego, Cargasaereas, Proyectiles
		if (Ataque == "No tiene" || Ataque == "Garras y colmillos") {
			min = 900;
			max = 1000;
		}
		else if (Ataque == "Ataques fisicos" || Ataque == "Respirar fuego") {
			min = 750;
			max = 9000;
		}
		else if (Ataque == "Cargas aereas" || Ataque == "Proyectiles") {
			min = 900;
			max = 1000;
		}
		else {
			cout << "error, hacer algo con trycatch";
		}
	}

	else if (Fuerza < 1000 && Fuerza > 500) {

		//Notiene, Garrasycolmillos, Ataquesfisicos, Respirarfuego, Cargasaereas, Proyectiles
		if (Ataque == "No tiene" || Ataque == "Garras y colmillos") {
			min = 500;
			max = 750;
		}
		else if (Ataque == "Ataques fisicos" || Ataque == "Respirar fuego") {
			min = 750;
			max = 900;
		}
		else if (Ataque == "Cargas aereas" || Ataque == "Proyectiles") {
			min = 900;
			max = 1000;
		}
		else
			cout << "error, hacer algo con trycatch";


	}

	else if (Fuerza < 500 && Fuerza > 0) {

		//Notiene, Garrasycolmillos, Ataquesfisicos, Respirarfuego, Cargasaereas, Proyectiles
		if (Ataque == "No tiene" || Ataque == "Garras y colmillos") {
			min = 0;
			max = 250;
		}
		else if (Ataque == "Ataques fisicos" || Ataque == "Respirar fuego") {
			min = 250;
			max = 500;
		}
		else if (Ataque == "Cargas aereas" || Ataque == "Proyectiles") {
			min = 500;
			max = 750;
		}
		else
			cout << "error, hacer algo con trycatch";

	}


	
	// Genera y devuelve un número aleatorio dentro del rango
	daniio = rand() % max;
	return daniio;

}

size_t cDragones::encontrarPosicion(list <cDragones*> dragones) {

		size_t posicion = 0;
		for (list<cDragones*>::iterator it = dragones.begin(); it != dragones.end(); ++it, ++posicion) {
			//if ((it)->Id == this->Id) {
				return posicion;
		//}
		}
		throw out_of_range("Elemento no encontrado en la lista");
	}


cDragones* cDragones::encontrardragon(unsigned int id, list<cDragones*>& dragones)
{
	list<cDragones*>::iterator it;
	for (it = dragones.begin(); it != dragones.end(); ++it) {
		cDragones* dragon = *it;
		if (dragon->getid() == id) {
			return dragon;
		}
	}
	return nullptr;
}



string cDragones::to__string(){
	string s = cPersona::to__string();
	s += ", Id: " + to_string(Id)
		+ ", Ataque: " + Ataque
		+ ", Estado: " + (Estado ? "Domado" : "No domado")
		+ ", Entrenado: " + to_string(Entrenado);
	return s;
}


void cDragones::Imprimir()
{
	cout << to__string();
}