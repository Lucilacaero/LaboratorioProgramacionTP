

#include "cPersona.h"
#include "cVikingos.h"
#include <iostream>
#include <cstdlib>
#include "AyuditaMain.h"
using namespace std;

cVikingos::cVikingos(): cPersona()
{
	Trabajo = Posicion::Agricultor;
	Dragon_Muerto= 0;
	Dragon = NULL;
	
}
cVikingos::cVikingos(const cVikingos& otro)  {
	this->Nombre = otro.Nombre;
	this->Fecha_nac = otro.Fecha_nac;
	this->Fuerza = otro.Fuerza;
	this->Vida = otro.Vida;
	this->Muerto = otro.Muerto;
	this->Trabajo = otro.Trabajo;
	this->Dragon = otro.Dragon;
	this->Dragon_Muerto = otro.Dragon_Muerto; 
	// Aquí se copian los atributos privados del objeto 'otro' al nuevo objeto creado
}

cVikingos::cVikingos(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto)
	: cPersona(nombre, fecha_nac, fuerza, vida, muerto) {
	Trabajo = trabajo;
	Dragon = dragon; 
	Dragon_Muerto = dragon_muerto;

}
cVikingos::~cVikingos() {}

int cVikingos::atacar()
{// en el caso de los vikingos asumo que la fuerza va hasta 500, de los dragones hasta 1000 
	int danio = 0;
	if (Fuerza < 100) {
		danio = rand() % 100;}
	else if (Fuerza < 200) {
		danio = rand() % 200;}
	else if (Fuerza < 300) {
		danio = rand() % 300;}
	else if (Fuerza < 400) {
		danio = rand() % 400;	}
	else {danio = rand() % 500;}
	
	cout << "el vikingo " << Nombre << " ataca y genera un danio de " << danio << " puntos al dragon "<< Dragon->getnombre() << endl;
	return danio;
}

Posicion cVikingos::getPosicion()
{
	return Trabajo;
}

void cVikingos::vida(int danio)
{
	Vida = Vida - danio;
	if (Vida < 0 || Vida == 0) {
		cout << "El vikingo murio en combate" << endl;
		Muerto = true;

		system("pause");
		system("cls");
	}
	
	//sacarlo de la lista
}



void cVikingos::asignarDragon(cDragones* dragon) {
	if (dragon != nullptr && dragon->Domado()) {
		this->Dragon = dragon;
		
	} 
	else {
		cout << "El dragon no está disponible o está domado." << endl;
	}
}

void cVikingos::trabajar()
{
	if (Trabajo == Posicion::Agricultor)
		cout << "el vikingo agricultor " << Nombre << " fue a cultivar" << endl;
	else if (Trabajo == Posicion::Entrenador)
		cout << "el vikingo entrenador " << Nombre << " fue a dar clases" << endl;
	else if (Trabajo == Posicion::Pescador)
		cout << "el vikingo pescador " << Nombre << " fue a trabajar" << endl;
	else if (Trabajo == Posicion::Guerrero) // llamar a funcion atacar
		cout << "el vikingo guerrero " << Nombre << " fue a pelear contra los dragones" << endl;
	else if (Trabajo == Posicion::Herrero)
		cout << "el vikingo herrero " << Nombre << " fue a soldar" << endl;
	else if (Trabajo == Posicion::Jinete)
		cout << "el vikingo Jinete " << Nombre << " fue a entrenar su dragon "<< Dragon->getnombre() << endl;
	//llamar a la funcion entrenar
}

bool cVikingos::getMuerto()
{
	return false;
}

cDragones* cVikingos::getDragon() {
	return this->Dragon;
}
void cVikingos::setMuerto(bool muerte)
{
	Muerto = muerte;
}
void cVikingos::setDragon(cDragones* dragon) {
	this->Dragon = dragon;
}
cVikingos* aleatorio(list <cVikingos*> vikingos) {

	if (vikingos.empty()) {
		throw out_of_range("La lista está vacía");
	}
	list<cVikingos*>::iterator it = vikingos.begin();
	advance(it, rand() % vikingos.size());
	return *it;
}


size_t cVikingos::encontrarPosicion(list <cVikingos*> vikingos) {

	size_t posicion = 0;
	for (list<cVikingos*>::iterator it = vikingos.begin(); it != vikingos.end(); ++it, ++posicion) {
		//if ((it)->Id == this->Id) {
		return posicion;
		//}
	}
	throw out_of_range("Elemento no encontrado en la lista");
}



string cVikingos::to__string()
{
	string s = cPersona::to__string();
	string str_trabajo = TrabajoToString(Trabajo);
	s += ", Trabajo: " + str_trabajo;


	// Si Dragon es un puntero válido, obtenemos su representación como string usando to_string() de cDragones
	if (Dragon != nullptr) {
		s += ", Dragon: " + Dragon->to__string();
	}
	else
		s += "No tiene dragon asignado";

	s += ", Dragon Muerto: " + to_string(Dragon_Muerto);

	return s;
}

void cVikingos::Imprimir()
{
	cout << to__string();
}

string cVikingos::getnombre()
{
	return Nombre;
}



string cVikingos::guardar()
{

	string s = cPersona::guardar();
	s = TrabajoToString(Trabajo) + "," + to_string(Dragon->getid()) + "," + to_string(Dragon_Muerto);
	return s;
}




int cVikingos::getvida()
{
	return Vida;
}
// Sobrecarga del operador += para agregar un cVikingos a la lista
list<cVikingos*>& operator+=(list<cVikingos*>& lista, cVikingos* vikingo) {
	lista.push_back(vikingo);
	return lista;
}

// Sobrecarga del operador -= para eliminar un cVikingos de la lista
list<cVikingos*>& operator-=(list<cVikingos*>& lista, cVikingos* vikingo) {
	lista.remove(vikingo);
	return lista;
}

