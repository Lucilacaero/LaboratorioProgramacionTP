#pragma once

#include "cVikingos.h"


//#include "cPersona.h"
#include <string>
using namespace std;
class cDragones;
class cVikingos;
class cJinetes : protected cVikingos {
private:
    string Resultado;// aprobado, desaprobado, primero o ultimo
    string NombreDragon;

public:
    cJinetes(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon);
  
    friend void asignarnombre(cJinetes& jinete, cDragones& dragon);

   void entrenarDragon();

};
