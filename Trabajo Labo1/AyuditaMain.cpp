
#include "AyuditaMain.h"

cDragones* encontrardragon(unsigned int id, list<cDragones*>& dragones) {
    for(auto &dragon :dragones){
        if (dragon->Id == id) {
            return dragon;
        }
    }
    return nullptr;
}

// Funcion para cargar datos desde un archivo CSV
void cargarlistas(const string& nombreArchivo, list<cDragones*>& dragones, list<cVikingos*>& vikingos, list<cJinetes*>& jinetes) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }
    cout << "Ver las listas cargadas? S/N: ";
    string  respuesta;
    cin >> respuesta;
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);

        string tipo, nombre, fecha_nac, ataque;
        unsigned int fuerza, id;
        int vida, entrenado;
        bool muerto, estado;
        char delimitador;

        getline(ss, tipo, ',');
        getline(ss, nombre, ',');
        getline(ss, fecha_nac, ',');
        ss >> fuerza >> delimitador;
        ss >> vida >> delimitador;
        string muertoStr;
        getline(ss, muertoStr, ',');
        muerto = (muertoStr == "si");

        // Depuracion: Imprimir los valores leIdos

       
        //"Tipo: " << tipo << ", Nombre: " << nombre << ", Fecha: " << fecha_nac << ", Fuerza: " << fuerza << ", Vida: " << vida << ", Esta muerto: " << (muerto ? "si" : "no") << endl;

        if (tipo == "dragon") {
            ss >> id >> delimitador;
            getline(ss, ataque, ',');
            string estadoStr;
            getline(ss, estadoStr, ',');
            estado = (estadoStr == "si");
            ss >> entrenado;


            cDragones* dragon = new cDragones(tipo,nombre, fecha_nac, fuerza, vida, muerto, id, ataque, estado, entrenado);
           
            dragon->formaDeAtaque();
            
            dragones+=dragon;
            if (respuesta == "S") {
                cout << *dragon;
            }
        }
        else if (tipo == "vikingo") {
            string posicionStr;
            unsigned int idDragon;
            int dragon_muerto;

            getline(ss, posicionStr, ',');
            Posicion trabajo = stringToTrabajo(posicionStr);
            ss >> idDragon >> delimitador;

            cDragones* dragon = encontrardragon(idDragon, dragones);
            if (dragon == nullptr) {
                throw runtime_error("No se encontro el dragon con el ID especificado");
            }

            ss >> dragon_muerto >> delimitador;

            cVikingos* vikingo = new cVikingos(tipo, nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto);
            vikingos+=vikingo;
            if (respuesta == "S") {
                cout << *vikingo;
            }
        }
        else if (tipo == "jinete") {
            string posicionStr;
            unsigned int idDragon;
            int dragon_muerto;
            string resultado, nombreDragon;

            getline(ss, posicionStr, ',');
            Posicion trabajo = stringToTrabajo(posicionStr);
            ss >> idDragon >> delimitador;

            cDragones* dragon = encontrardragon(idDragon, dragones);
            if (dragon == nullptr) {
                throw runtime_error("No se encontro el dragon con el ID especificado");
            }

            ss >> dragon_muerto >> delimitador;
            getline(ss, resultado, ',');
            getline(ss, nombreDragon, ',');

            cJinetes* jinete = new cJinetes(tipo, nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto, resultado, nombreDragon);
            jinetes+=jinete;
            if (respuesta == "S") {
                cout << *jinete;
            }
        }
       
        else {
            throw invalid_argument("Tipo no reconocido: " + tipo);
        }
       
    }
    
    cout << "Se cargaron correctamente las listas" << endl;

    archivo.close();
}



string TrabajoToString(Posicion& Trabajo) {
    string s;
    switch (Trabajo) {
    case Posicion::Entrenador:
        s = "Entrenador";
        break;
    case Posicion::Guerrero:
        s = "Guerrero";
        break;
    case Posicion::Agricultor:
        s = "Agricultor";
        break;
    case Posicion::Pescador:
        s = "Pescador";
        break;
    case Posicion::Herrero:
        s = "Herrero";
        break;
    case Posicion::Jinete:
        s = "Jinete";
        break;
    default:
        cout << "Posicion no reconocida" << endl;
        break;
    }
    return s;

}
// Funcion para convertir string a enum Posicion
Posicion stringToTrabajo(const string& stringt) {
    if (stringt == "Entrenador") {
        return Posicion::Entrenador;
    }
    else if (stringt == "Guerrero") {
        return Posicion::Guerrero;
    }
    else if (stringt == "Agricultor") {
        return Posicion::Agricultor;
    }
    else if (stringt == "Pescador") {
        return Posicion::Pescador;
    }
    else if (stringt == "Herrero") {
        return Posicion::Herrero;
    }
    else if (stringt == "Jinete") {
        return Posicion::Jinete;
    }
    else {
        throw invalid_argument("El String no coincide con la Posicion");
    }
}

void imprimirresumen(list <cDragones*>& listamodificadaD, list <cVikingos*>&listamodificadaV, list <cJinetes*>& listamodificadaJ) {


    cout << "A continuacion se mostraran los cambios de este dia" << endl;
    print();
    if (listamodificadaD.empty()) {
        cout << "Dragones muertos: Ningun dragon murio hoy" << endl;
    }
    else {
        cout << "Dragones : " << cDragones::DragonesMuertos << endl;
        cout << "Dragones muertos: " << endl;
        for (auto it = listamodificadaD.begin(); it != listamodificadaD.end(); ++it) {
            cDragones* dragon = *it;
            dragon->Imprimir();
        }
    }
    cout << "Dragones Vivos: " << cDragones::DragonesVivos << endl;
   
    cout << "Dragones domados " << cDragones::Domados << endl;
    cout << "\n";
    cout << "Vikingos muertos:" << endl;
    if (listamodificadaV.empty()) {
        cout << "Ningun vikingo murio hoy" << endl;
    }
    else {
        for (auto it = listamodificadaV.begin(); it != listamodificadaV.end(); ++it) {
            cVikingos* vikingo = *it;
            vikingo->Imprimir();
        }
    }
    cout << "\n";
    cout << "Jinetes muertos:" << endl;
    if (listamodificadaJ.empty()) {
        cout << "Ningun jinete murio hoy" << endl;
    }
    else {
        for (auto it = listamodificadaJ.begin(); it != listamodificadaJ.end(); ++it) {
            cJinetes* jinete = *it;
            jinete->Imprimir();
        }
    }

}
void print() {
    string dragon =
        R"(
                                        (  )   /\   _                 (     
                                       \ |  (  \ ( \.(               )                      _____
                                     \  \ \  `  `   ) \             (  ___                 / _   \
                                    (_`    \+   . x  ( .\            \/   \____-----------/ (o)   \_
                                    - .-               \+  ;          (  O                           \____
                                       \_____________  `              \  /
                                    (__                +- .( -'.- <. - _  VVVVVVV VV V\                 \/
                                    ( _____            ._._: <_ - <- _  (--  _AAAAAAA__A_/                  |
                                 .    /./.+-  . .- /  +--  - .     \______________//_              \_______
                                (__ ' /x  / x _/ (                                  \___'          \     /
                                 , x / ( '  . / .  /                                      |           \   /
                                   /  /  _/ /    +                                      /              \/
                                  '  (__/                                             /

                            
)";
    cout << dragon;
}