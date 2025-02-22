#pragma once
#include "cVikingos.h"
#include "cDragonAtaque.h"
#include"cVikingoAtaque.h"
#include"cDragonAtaque.h"
#include "cControl.h"
#include <list>
#include <conio.h>
using namespace std;
class Proyectiles;
class cDragonAtaque;


class cVikingoAtaque: public cVikingos {
    
    int x, y;

public:
    cVikingoAtaque(cVikingos& otro, int x, int y);
    cVikingoAtaque();
    void pintar() ;
    void borrar() ;
    void mover() ;
    void pintarCorazones();
    void MostrarDanio(int danio);
    void morir();
    void disparar(list<Proyectiles*>& B);
    int X() const { return x; }
    int Y()const { return y; }
    friend void manejarColisiones(cDragonAtaque& DragonAtaque);
};
