#include "cPersona.h"
//la clase cPersona es mas que nada abstracta 
cPersona::cPersona(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto)
{
	Nombre = nombre;
	Fecha_nac = fecha_nac;
	Fuerza = fuerza;
	Vida = vida; 
	Muerto = muerto;
}



void cPersona::setNombre(const string& nombre) {
	Nombre = nombre;
}
cPersona::~cPersona() {}



int cPersona::atacar() {
	// Implementaci�n de la funci�n atacar
	cout << Nombre << " est� atacando!" << endl;
	return 0;
}


