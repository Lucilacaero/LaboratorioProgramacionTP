// Trabajo Labo1.cpp : Este archivo contiene la funcion "main". La ejecucion del programa comienza y termina ahi.
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
        // Reseteo los seleccionados para cada iteracion, me va  a servir para los aleatorios
        VikingoSeleccionado = nullptr;
        DragonSeleccionado = nullptr;
        JineteSeleccionado = nullptr;

        option = rand()%2;
        switch (option) {
        case 0: // Atacar
          
            if (!vikingos.empty() && !dragones.empty()) {
                
                VikingoSeleccionado = aleatorio(vikingos);
                DragonSeleccionado = VikingoSeleccionado->getDragon();

                if (DragonSeleccionado == nullptr) {
                    DragonSeleccionado = aleatorio(dragones);
                }

                cout << "Se genera una pelea ente el vikingo " << VikingoSeleccionado->getnombre() << " y el dragon " << DragonSeleccionado->getnombre() << endl;

                cVikingoAtaque v(*VikingoSeleccionado, 38, 30);
                cDragonAtaque d(*DragonSeleccionado, 5,15 );
                cControl Juegos(&v, &d);
                Juegos.inicializar();
                Juegos.ejecutar();
                Juegos.terminar();
                if (v.getMuerto() == true) {
                    VikingoSeleccionado->setMuerto(true);
                    listamodificadaV += VikingoSeleccionado;
                }
                else {
                    DragonSeleccionado->setMuerto(true);
                    listamodificadaD += DragonSeleccionado;
                    cDragones::DragonesMuertos++;
                    cDragones::DragonesVivos--;
                    if (DragonSeleccionado->Domado() == true) {
                        cDragones::Domados--;
                    }
                }
                    
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
                        cDragonAtaque d(*DragonSeleccionado, 5, 15); 
                        cControl Juegos(&v,&d);
                        Juegos.inicializar();
                        Juegos.ejecutar();
                        Juegos.terminar();
                        if (v.getMuerto() == true) {
                            VikingoSeleccionado->setMuerto(true);
                            listamodificadaV += VikingoSeleccionado;
                        }
                        else {
                            DragonSeleccionado->setMuerto(true);
                            listamodificadaD += DragonSeleccionado;
                            cDragones::DragonesMuertos++;
                            cDragones::DragonesVivos--;
                            if (DragonSeleccionado->Domado() == true) {
                                cDragones::Domados--;
                            }
                        }
                    }
                    
                }
                
                else if (VikingoSeleccionado->getPosicion() == Posicion::Jinete && !jinetes.empty()) {
                   
                    
                    if (VikingoSeleccionado != nullptr) {
                        

                        if (VikingoSeleccionado->getFuerza() > 70) {
                            JineteSeleccionado = new cJinetes(*VikingoSeleccionado, "aprobado", " ");
                            
                        } 
                        else {
                            JineteSeleccionado = new cJinetes(*VikingoSeleccionado, "desaprobado", " ");
                        }

                        // Verificacion y entrenamiento del dragon
                        if (JineteSeleccionado->getDragon() != nullptr&& JineteSeleccionado->getResultado() != "desaprobado") {
                            JineteSeleccionado->entrenarDragon();
                            if (JineteSeleccionado->getMuerto() == true) {
                                listamodificadaJ += JineteSeleccionado;
                            }
                        }
                        else if(JineteSeleccionado->getResultado() == "desaprobado") {
                            cout << "El vikingo jinete aun no aprobo el examen, debera entrenar mas"<<endl;
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
                cJinetes* JineteSeleccionado = aleatorio(jinetes);
                if (JineteSeleccionado->getDragon() == nullptr) {
                    cDragones* dragon = aleatorio(dragones);
                    JineteSeleccionado->setDragon(dragon);
                }
                JineteSeleccionado->entrenarDragon();
                if (JineteSeleccionado->getMuerto() == true) {
                    listamodificadaJ += JineteSeleccionado;
                }
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
    it_jinete = jinetes.begin(); // Reiniciar el iterador después de modificar la lista
}

auto it_vikingo = vikingos.begin();
while (it_vikingo != vikingos.end()) {
    vikingos -= *it_vikingo;
    it_vikingo = vikingos.begin();
}

auto it_dragon = dragones.begin();
while (it_dragon != dragones.end()) {
    dragones -= *it_dragon;
    it_dragon = dragones.begin();
}

it_jinete = listamodificadaJ.begin();
while (it_jinete != listamodificadaJ.end()) {
    listamodificadaJ -= *it_jinete;
    it_jinete = listamodificadaJ.begin();
}

it_vikingo = listamodificadaV.begin();
while (it_vikingo != listamodificadaV.end()) {
    listamodificadaV -= *it_vikingo;
    it_vikingo = listamodificadaV.begin();
}

it_dragon = listamodificadaD.begin();
while (it_dragon != listamodificadaD.end()) {
    listamodificadaD -= *it_dragon;
    it_dragon = listamodificadaD.begin();
}

delete JineteSeleccionado;
delete DragonSeleccionado;
delete VikingoSeleccionado;

        
    return 0;
}