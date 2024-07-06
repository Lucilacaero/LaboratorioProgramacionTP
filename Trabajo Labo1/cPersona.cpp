
#include "cPersona.h"

// using namespace std;

//la clase cPersona es mas que nada abstracta 
cPersona::cPersona(string tipo,string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto)
{
	Tipo = tipo;
	Nombre = nombre;
	Fecha_nac = fecha_nac;
	Fuerza = fuerza;
	Vida = vida; 
	Muerto = muerto;
}
cPersona::cPersona(const cPersona& otro) {
	this->Tipo = otro.Tipo;
	this->Nombre = otro.Nombre;
	this->Fecha_nac = otro.Fecha_nac;
	this->Fuerza = otro.Fuerza;
	this->Vida = otro.Vida;
	this->Muerto = otro.Muerto;
	
}

cPersona::~cPersona() {}
void cPersona::setMuerto(bool muerte)
{
	Muerto = muerte;
}
int cPersona::getvida() const
{
	return Vida;
}

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
	s = " Nombre: " + Nombre + "\n"
		+ " Fecha de nacimiento: " + Fecha_nac + "\n"
		+ " Fuerza: " + to_string(Fuerza) + "\n"	  
		+ " Vida: " + to_string(Vida) + "\n"
		+ " Esta muerto: " + (Muerto ? "Si" : "No") + "\n";
	return s;
}

void cPersona::Imprimir()
{
	cout << to__string();
}
