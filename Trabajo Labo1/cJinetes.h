#ifndef CJINETES_H
#define CJINETES_H

#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include "cDragones.h"
using namespace std;
struct {
	int peso;
	int altura; 
	string color_pelo;
	string contextura;
}typedef sCaract;
class cJinetes
{
private:
	string Apodo;
	string Fecha_nac;
	sCaract Descripcion;
	string Resultado;
	string NombreDragon;
	cDragones* dragones;
public:
	cJinetes(string Apodo, string Fecha_nac, sCaract Descripcion, string Resultado,
		string NombreDragon, cDragones* dragones);
	~cJinetes();
	bool incorporar_dragon(cDragones* dragon);
	
	string getresultado();
	
	void setFechadeNacimiento(string fecha_nac);

	void setApodo(string apodo);


};


#endif // CJINETES_H