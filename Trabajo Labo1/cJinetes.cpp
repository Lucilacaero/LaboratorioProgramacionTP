/*
#include "cJinetes.h"

cJinetes::cJinetes(string nombre, string fecha_nac, string fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon):cVikingos(nombre,fecha_nac, fuerza, vida, muerto, trabajo,* dragon, dragon_muerto)
{
	this->Resultado = resultado;
	this->NombreDragon = nombredragon;

}*/
#include "cJinetes.h"

cJinetes::cJinetes(string nombre, string fecha_nac, string fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon)
    : cVikingos(nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto), Resultado(resultado), NombreDragon(nombredragon) {}
/* 
void Altanombre(cJinetes& asignado, string nuevoNombre) {
    if (asignado.Dragon) {
        asignado.Dragon->Nombre = nuevoNombre;
    }
}
*/