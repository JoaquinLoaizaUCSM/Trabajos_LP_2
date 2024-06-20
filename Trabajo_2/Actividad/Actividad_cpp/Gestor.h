#ifndef ACTIVIDADES_GESTOR_H
#define ACTIVIDADES_GESTOR_H

#include "Tarea.h"
#include <iostream>
#include <vector>
using namespace std;

//SRP:Clases con única razon, sin razon de cambio
//OCP:Uso de herencia y cambios no afectando a otras src

class Interfaz_Gestor{
public:
    //Como sabemos el = 0 es porque no se va usar
    virtual void añadir_tarea(Tarea tarea) = 0;
    virtual void mostrar() const = 0;
    virtual void completar(string id) = 0;
};

class Gestor : public Interfaz_Gestor{
public:
    vector<Tarea> lista;

void añadir_tarea(Tarea tarea) override {
    lista.push_back(tarea);
}

void mostrar() const override{
    cout << "Tareas Pendientes: " << endl;
    for (Tarea t : lista){
        t.mostrar_tarea();
    }
}

void completar(string id) override {
    for (Tarea& t : lista){
        if (t.numero == id){
            t.completar_tarea();
            cout << "Tarea Completada :)" << endl;
        }
    }
}
};


#endif
