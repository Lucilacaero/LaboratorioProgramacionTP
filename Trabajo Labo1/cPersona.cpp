#pragma once
#include "cPersona.h"
#include<string>
#include <iostream>
using namespace std;

//la clase cPersona es mas que nada abstracta 
cPersona::cPersona(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto)
{
	Nombre = nombre;
	Fecha_nac = fecha_nac;
	Fuerza = fuerza;
	Vida = vida; 
	Muerto = muerto;
}

cPersona::~cPersona() {}

void cPersona::setNombre(const string& nombre) {
	Nombre = nombre;
}



/*
int cPersona::atacar() {
	// Implementación de la función atacar
	cout << Nombre << " está atacando!" << endl;
	return 0;
}
*/
/*
int cPersona::getvida() {
	return Vida;
}
*/

