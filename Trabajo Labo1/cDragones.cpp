/*
int cDragones::Entrenar()
{
	//tomar en consideracion 
	1. La fuerza del dragon y del jinete
	2. la posicion del jinete, si termina en 1 o 2 lugar tiene ventaja, sino es normalito
	3. 

*/
#include <cstdlib> // para randoms 
#include "cDragones.h"
#include "cJinetes.h"
#include <iostream>
using namespace std;
int cDragones::DragonesVivos = 0;
int cDragones::DragonesMuertos = 0;
// void cDragones::operator=() {

//}
cDragones::cDragones(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, string ataque, bool estado, int entrenado, int puntosDomado)
	: cPersona(nombre, fecha_nac, fuerza, vida, muerto) {
	Ataque = ataque;
	Estado = estado;
	Entrenado = entrenado;
	PuntosDomado = puntosDomado;
	DragonesVivos++;
}

cDragones::~cDragones() {
	DragonesVivos--;
	DragonesMuertos++;
}

void asignarnombre(cJinetes& jinete, cDragones& dragon)
{
	if (jinete.Resultado == "aprobado") {
	
		dragon.Nombre = jinete.NombreDragon;
		//jinete.Dragon = dragon;
		//usar una sobrecarga para poder pasarle el cdragon 
	}
}

void cDragones::formaDeAtaque() {
	if (Ataque == "no tiene"|| Ataque == " ") {
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
void cDragones::Domado() {
	if (PuntosDomado >= 100) {
		Estado = true;
		domados++;
	}
		
}
void cDragones::mostrarnombre() {
	cout << Nombre << endl;
}

void cDragones::atacar()
{
	if (Ataque == "no tiene") {
		cout << "no se pero que pase algo";
	}


	cout << "el dragon ataca";
}
// esta funcion trae problemas.

//te odiooooooooooooooooooo
void cDragones::modificarDragonSegunJinete(cJinetes& jinete) {
	jinete.evaluarResultado();
	unsigned int *auxfuerza = new unsigned int;
	//&auxfuerza = getFuerza(jinete);
	//if (Fuerza == &auxfuerza)
		//Entrenado = Entrenado + 10;
}
void Entrenar(cJinetes& jinete, cDragones& dragon)
{
	if (dragon.Fuerza > jinete.Fuerza && dragon.Fuerza + jinete.Fuerza > 100) {
		jinete.Vida =jinete.Vida- rand()/10;
		dragon.Entrenado = dragon.Entrenado + rand() / 5;
		dragon.PuntosDomado= dragon.PuntosDomado + rand() / 5;
	}
	else if (dragon.Fuerza > jinete.Fuerza && dragon.Fuerza + jinete.Fuerza > 200) {
		jinete.Vida = jinete.Vida - rand() / 20;
		dragon.Entrenado = dragon.Entrenado + rand() / 5;
		dragon.PuntosDomado = dragon.PuntosDomado + rand() / 5;
	}
	else if (dragon.Fuerza > jinete.Fuerza && dragon.Fuerza + jinete.Fuerza > 300) {
		jinete.Vida = jinete.Vida - rand() / 30;
		dragon.Entrenado = dragon.Entrenado + rand() / 5;
		dragon.PuntosDomado = dragon.PuntosDomado + rand() / 5;
	}
	if (dragon.Fuerza < jinete.Fuerza && dragon.Fuerza + jinete.Fuerza > 100) {
		dragon.PuntosDomado = dragon.PuntosDomado + rand() / 5;
		dragon.Entrenado = dragon.Entrenado + rand() / 10;
	}
	else if (dragon.Fuerza < jinete.Fuerza && dragon.Fuerza + jinete.Fuerza > 200) {
		dragon.PuntosDomado = dragon.PuntosDomado + rand() / 5;
		dragon.Entrenado = dragon.Entrenado + rand() / 20;
	}if (dragon.Fuerza < jinete.Fuerza && dragon.Fuerza + jinete.Fuerza > 300) {
		dragon.PuntosDomado = dragon.PuntosDomado + rand() / 5;
		dragon.Entrenado = dragon.Entrenado + rand() / 30;
	}
	//agregar que pasaria si el jinete se queda sin vida en el medio del entrenamiente
}