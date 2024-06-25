// Trabajo Labo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#pragma once

#include "AyuditaMain.h"

class cVikingos;
using namespace std;

int main() {
   // srand(time(0)); 
    list<cDragones*> dragones;
    list<cVikingos*> vikingos;
    list<cJinetes*> jinetes;
    list<cDragones*> listamodificadaD;
    list<cVikingos*> listamodificadaV;
    list<cJinetes*> listamodificadaJ;
    string archivo = "Tp Labo1.csv"; 

    // Crear objetos de tipo cDragones
    cDragones* dragoncito1 = new cDragones("chimuelo", "15/10/2004", 100, 1000, false, 1, "no tiene", false, 50);
    cDragones* dragoncito2 = new cDragones("gaga", "15/10/2004", 100, 1000, false, 2, "no tiene", false, 50);
    dragones.push_back(dragoncito1);
    dragones.push_back(dragoncito2);


    // Crear un objeto de tipo cVikingos y añadirlo a la lista
    cVikingos* vikingo1 = new cVikingos("Hiccup", "25/04/1990", 75, 500, false, Posicion::Entrenador, dragoncito1, 0);
    vikingos.push_back(vikingo1);

    // Crear un objeto de tipo cJinetes y añadirlo a la lista
    cJinetes* jinete1 = new cJinetes("Alan", "31/08/1992", 85, 600, false, Posicion::Jinete, dragoncito2, 0, "aprobado", "Chimuelo");
    jinetes.push_back(jinete1);

    // Cargar listas desde el archivo CSV
    try {
        cargarlistas(archivo, dragones, vikingos, jinetes);
    }
    catch (const exception& e) {
        cerr << "Error al cargar listas desde archivo: " << e.what() << endl;
    }

    // Simulación de acciones aleatorias
    int repe = 8;
    int i = 0;
    int danio;

    while (i <= repe) {
       
        int option = rand() % 3;
        switch (option) {
          
        case 0: // Atacar
            if (!vikingos.empty() && !dragones.empty()) {
                
                cDragones* dragon = aleatorio(dragones);
                cVikingos* viking = aleatorio(vikingos);
                viking->asignarDragon(dragon);
                
               
                while (viking->getMuerto()!= true && dragon->getMuerto()!=true) {
                    
                    int option2 = rand() % 2;
                    switch (option2) {
                    case 0:
                       danio = dragon->atacar();
                       viking->vida(danio);
                       cout << "El dragon " << dragon->getnombre() << " genero un danio de " << danio << " puntos" << " al vikingo " << viking->getnombre() << endl;
                       if (viking->getvida() <= 0) {
                           listamodificadaV.push_back(viking);
                           vikingos -= viking;
                           delete viking;
                        }
                          
                            
                       
                        break;

                    case 1:
                        
                        dragon->vida(viking->atacar());

                        
                        if (dragon->getvida() <= 0) {
                            dragon->setMuerto(true);
                            listamodificadaD.push_back(dragon);
                            cout << "El dragón murio." << endl;
                            dragones -= dragon;
                            delete dragon;
                            //eliminar dragon de la lista original
                        }
                        break;
                    }
                }
            }
            break;
            
        case 1: // Entrenar
           
            if (!jinetes.empty()) {
                cJinetes* jinete = aleatorio(jinetes);
                jinete->entrenarDragon();
            }
            break;

        case 2: // Trabajar
            
            if (!vikingos.empty()) {
                cVikingos* viking = aleatorio(vikingos);
                viking->trabajar();
                if (viking->getPosicion() == Posicion::Guerrero)
                    option = 0;
                else if (viking->getPosicion() == Posicion::Jinete)
                    option = 1;
            }
            break;
        }
       
        

        i++;
    }
    // Guardar listas modificadas en archivo
    guardarListas(archivo, listamodificadaD, listamodificadaV, listamodificadaJ);


    return 0;
}
