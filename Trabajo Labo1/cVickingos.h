/*
#include "cPersona.h"
enum Posicion { Entrenador, Guerrero, Agricultor, pescador, Herreros, Jinetes };
class cVikingos : protected cPersona
{
protected:
	Posicion Trabajo;
	cDragones * Dragon;
	int Dragon_Muerto;

public:
	cVikingos(string nombre, string fecha_nac, string fuerza, int vida, bool muerto, Posicion trabajo, cDragones *dragon, int dragon_muerto);
	~cVikingos();
	//enum Trabajar(); para mas adelante


};*/
#pragma once
#include "cPersona.h"

enum Posicion { Entrenador, Guerrero, Agricultor, Pescador, Herrero, Jinete };

class cDragones; // Forward declaration

class cVikingos : protected cPersona {
protected:
	Posicion Trabajo;
	cDragones* Dragon;
	int Dragon_Muerto;

public:
	cVikingos(string nombre, string fecha_nac, string fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto);
	~cVikingos();
};
