
#include "cPersona.h"

// using namespace std;

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

bool cPersona::getMuerto()
{
	return Muerto;
}

void cPersona::setNombre(const string& nombre) {
	Nombre = nombre;
}

cPersona::cPersona()
{
	Nombre = " ";
	Fecha_nac= " ";
	Fuerza= 100; // Cambiado a unsigned int
	Vida= 500;
	Muerto= false;
}

string cPersona::to__string()
{
	string s;
	s = "Nombre: " + Nombre
		+ ", Fecha de nacimiento: " + Fecha_nac
		+ ", Fuerza: " + to_string(Fuerza)//castea 
		+ ", Vida: " + to_string(Vida)
		+ ", Esta muerto: " + (Muerto ? "Sí" : "No");
	return s;
}

void cPersona::Imprimir()
{
	cout << to__string();
}



