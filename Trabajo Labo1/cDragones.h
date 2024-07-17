
#pragma once
#include "cPersona.h"
#include <string>
#include<list>
class cVikingos;
class cJinetes;
const int MaxEntrenamiento = 3200;

// Entrenamiento de 0 a 100 para que adquiera el 1er
// Entrenamiento de 100 a 200 para que adquiera el 2do
// Entrenamiento de 200 a 400 para que adquiera el 3er
// Entrenamiento de 400 a 800 para que adquiera el 4to
// Entrenamiento de 800 a 1600 para que adquiera el 5to
// Entrenamiento de 1600 a 3200 para que adquiera el 6to

// Dependiendo de la FormadeAtaque que tenga el dragon, inflinge mas danio y va a ser mas dificil de domarlo
// ¿Como obtiene su forma de ataque? para empezar puede tenerla o no, pero si se lo esta entrenando va a ir subiendo de nivel y adquiriendo una nueva forma de ataque
// Se considera que esta domado una vez que este en 100 puntos de domado.
// Que tenga una forma de ataque definida no significa que tenga puntos de entrenamiento, a menos que asi sea.


class cDragones : public cPersona {
private:
	unsigned int Id;//para buscarlo facil en ell csv
	string Ataque;
	bool Estado;// domado o no
	int Entrenado;// para saber si esta domado y su forma de ataque
	
	


public:
	static int DragonesVivos;
	static int DragonesMuertos;
	static int Domados;
	//CONSTRUCTORES
	cDragones(string tipo, string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, unsigned int id, string ataque, bool estado, int entrenado);
	cDragones(const cDragones& otro);
	cDragones();
	~cDragones(); 
	
	//friend void asignarnombre(cJinetes& jinete, cDragones& dragon);
	
	
	//GETTERS Y SETTERS
	
	bool getDomado () const;
	int getEntrenado()const;
	unsigned int getfuerza() const;
	unsigned int getid() const;
	bool Domado(); 
	void setEntrenado(int entrenado); 
	void setNombre(cJinetes*& jinete);
	
	//Otras funciones
	int atacar();
	void formaDeAtaque();
	
	
	string to__string();
	void Imprimir();

	//Funciones friend

	friend cDragones* encontrardragon(unsigned int id, list<cDragones*>& dragones);
	friend cDragones* aleatorio(list <cDragones*> dragones);
	friend ostream& operator<<(ostream& out, cDragones& dragon);
};
list<cDragones*>& operator+=(list<cDragones*>& lista, cDragones* dragon);
list<cDragones*>& operator-=(list<cDragones*>& lista, cDragones* dragon);