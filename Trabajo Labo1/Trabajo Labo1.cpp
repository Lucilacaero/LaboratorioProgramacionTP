// Trabajo Labo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <list>
#include "cPersona.h"
#include "cDragones.h"
#include "cVikingos.h"
#include <iostream>
#include <stdio.h>
using namespace std;

// Función para cargar datos desde un archivo CSV

void cargarlistaDragones(const string& nombreArchivo, list<cDragones*>& dragones) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        //auxiliares
        string nombre, fecha_nac, ataque;
        unsigned int fuerza;
        int vida, entrenado, puntosDomado;
        bool muerto, estado;
        char delimitador;

        // Lee los datos desde el stringstream
        getline(ss, nombre, ',');
        getline(ss, fecha_nac, ',');
        ss >> fuerza >> delimitador;
        ss >> vida >> delimitador;
        ss >> muerto >> delimitador;
        getline(ss, ataque, ',');
        ss >> estado >> delimitador;
        ss >> entrenado >> delimitador;
        ss >> puntosDomado;
        //creo al dragon
        cDragones* dragon = new cDragones(nombre, fecha_nac, fuerza, vida, muerto, ataque, estado, entrenado, puntosDomado);
      //lo agrego a la lista
        dragones.push_back(dragon);
    }

    archivo.close();
}


 
int main(){
    list <cDragones*> dragones;
    //nada importante, solo una prueba
    cDragones * dragoncito = new cDragones("chimuelo", "15102004", 100, 1000, false, "no tiene", false, 50, 5);
    dragones.push_front(dragoncito);
    cDragones* dragoncito2 = new cDragones("gaga", "15102004", 100, 1000, false, "no tiene", false, 50, 5);
    dragones.push_front(dragoncito2);
    dragoncito2->mostrarnombre();
    // fin de la prueba



    // Cargar datos desde un archivo CSV
    cargarlistaDragones("dragones.csv", dragones);

    // Mostrar los nombres de los dragones cargados
    for (cDragones* dragon : dragones) {
        dragon->mostrarnombre();
    }

    // Falta liberar memoria
    

    return 0;
}
/*

    list<int> myList;
  //  Añadir Elementos al final de la lista :

        myList.push_back(10);
        // Añadir al principio
        myList.push_front(5);
       // Eliminar Elementos del final de la lista :
        myList.pop_back();
     //  Eliminar del principio de la lista :
        myList.pop_front();

       // Iterar sobre la Lista: usar iteradores para recorrer la lista :

            for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
                cout << *it << " ";
            }
        cout <<endl;
        for (int value : myList) {
            std::cout << value << " ";
        }
        std::cout << std::endl;

       // Insertar y Eliminar en Posiciones Específicas
       //     Insertar :

            list<int>::iterator it = myList.begin();
        advance(it, 1); // Avanzar el iterador a la segunda posición
        myList.insert(it, 15);
        // Eliminar:


            it = myList.begin();
       advance(it, 1); // Avanzar el iterador a la segunda posición
        myList.erase(it);
    cout << "hola";
    */

/*
* en el uml no va el friend 
* friend: el jinete le tiene que dar permiso a la clase del dragon para que acceda a sus atributos
*/

/*
Vamos a hacer dos herencias:
cambiar cPersona a cHabitantes

cPersona es el padre de vikingo y cdragones, vikingo es el padre de jinete

¿Qué comparten entre ellos?


Plantear funciones polimorficas
vida, nombre, struct
listas

NOTA: cuando el dragon esta domado el vikingo no lo puede matar y viceversa.

*/



/* Nota si aparece este error reiniciar la compu
 LNK1168 no se puede abrir
 C:\Users\Toty\Desktop\Proyectos git\LaboratorioProgramacionTP\x64\Debug\Trabajo Labo1.exe para escritura
 */
