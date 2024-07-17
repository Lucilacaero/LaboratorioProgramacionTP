
#include "cJinetes.h"
#include <iostream>
#include "AyuditaMain.h"
class cVikingos;
class cDragones;
using namespace std;

cJinetes::cJinetes(string tipo, string nombre, string fecha_nac, unsigned int fuerza, int vida, bool muerto, Posicion trabajo, cDragones* dragon, int dragon_muerto, string resultado, string nombredragon)
    :cVikingos(tipo, nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto) {

    Resultado = resultado;
    NombreDragon = nombredragon;
}
cJinetes::cJinetes(const cJinetes& otro) {
    // Copiar cada atributo desde 'otro' al nuevo objeto creado 
    this->Tipo = otro.Tipo;
    this->Nombre = otro.Nombre;
    this->Fecha_nac = otro.Fecha_nac;
    this->Fuerza = otro.Fuerza;
    this->Vida = otro.Vida; 
    this->Muerto = otro.Muerto;
    this->Trabajo = otro.Trabajo;
    this->Dragon = otro.Dragon;
    this->Dragon_Muerto = otro.Dragon_Muerto;
    this->Resultado = otro.Resultado;
    this->NombreDragon = otro.NombreDragon;
}
cJinetes::cJinetes(const cVikingos& otro, string resultado, string Nombre): cVikingos(otro)
{
    Resultado = resultado;
    this->Nombre = Nombre;

}
cJinetes::~cJinetes()
{
}
cJinetes::cJinetes()
{
    this->Tipo = "Jinete";
    this->Nombre = " ";
    this->Fecha_nac = " ";
    this->Fuerza = 0;
    this->Vida = 100;
    this->Muerto = false;
    this->Trabajo = Posicion::Jinete;
    this->Dragon = nullptr;
    this->Dragon_Muerto = 0;
    this->Resultado = "desaprobado";
    this->NombreDragon = " ";
}
void cJinetes::entrenarDragon() {//agregar en el main que si no aprobo el curso no va a poder entrenar a un dragon y si termino primero se le agrega un 50+ de fuerza
    /* tomar en consideracion
    1. La fuerza del dragon y del jinete
    2. la posicion del jinete, si termina en 1 o 2 lugar tiene ventaja, sino es normalito */
    bool juego;
    juego = entrenar(); //funcion de prueba para que el jinete haga algo y no se asigne puntos porque si
   
    if (juego == true) {
     cDragones* Dragon = this->getDragon();
     int entrenado;

     cout << "El jinete " << Nombre << " va a entrena al dragon " << Dragon->getnombre() << endl;
     if (Resultado == "desaprobado") {
        cout << "lamentamos informarle que el jinete no aprobo el examen y por lo tanto no puede entrenar dragones"<<endl;
     }
     else if (Resultado == "primero" || Resultado == "segundo") {
         this->Fuerza = this->Fuerza + 30;
     }
        if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) < 100) {
            this->Vida -= rand() % 10;
            entrenado = rand() % 5;
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
            entrenado = entrenado + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "Sus puntos totales son " << Dragon->getEntrenado() << endl;

   }
   else if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) < 200) {
            this->Vida -= rand() % 20;
            entrenado = rand() % 3 ;
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
            entrenado = rand() % 3 +Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "Sus puntos totales son " << Dragon->getEntrenado() << endl;
        }
  else if (Dragon->getfuerza() > this->Fuerza && (Dragon->getfuerza() - this->Fuerza) > 200) {
            this->Vida -= rand() % 30;
            entrenado = rand() % 2;
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
            entrenado = rand() % 2 + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "Sus puntos totales son " << Dragon->getEntrenado() << endl;

        }

  else if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) < 100) {

            entrenado = rand() % 10;
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
            entrenado = entrenado + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "Sus puntos totales son " << Dragon->getEntrenado() << endl;
        }
        else if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) < 200) {
            entrenado = rand() % 20;
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
            entrenado = entrenado + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "Sus puntos totales son " << Dragon->getEntrenado() << endl;
        }
        else if (Dragon->getfuerza() < this->Fuerza && (this->Fuerza - Dragon->getfuerza()) > 200) {
            entrenado = rand() % 30;
            cout << "durante el entrenamiento el dragon obtuvo " << entrenado << " puntos de entrenamiente" << endl;
            entrenado = entrenado + Dragon->getEntrenado();
            Dragon->setEntrenado(entrenado);
            cout << "Sus puntos totales son " << Dragon->getEntrenado() << endl;
        }
    
   
    if (Dragon->getEntrenado() >= MaxEntrenamiento) {
        cout << "El dragon ha alcanzado el nivel maximo de entrenamiento." << endl;
    }

    if (this->Vida <= 0) {

        cout << "El jinete ha muerto durante el entrenamiento." << endl;
        setMuerto(true);
    }

    Dragon->Domado();
    
}
}
cJinetes* aleatorio(list<cJinetes*> jinetes) {
    if (jinetes.empty()) {
        cout << "La lista está vacia" << endl;
        return nullptr;
    }

    list<cJinetes*>::iterator it;
    int intentos = 0;
    int maxIntentos = jinetes.size() * 2; // Un limite razonable para evitar un bucle infinito

    do {
        it = jinetes.begin();
        advance(it, rand() % jinetes.size());
        intentos++;
    } while ((*it)->getMuerto() && intentos < maxIntentos);

    if (intentos >= maxIntentos) {
        cout << "No se encontro un jinete vivo después de varios intentos." << endl;
        return nullptr;
    }

    return *it;
}


string cJinetes::to__string()
{
    string s = cVikingos::to__string();

    if (Dragon != nullptr) {
        s += " Dragon: " + Dragon->to__string();
    }
    else
        s += "No tiene dragon asignado";
    s +="/n Resultado: " + Resultado; //no le pongo el atributo nombredragon porque es repetitivo
    return s;
}

void cJinetes::Imprimir()
{
    cout << to__string();
}






cDragones* cJinetes::getDragon()
{
    return Dragon;
}

string cJinetes::getResultado()
{
    return Resultado;
}

void cJinetes::setDragon(cDragones* dragon)
{
    Dragon = dragon;
}

void cJinetes::setResultado(string resultado)
{
    Resultado = resultado;
}


list<cJinetes*>& operator+=(list<cJinetes*>& lista, cJinetes* jinete) {
    lista.push_back(jinete);
    return lista;
}

list<cJinetes*>& operator-=(list<cJinetes*>& lista, cJinetes* jinete) {
    auto it = find(lista.begin(), lista.end(), jinete);
    if (it != lista.end()) {
        delete* it;
        lista.erase(it);
    }
    return lista;
}
ostream& operator<<(ostream& out,  cJinetes& jinete) {
    out << left << setw(15) << setfill(' ') << "Jinete"
        << left << setw(15) << setfill(' ') << jinete.Nombre
        << left << setw(15) << setfill(' ') << jinete.Fecha_nac
        << left << setw(10) << setfill(' ') << jinete.Fuerza
        << left << setw(10) << setfill(' ') << jinete.Vida
        << left << setw(10) << setfill(' ') << (jinete.Muerto ? "si" : "no")
 
        << left << setw(15) << setfill(' ') << TrabajoToString(jinete.Trabajo)
        << left << setw(15) << setfill(' ') << jinete.Resultado
        << left << setw(15) << setfill(' ') << jinete.NombreDragon
        << endl;
    return out;
}


void cJinetes::displayStatus(int clicksActuales, int totalClicks, double TiempoRestante) {
    float progreso = (static_cast<float>(clicksActuales) / totalClicks) * 100; //saco el porcentaje
    cout << "\rTiempo restante: " << TiempoRestante << "s \t";
    cout << "Progreso: " << progreso << "%   ";
    cout.flush(); //evito que se espere a imprimir
}

bool cJinetes::entrenar(){
    const int clicksRequeridos = 25;
    const int TiempoLimite = 5; // en segundos
    int clicksActuales = 0;

    cout << "Presiona las teclas de flecha izquierda y derecha 15 veces en menos de 5 segundos\n";
    cout << "Presiona cualquier tecla para comenzar...\n";
    _getch(); 

    clock_t TiempoDeInicio = clock();// clock() mide el tiempo desde la compu desde que comenzó la ejecución del codigo
    // clock_t representa el tiempo en "ticks de reloj"
    double TiempoRestante = TiempoLimite;

    while (clicksActuales < clicksRequeridos && TiempoRestante > 0) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 224) { 
                key = _getch();
                if (key == 75 || key == 77) { // 75 es flecha izquierda, 77 es flecha derecha
                    clicksActuales++;
                }
            }
        }

        clock_t TiempoACtual = clock();
        TiempoRestante = TiempoLimite - double(TiempoACtual - TiempoDeInicio) / CLOCKS_PER_SEC;
        displayStatus(clicksActuales, clicksRequeridos, TiempoRestante);

        this_thread::sleep_for(chrono::milliseconds(50)); // para que no se sobrecargue la compu
    }

    cout << endl;

    if (clicksActuales >= clicksRequeridos) {
        
        cout << "¡Felicidades! el entrenamiento se completo con exito\n";
        return true;
    }
    else {
        cout << "No lograste completar el entrenamiento a tiempo.\n";
        return false;
    }

    
}
