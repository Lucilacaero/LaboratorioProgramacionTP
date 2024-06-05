
#pragma once
#include <string>
#include <random>
#include <iostream>
using namespace std;
class cPersona {
protected:
    string Nombre;
    string Fecha_nac;
    unsigned int Fuerza; // Cambiado a unsigned int
    int Vida;
    bool Muerto;
    void setNombre(const string& nombre);

public:
    cPersona(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto);
    virtual ~cPersona();
    virtual int atacar();// esta va a ser la funcion con polimorfismo
  
   

    // es polimorfismo si usas una funcion y es totalmetente distinta una de la otra, es decir que si 
    // uso vida y la defino para cada clase, eso es polimorfismo
};
