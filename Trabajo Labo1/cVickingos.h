
#include <string>
#include <iostream>
using namespace std;
enum Posición { Entrenador, Guerrero, Agricultor, pescador, Herreros, Jinetes };
class cVikingos
{
	string Nombre;
	string Apellido;
	enum Posición;
	int Dragon_Muerto;
	int vida;

public:
	//enum Trabajar(); para mas adelante
	bool Dragones_terminados();//es para ver si es positivo o negativo la cantidad de dragones muertos
	void Atacar_dragones(cDragones* dragon);
	int Salud();// si llega a 0 muere
	

};

