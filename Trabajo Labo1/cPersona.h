#pragma once
#include <string>
#include <iostream>
#include <list>

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
    cPersona(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto);
    virtual ~cPersona();
    cPersona(const cPersona& otro);
    void setMuerto(bool muerte);
  int getvida();
    virtual int atacar() = 0;// esta va a ser la funcion con polimorfismo
    virtual void vida(int danio) = 0;// esta tambien porque despues llamo a los destructores 
   virtual bool getMuerto(); 
   virtual string to__string(); //voy a imprimir todos los atributos de cPErsona y despues le agrego los de la clase correspondiente
   virtual void Imprimir();
   virtual string guardar(); // copiar el csv
   friend void guardarlistas( string& nombreArchivo, list<cPersona*>& listamodificada);
 //  friend  void cargarlistas(string& nombreArchivo, list<cDragones*>& dragones, list <cVikingos*>& vikingos, list <cJinetes*> jinetes);
   void borrarLista(size_t position);
   cPersona* seleccionarElementoAleatorio();
   size_t encontrarPosicion(cPersona* value);



};



   // es polimorfismo si usas una funcion y es totalmetente distinta una de la otra, es decir que si 
   // uso vida y la defino para cada clase, eso es polimorfismo