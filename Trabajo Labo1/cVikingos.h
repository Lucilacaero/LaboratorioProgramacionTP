#pragma once
#include "cPersona.h"
#include "cDragones.h"


enum Posicion { Entrenador, Guerrero, Agricultor, Pescador, Herrero, Jinete };

class cDragones;

class cVikingos : protected cPersona {
protected:
	Posicion Trabajo;
	cDragones* Dragon;
	int Dragon_Muerto;
	

public:
	cVikingos();
	cVikingos(const cVikingos& otro);
	cVikingos(string tipo, string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto);
	virtual ~cVikingos();
	int atacar();
	int getvida();
	Posicion getPosicion();
	void vida(int danio);
	void setDragon(cDragones* dragon);
	cDragones* getDragon();
	void setMuerto(bool muerte);

	void asignarDragon(list <cDragones*> dragones, cDragones* dragon);
	void trabajar();
	bool getMuerto();
	void setDragonmuerto();
	friend cVikingos* aleatorio(list <cVikingos*> vikingos);
	
	virtual string to__string() override; //son virtual porque se lo voy a pasar a cJinete
	virtual void Imprimir();
	string getnombre();
	//friend void cargarlistas(string& nombreArchivo, list<cDragones*>& dragones, list <cVikingos*>& vikingos, list <cJinetes*> jinetes);
	
	friend ostream& operator<<(ostream& out, cVikingos& vikingo);
	};

list<cVikingos*>& operator+=(list<cVikingos*>& lista, cVikingos* vikingo);
list<cVikingos*>& operator-=(list<cVikingos*>& lista, cVikingos* vikingo); 