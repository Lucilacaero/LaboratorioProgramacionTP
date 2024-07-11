
#include "cJinetes.h"
#include <iostream>
#include "AyuditaMain.h"
class cVikingos;
class cDragones;
using namespace std;

cJinetes::cJinetes(string tipo, string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon)
    :cVikingos(tipo, nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto) {

    Resultado = resultado;
    NombreDragon = nombredragon;
}
cJinetes::cJinetes(const cJinetes& otro) {
    // Copiar cada atributo desde 'otro' al nuevo objeto creado (this)
    this->Tipo = otro.Tipo;
    this->Nombre = otro.Nombre;
    this->Fecha_nac = otro.Fecha_nac;
    this->Fuerza = otro.Fuerza;
    this->Vida = otro.Vida; 
    this->Muerto = otro.Muerto;
    this->Trabajo = otro.Trabajo;
    this->Dragon = otro.Dragon;
    this->Dragon_Muerto = otro.Dragon_Muerto;
    this->Resultado = otro.Resultado;
    this->NombreDragon = otro.NombreDragon;
}
cJinetes::~cJinetes()
{
}
cJinetes::cJinetes()
{
    this->Tipo = "Jinete";
    this->Nombre = " ";
    this->Fecha_nac = " ";
    this->Fuerza = 0;
    this->Vida = 100;
    this->Muerto = false;
    this->Trabajo = Posicion::Jinete;
    this->Dragon = nullptr;
    this->Dragon_Muerto = 0;
    this->Resultado = "desaprobado";
    this->NombreDragon = " ";
}
void cJinetes::entrenarDragon() {//agregar en el main que si no aprobo el curso no va a poder entrenar a un dragon y si termino primero se le agrega un 50+ de fuerza
    /* tomar en consideracion
    1. La fuerza del dragon y del jinete
    2. la posicion del jinete, si termina en 1 o 2 lugar tiene ventaja, sino es normalito */
    cDragones* Dragon = this->getDragon();
    int entrenado;
    // poner getter y setter para que deje de tirar erroes
    if (Dragon == nullptr) {
        throw  ("No hay dragon asignado para entrenar.");
    }
    cout << "El jinete " << Nombre << " va a entrena al dragon " << Dragon->getnombre() << endl;
    if (Resultado == "desaprobado") {
        cout << "lamentamos informarle que el jinete no aprobo el examen y por lo tanto no puede entrenar dragones"<<endl;
    }
    else if (Resultado == "primero" || Resultado == "segundo") {
        this->Fuerza = this->Fuerza + 30;
    }
        if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) < 100) {
            this->Vida -= rand() % 10;
            entrenado = rand() % 5 + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
   }
   else if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) < 200) {
            this->Vida -= rand() % 20;
            entrenado = rand() % 3 + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
        }
  else if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) > 200) {
            this->Vida -= rand() % 30;
            entrenado = rand() % 2 + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
        }

  else if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) < 100) {

            entrenado = rand() % 10 + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
        }
        else if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) < 200) {
            entrenado = rand() % 20 + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
        }
        else if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) > 200) {
            entrenado = rand() % 30 + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
        }
    
   
    if (Dragon->getEntrenado() >= MaxEntrenamiento) {
        cout << "El dragon ha alcanzado el nivel maximo de entrenamiento." << endl;
    }

    if (this->Vida <= 0) {
        cout << "El jinete ha muerto durante el entrenamiento." << endl;
    }

    Dragon->Domado();
}

cJinetes* aleatorio(list<cJinetes*> jinetes)
{
    if (jinetes.empty()) {

        cout <<"La lista está vacía"<<endl;
    }
    list<cJinetes*>::iterator it = jinetes.begin();
    advance(it, rand() % jinetes.size());
    return *it;
}



string cJinetes::to__string()
{
    string s = cVikingos::to__string();

    if (Dragon != nullptr) {
        s += " Dragon: " + Dragon->to__string();
    }
    else
        s += "No tiene dragon asignado";
    s +="/n Resultado: " + Resultado; //no le pongo el atributo nombredragon porque es repetitivo
    return s;
}

void cJinetes::Imprimir()
{
    cout << to__string();
}






cDragones* cJinetes::getDragon()
{
    return Dragon;
}

void cJinetes::setDragon(cDragones* dragon)
{
    Dragon = dragon;
}

void cJinetes::setResultado(string resultado)
{
    Resultado = resultado;
}


list<cJinetes*>& operator+=(list<cJinetes*>& lista, cJinetes* jinete) {
    lista.push_back(jinete);
    return lista;
}

list<cJinetes*>& operator-=(list<cJinetes*>& lista, cJinetes* jinete) {
    auto it = find(lista.begin(), lista.end(), jinete);
    if (it != lista.end()) {
        delete* it;
        lista.erase(it);
    }
    return lista;
}
ostream& operator<<(ostream& out,  cJinetes& jinete) {
    out << left << setw(15) << setfill(' ') << "Jinete"
        << left << setw(15) << setfill(' ') << jinete.Nombre
        << left << setw(15) << setfill(' ') << jinete.Fecha_nac
        << left << setw(10) << setfill(' ') << jinete.Fuerza
        << left << setw(10) << setfill(' ') << jinete.Vida
        << left << setw(10) << setfill(' ') << (jinete.Muerto ? "si" : "no")
 
        << left << setw(15) << setfill(' ') << TrabajoToString(jinete.Trabajo)
        << left << setw(15) << setfill(' ') << jinete.Resultado
        << left << setw(15) << setfill(' ') << jinete.NombreDragon
        << endl;
    return out;
}

