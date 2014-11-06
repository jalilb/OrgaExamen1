// queue::push/pop
#include "Monstruo.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto monstruo (dado) en el archivo binario nombre_archivo (dado) en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Monstruo*monstruo, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    if(!out.is_open()){
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*53);
    out.write((char*)&monstruo->cabezas,4);
    out.write((char*)&monstruo->brazos,4);
    out.write((char*)&monstruo->piernas,4);
    out.write(monstruo->nombre.c_str(),20);
    out.write(monstruo->apodo.c_str(),20);
    out.write((char*)&monstruo->es_carnivoro,1);
    out.close();
}

//Devuelve un monstruo previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Monstruo* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*53);
    int cabezas;
    int brazos;
    int piernas;
    char nombre[20];
    char apodo[20];
    bool es_carnivoro;
    in.read((char*)&cabezas,4);
    in.read((char*)&brazos,4);
    in.read((char*)&piernas,4);
    in.read(nombre,20);
    in.read(apodo,20);
    in.read((char*)&es_carnivoro,1);
    return new Monstruo(cabezas,brazos,piernas,nombre,apodo,es_carnivoro);
}

//Devuelve el nombre del monstruo con mas cabezas previamente escrito (con la funcion escribir) en el archivo dado
string getMonstruoConMasCabezas(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(0,in.end);
    float tam=in.tellg()/53;
    in.seekg(0);
    int cabezas;
    int brazos;
    int piernas;
    char nombre[20];
    char apodo[20];
    bool es_carnivoro;
    int mayor=0;
    string temp_nombre;
    for(int i = 0; i < tam; i++){
        in.read((char*)&cabezas,4);
        in.read((char*)&brazos,4);
        in.read((char*)&piernas,4);
        in.read(nombre,20);
        in.read(apodo,20);
        in.read((char*)&es_carnivoro,1);
        if(mayor < cabezas){
            temp_nombre = nombre;
        }
    }
    return temp_nombre;
}


int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
