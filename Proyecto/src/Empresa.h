#ifndef TRABAJOS_LP_2_EMPRESA_H
#define TRABAJOS_LP_2_EMPRESA_H

#include <set>
#include <algorithm>
#include <iostream>
#include "Departamento.h"

using namespace std;

template <typename T>
class Empresa {
public:
    explicit Empresa(string  nombre, set<T*> departamentos)
            : nombre(std::move(nombre)), departamentos(move(departamentos)) {}

    Empresa(string  nombre, T* depatamento) : nombre(std::move(nombre)) {
        departamentos.insert(depatamento);
    }

    ~Empresa() {
        for (auto departamento : departamentos) {
            delete departamento;
        }
    }

    void agregarDepartamento(T* departamento) {
        departamentos.insert(departamento);
    }

    void eliminarDepartamento(const string& nombre) {
        auto it = find_if(departamentos.begin(), departamentos.end(),
                          [&nombre](T* departamento) {
                              return departamento->getNombre() == nombre;
                          });
        if (it != departamentos.end()) {
            delete *it;
            departamentos.erase(it);
            cout << "Departamento eliminado correctamente" << endl;
        } else {
            cout << "Departamento no encontrado" << endl;
        }
    }

    T* buscarDepartamento(const string& nombre) {
        auto it = find_if(departamentos.begin(), departamentos.end(),
                          [&nombre](T* departamento) {
                              return departamento->getNombre() == nombre;
                          });
        if (it != departamentos.end()) {
            return *it;
        }
        return nullptr;
    }


    string getNombre()  {
        return nombre;
    }

    set<T*> getDepartamentos() {
        return departamentos;
    }


private:
    string nombre;
    set<T*> departamentos;
};

#endif // TRABAJOS_LP_2_EMPRESA_H