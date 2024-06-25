
#include "AyuditaMain.h"



// Función para cargar datos desde un archivo CSV
void cargarlistas(const string& nombreArchivo, list<cDragones*>& dragones, list<cVikingos*>& vikingos, list<cJinetes*>& jinetes) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }
    cout << "¿Ver las listas cargadas? S/N";
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

        // Depuración: Imprimir los valores leídos
        
        if (respuesta == "S") {
            cout << "Tipo: " << tipo << ", Nombre: " << nombre << ", Fecha: " << fecha_nac << ", Fuerza: " << fuerza << ", Vida: " << vida << ", Muerto: " << muerto << endl;

        }
        
        if (tipo == "dragon") {
            ss >> id >> delimitador;
            getline(ss, ataque, ',');
            string estadoStr;
            getline(ss, estadoStr, ',');
            estado = (estadoStr == "si");
            ss >> entrenado;

            cDragones* dragon = new cDragones(nombre, fecha_nac, fuerza, vida, muerto, id, ataque, estado, entrenado);
            dragones.push_back(dragon);
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
                throw runtime_error("No se encontró el dragón con el ID especificado");
            }

            ss >> dragon_muerto >> delimitador;

            cVikingos* vikingo = new cVikingos(nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto);
            vikingos.push_back(vikingo);
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
                throw runtime_error("No se encontró el dragón con el ID especificado");
            }

            ss >> dragon_muerto >> delimitador;
            getline(ss, resultado, ',');
            getline(ss, nombreDragon, ',');

            cJinetes* jinete = new cJinetes(nombre, fecha_nac, fuerza, vida, muerto, trabajo, dragon, dragon_muerto, resultado, nombreDragon);
            jinetes.push_back(jinete);
        }
        else {
            throw invalid_argument("Tipo no reconocido: " + tipo);
        }
    }

    archivo.close();
}


void guardarListas(string& nombreArchivo, list<cDragones*>& listamodificadaD, list<cVikingos*>& listamodificadaV, list<cJinetes*>& listamodificadaJ) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo para guardar");
    }

    // Guardar dragones
    for (auto it = listamodificadaD.begin(); it != listamodificadaD.end(); ++it) {
        archivo << "dragon,"
            << (*it)->Nombre << ","
            << (*it)->Fecha_nac << ","
            << (*it)->Fuerza << ","
            << (*it)->Vida << ","
            << ((*it)->Muerto ? "si" : "no") << ","
            << (*it)->Id << ","
            << (*it)->Ataque << ","
            << ((*it)->Entrenado ? "si" : "no") << endl;
    }

    // Guardar vikingos
    for (auto it = listamodificadaV.begin(); it != listamodificadaV.end(); ++it) {
        archivo << "vikingo,"
            << (*it)->Nombre << ","
            << (*it)->Fecha_nac << ","
            << TrabajoToString((*it)->Trabajo) << ","
            << (*it)->getDragon()->Id << ","
            << (*it)->Dragon_Muerto << endl;
    }

    // Guardar jinetes
    for (auto it = listamodificadaJ.begin(); it != listamodificadaJ.end(); ++it) {
        archivo << "jinete,"
            << (*it)->Nombre << ","
            << (*it)->Fecha_nac << ","
            << (*it)->Fuerza << ","
            << (*it)->Vida << ","
            << ((*it)->Muerto ? "si" : "no") << ","
            << TrabajoToString((*it)->Trabajo) << ","
            << (*it)->getDragon()->Id << ","
            << (*it)->Dragon_Muerto << ","
            << (*it)->Resultado << ","
            << (*it)->NombreDragon << endl;
    }

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
        cout << "Posición: Pescador" << endl;
        break;
    case Posicion::Herrero:
        s = "Herrero";
        break;
    case Posicion::Jinete:
        s = "Jinete";
        break;
    default:
        cout << "Posición no reconocida" << endl;
        break;
    }
    return s;

}
// Función para convertir string a enum Posicion
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
        throw invalid_argument("String no válido para Posicion");
    }
}


// Función auxiliar para encontrar un

// 
// estoy trabajando con el dato original porwue lo devuelvo por referencia, puede perder el encapsulamiwnto