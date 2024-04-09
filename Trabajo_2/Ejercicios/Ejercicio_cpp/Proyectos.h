#ifndef ACTIVIDADES_PROYECTOS_H
#define ACTIVIDADES_PROYECTOS_H

#include "Tarea.h"
#include <vector>

class IProyectos{
public:
    //La presencia del const por lo que entiendo, hace que no se modifique el estado interno del objeto, por lo que siempre debe estar presente
    virtual void mostrar_tareas() const = 0;
    //Se iguala a 0 para declarar que en esta clase, que es la interfaz esta funcion no tiene implementación y que no bote error
    virtual void estado() = 0;

    virtual void añadirTarea() = 0;

    virtual void finalizarTarea() = 0 ;
};



class Proyectos : public IProyectos{
public:
    string nombre;
    vector<Tarea> lista;


    //Constructor
    Proyectos(string name)
    {
        this -> nombre = name;
        this -> lista = {};
    }
    void mostrar_tareas() const override
    {
        cout << "Proyecto: " << nombre << endl;
        cout << "Tareas Pendientes: " << endl;
        for (Tarea t : lista)
        {
            t.mostrar_tarea();
        }
    }
    void estado() override
    {
        cout << "Proyecto: " << nombre << endl;
        cout << "Tareas Completadas: " << endl;
        for (Tarea t : lista){
            if (t.estado == true)
            {
                t.mostrar_tarea();
            }
        }
    }
    void añadirTarea() override
    {
        string num;
        string name;
        string date;
        cout << "Ingrese el numero de la tarea: ";
        cin >> num;
        cout << "Ingrese el nombre de la tarea: ";
        cin >> name;
        cout << "Ingrese la fecha limite de la tarea: ";
        cin >> date;
        Tarea tarea(num, name, date);
        lista.push_back(tarea);
    }
    void finalizarTarea() override
    {
        string id;
        cout << "Ingrese el numero de la tarea a finalizar: ";
        cin >> id;
        for (Tarea& t : lista)
        {
            if (t.getNumero() == id)
            {
                t.completar_tarea();
                cout << "Tarea Completada :)" << endl;
            }
        }
    }

};

#endif //ACTIVIDADES_PROYECTOS_H
