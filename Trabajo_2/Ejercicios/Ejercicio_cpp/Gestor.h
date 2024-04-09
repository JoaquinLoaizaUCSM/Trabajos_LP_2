#ifndef ACTIVIDADES_GESTOR_H
#define ACTIVIDADES_GESTOR_H

#include "Tarea.h"
#include <iostream>
#include <vector>
using namespace std;

//SRP:Clases con única razon, sin razon de cambio
//OCP:Uso de herencia y cambios no afectando a otras clases

class IGestor{
public:
    //Como sabemos el = 0 es porque no se va usar
    virtual void anadir_tarea(Tarea tarea) = 0;
    virtual void mostrar() const = 0;
    virtual void completar(string id) = 0;
};

class Gestor : public IGestor
        {
public:
    vector<Tarea> lista;

    void anadir_tarea(Tarea tarea) override ;

    void mostrar() const override;

    void completar(string id) override;



};

void Gestor::anadir_tarea(Tarea tarea)
{
    lista.push_back(tarea);
}

void Gestor::mostrar() const {
    cout << "Tareas Pendientes: " << endl;
    for (Tarea t : lista){
        t.mostrar_tarea();
    }

}

void Gestor::completar(string id) {
    for (auto &t : lista){
        if (t.getNombre() == id){
            t.getEstado();
        }
    }
}



#endif
