#include "cJinetes.h"
#include "cDragones.h"


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

