
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
      //  cout << "No se pudo abrir el archivo" << endl;
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
        cout << "Dragones : "<< endl;
        cout << "Dragones muertos: " << cDragones::DragonesMuertos << endl; 
        for (auto it = listamodificadaD.begin(); it != listamodificadaD.end(); ++it) {
            cDragones* dragon = *it;
            dragon->Imprimir();
            if (dragon->Domado() == true) {
               cout<<"Jinete: "<< buscarJinetePorDragon(listamodificadaJ, dragon)<< endl;
            }
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
                                        (  )   /\   _                       
                                       \ |  (  \ ( \.(                                      _____
                                     \  \ \  `  `   ) \                ___                 / _   \
                                    (_`    \+   . x  ( .\             /   \____-----------/ (o)   \_
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

void usleep(unsigned long long tiempo) {
    this_thread::sleep_for(chrono::microseconds(tiempo));
}

void LimpiarCursor(int x, int y)
{
    situarCursor(x, y);
    cout << "                                                                   ";
}

// Funcion para mover el cursor de la consola a la posicion (x, y)
void situarCursor(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";

    //Comentarios para enteder el codigo
/*
cout << "\033[" << y << ";" << x << "H";
Es una secuencia de escape ANSI utilizada para mover el cursor a una posicion especifica en la consola.


\033[  inicia el comando de control de cursor.
y es la fila a la que se mueve el cursor.
; separa la fila y la columna en la secuencia de escape.
x es la columna a la que se mueve el cursor.
H finaliza la secuencia y efectua el movimiento del cursor.
Sirve para actualizar partes especificas de la pantalla sin borrar y volver a dibujar todo.
*/

}


void ocultarCursor() {
    cout << "\033[?25l";
    /*
    \033[?25l: Es un "codigo secreto" que le dice a la consola que oculte el cursor.
    \033 es una senial especial que dice "voy a enviar un comando",
    y [?25l es el comando especifico para ocultar el cursor.

    */
}

// Funcion para dibujar los limites del área de juego y un dragon en el borde izquierdo
void pintarLimites() {
    for (int i = 2; i < 78; i++) { // Dibuja las lineas de arriba y abajo
        situarCursor(i, 2); cout << char(205);// caracter ═
        situarCursor(i, 33); cout << char(205);
    }
   
    for (int i = 3; i < 33; i++) { // Dibuja las lineas de  los costados
       // caracter │
        situarCursor(77, i); cout << char(186);
    }

    for (int i = 3; i < 15; i++) { // Dibuja las lineas de  los costados
        situarCursor(2, i); cout << char(186); // caracter │
        
    }
    for (int i = 25; i < 33; i++) { // Dibuja las lineas de  los costados
        situarCursor(2, i); cout << char(186); // caracter │
        
    }
    // Dibujo las esquinas
    situarCursor(2, 2); cout << char(201);//caracter ╔
    situarCursor(2, 33); cout << char(200);// ╚
    situarCursor(77, 2); cout << char(187); // ╝
    situarCursor(77, 33); cout << char(188);// ╒

    // Dibujo un dragon en el lado izquierdo
    situarCursor(1, 15); cout << "    , |\\/| ,";
    situarCursor(1, 16); cout << "   /| (..) |\\";
    situarCursor(1, 17); cout << " /  \\(oo)/   \\";
    situarCursor(1, 18); cout << "/    /''\\     \\";
    situarCursor(1, 19); cout << "/    /\\  /\\    \\";
    situarCursor(1, 20); cout << "\\/\\/`\\ \\/ /`\\/\\/ ";
    situarCursor(1, 21); cout << "   ^^--^^^^-^^ ";
}

string buscarJinetePorDragon(list<cJinetes*>& jinetes, cDragones* dragon) {
    for (const auto& jinete : jinetes) {
        if (jinete->getDragon() == dragon) {
            return jinete->getnombre();
        }
    }
    return " No se encontro en la lista de datos. "; // Si no se encuentra ningún jinete para el dragon
    //si dice esto es porque en el csv falta un jinete que tenga al dragon como puntero, puede pasar porque no tengo la misma cantidad de dragones que de jinetes
}
