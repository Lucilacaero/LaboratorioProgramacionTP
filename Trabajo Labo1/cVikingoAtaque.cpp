#include "cVikingoAtaque.h"
#include "Proyectiles.h"
#include "AyuditaMain.h"
#include "cVikingos.h"
#include <iostream>
#include <list>
using namespace std;


cVikingoAtaque::cVikingoAtaque(cVikingos& otro, int x, int y): cVikingos(otro)
{
    this->x = x;
    this->y = y;
}

cVikingoAtaque::cVikingoAtaque()
{
}

void cVikingoAtaque::pintar() {
    situarCursor(x, y);     cout << "  ()";
    situarCursor(x, y + 1); cout << " -[]-";
    situarCursor(x, y + 2); cout << "  /\\";
}

void cVikingoAtaque::borrar() {
    for (int i = 0; i < 3; i++) {
        situarCursor(x, y + i); cout << "       ";
    }
}

void cVikingoAtaque::mover() {
    if (_kbhit()) {  //verifica que se presiono una tecla 
        char tecla = _getch(); //lee la tecla que se ingreso
        borrar();
        if (tecla == IZQUIERDA && x > 3) { x--; }
        if (tecla == DERECHA && x + 5 < 78) { x++; }
        if (tecla == ARRIBA && y > 3) { y--; }
        if (tecla == ABAJO && y + 3 < 33) { y++; }
        pintar();
    }
}

void cVikingoAtaque::pintarCorazones() {
    LimpiarCursor(78, 10);
    situarCursor(78, 10);
    cout << "Vida actualizada: " << Vida;
   

}

void cVikingoAtaque::MostrarDanio(int danio) {
    situarCursor(78, 8); cout << "El dragon  ataca y genera un danio de " << danio << "\n";
    LimpiarCursor(78, 9);
    situarCursor(78, 9);
    cout<< "Vida antes del ataque: " << Vida << endl;


}

void cVikingoAtaque::morir() {
    
        borrar();
        situarCursor(x, y);   cout << "   **   ";
        situarCursor(x, y + 1); cout << "  ***  ";
        situarCursor(x, y + 2); cout << "   **   ";
        usleep(200000);
        borrar();
        pintarCorazones();
        pintar();
}




void cVikingoAtaque::disparar(list<Proyectiles*>& B) {
    B.push_back(new Proyectiles(x + 2, y - 1, atacar()));
}
