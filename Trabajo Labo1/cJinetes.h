#pragma once
#include "cVikingos.h"
#include "cDragones.h"
#include <string>



class cJinetes : protected cVikingos {
private:
	string Resultado;
	string NombreDragon;
public:
	
	cJinetes(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon);
	~cJinetes();
	cJinetes(const cJinetes& otro);
	int getvida();
	//friend void asignarnombre(cJinetes& jinete, cDragones& dragon);
	friend void cDragones::setNombre(cJinetes*& jinete); 
	void entrenarDragon();
	friend cJinetes* aleatorio(list <cJinetes*> jinetes);
	void setMuerte(bool muerte);
	string to__string(); //son virtual porque se lo voy a pasar a cJinete
	void Imprimir();
	string guardar();
	friend void guardarListas(string& nombreArchivo, list<cDragones*>& listamodificadaD, list<cVikingos*>& listamodificadaV, list<cJinetes*>& listamodificadaJ);




}; 

list<cJinetes*>& operator-=(list<cJinetes*>& lista, cJinetes* jinete);
list<cJinetes*>& operator+=(list<cJinetes*>& lista, cJinetes* jinete);