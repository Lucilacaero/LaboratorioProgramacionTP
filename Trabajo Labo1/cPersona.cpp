#include "cPersona.h"
cPersona::cPersona(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto)
{
	Nombre = nombre;
	Fecha_nac = fecha_nac;
	Fuerza = fuerza;
	Vida = vida;
	Muerto = muerto;
}



cPersona::~cPersona() {}



