#include "cDragones.h"
#include "cJinetes.h"
#include <iostream>
#include <random> 
#include <cstdlib>
using namespace std;
int cDragones::DragonesVivos = 0;
int cDragones::DragonesMuertos = 0;
int cDragones::domados = 0;


//CONSTRUCTORES Y DESTRUCTORES
cDragones::cDragones(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, unsigned int id, string ataque, bool estado, int entrenado)
	: cPersona(nombre, fecha_nac, fuerza, vida, muerto) {
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

void cDragones::setMuerto(bool muerte)
{
	Muerto = muerte;
}

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

//FRIEND
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



void cDragones::formaDeAtaque() {
	//ASUMO QUE PUEDE ESTAR DESACTUUALIZADO Y COMO ENTRENA VA ADQQUIRIENDO NUEVAS FORMAS DE ATAQUE
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
	cout << "Después de asignar: Ataque = " << Ataque << endl;
	
}

bool cDragones::Domado() {
	if (Entrenado >= 100) {
		Estado = true;
		domados++;
	}
	return Estado;
}
void cDragones::vida(int danio)
{
	Vida = Vida - danio;
	if (Vida < 0 || Vida == 0) {
		Muerto = true;
		//system("pause");
		//system("cls");
	}
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
			cout << "No se detectó un tipo específico de ataque. Se le asignará un daño aleatorio.\n";
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
			cout << "No se detectó un tipo específico de ataque. Se le asignará un daño aleatorio.\n";
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
			cout << "No se detectó un tipo específico de ataque. Se le asignará un daño aleatorio.\n";
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

//	cout << "El dragón " << Nombre << " ataca y genera un daño de " << daniio << " puntos.\n";
	return daniio;
}


//FUNCIONES PARA CSV y otros
size_t cDragones::encontrarPosicion(list <cDragones*> dragones) {

	size_t posicion = 0;
	for (list<cDragones*>::iterator it = dragones.begin(); it != dragones.end(); ++it, ++posicion) {
		if ((*it)->Id == this->Id) {
			return posicion;
		}
		throw out_of_range("Elemento no encontrado en la lista");
	}

}

string cDragones::guardar() //va a ser para escribir mas facil el csv
{
	string s;
	s = to_string(Id) + "," + Ataque + "," + (Estado ? "Si" : "No") + "," + to_string(Entrenado);
	
	return s;
}

string cDragones::to__string(){
	//voy a imprimir todos los atributos de cPersona y despues le agrego los de la clase correspondiente
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
void cDragones::recibirDanio(int danio) {
	Vida = Vida - danio;
	if (Vida <= 0) {
		cout << "El dragón " << Nombre << " ha sido derrotado." << endl;
		// Podrías implementar aquí la lógica adicional cuando el dragón muere
	}
}

list<cDragones*>& operator+=(list<cDragones*>& lista, cDragones* dragon) {
	
	lista.push_back(dragon);
	return lista;
}

// Sobrecarga del operador -= para eliminar un cDragones de la lista
list<cDragones*>& operator-=(list<cDragones*>& lista, cDragones* dragon) {
	lista.remove(dragon);
	return lista;
}


