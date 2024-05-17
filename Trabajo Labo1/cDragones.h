#include <string>
#include <iostream>
using namespace std;
struct {
	string color;
	int peso;
	int edad;
	enum FormaAtaque Ataque;

} typedef sDescripcion;

enum FormaAtaque { Notiene, Respirarfuego, Proyectiles, Garrasycolmillos, Cargasaereas, Ataquesfisicos };


class cDragones
{
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
	friend cDragones* dragonAsignado;
	friend int Dragonesmuertos(bool Muerte);//suma un dragon muerto a vikingos
	friend bool incorporar_dragon(cDragones* dragon);
	void Altanombre(string NombreDragon);
	
	bool Domado();
	int Entrenar();
	int PuntosDomados();
	bool Baja();
	
};
