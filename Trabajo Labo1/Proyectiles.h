#pragma once

#include "cJuego.h"

class Proyectiles  {
    int x, y, danio;
public:
    Proyectiles( int x, int y,int danio);

    void pintar();
    void borrar() ;
    void mover() ;
    bool fuera()const;
    unsigned int getDanio();
    int X() const { return x; }
    int Y()const { return y; }
};

