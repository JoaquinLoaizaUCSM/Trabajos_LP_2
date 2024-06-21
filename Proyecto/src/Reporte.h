#ifndef TRABAJOS_LP_2_REPORTE_H
#define TRABAJOS_LP_2_REPORTE_H

#include <iostream>
using namespace std;

template <typename T>

class Reportes {
public:

    static void generarReporte(T& empresa) {
        cout << "Reporte de la Empresa:" << empresa.getNombre() << endl;
        for (auto& departamento : empresa.getDepartamentos()) {
            cout << "Departamento:" << departamento->getNombre() << endl;
            for (auto& empleado : departamento->getEmpleados()) {
                cout << "  Empleado: " << empleado->getNombre() << ", Salario: " << empleado->calcularSalario() << endl;
            }
        }
    }

    static void mostrarSalarioTotal(const T& empresa) {
        double salarioTotal = 0;
        for (auto& departamento : empresa.getDepartamentos()) {
            for (auto& empleado : departamento->getEmpleados()) {
                salarioTotal += empleado->calcularSalario();
            }
        }
        cout << "Salario total de la empresa: " << salarioTotal << endl;
    }

    static void mostrarEmpleadosPorDepartamento(T& empresa) {
        for (auto& departamento : empresa.getDepartamentos()) {
            cout << "Departamento: " << departamento->getNombre() << endl;
            for (auto& empleado : departamento->getEmpleados()) {
                cout << "  Empleado: " << empleado->getNombre() << endl;
            }
        }
    }

};

#endif //TRABAJOS_LP_2_REPORTE_H