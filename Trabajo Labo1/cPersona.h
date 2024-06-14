
#pragma once
#include <string>
#include <iostream>

#include <stdexcept>
using namespace std;
class cPersona {
protected:
    string Nombre;
    string Fecha_nac;
    unsigned int Fuerza; // Cambiado a unsigned int
    int Vida;
    bool Muerto;
public:
    void setNombre(const string& nombre);
    cPersona();
    cPersona(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto);
    virtual ~cPersona();
    virtual int atacar() = 0;// esta va a ser la funcion con polimorfismo
    virtual void vida(int danio) = 0;// esta tambien porque despues llamo a los destructores 
    //virtual string to_string() const = 0;
  //  virtual void Imprimir() const = 0;
    bool getMuerto();
};



   // es polimorfismo si usas una funcion y es totalmetente distinta una de la otra, es decir que si 
   // uso vida y la defino para cada clase, eso es polimorfismo