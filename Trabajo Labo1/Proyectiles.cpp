#include "Proyectiles.h"
#include "AyuditaMain.h"
#include <iostream>


Proyectiles::Proyectiles( int x, int y, int danio )
{
    this->x = x;
    this->y = y;
   this->danio = danio;
}

void Proyectiles::pintar() {
    situarCursor(x, y); cout << "*"; 
}

void Proyectiles::borrar() {
    situarCursor(x, y); cout << " "; 
}

void Proyectiles::mover() {
    borrar();
    x--;
    pintar();
}

bool Proyectiles::fuera() const {//modificar
    return x == 3;
}

unsigned int Proyectiles::getDanio() {
    return danio;
}
