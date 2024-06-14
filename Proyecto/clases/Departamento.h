
#ifndef TRABAJOS_LP_2_DEPARTAMENTO_H
#define TRABAJOS_LP_2_DEPARTAMENTO_H

#include "empleado.h"
#include <vector>
#include <string>

// Plantilla de clase Departamento
template <typename T>
class Departamento {
private:
    std::vector<T*> empleados;

public:
    void agregarEmpleado(T* empleado) {
        empleados.push_back(empleado);
    }


    void eliminarEmpleado(size_t indice) {
        if (indice < empleados.size()) {
            delete empleados[indice];
            empleados.erase(empleados.begin() + indice);
        }
    }

    T* buscarEmpleado(const std::string& nombre) {
        for (T* emp : empleados) {
            if (emp->getNombre() == nombre) {
                return emp;
            }
        }
        return nullptr; // No encontrado
    }

    void listarEmpleados() const {
        for (Empleado *emp : empleados) {
            emp->mostrarDatos();
            std::cout << "Salario Calculado: " << emp->calcularSalario() << std::endl;
        }
    }

    ~Departamento() {
        for (T* emp : empleados) {
            delete emp;
        }
    }
};
#endif //TRABAJOS_LP_2_DEPARTAMENTO_H
