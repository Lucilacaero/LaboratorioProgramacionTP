#pragma once
#include "cJinetes.h"

#include "cDragones.h"
#include <iostream>
class cVikingos;
class cDragones;
using namespace std;
/*
void Altanombre(cJinetes& asignado, string nuevoNombre)
*/

cJinetes::cJinetes(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon)
    :cVikingos(nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto) {

    Resultado = resultado;
    NombreDragon = nombredragon;
}
cJinetes::~cJinetes()
{
}
void cJinetes::entrenarDragon() {
    cDragones* Dragon = this->getDragon();
    int entrenado;
    // poner getter y setter para que deje de tirar erroes
    if (Dragon == nullptr) {
        cout << "No hay drag�n asignado para entrenar." << std::endl;
        return;
    }
    // usar e
    if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) > 100) {
        this->Vida -= rand() % 10;
        entrenado = rand() % 5 + Dragon->getEntrenado();
        Dragon->setEntrenado(entrenado);
    }
    else if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) > 200) {
        this->Vida -= rand() % 20;
        entrenado = rand() % 3 + Dragon->getEntrenado();
        Dragon->setEntrenado(entrenado);

    }
    else if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) > 300) {
        this->Vida -= rand() % 30;
        entrenado = rand() % 2 + Dragon->getEntrenado();
        Dragon->setEntrenado(entrenado);
    }

    if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) > 100) {

        entrenado = rand() % 10 + Dragon->getEntrenado();
        Dragon->setEntrenado(entrenado);
    }
    else if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) > 200) {
        entrenado = rand() % 20 + Dragon->getEntrenado();
        Dragon->setEntrenado(entrenado);
    }
    else if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) > 300) {
        entrenado = rand() % 30 + Dragon->getEntrenado();
        Dragon->setEntrenado(entrenado);
    }

    if (Dragon->getEntrenado() >= MaxEntrenamiento) {
        cout << "El drag�n ha alcanzado el nivel m�ximo de entrenamiento." << std::endl;
    }

    if (this->Vida <= 0) {
        cout << "El jinete ha muerto durante el entrenamiento." << std::endl;
    }

    Dragon->Domado();
}