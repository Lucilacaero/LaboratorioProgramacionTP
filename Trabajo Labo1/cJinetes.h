#pragma once
#include "cVikingos.h"

class cJinetes : protected cVikingos {
private:
    string Resultado;// aprobado, desaprobado, primero o ultimo
    string NombreDragon;

public:
    cJinetes(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon);
 
    friend void modificarDragonSegunJinete(cJinetes& jinete);
    friend void asignarnombre(cJinetes& jinete, cDragones& dragon);
    friend void Entrenar(cJinetes& jinete, cDragones& dragon);
    void evaluarResultado(); // tira un cout de que se le va a asignar un dragon;
};
