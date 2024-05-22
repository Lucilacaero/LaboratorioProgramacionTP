#include "cJinetes.h"
#include "cDragones.h"


cJinetes::cJinetes(string Apodo, string Fecha_nac, sCaract Descripcion, string Resultado,
string NombreDragon,cDragones* dragones)
{
	this->Apodo= Apodo;
	this->Fecha_nac= Fecha_nac;
	this-> Descripcion.altura= Descripcion.altura;
	this->Descripcion.peso = Descripcion.peso;
	this->Descripcion.color_pelo = Descripcion.color_pelo;
	this->Descripcion.contextura = Descripcion.contextura;
	this->Resultado= Resultado;
	this->NombreDragon= NombreDragon;
	this->dragones= dragones;
} 

cJinetes::~cJinetes()
{
}

bool cJinetes::incorporar_dragon(cDragones* dragon) {
	/* Para incorporar un dragon el resultado tiene que ser 
	= aprobbado
	y el dragoninc no tiene que ser nulo y el estado del dragon tiene que ser true*/
	return true;
}
string cJinetes::getresultado() {
	return Resultado;
}
void cJinetes::setFechadeNacimiento(string fecha_nac) {
	Fecha_nac = fecha_nac;
}
void cJinetes::setApodo(string apodo) {
	this->Apodo = apodo;
}

