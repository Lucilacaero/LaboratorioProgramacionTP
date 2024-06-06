// Trabajo Labo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <list>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cPersona.h"
#include "cDragones.h"
#include "cVikingos.h"
#include "cJinetes.h"

using namespace std;

template<typename T>
void borrarLista(list<T>& myList, size_t position) {
    try {
        if (position >= myList.size()) {
            throw out_of_range("Posición fuera de rango");
        }

        typename list<T>::iterator it = myList.begin();
        advance(it, position); // Avanzar el iterador a la posición deseada
        myList.erase(it);
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}

template<typename T>
T seleccionarElementoAleatorio(const list<T>& myList) {
    if (myList.empty()) {
        throw out_of_range("La lista está vacía");
    }
    auto it = myList.begin();
    advance(it, rand() % myList.size());
    return *it;
}

template<typename T>
size_t encontrarPosicion(const list<T>& myList, const T& value) {
    size_t position = 0;
    for (auto it = myList.begin(); it != myList.end(); ++it, ++position) {
        if (*it == value) {
            return position;
        }
    }
    throw out_of_range("Elemento no encontrado en la lista");
}

int main() {
    srand(time(0)); // Inicializar la semilla para los números aleatorios

    list<cDragones*> dragones;

    // Prueba de inserción de dragones
    cDragones* dragoncito1 = new cDragones("chimuelo", "15102004", 100, 1000, false, "no tiene", false, 50);
    dragones.push_front(dragoncito1);
    cDragones* dragoncito2 = new cDragones("gaga", "15102004", 100, 1000, false, "no tiene", false, 50);
    dragones.push_front(dragoncito2);
    dragoncito2->mostrarnombre();

    // Mostrar los nombres de los dragones cargados
    for (cDragones* dragon : dragones) {
        dragon->mostrarnombre();
    }

    list<cVikingos*> vikingos;
    Posicion pos = Posicion::Guerrero;
    cVikingos* viking1 = new cVikingos("chimuelo", "15102004", 1000, 100, false, pos, dragoncito1, 0);
    vikingos.push_front(viking1);
    cVikingos* viking2 = new cVikingos("viking2", "15102005", 800, 200, false, pos, dragoncito2, 0);
    vikingos.push_front(viking2);

    int option = rand() % 3;

    switch (option) {
    case 1:
        while (!vikingos.empty() && !dragones.empty()) {
            cVikingos* viking = seleccionarElementoAleatorio(vikingos);
            cDragones* dragon = seleccionarElementoAleatorio(dragones);

            int Option2 = rand() % 2;
            switch (Option2) {
            case 0:
                dragon->atacar();
                if (viking->getvida() <= 0) {
                    try {
                        size_t pos = encontrarPosicion(vikingos, viking);
                        borrarLista(vikingos, pos);
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
                        size_t pos = encontrarPosicion(dragones, dragon);
                        borrarLista(dragones, pos);
                    }
                    catch (const out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }
                break;
            }
        }
        break;

    case 2:


        // Entrenar(dragon, jinete);
        //  Necesito definir la función Entrenar y jinete
        break;
    }

    // Liberar memoria
    for (cDragones* dragon : dragones) {
        delete dragon;
    }
    for (cVikingos* viking : vikingos) {
        delete viking;
    }

    return 0;
}


// Función para cargar datos desde un archivo CSV
/*
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
