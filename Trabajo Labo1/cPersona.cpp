
#include "cPersona.h"
#include "ayuditaMain.h"
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

bool cPersona::getMuerto() const
{
	return Muerto;
}

string cPersona::getnombre() const
{
	return Nombre;
}

unsigned int cPersona::getFuerza() const
{
	return Fuerza;
}

void cPersona::vida(int danio)
{

	Vida = Vida - danio;
	if (Vida < 0 || Vida == 0) {

		Muerto = true;
		situarCursor(78, 3); cout << Nombre << " fue derrotado." << endl;
		if (Tipo == "dragon") {
			cDragones::DragonesMuertos++;
		}
		//esto me mato el programa, ponerl en otro lado
		//system("pause");
		//system("cls");
		//cout << "presiones enter para finalizar";
	}
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
