// Trabajo Labo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//  
#pragma once

#include "AyuditaMain.h"

using namespace std;


/*
Ante cualquier error que no se pueda solucioner:
1. reiniciar la compu,
2. si no funca eso reeinstalar visual,
3. si eso tampoco funciona, entonces borrar lo que no funca, reiniciar la compu, compilarlo
y volver a escribir el codigo
4. si nada de eso funciona hacerlo en distinto orden
.
*/



class cVikingos;
class cDragones;

int main() {
    // Para numeros aleatorios
    srand(time(NULL));

    // Listas normales y de cambio
    list<cDragones*> dragones;
    list<cVikingos*> vikingos;
    list<cJinetes*> jinetes;
    list<cDragones*> listamodificadaD;
    list<cVikingos*> listamodificadaV;
    list<cJinetes*> listamodificadaJ;

    // objetos random de prueba
    cDragones* dragoncito1 = new cDragones("dragon", "chimuelo", "15 / 10 / 2004", 100, 1000, false, 1, "No tiene", false, 50);
    cDragones* dragoncito2 = new cDragones("dragon", "gaga", "15 / 10 / 2004", 100, 1000, false, 2, "No tiene", false, 50);

    // operator prueba
    dragones += dragoncito1;
    dragones += dragoncito2;

    // lista cVikingo
    cVikingos* vikingo1 = new cVikingos("vikingo", "Hiccup", "25/04/1990", 75, 500, false, Entrenador, dragoncito1, 0);
    vikingos += (vikingo1);

    // Lista cJinete
    cJinetes* jinete1 = new cJinetes("jinete", "Alan", "31 / 08 / 1992", 85, 600, false, Jinete, dragoncito2, 0, "aprobado", "Chimuelo");
    jinetes += (jinete1);

    string archivo = "Tp Labo1.csv"; // archivo de los objetos
    ifstream file(archivo);

    cargarlistas(archivo, dragones, vikingos, jinetes);


    for (auto it = dragones.begin(); it != dragones.end(); ++it) {//quiero saber cuantos dragones domados hay antes de iniciar el dia 
        cDragones* dragon = *it;
        if (dragon->getDomado() == true) {
            cDragones::Domados++;
        }

    }

    int i = 0;
    int option = 0;

    cJinetes* JineteSeleccionado = nullptr;     //creo objetos dinamicos para despues usarlos como auxiliares
    cDragones* DragonSeleccionado = nullptr;
    cVikingos* VikingoSeleccionado = nullptr;
    system("pause");
    system("cls");


    while (i <= 5) {
        // Reseteo los seleccionados para cada iteración, me va  a servir para los aleatorios
        VikingoSeleccionado = nullptr;
        DragonSeleccionado = nullptr;
        JineteSeleccionado = nullptr;

        option = rand() % 3;
        switch (option) {
        case 0: // Atacar
            cout << "Ocurrio un caso de hostilidad" << endl;
            if (!vikingos.empty() && !dragones.empty()) {
                VikingoSeleccionado = aleatorio(vikingos);
                DragonSeleccionado = VikingoSeleccionado->getDragon();

                if (DragonSeleccionado == nullptr) {
                    DragonSeleccionado = aleatorio(dragones);
                }

                cout << "Se genera una pelea ente el vikingo " << VikingoSeleccionado->getnombre() << " y el dragon " << DragonSeleccionado->getnombre() << endl;
                while (!VikingoSeleccionado->getMuerto() && !DragonSeleccionado->getMuerto()) {
                    int danio = DragonSeleccionado->atacar();
                    VikingoSeleccionado->vida(danio);
                    if (VikingoSeleccionado->getvida() <= 0) {
                        VikingoSeleccionado->setMuerto(true);
                        cout << "El Vikingo murio en el combate." << endl;
                        listamodificadaV += VikingoSeleccionado;
                        vikingos -= (VikingoSeleccionado);
                        break;
                    }
                    DragonSeleccionado->vida(VikingoSeleccionado->atacar());
                    if (DragonSeleccionado->getvida() <= 0) {
                        DragonSeleccionado->setMuerto(true);
                        listamodificadaD += DragonSeleccionado;
                        dragones -= (DragonSeleccionado);
                        VikingoSeleccionado->setDragonmuerto();
                        break;
                    }
                }
            }
            break;

        case 1: // Trabajar
            cout << "El vikingo agarra la pala (va a trabajar) " << endl;
            if (!vikingos.empty()) {
                VikingoSeleccionado = aleatorio(vikingos);
                VikingoSeleccionado->trabajar();
                if (VikingoSeleccionado->getPosicion() == Posicion::Guerrero) {

                    if (!dragones.empty()) {
                        DragonSeleccionado = VikingoSeleccionado->getDragon();
                        if (DragonSeleccionado == nullptr) {
                            DragonSeleccionado = aleatorio(dragones);
                        }

                        cout << "Se genera una pelea entre el vikingo " << VikingoSeleccionado->getnombre() << " Y el dragon " << DragonSeleccionado->getnombre() << endl;
                        while (!VikingoSeleccionado->getMuerto() && !DragonSeleccionado->getMuerto()) {
                            int danio = DragonSeleccionado->atacar();
                            VikingoSeleccionado->vida(danio);
                            if (VikingoSeleccionado->getvida() <= 0) {
                                VikingoSeleccionado->setMuerto(true);
                                cout << "El vikingo murio en el combate." << endl;
                                listamodificadaV += VikingoSeleccionado;
                                vikingos -= (VikingoSeleccionado); // Eliminar de la lista original

                                break; // Terminar la batalla si el vikingo muere
                            }
                            DragonSeleccionado->vida(VikingoSeleccionado->atacar());
                            if (DragonSeleccionado->getvida() <= 0) {
                                DragonSeleccionado->setMuerto(true);
                                VikingoSeleccionado->setDragonmuerto();
                                cDragones::DragonesMuertos++;
                                listamodificadaD += (DragonSeleccionado);
                                dragones -= (DragonSeleccionado); // Eliminar de la lista original
                                break; // Terminar la batalla si el dragón muere
                            }
                        }
                    }
                }
                else if (VikingoSeleccionado->getPosicion() == Posicion::Jinete && !jinetes.empty()) {
                    cJinetes* jinete = dynamic_cast<cJinetes*>(VikingoSeleccionado);
                    (jinete->getFuerza() > 70) ? jinete->setResultado("aprobado") : jinete->setResultado("desaprobado");

                    if (VikingoSeleccionado->getDragon() != nullptr) {
                        jinete->entrenarDragon();
                    }
                    else
                        cout << "el vikingo jinete aun no tiene asignado ningun dragon, la proxima le tocara entrenar";
                }
            }
            break;


            case 2: // Entrenar
            cout << "Hoy es un lindo dia para entrenar " << endl;
            if (!jinetes.empty()) {
                cJinetes* jinete = aleatorio(jinetes);
                if (jinete->getDragon() == nullptr) {
                    cDragones* dragon = aleatorio(dragones);
                    jinete->setDragon(dragon);
                }
                jinete->entrenarDragon();
            }
            break;

            
        }
        cout << "Iteracion: " << i + 1 << endl;
        i++;
        system("pause");
        system("cls");
         }
        imprimirresumen(listamodificadaD, listamodificadaV, listamodificadaJ);

        //Elimino la memoria que pedi
        auto it_jinete = jinetes.begin();
        while (it_jinete != jinetes.end()) {
            delete* it_jinete;
            it_jinete = jinetes.erase(it_jinete);
        }
        auto it_vikingo = vikingos.begin();
        while (it_vikingo != vikingos.end()) {
            delete* it_vikingo;
            it_vikingo = vikingos.erase(it_vikingo);
        }
        auto it_dragon = dragones.begin();
        while (it_dragon != dragones.end()) {
            delete* it_dragon;
            it_dragon = dragones.erase(it_dragon);
        }
   

    return 0;
}