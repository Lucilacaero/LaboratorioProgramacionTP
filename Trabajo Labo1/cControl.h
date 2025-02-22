#pragma once

#include "cVikingoAtaque.h"
#include "cDragonAtaque.h"
#include "Proyectiles.h"

#include <list>
using namespace std;
class cVikingoAtaque;
class cDragonAtaque;


#include <vector>

class cControl {
private:
    cVikingoAtaque* v;
    cDragonAtaque* dragonAtaque;
    vector<Proyectiles*> balas;
    vector<cDragonAtaque*> asteroides;

public:
    cControl(cVikingoAtaque* vikingo, cDragonAtaque* dragon);
    ~cControl();
    void inicializar();
    void generarAsteroides();
    void manejarColisiones();
    void ejecutar();
    void terminar() const;
};


