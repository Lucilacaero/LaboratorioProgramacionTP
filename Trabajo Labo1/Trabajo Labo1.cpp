// Trabajo Labo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//  
#pragma once

#include "AyuditaMain.h"
class cVikingos;
using namespace std;


// no se porque cuando pongo el .h me tira el error LNK2019 y con el cpp no
class cDragones;

/*
Ante cualquier error que no se pueda solucioner:
1. reiniciar la compu,
2. si no funca eso reeinstalar visual,
3. si eso tampoco funciona, entonces borrar lo que no funca, reiniciar la compu, compilarlo
y volver a escribir el codigo
4. si nada de eso funciona hacerlo en distinto orden
*/

using namespace std;


int main() {

    // para los números aleatorios
   ;// aca se van a guardar todos los cambios de las listas 
    list<cDragones*> dragones;
    list<cVikingos*> vikingos;
    list<cJinetes*> jinetes;
    list<cDragones*> listamodificadaD;
    list<cVikingos*> listamodificadaV;
    list<cJinetes*> listamodificadaJ;
    // Crear objetos de tipo cDragones

    cDragones* dragoncito1 = new cDragones("chimuelo", "15/10/2004", 100, 1000, false, 1, "no tiene", false, 50);
    cDragones* dragoncito2 = new cDragones("gaga", "15/10/2004", 100, 1000, false, 2, "no tiene", false, 50);

    // Agregar los punteros a los objetos a la lista del panóptico

    dragones+=dragoncito1;
    dragones+=dragoncito2;

    // Crear una lista vikingo
  
    cVikingos* vikingo1 = new cVikingos("Hiccup", "25/04/1990", 75, 500, false, Entrenador, dragoncito1, 0);
    vikingos+=vikingo1;

    // Crear una lista jinete
   // cJinetes* jinete1 = new cJinetes("Alan", "31/08/1992", 85, 600, false, Jinete, dragoncito2, 0, "aprobado", "Chimuelo");
   
   // jinetes+=jinete1);
    string archivo = "Tp Labo1.csv"; // Nombre del archivo CSV 
    ifstream file(archivo);

    cargarlistas(archivo, dragones, vikingos, jinetes);
    int i = 0;
   
   
    int option = 0;
    int option2;


    while (i <= 5) {
       option = rand() % 3;
        switch (option) {
        case 0: // Atacar
            cout << "caso 3, batalla" << endl;
            if (!vikingos.empty() && !dragones.empty()) {
              
                cVikingos* viking = aleatorio(vikingos);
                cDragones* dragon = aleatorio(dragones);
                cout << "Se genera un pelea entre el vikingo " << viking->getnombre()<< " y el dragon "<< dragon->getnombre() << endl;
                while (!viking->getMuerto() && !dragon->getMuerto()) {
                    int danio;
                    danio = dragon->atacar();
                      //  cout << "el vikingo " << viking->getnombre() << " ataca y genera un danio de " << danio << " puntos al dragon " << dragon->getnombre() << endl;
                    viking->vida(danio);
                        if (viking->getvida() <= 0) {
                            viking->setMuerto(true);
                           // cout << "El vikingo murio en combate" << endl;
                            listamodificadaV+=viking;
                            //eliminarlo de la lista original
                          
                        }
                          
                          dragon->vida(viking->atacar());
                        if (dragon->getvida() <= 0) {
                            dragon->setMuerto(true);
                            listamodificadaD+=dragon;
                            //eliminar dragon de la lista original
                          
                        }
                       
                    
                }
            }
            break;

        case 1: // Trabajar
            cout << "caso 1 trabajar"<< endl;
            if (!vikingos.empty()) {
                cVikingos* viking = aleatorio(vikingos);
                viking->trabajar();
                if (viking->getPosicion() == Posicion::Guerrero) {
                    option = 0;
                    break;
                }

           
            if (viking->getPosicion() == Posicion::Jinete) // tengo que castear a los vikingos a jinetes
                if (!jinetes.empty()) {
                    option = 2;
                    break;
                }
            }
            
          
        case 2: // Entrenar
            cout << "caso 2, entrenar"<<endl;
            if (!jinetes.empty()) {
                cJinetes* jinete = aleatorio(jinetes);//aca se cambia el jinete y el dragon ver
                jinete->entrenarDragon(); 
            }
            break;

        }

        // Eliminar vikingos muertos de la lista
        auto it_vikingo = vikingos.begin();
        while (it_vikingo != vikingos.end()) {
            if ((*it_vikingo)->getMuerto()) {
                delete* it_vikingo;
                it_vikingo = vikingos.erase(it_vikingo); // Avanzar iterador después de borrar
            }
            else {
                ++it_vikingo; // Avanzar al siguiente elemento
            }
        }

        // Eliminar dragones muertos de la lista
        auto it_dragon = dragones.begin();
        while (it_dragon != dragones.end()) {
            if ((*it_dragon)->getMuerto()) {
                delete* it_dragon;
                it_dragon = dragones.erase(it_dragon); // Avanzar iterador después de borrar
            }
            else {
                ++it_dragon; // Avanzar al siguiente elemento
            }
        }

        i++;
        system("pause");
        system("cls");
    }
    // Guardar listas modificadas en archivo
    /*try {
        ofstream archivoSalida("dragones_modificados.csv");
        if (archivoSalida.is_open()) {
            // guardarlistas(archivoSalida, listamodificada);
            archivoSalida.close();
        }
        else {
            throw runtime_error("No se pudo abrir el archivo para escritura");
        }
    }
    catch (const exception& e) {
        cerr << "Error al guardar listas en archivo: " << e.what() << endl;
    }
    */

   
   
    return 0;
  
}
    /*
    while (i <= repe) {
        switch (option) {
        case 1://atacar
            while (!vikingos.empty() && !dragones.empty()) {// no se porque no me deja acceder a los atributos de panoptico si son publicos
                cVikingos* viking = aleatorio(vikingos);
                cDragones* dragon = aleatorio(dragones);
                while (viking->getMuerto() != true || dragon->getMuerto() != true) {
                    option2 = rand() % 2;
                    switch (option2) {
                    case 0:
                        dragon->atacar();
                        if (viking->getvida() <= 0) {
                            try {
                                size_t pos = (*viking).encontrarPosicion(vikingos);
                                //   vikingos.Borrarlista(pos);
                            }
                            catch (const out_of_range& e) {
                                cout << e.what() << endl;
                            }
                        }
                        break;

                    case 1:
                        viking->atacar();

                        if (dragon->getvida() <= 0) {
                            try {
                                size_t pos = (*dragon).encontrarPosicion(dragones);
                                // dragones.borrarLista(pos);
                            }
                            catch (const out_of_range& e) {
                                cout << e.what() << endl;
                            }
                        }
                        break;
                    }
                }
                break;
            }

        case 2: {// entrenar
            cJinetes* jinete = aleatorio(jinetes);
            jinete->entrenarDragon();
            jinete->Imprimir();

            break;
        }
        case 3: {//trabajar
            cVikingos* viking = aleatorio(vikingos);
            viking->trabajar();
            if (Posicion::Guerrero)
                option = 1;
            if (Posicion::Jinete)
                option = 2;
        }


        }
        i++;
    }
    // Liberar memoria
    // reescribir el csv con las listas modificadas

    delete dragoncito1;
    delete dragoncito2;
    delete vikingo1;
   // delete jinete1;

    return 0;


}
*/