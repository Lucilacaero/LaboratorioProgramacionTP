

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
cVikingos::cVikingos(const cVikingos& otro)  {// ya le encontre un uso
	this->Tipo = otro.Tipo;
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

cVikingos::cVikingos(string tipo, string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto)
	: cPersona(tipo,nombre, fecha_nac, fuerza, vida, muerto) {
	Trabajo = trabajo;
	Dragon = dragon; 
	Dragon_Muerto = dragon_muerto;

}
cVikingos::~cVikingos() {}

int cVikingos::atacar()
{// en el caso de los vikingos asumo que la fuerza va hasta 700, de los dragones hasta 1000 
	int danio = 0;
	if (Fuerza < 100) {
		danio = rand() % 200;}
	else if (Fuerza < 200) {
		danio = rand() % 300;}
	else if (Fuerza < 300) {
		danio = rand() % 400;}
	else if (Fuerza < 400) {
		danio = rand() % 500;	}
	else {danio = rand() % 700;}
	
	cout << "el vikingo genero un danio de " << danio << " puntos." << endl;
	return danio;
}

Posicion cVikingos::getPosicion() const
{
	return Trabajo;
}





void cVikingos::asignarDragon(list <cDragones*> dragones, cDragones * dragon) {
	if (dragon != nullptr && dragon->Domado()) {
		this->Dragon = dragon;
	} 
	else {
		cout << "El dragon no esta disponible o esta domado." << endl;
		while (Dragon == nullptr) {
			dragon = aleatorio(dragones);
			asignarDragon(dragones, dragon);
		}
		
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



void cVikingos::setDragonmuerto()
{
	Dragon_Muerto++;
}

cDragones* cVikingos::getDragon() {
	return this->Dragon;
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




string cVikingos::to__string()
{

	string str_trabajo = TrabajoToString(Trabajo);
	string s = cPersona::to__string();
	s += " Trabajo: " + str_trabajo + "\n" + " Dragon Muerto: " + to_string(Dragon_Muerto) + "\n" + "\n";

	return s;
}

void cVikingos::Imprimir()
{
	cout << to__string();
}





// Sobrecarga del operador += para agregar un cVikingos a la lista
list<cVikingos*>& operator+=(list<cVikingos*>& lista, cVikingos* vikingo) {
	lista.push_back(vikingo);
	return lista;
}

// Sobrecarga del operador -= para eliminar un cVikingos de la lista
list<cVikingos*>& operator-=(list<cVikingos*>& lista, cVikingos* vikingo) {
	auto it = find(lista.begin(), lista.end(), vikingo);
	if (it != lista.end()) {
		delete* it;
		lista.erase(it);
	}
	return lista;
}

ostream& operator<<(ostream& out,  cVikingos& vikingo) {
	out << left << setw(15) << setfill(' ') << "Vikingo"
		<< left << setw(15) << setfill(' ') << vikingo.Nombre
		<< left << setw(15) << setfill(' ') << vikingo.Fecha_nac
		<< left << setw(10) << setfill(' ') << vikingo.Fuerza
		<< left << setw(10) << setfill(' ') << vikingo.Vida
		<< left << setw(10) << setfill(' ') << (vikingo.Muerto ? "si" : "no")
		<< left << setw(15) << setfill(' ') << TrabajoToString(vikingo.Trabajo) // Assumes you have a function to convert Posicion to string
		<< endl;
	return out;
}
