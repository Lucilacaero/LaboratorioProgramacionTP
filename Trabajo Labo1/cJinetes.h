#pragma once
#include "cVikingos.h"
#include "cDragones.h"
#include <string>



class cJinetes : public cVikingos {
private:
	string Resultado;
	string NombreDragon;
public:
	
	cJinetes(string tipo, string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon);
	~cJinetes();
	cJinetes();
	cJinetes(const cJinetes& otro);
	cJinetes(const cVikingos& otro, string resultado, string Nombre );
	cDragones* getDragon();
	string getResultado();
	void setDragon(cDragones* dragon);
	void setResultado(string resultado);

	void displayStatus(int clicksActuales, int totalClicks, double TiempoRestante);

	bool entrenar();
	
	friend void cDragones::setNombre(cJinetes*& jinete); 
	void entrenarDragon();
	friend cJinetes* aleatorio(list <cJinetes*> jinetes);
	
	string to__string(); //son virtual porque se lo voy a pasar a cJinete
	void Imprimir();
	friend ostream& operator<<(ostream& out, cJinetes& jinete);


}; 

list<cJinetes*>& operator-=(list<cJinetes*>& lista, cJinetes* jinete);
list<cJinetes*>& operator+=(list<cJinetes*>& lista, cJinetes* jinete);