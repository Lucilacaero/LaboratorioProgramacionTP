#include "cDragonAtaque.h"
#include "AyuditaMain.h"
#include <iostream>

cDragonAtaque::cDragonAtaque( cDragones& otro, int x, int y): cDragones(otro) {
    this->x = x;
    this->y = y;
    dx = 1;
}

void cDragonAtaque::pintar() {
    situarCursor(x, y);
    cout << "*";
}

void cDragonAtaque::borrar() {
    situarCursor(x, y); 
cout << " ";
}

void cDragonAtaque::mover() {
    borrar();
    x += dx;
    if (x <= 3 || x >= 77) {
        dx = -dx;
        y = rand() % 3 + 15;
    }
    pintar();
}


void cDragonAtaque::choque(cVikingoAtaque& N) {
    if (x >= N.X() && x <= N.X() + 4 && y >= N.Y() && y <= N.Y() + 2) {
      int  danio = atacar();
        N.vida(danio);
        N.morir();
        N.pintar();
        N.pintarCorazones();
        x = rand() % 71 + 4;
    }
}
