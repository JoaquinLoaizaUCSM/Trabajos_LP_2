#ifndef TRABAJOS_LP_2UTILIDADES_H
#define TRABAJOS_LP_2UTILIDADES_H

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Empleado.h"

using namespace std;

class GestorArchivos {
public:
    template <typename T>
    static void guardar(const string& archivo, const vector<T*>& empleados) {
        ofstream ofs(archivo);
        if (!ofs) {
            throw runtime_error("Error al abrir el archivo para guardar");
        }
        for (const auto& empleado : empleados) {
            ofs << typeid(*empleado).name() << " "
                << empleado->getNombre() << " "
                << empleado->getSalario() << " "
                << empleado->getFechaContratacion() << endl;
        }
    }

    static Empleado* crearEmpleado(const string& tipo, const string& nombre, double salario, int fechaContratacion) {
        if (tipo == typeid(Gerente).name()) {
            return new Gerente(nombre, salario, fechaContratacion); // Se podría ajustar el bono aquí
        } else if (tipo == typeid(Desarrollador).name()) {
            return new Desarrollador(nombre, salario, fechaContratacion);
        } else if (tipo == typeid(Disenador).name()) {
            return new Disenador(nombre, salario, fechaContratacion);
        }
        return nullptr;
    }

    template <typename T>
    static void cargar(const string& archivo, vector<T*>& empleados) {
        ifstream ifs(archivo);
        if (!ifs) {
            throw runtime_error("Error al abrir el archivo para cargar");
        }
        string tipo, nombre;
        double salario;
        time_t fechaContratacion;
        while (ifs >> tipo >> nombre >> salario >> fechaContratacion) {
            Empleado* empleado = crearEmpleado(tipo, nombre, salario, fechaContratacion);
            if (empleado) {
                empleados.push_back(static_cast<T*>(empleado));
            }
        }
    }
};
#endif // TRABAJOS_LP_2UTILIDADES_H

