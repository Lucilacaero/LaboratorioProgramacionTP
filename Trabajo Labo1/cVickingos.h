#pragma once
#include <string>
#include <iostream>
using namespace std;
enum Posici�n { Entrenador, Guerrero, Agricultor, pescador, Herreros, Jinetes };
class cVikingos
{
	string Nombre;
	string Apellido;
	//string Posicion;
	enum Posici�n;
	int Dragon_Muerto;
	int vida;

public:
	enum Trabajar;
	bool Dragones_terminados();
	//void Atacar_dragones(cDragones* dragon);
	int Salud();// si llega a 0 muere
	friend int Dragonesmuertos(bool Muerte);

};

