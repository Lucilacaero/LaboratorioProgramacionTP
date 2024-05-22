#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include "cDragones.h"
using namespace std;
enum Posicion { Entrenador, Guerrero, Agricultor, pescador, Herreros, Jinetes };
class cVikingos
{
	string Nombre;
	string Apellido;
	Posicion trabajo;
	int Dragon_Muerto;
	int vida;
	cDragones* dragon;

public:
	//faltan los const y dest 
	cVikingos(string Nombre, string Apellido, Posicion trabajo, int Dragon_Muerto, int vida, cDragones* dragon);
	~cVikingos();
	//enum Trabajar(); para mas adelante
	int Dragonesmuertos(bool Muerte);//suma un dragon muerto a vikingos

	bool Dragones_terminados(cDragones& _dragon);//es para ver si es positivo o negativo la cantidad de dragones muertos
	void Atacar_dragones(cDragones& _dragon);
	int Salud();// si llega a 0 muere
	

};

