#pragma once
#include <string>
#include <iostream>
#include <list>
#include <iomanip>

using namespace std;
class cPersona {
protected:
    string Tipo;
    string Nombre;
    string Fecha_nac;
    unsigned int Fuerza; // Cambiado a unsigned int
    int Vida;
    bool Muerto;
public:
    void setNombre(const string& nombre);
    cPersona();
    cPersona(string tipo, string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto);
    virtual ~cPersona();
    cPersona(const cPersona& otro);
    void setMuerto(bool muerte);
    int getvida() const;
    bool getMuerto() const;
    string getnombre()const;
    unsigned int getFuerza()const;

    virtual int atacar() = 0;// esta va a ser la funcion con polimorfismo
   void vida(int danio);// esta tambien porque despues llamo a los destructores 
   virtual bool getMuerto(); 
   virtual string to__string(); //voy a imprimir todos los atributos de cPErsona y despues le agrego los de la clase correspondiente
   virtual void Imprimir();
   
};



   // es polimorfismo si usas una funcion y es totalmetente distinta una de la otra, es decir que si 
   // uso vida y la defino para cada clase, eso es polimorfismo