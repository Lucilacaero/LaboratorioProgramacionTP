#pragma once

#include "cControl.h"
#include "cVikingoAtaque.h"

class cVikingoAtaque;
class cDragonAtaque : public cDragones{
    int x, y;
    int dx;
    int danio;

public:
    cDragonAtaque( cDragones& otro, int x, int y);

    void pintar();
    void borrar();
    void MostrarCambios(int danio);
    void mover();
    void PintarVida();
    void choque(cVikingoAtaque& N);
    unsigned int getDanio();
    int X() const { return x; }
    int Y()const { return y; }
    friend void manejarColisiones(cDragonAtaque& DragonAtaque);
};


