#include "cDragonAtaque.h"
#include "AyuditaMain.h"
#include <iostream>

cDragonAtaque::cDragonAtaque( cDragones& otro, int x, int y): cDragones(otro) {
    this->x = x;
    this->y = y;
    dx = 1;
    this->danio = otro.atacar();// de esta forma los ataques del dragon tienen un danio predefinido
}

cDragonAtaque::~cDragonAtaque()
{
}

void cDragonAtaque::pintar()const {
    situarCursor(x, y);
    cout << "*";
}

void cDragonAtaque::borrar() {
    situarCursor(x, y); 
cout << " ";
}
void cDragonAtaque::MostrarCambios(int danio) {
    LimpiarCursor(78, 12);
    situarCursor(78, 12);
    cout << "Vida del dragon antes del danio: " << Vida << endl;
    vida(danio); // Aplica el danio al dragon
    LimpiarCursor(78, 13);
    situarCursor(78, 13);
    cout << "El vikingo genero un danio de " << danio << " puntos." << endl;
    LimpiarCursor(78, 14);
    situarCursor(78, 14);
    cout << "Vida del dragon despues del danio: " << Vida << endl;
 
    
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
    if (x >= N.X() && x <= N.X() + 4 && y >= N.Y() && y <= N.Y() + 2) {// verifico las coordenadas para 
      int  danio = atacar();
     
        N.MostrarDanio(danio);
        N.vida(danio);
        N.morir();
        N.pintar();
        N.pintarCorazones(); 
        x = rand() % 71 + 4;
    }
}

unsigned int cDragonAtaque::getDanio() {
    return danio;
}
