#ifndef ACTIVIDADES_TAREA_H
#define ACTIVIDADES_TAREA_H

#include <iostream>
using namespace std;


//La presencia de esta interfaz permite que estos métodos sean implementados por cualquier clase, considerando que las mismas
//pueden cambiar su funcionamiento, es como un “prototipo”, por asi decirlo
class Interfaz_Tarea{
public:
    //La presencia del const por lo que entiendo, hace que no se modifique el estado interno del objeto, por lo que siempre debe estar presente
    virtual void mostrar_tarea() const = 0;
    //Se iguala a 0 para declarar que en esta clase, que es la interfaz esta funcion no tiene implementación y que no bote error
    virtual void completar_tarea() = 0;

};


class Tarea : public Interfaz_Tarea {
private:
    string numero;
    string nombre;
    string fecha;

public:
    //Constructor
    Tarea(string num = "01" ,string name= "Informe LP", string date= "29/12/2025", bool state= false)
    {
        this -> numero = num;
        this -> nombre = name;
        this -> fecha = date;
        this -> estado = state;
    }

    void mostrar_tarea() const override
    {
        cout << "*---*" << endl;
        cout << "Identificador: " << numero << endl;
        cout << "Tarea: " << nombre << endl;
        cout << "Fecha Limite: " << fecha << endl;

        if (estado == true)
        {
            cout << "Completada: " << "SI" << endl;
        } else
        {
            cout << "Completada: " << "NO" << endl;
        }

    cout << "*---*" << endl;

    };

    void completar_tarea() override
    {
        estado = true;
    }

    const string &getNumero() const {
        return numero;
    }

    void setNumero(const string &numero) {
        Tarea::numero = numero;
    }

    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        Tarea::nombre = nombre;
    }

    const string &getFecha() const {
        return fecha;
    }

    void setFecha(const string &fecha) {
        Tarea::fecha = fecha;
    }

    bool getEstado() const {
        return estado;
    }

    void setEstado(bool estado) {
        Tarea::estado = estado;
    }

    bool estado;
};
#endif
