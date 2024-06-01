#pragma once
#include <string>

using namespace std;

class cPersona {
protected:
    string Nombre;
    string Fecha_nac;
    string Fuerza; // Depende de que tan fuerte (mucho, mediano, poco) sea va a ser más fácil de domar o matar
    int Vida;
    bool Muerto;

public:
    cPersona(string nombre, string fecha_nac, string fuerza, int vida, bool muerto);
    virtual ~cPersona();
};