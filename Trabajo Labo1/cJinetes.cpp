
#include "cJinetes.h"
#include <iostream>
class cVikingos;
class cDragones;
using namespace std;

cJinetes::cJinetes(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon)
    :cVikingos(nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto) {

    Resultado = resultado;
    NombreDragon = nombredragon;
}
cJinetes::~cJinetes()
{
}
void cJinetes::entrenarDragon() {//agregar en el main que si no aprobo el curso no va a poder entrenar a un dragon y si termino primero se le agrega un 50+ de fuerza
    /* tomar en consideracion
    1. La fuerza del dragon y del jinete
    2. la posicion del jinete, si termina en 1 o 2 lugar tiene ventaja, sino es normalito */
    cDragones* Dragon = this->getDragon();
    int entrenado;
    // poner getter y setter para que deje de tirar erroes
    if (Dragon == nullptr) {
        cout << "No hay dragon asignado para entrenar." << endl;
        
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
        cout << "El dragon ha alcanzado el nivel maximo de entrenamiento." << endl;
    }

    if (this->Vida <= 0) {
        cout << "El jinete ha muerto durante el entrenamiento." << endl;
    }

    Dragon->Domado();
}