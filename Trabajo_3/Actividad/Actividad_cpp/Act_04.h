#ifndef LP_04_ACT_04_H
#define LP_04_ACT_04_H
#include <iostream>
#include <vector>

using namespace std;

class Trabajador;
class Gerente;
const int MAX_TRABAJADORES = 10;

class Trabajador {
private:
    string nombre;
    string apellido;
    Trabajador* companeros[MAX_TRABAJADORES];
    int num_compas = 0;
public:
    Trabajador(string nombre="", string apellido="") {
        this->nombre = nombre;
        this->apellido = apellido;
    }
    void agregar_companero(Trabajador* trabajador) {
        if(num_compas < MAX_TRABAJADORES) {
            companeros[num_compas++] = trabajador;
        }else {
            cout << "Limite alcanzado." << endl;
        }
    }
    string getNombre() {
        return nombre;
    }

    void mostrar_compas() {
        cout << "Companeros de : " << nombre << endl;
        for (int i = 0; i < num_compas; i++) {
            cout << "   - " << companeros[i]->getNombre() << endl;
        }
    }
};

class Gerente: public Trabajador {
private:
    Trabajador* trabajadores_cargo[MAX_TRABAJADORES];
    int num_traba_cargo = 0;
public:
    Gerente(string nombre="", string apellido="") : Trabajador(nombre, apellido) {}

    void agregar_trabajar_cargo(Trabajador* trabajador) {
        if (num_traba_cargo < MAX_TRABAJADORES) {
            trabajadores_cargo[num_traba_cargo++] = trabajador;
        } else {
            cout << "No se pueden agregar más trabajadores a cargo." << endl;
        }
    }

    void mostrar_trabajadores_cargo() {
        cout << "Trabajadores a cargo de " << getNombre() << endl;
        for (int i = 0; i < num_traba_cargo; i++) {
            cout << "- " << trabajadores_cargo[i]->getNombre() << endl;
        }
        cout << endl;
    }
};


#endif
