#include "cControl.h"
#include "AyuditaMain.h" 
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

cControl::cControl(cVikingoAtaque* vikingo) : v(vikingo) {}

void cControl::inicializar() {

    pintarLimites();
    ocultarCursor(); 
    v->MostrarDanio(0);
    v->pintar();
    v->pintarCorazones();
}

void cControl::generarAsteroides(cDragones *otro) {
    if (asteroides.size() < 5) {
        //hay error porque cambie el constructor
        //arreglado pero creo que voy a cambiar un par de cosas
        asteroides.push_back(new cDragonAtaque(*otro, rand() % 75 + 3, rand() % 23 + 10));
    }
}


void cControl::manejarColisiones(cDragonAtaque& DragonAtaque) {
    for (auto it = balas.begin(); it != balas.end(); ) {
        bool colision = false;
        for (auto jt = asteroides.begin(); jt != asteroides.end(); ) {// los asteroides son las colisiones del dragon
            if ((*it)->X() == (*jt)->X() && (*it)->Y() == (*jt)->Y()) {
                int danio = v->atacar() - DragonAtaque.atacar();
                if (danio < 0) {
                    DragonAtaque.vida(danio); //ERROR A VECES SE LE SUMA VIDA AL VIKINGO
                }
                else {
                    v->vida(danio);
                }
                v->MostrarDanio(danio);
                (*it)->borrar();
                (*jt)->borrar();
                delete (*it);
                delete (*jt);
                it = balas.erase(it);
                jt = asteroides.erase(jt);

                colision = true;
                break;
            }
            else {
                ++jt;
            }
        }
        if (!colision) {
            ++it;
        }
    }
}


void cControl::ejecutar() {
   
    bool game_over = false;//la clase cControl tiene un puntero vikingo soo lo mando aca 
    while (!game_over) {
        pintarLimites();
        generarAsteroides(v->getDragon());

        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 'c') {
                
                balas.push_back(new Proyectiles(v->X() + 2, v->Y() - 1, v->atacar()));
            }
        }
        v->mover();

        for (auto it = balas.begin(); it != balas.end(); ) {
            (*it)->mover();
            if ((*it)->fuera()) {
                (*it)->borrar();
                delete (*it);
                it = balas.erase(it);
            }
            else {
                ++it;

            }
        }
        for (auto& asteroide : asteroides) {
            asteroide->mover();
            asteroide->choque(*v);
            if (v->getvida() < 0) {//CAMBIAR A <0
                game_over = true;
                break;
            }
        }

        
        cDragonAtaque AtaqueD(*(v->getDragon()), 2,4);
        manejarColisiones(AtaqueD);
        if (v->getvida() < 0) {
            v->setMuerto(true);
            game_over = true; }
        this_thread::sleep_for(chrono::milliseconds(30));
    }
}




void cControl::terminar() const{
    situarCursor(35, 14);
    cout << "Game Over";
    situarCursor(30, 15);
   
}
