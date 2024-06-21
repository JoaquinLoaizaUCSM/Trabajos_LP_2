#ifndef TRABAJOS_LP_2_REPORTE_H
#define TRABAJOS_LP_2_REPORTE_H

#include "Empleados/Empleado.h"
#include <iostream>
using namespace std;

template <typename T>

class Reportes {
public:

    static void generarReporte(T& empresa) {
        cout << "Reporte de la Empresa:" << empresa.getNombre() << endl;

        if (empresa.getDepartamentos().empty()) {
            cout << "No hay departamentos registrados" << endl;
            return;
        }
        else {
            for (auto& departamento : empresa.getDepartamentos()) {
                cout << "Departamento:" << departamento->getNombre() << endl;
                for (pair<const int, Empleado *> empleado : departamento->getEmpleados()) {
                    cout << "  Empleado: " << empleado.second->getNombre() << ", Salario: " << empleado.second->calcularSalario() << endl;
                }
            }
        }
    }

    static void mostrarSalarioTotal(const T& empresa) {
        if (empresa.getDepartamentos().empty()) {
            cout << "No hay departamentos registrados" << endl;
            return;
        }
        double salarioTotal = 0;
        for (auto& departamento : empresa.getDepartamentos()) {
            for (auto& empleado : departamento->getEmpleados()) {
                salarioTotal += empleado->calcularSalario();
            }
        }
        cout << "Salario total de la empresa: " << salarioTotal << endl;
    }

    static void mostrarEmpleadosPorDepartamento(T& empresa) {
        if (empresa.getDepartamentos().empty()) {
            cout << "No hay departamentos registrados" << endl;
            return;
        } else {
            for (auto& departamento : empresa.getDepartamentos()) {
                cout << "Departamento: " << departamento->getNombre() << endl;
                for (auto& empleado : departamento->getEmpleados()) {
                    cout << "  Empleado: " << empleado->getNombre() << endl;
                }
            }
        }
    }

    static void mostrarEmpleadosDelDepartamento(T* departamento) {
        if (departamento->getEmpleados().empty()) {
            cout << "No hay empleados registrados en el departamento" << endl;
            return;
        }

        cout << "Empleados del departamento: " << departamento->getNombre() << endl;
        for (pair<const int, Empleado *> &empleado : departamento->getEmpleados()) {
            cout << "  Empleado: " << empleado.second->getNombre() << endl;
        }
    }

};

#endif //TRABAJOS_LP_2_REPORTE_H