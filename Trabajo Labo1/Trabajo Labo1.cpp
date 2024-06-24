// Trabajo Labo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#pragma once
#include <iterator>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <list>

#include "cVikingos.h"
#include "cJinetes.h"
#include "cDragones.h"
// no se porque cuando pongo el .h me tira el error LNK2019 y con el cpp no
class cDragones;

using namespace std;
void cargarlistas(string& nombreArchivo, list<cDragones*>& dragones, list <cVikingos*>& vikingos, list <cJinetes*> &jinetes);
void guardarlistas (string & nombreArchivo, list<cPersona*>&listamodificada); 
Posicion stringToPosicion(string& stringt);
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
    list <cDragones*> dragones;
    list <cPersona*> listamodificada;// aca se van a guardar todos los cambios de las listas 
   
    // Crear objetos de tipo cDragones

    cDragones* dragoncito1 = new cDragones("chimuelo", "15/10/2004", 100, 1000, false,1, "no tiene", false, 50);
    cDragones* dragoncito2 = new cDragones("gaga", "15/10/2004", 100, 1000, false,2, "no tiene", false, 50);

    // Agregar los punteros a los objetos a la lista del panóptico

    dragones.push_back(dragoncito1);
    dragones.push_back(dragoncito2); 

    // Crear una lista vikingo
    list <cVikingos*> vikingos;
    cVikingos* vikingo1 = new cVikingos("Hiccup", "25/04/1990", 75, 500, false, Entrenador, dragoncito1, 0);
    vikingos.push_back(vikingo1); 

    // Crear una lista jinete
    cJinetes* jinete1 = new cJinetes("Alan", "31/08/1992", 85, 600, false, Jinete, dragoncito2, 0, "aprobado", "Chimuelo");
    list<cJinetes*> jinetes;
    jinetes.push_back(jinete1);
    string archivo = "Tp Labo1.csv"; // Nombre del archivo CSV 
    ifstream file(archivo); 
    cargarlistas(archivo, dragones, vikingos, jinetes); 
    int i = 0;
    int repe = 0;
    repe = rand() % 50;
    int option = rand() % 3;
    int option2;
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
    delete jinete1;

    return 0;


}
Posicion stringToPosicion(string& stringt) {

    if (stringt == "Entrenador") {
        return Posicion::Entrenador;
    }
    else if (stringt == "Guerrero") {
        return Posicion::Guerrero;
    }
    else if (stringt == "Agricultor") {
        return Posicion::Agricultor;
    }
    else if (stringt == "Pescador") {
        return Posicion::Pescador;
    }
    else if (stringt == "Herrero") {
        return Posicion::Herrero;
    }
    else if (stringt == "Jinete") {
        return Posicion::Jinete;
    }
    else {
        throw std::invalid_argument("String no válido para Posicion");
    }
}

// Función para cargar datos desde un archivo CSV

void cargarlistas(string& nombreArchivo, list<cDragones*>& dragones, list <cVikingos*>& vikingos, list <cJinetes*>& jinetes) {
    ifstream archivo(nombreArchivo);
    // el getline lee cadenas de caracteres y los almacena como tal el >> los manda en su formato, por comodidad uso el ss>>
    if (!archivo.is_open()) {
        throw exception("no se pudo abrir el archivo");
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        //auxiliares
        string tipo, nombre, fecha_nac, ataque; //para que sea mas facil leer los archivos csv voy a poner si es un dragon o un vikingo antes que todos sus atributos
        unsigned int fuerza, id;
        int vida, entrenado;
        bool muerto, estado;
        char delimitador;

        // Lee los datos desde el stringstream
        ss >> tipo >> delimitador;
        // estos son los atributos de cPersona
        ss >> nombre >> delimitador;
        ss >> fecha_nac >> delimitador;
        ss >> fuerza >> delimitador;
        ss >> vida >> delimitador;
        ss >> muerto >> delimitador;

        if (tipo == "dragon") {
            ss >> id >> delimitador;
            ss >> ataque >> delimitador;
            ss >> estado >> delimitador;
            ss >> entrenado;
            //creo al dragon
            cDragones* dragon = new cDragones(nombre, fecha_nac, fuerza, vida, muerto, id, ataque, estado, entrenado);

            //lo agrego a la lista
            dragones.push_back(dragon);
        }

        //ver como leer y escribir la posicion y el dragon, el dragon lo vamos a hacer con un id que los une y la posicion va a ser un string que se pasa a enumprobablemente
        if (tipo == "vikingo") {
            //  Posicion trabajo;
             // cDragones* dragon;
            int dragon_muerto;
            unsigned int idDragon;
            string stringt;
            ss >> stringt >> delimitador;
            Posicion trabajo = stringToPosicion(stringt);
            ss >> idDragon >> delimitador;

            cDragones* dragon = encontrardragon(idDragon, dragones);
            ss >> dragon_muerto >> delimitador;


            if (Posicion::Jinete) {
                string resultado;
                string nombreDragon;

                ss >> resultado >> delimitador;
                ss >> nombreDragon >> delimitador;

                cJinetes* jinete = new cJinetes(nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto, resultado, nombreDragon);
                jinetes.push_back(jinete);
            }

            else {
                cVikingos* vikingo = new cVikingos(nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto);
                vikingos.push_back(vikingo);
            }
        }

        archivo.close();

    }
}

/*
void guardarlistas(string& nombreArchivo, list<cPersona*>& listamodificada) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
       throw "No se pudo abrir el archivo: ";
        return;
    }

    list<cPersona*>::const_iterator it;
    for (it = listamodificada.begin(); it != listamodificada.end(); ++it) {
            archivo << (*it)->guardar() << endl;
    }

}
*/
/*
* en el uml no va el friend 
* friend: el jinete le tiene que dar permiso a la clase del dragon para que acceda a sus atributos
*/




/* Nota si aparece este error reiniciar la compu
 LNK1168 no se puede abrir
 C:\Users\Toty\Desktop\Proyectos git\LaboratorioProgramacionTP\x64\Debug\Trabajo Labo1.exe para escritura
 */


//nota: si devuelvo & estoy trabajando con el dato original porwue lo devuelvo por referencia, puede perder el encapsulamiwnto