
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

// Dependiendo de la FormadeAtaque que tenga el dragon, inflinge mas daño y va a ser mas dificil de domarlo
// ¿Cómo obtiene su forma de ataque? para empezar puede tenerla o no, pero si se lo esta entrenando va a ir subiendo de nivel y adquiriendo una nueva forma de ataque
// Se considera que esta domado una vez que este en 100 puntos de domado.
// Que tenga una forma de ataque definida no significa que tenga puntos de entrenamiento, a menos que así sea.


class cDragones : protected cPersona {
private:
	unsigned int Id;//para buscarlo facil en ell csv
	string Ataque;
	bool Estado;// domado o no
	int Entrenado;// para saber si esta domado y su forma de ataque
	
	static int DragonesVivos;
	static int DragonesMuertos;
	static int domados;


public:
	cDragones(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, unsigned int id, string ataque, bool estado, int entrenado);
	~cDragones();
	//friend void asignarnombre(cJinetes& jinete, cDragones& dragon);
	bool Domado();
	int danio();
	string getnombre();
	void setEntrenado(int entrenado);
	void formaDeAtaque();
	int atacar();
	void vida(int danio);
	int getvida();
	unsigned int getfuerza();
	int getEntrenado();
	bool getMuerto();
	unsigned int getid();
	void setNombre(cJinetes*& jinete);
	friend cDragones* aleatorio(list <cDragones*> dragones); 
	size_t encontrarPosicion(list <cDragones*> dragones);
	string to__string(); //voy a imprimir todos los atributos de cPErsona y despues le agrego los de la clase correspondiente
	void Imprimir();
	cDragones* encontrardragon(unsigned int id, list<cDragones*>& dragones);



	/*
	string to_string() const override;
	void Imprimir() const override;
	*/
	

	//HACER FUNCION PARA ASIGNARLE UN NOMBRE
	//friend void Entrenar(cJinetes& jinete);
	//void modificarDragonSegunJinete(cJinetes& jinete);
};
