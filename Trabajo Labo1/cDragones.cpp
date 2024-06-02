#include "cDragones.h"
#include <cstdlib> // Para rand() y srand()
#include <iostream>

int cDragones::DragonesVivos = 0;
int cDragones::DragonesMuertos = 0;
int cDragones::domados = 0;

cDragones::cDragones(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, string ataque, bool estado, int entrenado, int puntosDomado)
	: cPersona(nombre, fecha_nac, fuerza, vida, muerto), Ataque(ataque), Estado(estado), Entrenado(entrenado), PuntosDomado(puntosDomado) {
	DragonesVivos++;
}

cDragones::~cDragones() {
	DragonesVivos--;
	DragonesMuertos++;
}



void cDragones::setEstado()
{
	if (PuntosDomado >= 100)
		Estado = true;
}

void cDragones::mostrarnombre()
{
	cout << Nombre;
}

int cDragones::Entrenar()
{
	//tomar en consideracion 
	/*
	1. La fuerza del dragon y del jinete
	2. la posicion del jinete, si termina en 1 o 2 lugar tiene ventaja, sino es normalito
	3. 
	*/
	return 0;
}

