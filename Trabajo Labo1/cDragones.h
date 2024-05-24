
#pragma once
const int MaxEntrenamiento = 500;
#include <string>

#include <iostream>
using namespace std;

enum FormaAtaque { Notiene, Respirarfuego, Proyectiles, Garrasycolmillos, Cargasaereas, Ataquesfisicos };

typedef struct {
	string color;
	int peso;
	int edad;
	FormaAtaque Ataque;

} sDescripcion;



class cDragones{
private:
	string Nombre; 
	sDescripcion Ficha;
	bool Estado; // domado o no
	int Entrenado;
	int PuntosDomado;
	bool Muerte; 
	int vida;
	static int DragonesVivos;
	static int DragonesMuertos;
		
public:
	
	cDragones();
	~cDragones();
	//friend cDragones* dragonAsignado;
	void Altanombre(string NombreDragon);
	
	bool Domado();
	int Entrenar();
	int PuntosDomados();
	bool Baja();
	int Dragonesmuertos();
	bool getEstado();
	
};
