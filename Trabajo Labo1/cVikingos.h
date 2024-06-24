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
	cVikingos(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto);
	virtual ~cVikingos();
	int atacar();
	void vida(int danio);
	void setDragon(cDragones* dragon);
	cDragones* getDragon();
	int getvida();
	void asignarDragon(cDragones* dragon);
	void trabajar();
	bool getMuerto();
	friend cVikingos* aleatorio(list <cVikingos*> vikingos);
	size_t encontrarPosicion(list <cVikingos*> vikingos);
	virtual string to__string() override; //son virtual porque se lo voy a pasar a cJinete
	virtual void Imprimir();
	string EnumAstring();
	//friend void cargarlistas(string& nombreArchivo, list<cDragones*>& dragones, list <cVikingos*>& vikingos, list <cJinetes*> jinetes);
	virtual string guardar();
	/*
	string to_string() const override;
	void Imprimir() const override;
	*/
	};

