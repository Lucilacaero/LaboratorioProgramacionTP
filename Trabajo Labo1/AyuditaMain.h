
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <thread>
#include <chrono>
#include "cVikingos.h"
#include "cJinetes.h"
#include "cDragones.h"

#define ARRIBA 72 // 72 Es la tecla de flechita hacia arriba
#define IZQUIERDA 75// teclita flecha hacia la ozquierda
#define DERECHA 77// idem
#define ABAJO 80// idem 

// Declaraciones de funciones
void cargarlistas(const string& nombreArchivo, list<cDragones*>& dragones, list<cVikingos*>& vikingos, list<cJinetes*>& jinetes);
//void guardarlistas(ofstream& archivo, const list<cPersona*>& listamodificada);
Posicion stringToTrabajo(const string& stringt);
cDragones* encontrardragon(unsigned int id, list<cDragones*>& dragones);
string TrabajoToString(Posicion& Trabajo);
void imprimirresumen(list <cDragones*>& listamodificadaD, list <cVikingos*>& listamodificadaV, list <cJinetes*>& listamodificadaJ);
void print();

void situarCursor(int x, int y);
void pintarLimites();
void ocultarCursor();
void usleep(unsigned long long tiempo);