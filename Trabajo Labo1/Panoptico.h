#pragma once

#include <list>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
class cPanoptico {
public:
    list<T*> myList;

    void agregarElemento(T *elemento);
    void borrarLista(size_t position);
    T* seleccionarElementoAleatorio();
    size_t encontrarPosicion(T* value);
   // void imprimirLista();
};