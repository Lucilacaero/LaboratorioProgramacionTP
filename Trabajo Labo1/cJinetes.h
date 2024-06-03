/*
#ifndef CJINETES_H
#define CJINETES_H

#include "cPersona.h"

class cJinetes : protected cVikingos
{
private:

	string Resultado;
	string NombreDragon;
public:
	cJinetes(string nombre, string fecha_nac, string fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon);
};

#endif // CJINETES_H

*/

/*
#pragma once
#include "cVickingos.h"

class cJinetes : protected cVikingos {
private:
    string Resultado;
    string NombreDragon;

public:
    cJinetes(string nombre, string fecha_nac, string fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon);
    friend void Altanombre(cJinetes& asignado, string nuevoNombre); // Declaración de función friend
};
*/
#pragma once
#include "cVikingos.h"

class cJinetes : protected cVikingos {
private:
    string Resultado;
    string NombreDragon;

public:
    cJinetes(string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon);
    friend void Altanombre(cJinetes& asignado, string nuevoNombre);
};
