// Trabajo Labo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//  
#pragma once

#include "AyuditaMain.h"
#include "cControl.h"

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

    cJinetes* JineteSeleccionado = new cJinetes();     //creo objetos dinamicos para despues usarlos como auxiliares
    cDragones* DragonSeleccionado = new cDragones() ;
    cVikingos* VikingoSeleccionado = new cVikingos();
    system("pause");
    system("cls");
    VikingoSeleccionado = aleatorio(vikingos); 

    while (i <= 5) {
        // Reseteo los seleccionados para cada iteración, me va  a servir para los aleatorios
        VikingoSeleccionado = nullptr;
        DragonSeleccionado = nullptr;
        JineteSeleccionado = nullptr;

        option = rand() % 3;
        switch (option) {
        case 0: // Atacar
            cout << "Estamos trabajando para mejorar esta parte";
            if (!vikingos.empty() && !dragones.empty()) {
                VikingoSeleccionado = aleatorio(vikingos);
                DragonSeleccionado = VikingoSeleccionado->getDragon();

                if (DragonSeleccionado == nullptr) {
                    DragonSeleccionado = aleatorio(dragones);
                }

                cout << "Se genera una pelea ente el vikingo " << VikingoSeleccionado->getnombre() << " y el dragon " << DragonSeleccionado->getnombre() << endl;

                cVikingoAtaque v(*VikingoSeleccionado, 38, 30);
                cControl Juegos(&v);
                Juegos.inicializar();
                Juegos.ejecutar();
                Juegos.terminar();

            }
            break;

        case 1:
            // Trabajar
            cout << "El vikingo agarra la pala (va a trabajar) " << endl;
            if (!vikingos.empty()) {
                VikingoSeleccionado = aleatorio(vikingos);
                VikingoSeleccionado->trabajar();
                if (VikingoSeleccionado->getPosicion() == Posicion::Guerrero) {

                    if (!vikingos.empty() && !dragones.empty()) {
                        VikingoSeleccionado = aleatorio(vikingos);
                        DragonSeleccionado = VikingoSeleccionado->getDragon();

                        if (DragonSeleccionado == nullptr) {
                            DragonSeleccionado = aleatorio(dragones);
                        }

                        cout << "Se genera una pelea ente el vikingo " << VikingoSeleccionado->getnombre() << " y el dragon " << DragonSeleccionado->getnombre() << endl;

                        cVikingoAtaque v(*VikingoSeleccionado, 38, 30);
                        cControl Juegos(&v);
                        Juegos.inicializar();
                        Juegos.ejecutar();
                        Juegos.terminar();
                    }
                    
                }
                else if (VikingoSeleccionado->getPosicion() == Posicion::Jinete && !jinetes.empty()) {
                    cJinetes* jinete = dynamic_cast<cJinetes*>(VikingoSeleccionado);

                    if (jinete != nullptr) {
                        // Verificación de fuerza
                        if (jinete->getFuerza() > 70) {
                            jinete->setResultado("aprobado");
                        }
                        else {
                            jinete->setResultado("desaprobado");
                        }

                        // Verificación y entrenamiento del dragón
                        if (jinete->getDragon() != nullptr) {
                            jinete->entrenarDragon();
                        }
                        else {
                            cout << "El vikingo jinete aún no tiene asignado ningún dragón, la próxima le tocará entrenar";
                        }
                    }
                    else {
                        cout << "Error: No se pudo realizar el dynamic_cast a cJinetes" << endl;
                    }
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
        system("pause");
        system("cls");

        //Elimino la memoria que pedi
        auto it_jinete = jinetes.begin();
        while (it_jinete != jinetes.end()) {
            jinetes -= *it_jinete;
            
        }
        auto it_vikingo = vikingos.begin();
        while (it_vikingo != vikingos.end()) {
            vikingos -= *it_vikingo;
        }
        auto it_dragon = dragones.begin();
        while (it_dragon != dragones.end()) {
            dragones -= * it_dragon;
        }

        it_jinete = jinetes.begin();
        while (it_jinete != jinetes.end()) {
            listamodificadaJ -= *it_jinete;

        }
        it_vikingo = vikingos.begin();
        while (it_vikingo != vikingos.end()) {
            listamodificadaV -= *it_vikingo;
        }
        it_dragon = dragones.begin();
        while (it_dragon != dragones.end()) {
            listamodificadaD -= *it_dragon;
        }
        delete JineteSeleccionado;
        delete DragonSeleccionado;
        delete VikingoSeleccionado;
    return 0;
}