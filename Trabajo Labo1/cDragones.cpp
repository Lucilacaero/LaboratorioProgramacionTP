#include "cDragones.h"
int cDragones::DragonesVivos = 0;
int cDragones::DragonesMuertos = 0;

cDragones::cDragones() {
	Nombre= " ";
	Estado= false; // domado o no
	
	Entrenado=0;
	PuntosDomado=0;
	Muerte= false;
	vida= 10;
	Ficha.color=" ";
	Ficha.peso= 0;
	//enum edad;
	Ficha.Ataque= FormaAtaque::Notiene;

};


bool cDragones::Domado() {
	if (Entrenado >= 10) 
		return true;
	else
	return false;
}
int cDragones::Entrenar() {
	Entrenado++;
	return Entrenado;

}
int cDragones::PuntosDomados() {
	return PuntosDomado++;
}
bool cDragones::Baja() {
	if (vida <= 0)
		Muerte = true;
		return Muerte;
}
cDragones::~cDragones() {
	DragonesVivos--;
	DragonesMuertos++;
}
void cDragones::Altanombre(string NombreDragon) {
	if (Estado == true)//cambiar estos if por try/catch 
		this->Nombre = NombreDragon;

}

// PORQUE MIERDA NO ANDAAAAAAAAA

int cDragones::Dragonesmuertos()
{
	if (Muerte = true) {
		/* vector<cDragones*> listaDragones;

    // Agregar algunos dragones para la demostración
    for (int i = 0; i < 5; ++i) {
        listaDragones.push_back(new cDragones());
    }

    // Marcar algunos dragones como muertos
    listaDragones[1]->Morir();
    listaDragones[3]->Morir();

    // Contar los dragones muertos
    for (cDragones* dragon : listaDragones) {
        if (dragon->Muerte) {
            contador++;
        }
    }

    // Liberar la memoria de los dragones restantes
    for (cDragones* dragon : listaDragones) {
        delete dragon;
    }

    return contador;
}*/
		return cDragones::DragonesMuertos;

	}
	return 0;
}
