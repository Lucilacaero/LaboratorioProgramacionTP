#ifndef CJINETES_H
#define CJINETES_H

#include <string>
#include <iostream>
using namespace std;
class cDragones;
struct {
	int peso;
	int altura; 
	string color_pelo;
	string contextura;
}typedef sCaract;
class cJinetes
{
private:
	string Apodo;
	string Fecha_nac;
	sCaract Descripcion;
	string Resultado;
	string NombreDragon;
public:
	cJinetes();
	~cJinetes();
	bool incorporar_dragon(cDragones* dragon);
	
	string getresultado();
	
	void setFechadeNacimiento(string fecha_nac);

	void setApodo(string apodo);


};


#endif // CJINETES_H