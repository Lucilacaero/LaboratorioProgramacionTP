#include "cControl.h"
#include "AyuditaMain.h" 
#include "cDragones.h"
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>


cControl::cControl(cVikingoAtaque* vikingo) : v(vikingo) {}

void cControl::inicializar() {

    pintarLimites();
    ocultarCursor();
    v->getDragon()->MostrarVida();
    v->pintar();
    v->pintarCorazones();
}

void cControl::generarAsteroides(cDragones* otro) {
    if (asteroides.size() < 5) {
        //hay error porque cambie el constructor
        //arreglado pero creo que voy a cambiar un par de cosas
        asteroides.push_back(new cDragonAtaque(*otro, rand() % 75 + 3, rand() % 23 + 10));
    }
}
//	situarCursor(78,4); cout << "el vikingo genero un danio de " << danio << " puntos." << endl;
//it balas
// jt asteroide/ dragon
void cControl::manejarColisiones(cDragonAtaque& DragonAtaque) {
    for (auto it = balas.begin(); it != balas.end(); ) {
        // Primer caso: el vikingo genera un ataque al dragón
        if ((*it)->X() >= 2 && (*it)->X() <= 10 && (*it)->Y() >= 15 && (*it)->Y() <= 20) {
            int danio = (*it)->getDanio(); // Al atacar devuelve el daño que el vikingo puede generar
            DragonAtaque.vida(danio); 
            DragonAtaque.MostrarVida();

            situarCursor(78, 4);
             cout << "El vikingo generó un daño de " << danio << " puntos." <<  endl;

            (*it)->borrar();
            delete (*it);
            it = balas.erase(it);

            continue; // Pasar a la siguiente bala
        }
        
        bool colision = false;
        for (auto jt = asteroides.begin(); jt != asteroides.end(); ) {
            // Segundo caso: hay una colisión entre una bala y un asteroide
            if ((*it)->X() == (*jt)->X() && (*it)->Y() == (*jt)->Y()) {
                int danio = (*it)->getDanio() - (*jt)->getDanio();
                if (danio > 0) {
                    v->vida(-danio); // El vikingo recibe el daño restante
                    v->MostrarDanio(danio);
                }
                else {
                    DragonAtaque.vida(-danio); // El dragón pierde puntos de vida (danio es negativo)
                    DragonAtaque.MostrarVida();
                    situarCursor(78, 4);
                    cout << "El dragón recibió un daño de " << danio << " puntos." << endl;
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
            v->vida(-danio); // El vikingo recibe el daño del asteroide
            v->MostrarDanio(danio);
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
            if (v->getvida() <= 0) {//CAMBIAR A <0
                v->setMuerto(true);
                game_over = true;
                break;
            }

        }


        cDragonAtaque AtaqueD(*(v->getDragon()), 2, 4);
        manejarColisiones(AtaqueD);
        if (v->getvida() < 0) {
            v->setMuerto(true);
            game_over = true;
        }
        this_thread::sleep_for(chrono::milliseconds(30));
    }
}


void cControl::terminar() const {
    situarCursor(35, 14);
    cout << "Game Over";
    situarCursor(30, 15);
}
