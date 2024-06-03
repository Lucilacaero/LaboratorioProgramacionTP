
#pragma once
#include <string>
using namespace std;
class cPersona {
protected:
    string Nombre;
    string Fecha_nac;
    unsigned int Fuerza; // Cambiado a unsigned int
    int Vida;
    bool Muerto;

public:
    cPersona(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto);
    virtual ~cPersona();
};
