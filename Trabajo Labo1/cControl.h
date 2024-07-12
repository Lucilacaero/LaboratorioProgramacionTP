#pragma once

#include "cVikingoAtaque.h"
#include "cDragonAtaque.h"
#include "Proyectiles.h"
#include "cJuego.h"
#include <list>
using namespace std;
class cVikingoAtaque;
class cDragonAtaque;

class cControl {
    cVikingoAtaque* v;
  
    list<cDragonAtaque*> asteroides;
    list<Proyectiles*> balas;
  
public:
    cControl(cVikingoAtaque* vikingo);


   
    void manejarColisiones(cDragonAtaque& DragonAtaque);
    void inicializar();
    void generarAsteroides(cDragones* otro);
    void ejecutar();
   
   // void manejarColisiones(cDragonAtaque& DragonAtaque);
    void terminar()const;
};


