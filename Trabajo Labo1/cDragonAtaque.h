#pragma once

#include "cControl.h"
#include "cVikingoAtaque.h"

class cVikingoAtaque;
class cDragonAtaque : public cDragones{
    int x, y;
    int dx;

public:
    cDragonAtaque( cDragones& otro, int x, int y);

    void pintar();
    void borrar();
    void mover();
    void choque(cVikingoAtaque& N);
    int X() const { return x; }
    int Y()const { return y; }
    friend void manejarColisiones(cDragonAtaque& DragonAtaque);
};


