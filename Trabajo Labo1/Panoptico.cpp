
#include "Panoptico.h"



using namespace std;


template<typename T>
void cPanoptico<T>::agregarElemento(T* elemento) {
    myList.push_back(elemento);
}

template<typename T>
void cPanoptico<T>::borrarLista(size_t position) {
    try {
        if (position >= myList.size()) {
            throw out_of_range("Posición fuera de rango");
        }

        typename list<T*>::iterator it = myList.begin();
        advance(it, position); // Avanzar el iterador a la posición deseada
        myList.erase(it);
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}

template<typename T>
T* cPanoptico<T>::seleccionarElementoAleatorio() {
    if (myList.empty()) {
        throw out_of_range("La lista está vacía");
    }
    typename list<T*>::iterator it = myList.begin();
    advance(it, rand() % myList.size());
    return *it;
}

template<typename T>
size_t cPanoptico<T>::encontrarPosicion(T* value) {
    size_t position = 0;
    for (typename list<T*>::iterator it = myList.begin(); it != myList.end(); ++it, ++position) {
        if (*it == value) {
            return position;
        }
    }
    throw out_of_range("Elemento no encontrado en la lista");
}
template<typename T>
bool cPanoptico<T>::vacia() {
    return myList.empty();
}
/*
template<typename T>
void cPanoptico<T>::imprimirLista() {
    for (typename list<T*>::iterator it = myList.begin(); it != myList.end(); ++it) {
        (*it)->Imprimir();
    }
}
*/