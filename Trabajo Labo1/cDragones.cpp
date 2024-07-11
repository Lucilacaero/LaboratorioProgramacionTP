#include "cDragones.h"
#include "cJinetes.h"
#include <iostream>
#include <random> 
#include <cstdlib>
#include "AyuditaMain.h"

using namespace std;
int cDragones::DragonesVivos = 0;
int cDragones::DragonesMuertos = 0;
int cDragones::Domados = 0;


//CONSTRUCTORES Y DESTRUCTORES
cDragones::cDragones(string tipo, string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, unsigned int id, string ataque, bool estado, int entrenado)
	: cPersona(tipo, nombre, fecha_nac, fuerza, vida, muerto) {
	Id = id;
	Ataque = ataque;
	Estado = estado;
	Entrenado = entrenado;
	DragonesVivos++;
}
cDragones::cDragones(const cDragones& otro) {
	// Constructor por copia, para copiar los elementos a una lista de modificados
	this->Nombre = otro.Nombre;
	this->Fecha_nac = otro.Fecha_nac;
	this->Fuerza = otro.Fuerza;
	this->Vida = otro.Vida;
	this->Muerto = otro.Muerto;
	this->Id = otro.Id;
	this->Ataque = otro.Ataque;
	this->Estado = otro.Estado;
	this->Entrenado = otro.Entrenado;
}

cDragones::cDragones()
{

	this->Tipo = "cDragon";
	this->Nombre = " ";
	this->Fecha_nac = " ";
	this->Fuerza = 0;
	this->Vida = 500;
	this->Muerto = false;
	this->Id = 0;
	this->Ataque = "No tiene";
	this->Estado = false;
	this->Entrenado = 0;
	
}


cDragones::~cDragones() {
	
}


	//GETTERS


unsigned int cDragones::getfuerza()const
{
	return Fuerza;
}

int cDragones::getEntrenado () const
{
	return Entrenado; 
}



unsigned int cDragones::getid() const
{
	return Id;
}


bool cDragones::getDomado() const
{
	return Estado;
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
			cout<< "Error: jinete es un puntero nulo"<<endl; 
		}
		this->Nombre = jinete->NombreDragon; 
	}
	catch (const invalid_argument& e) {
		cerr << e.what() << endl; // cerr = cout error
	}

}

//FRIEND
cDragones* aleatorio( list<cDragones*> dragones)
{
		if (dragones.empty()) {// VER QUE NO HAYA UN TRYCATCH CON EL ALETATORIO
			throw out_of_range("La lista está vacía");
		}
		list<cDragones*>::iterator it = dragones.begin();
		advance(it, rand() % dragones.size());
		return *it;
	
}




//Otras funciones importantes y no tanto



void cDragones::formaDeAtaque() {
//a medida que entrena tiene nuevas formas de ataque
	if (this->Ataque == "No tiene" || this->Ataque == " ") {
		if (Entrenado < 100)
			this->Ataque = "No tiene";
		else if (Entrenado < 200 && Entrenado >100)
			this->Ataque = "Garras y colmillos";
		else if (Entrenado < 400 && Entrenado >200)
			this->Ataque = "Ataques fisicos";
		else if (Entrenado < 800 && Entrenado >400)
			this->Ataque = "Respirar fuego";
		else if (Entrenado < 1600 && Entrenado >800)
			this->Ataque = "Cargas aereas";
		else if (Entrenado < 3200 && Entrenado >1600)
			this->Ataque = "Proyectiles";
	}
	
	
}

bool cDragones::Domado() {
	if (Entrenado >= 100) {
		Estado = true;
		Domados++;
	}
	return Estado;
}


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
int cDragones::atacar()
{
	int daniio = 0;
	int max = 0;
	int min = 0;

	if (Fuerza >= 0 && Fuerza <= 500) {
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
		else {
			cout << "No se detectó un tipo específico de ataque. Se le asignará un danioo aleatorio.\n";
			min = 0;
			max = 500;
		}
	}
	else if (Fuerza > 500 && Fuerza <= 1000) {
		if (Ataque == "No tiene" || Ataque == "Garras y colmillos") {
			min = 500;
			max = 750;
		}
		else if (Ataque == "Ataques físicos" || Ataque == "Respirar fuego") {
			min = 750;
			max = 900;
		}
		else if (Ataque == "Cargas aéreas" || Ataque == "Proyectiles") {
			min = 900;
			max = 1000;
		}
		else {
			cout << "No se detectó un tipo específico de ataque. Se le asignará un danio aleatorio.\n";
			min = 500;
			max = 1000;
		}
	}
	else if (Fuerza > 1000 && Fuerza <= 1500) {
		if (Ataque == "No tiene" || Ataque == "Garras y colmillos") {
			min = 900;
			max = 1000;
		}
		else if (Ataque == "Ataques físicos" || Ataque == "Respirar fuego") {
			min = 1000;
			max = 1250;
		}
		else if (Ataque == "Cargas aéreas" || Ataque == "Proyectiles") {
			min = 1250;
			max = 1500;
		}
		else {
			cout << "No se detectó un tipo específico de ataque. Se le asignará un danio aleatorio.\n";
			min = 1000;
			max = 1500;
		}
	}
	else {
		cout << "Error: La fuerza del dragón está fuera de los límites esperados.\n";
		return 0;
	}

	// Generar un número aleatorio en el rango [min, max]
	daniio = min + rand() % (max - min + 1);

	
	return daniio;
}


//funciones para csv y otros



string cDragones::to__string(){
	//voy a imprimir todos los atributos de cPersona y despues le agrego los de la clase correspondiente
	string s = cPersona::to__string();
	s += ", Id: " + to_string(Id) + "\n"
		+ ", Ataque: " + Ataque + "\n"
		+ ", Estado: " + (Estado ? "Domado" : "No domado") + "\n"
		+ ", Entrenado: " + to_string(Entrenado) + "\n";
	return s;
}


void cDragones::Imprimir()
{
	cout << to__string();
}



list<cDragones*>& operator+=(list<cDragones*>& lista, cDragones* dragon) {
	
	lista.push_back(dragon);
	return lista;
}

// Sobrecarga del operador -= para eliminar un cDragones de la lista
list<cDragones*>& operator-=(list<cDragones*>& lista, cDragones* dragon) {
	auto it = find(lista.begin(), lista.end(), dragon);
	if (it != lista.end()) {
		delete* it;
		lista.erase(it);
	}
	return lista;
}



ostream& operator<<(ostream& out, cDragones& dragon) {
	out << left << setw(15) << setfill(' ') << dragon.Tipo
		<< left << setw(15) << setfill(' ') << dragon.Nombre
		<< left << setw(15) << setfill(' ') << dragon.Fecha_nac
		<< left << setw(10) << setfill(' ') << dragon.Fuerza
		<< left << setw(10) << setfill(' ') << dragon.Vida
		<< left << setw(10) << setfill(' ') << (dragon.Muerto ? "si" : "no")
		<< endl;
	return out;
}