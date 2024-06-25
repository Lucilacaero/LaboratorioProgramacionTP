
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include "cVikingos.h"
#include "cJinetes.h"
#include "cDragones.h"
// Declaraciones de funciones
void cargarlistas(const string& nombreArchivo, list<cDragones*>& dragones, list<cVikingos*>& vikingos, list<cJinetes*>& jinetes);
//void guardarlistas(ofstream& archivo, const list<cPersona*>& listamodificada);
Posicion stringToTrabajo(const string& stringt);
cDragones* encontrardragon(unsigned int id, list<cDragones*>& dragones);
string TrabajoToString(Posicion& Trabajo);