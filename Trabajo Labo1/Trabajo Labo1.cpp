// Trabajo Labo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#pragma once
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cVikingos.h"
#include "cDragones.h"
#include "Panoptico.h"
#include "cJinetes.h"
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

    /*
    // Creo una lista dragón
    cPanoptico<cDragones*> D;
    
    // Crear objetos de tipo cDragones*
    cDragones* dragon1 = new cDragones("Chimuelo", "15/10/2004", 100, 1000, false, "ninguno", false, 50);
    cDragones* dragon2 = new cDragones("Furioso", "20/05/2005", 120, 1200, false, "fuego", true, 80);
    cDragones* dragoncito1 = new cDragones("chimuelo", "15102004", 100, 1000, false, "no tiene", false, 50);
    cDragones* dragoncito2 = new cDragones("gaga", "15102004", 100, 1000, false, "no tiene", false, 50);
    // Agregar los punteros a los objetos a la lista del panóptico
   

    D.agregarElemento(&dragon1);
    D.agregarElemento(&dragon2); 
    D.agregarElemento(&dragoncito1); 
    D.agregarElemento(&dragoncito2); 

    cPanoptico<cVikingos> V;
    cVikingos * vikingo1= new cVikingos("Hiccup", "25/04/1990", 75, 500, false, Entrenador, dragon1, 0);
    V.agregarElemento(vikingo1);
    // Crear un objeto de tipo cJinetes
    
    cJinetes * jinete1 = new cJinetes("Astrid", "31/08/1992", 85, 600, false, Jinete, dragon1, 0, "aprobado", "Chimuelo");
    cPanoptico<cJinetes> J;
    J.agregarElemento(jinete1); 
 
    delete dragon1;
    delete vikingo1;
    delete jinete1;
    */
    cPanoptico<cDragones> D;

    // Crear objetos de tipo cDragones
    cDragones* dragon1 = new cDragones("Chimuelo", "15/10/2004", 100, 1000, false, "ninguno", false, 50);
    cDragones* dragon2 = new cDragones("Furioso", "20/05/2005", 120, 1200, false, "fuego", true, 80);
    cDragones* dragoncito1 = new cDragones("chimuelo", "15/10/2004", 100, 1000, false, "no tiene", false, 50);
    cDragones* dragoncito2 = new cDragones("gaga", "15/10/2004", 100, 1000, false, "no tiene", false, 50);

    // Agregar los punteros a los objetos a la lista del panóptico
    D.agregarElemento(dragon1);
    D.agregarElemento(dragon2);
    D.agregarElemento(dragoncito1);
    D.agregarElemento(dragoncito2);

    // Crear una lista vikingo
    cPanoptico<cVikingos> V;
    cVikingos* vikingo1 = new cVikingos("Hiccup", "25/04/1990", 75, 500, false, Entrenador, dragon1, 0);
    V.agregarElemento(vikingo1);

    // Crear una lista jinete
    cJinetes* jinete1 = new cJinetes("Astrid", "31/08/1992", 85, 600, false, Jinete, dragon1, 0, "aprobado", "Chimuelo");
    cPanoptico<cJinetes> J;
    J.agregarElemento(jinete1);

    // Aquí puedes añadir código para mostrar o manipular los objetos

    // Liberar memoria
    delete dragon1;
    delete dragon2;
    delete dragoncito1;
    delete dragoncito2;
    delete vikingo1;
    delete jinete1;

    return 0;

    //Esto se deberia hacer en el csv cada vez que se leen los datos.


    /*
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
     //   jinete.entrenarDragon();

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
    */
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


//nota: si devuelvo & estoy trabajando con el dato original porwue lo devuelvo por referencia, puede perder el encapsulamiwnto