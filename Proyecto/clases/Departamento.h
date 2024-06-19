
#ifndef TRABAJOS_LP_2_DEPARTAMENTO_H
#define TRABAJOS_LP_2_DEPARTAMENTO_H

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include "GestorArchivo.h"
#include "Empleado.h"

using namespace std;

template <typename T>
class Departamento {
    vector<T*> empleados;

public:
    ~Departamento() {
        for (auto empleado : empleados) {
            delete empleado;
        }
    }

    void agregarEmpleado(T* empleado) {
        empleados.push_back(empleado);
    }

    void eliminarEmpleado(const string& nombre) {
        empleados.erase(remove_if(empleados.begin(), empleados.end(),
                                  [&nombre](T* empleado) {
                                      return empleado->getNombre() == nombre;
                                  }), empleados.end());
    }

    T* buscarEmpleado(const string& nombre) const {
        auto it = find_if(empleados.begin(), empleados.end(),
                          [&nombre](T* empleado) {
                              return empleado->getNombre() == nombre;
                          });
        if (it != empleados.end()) {
            return *it;
        } else {
            throw runtime_error("Empleado no encontrado");
        }
    }

    void ordenarEmpleados(function<bool(T*, T*)> comparador) {
        sort(empleados.begin(), empleados.end(), comparador);
    }


    void listarEmpleados() const {
        for (const auto& empleado : empleados) {
            cout << "Nombre: " << empleado->getNombre() << ", Salario: " << empleado->calcularSalario() << endl;
        }
    }

    void guardar(const string& archivo) const {
        GestorArchivos::guardar(archivo, empleados);
    }

    void cargar(const string& archivo) {
        GestorArchivos::cargar(archivo, empleados);
    }
};

#endif //TRABAJOS_LP_2_DEPARTAMENTO_H
