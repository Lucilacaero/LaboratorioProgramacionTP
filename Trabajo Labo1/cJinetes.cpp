
#include "cJinetes.h"
#include "cDragones.h"
#include <iostream>
class cDragones;
using namespace std;
/*
void Altanombre(cJinetes& asignado, string nuevoNombre) 
*/

cJinetes::cJinetes(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon)
	:cVikingos(nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto){
	
	Resultado = resultado;
	NombreDragon = nombredragon;
}
 void cJinetes::entrenarDragon() {
    cDragones* Dragon = this->getDragon();
    // poner getter y setter para que deje de tirar erroes
    if (Dragon == nullptr) {
        cout << "No hay dragón asignado para entrenar." << std::endl;
        return;
    } 

    if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) > 100) {
        this->Vida -= rand() % 10;
        Dragon->Entrenado += rand() % 5; 
    }
    else if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) > 200) {
        this->Vida -= rand() % 20;
        Dragon->Entrenado += rand() % 3;
    }
    else if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) > 300) {
        this->Vida -= rand() % 30;
        Dragon->Entrenado += rand() % 2;
    }

    if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) > 100) {
        Dragon->Entrenado += rand() % 10;
    }
    else if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) > 200) {
        Dragon->Entrenado += rand() % 20;
    }
    else if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) > 300) {
        Dragon->Entrenado += rand() % 30;
    }

    if (Dragon->Entrenado >= MaxEntrenamiento) {
        cout << "El dragón ha alcanzado el nivel máximo de entrenamiento." << std::endl;
    }

    if (this->Vida <= 0) {
        cout << "El jinete ha muerto durante el entrenamiento." << std::endl;
    }

    Dragon->Domado();
}
