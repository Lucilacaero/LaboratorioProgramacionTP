
#include "cJinetes.h"
#include "cDragones.h"
#include <iostream>

using namespace std;
/*
void Altanombre(cJinetes& asignado, string nuevoNombre) 
*/

cJinetes::cJinetes(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon)
	:cVikingos(nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto){
	
	Resultado = resultado;
	NombreDragon = nombredragon;
}

/*
void cJinetes::evaluarResultado() {
    if (Resultado == "Aprobado") {
        cout << "El jinete " << Nombre << " ha ganado. Su dragón recibirá un entrenamiento especial." << endl;
        //ver como accedo al dragon asignado
        // dragon.Entrenar();
    }
    else if (Resultado == "Aprobado") {
        cout << "El jinete " << Nombre << " ha perdido. Su dragón no recibirá entrenamiento." <<endl;
    }
    else {
        cout << "Resultado desconocido para el jinete " << Nombre << "." << endl;
    }
}
*/

