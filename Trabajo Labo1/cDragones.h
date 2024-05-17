#pragma once
#include <string>
#include <iostream>
using namespace std;
struct {
	string color;
	int peso;
	//enum edad;
	enum FormaAtaque Ataque;

} typedef sDescripcion;

enum FormaAtaque { Notiene, Respirarfuego, Proyectiles, Garrasycolmillos, Cargasaereas, Ataquesfisicos };


class cDragones
{
private:
	string Nombre; 
	sDescripcion Ficha;
	bool Estado; // domado o no
	//enum FormaAtaque* Ataque;
	int Entrenado;
	int PuntosDomado;
	bool Muerte; 
	int vida;
		
public:
	cDragones();
	friend string Altanombre(string NombreDragon);
	friend void incorporar_dragon(cDragones* dragon);
	bool Domado();
	int Entrenar();
	int PuntosDomados();
	bool Baja();
};
