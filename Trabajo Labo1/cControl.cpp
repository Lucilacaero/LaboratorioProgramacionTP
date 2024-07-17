#include "cControl.h"
#include "AyuditaMain.h" 
#include "cDragones.h"
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>


using namespace std;

cControl::cControl(cVikingoAtaque* vikingo, cDragonAtaque* dragon)
    : v(vikingo), dragonAtaque(dragon) {}

cControl::~cControl()
{
}

void cControl::inicializar() {
    pintarLimites();
    ocultarCursor();
    v->pintar();
    v->pintarCorazones();
   
}

void cControl::generarAsteroides() {
    if (asteroides.size() < 5) {
        asteroides.push_back(new cDragonAtaque(*dragonAtaque, rand() % 75 + 3, rand() % 23 + 10));
    }
}


void cControl::terminar() const {
    situarCursor(35, 14);
    cout << "Game Over";
    situarCursor(30, 15);
}
void cControl::manejarColisiones() {
    for (auto it = balas.begin(); it != balas.end(); ) {

        // Primer caso: el vikingo genera un ataque al dragon
        if ((*it)->X() >= 2 && (*it)->X() <= 10 && (*it)->Y() >= 15 && (*it)->Y() <= 20) { //verifico que las balas esten en  unrango que causan "danio"
            int danio = (*it)->getDanio(); // Al atacar devuelve el danio que el vikingo puede generar
            dragonAtaque->MostrarCambios(danio);
            (*it)->borrar();
            delete (*it);
            it = balas.erase(it);
            continue; // Pasar a la siguiente bala
        }

        bool colision = false;
        for (auto jt = asteroides.begin(); jt != asteroides.end(); ) {
            // Segundo caso: hay una colision entre una bala y un asteroide
            if ((*it)->X() == (*jt)->X() && (*it)->Y() == (*jt)->Y()) {
                int danio = (*it)->getDanio() - (*jt)->getDanio(); // jt son el ataque del dragon, asi que si es negativo el dragon genera mas danio
                if (danio < 0) {
                    v->vida(-danio); // El vikingo recibe el danio restante
                }
                else {
                    dragonAtaque->MostrarCambios(danio);
                }

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

    // Tercer caso: los asteroides golpean al vikingo
    for (auto jt = asteroides.begin(); jt != asteroides.end(); ) {
        if ((*jt)->X() == v->X() && (*jt)->Y() == v->Y()) {
            int danio = (*jt)->getDanio();
            
            v->vida(danio); // El vikingo recibe el danio del asteroide
            
            (*jt)->borrar();
            delete (*jt);
            jt = asteroides.erase(jt);
        }
        else {
            ++jt;
        }
    }
}
void cControl::ejecutar() {
    bool game_over = false;
    while (!game_over) {
        pintarLimites();
        generarAsteroides();

        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 'b') {
                balas.push_back(new Proyectiles(v->X() + 2, v->Y() - 1, v->atacar()));
            }
        }
        v->mover();

        for (auto it = balas.begin(); it != balas.end(); ) {//el incremento solo lo hago en el else
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
            if (v->getvida() <= 0) {
                v->setMuerto(true);

                game_over = true;
                break;
            }
        }

        manejarColisiones();

        if (dragonAtaque->getvida() <= 0) {
            situarCursor(35, 14);
            cout << "Game Over. El dragon ha sido derrotado.";
            game_over = true;
        }

        this_thread::sleep_for(chrono::milliseconds(30));
    }
}

