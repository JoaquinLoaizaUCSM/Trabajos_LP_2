#ifndef TRABAJOS_LP_2_DEPARTAMENTO_H
#define TRABAJOS_LP_2_DEPARTAMENTO_H

#include <vector>
#include <stdexcept>
#include <functional>
#include "GestorArchivos.h"
#include "Empleados/Empleado.h"

using namespace std;

template <typename T>
class Departamento {
private:
    vector<T*> empleados;
    GestorArchivos manejadorArchivos;
    string nombre;

public:
    ~Departamento() {
        for (auto empleado : empleados) {
            delete empleado;
        }
    }

    explicit Departamento(string nombre) : nombre(nombre) {}

    Departamento(string nombre, vector<T*> empleados) : empleados(empleados), nombre(nombre) {}

    Departamento(string nombre, vector<T*> empleados, GestorArchivos manejadorArchivos)
            : empleados(empleados), manejadorArchivos(manejadorArchivos), nombre(nombre) {}



    void agregarEmpleado(T* empleado) {
        empleados.push_back(empleado);
        cout << "Empleado agregado correctamente" << endl;
    }

    void agregarEmpleado(vector<T*> empleados) {
        for (auto empleado : empleados)
            this->empleados.push_back(empleado);

        cout << "Empleados agregados correctamente" << endl;
    }

    void eliminarEmpleado(const string& nombre) {
        empleados.erase(remove_if(empleados.begin(), empleados.end(),
                                  [&nombre](T* empleado) {
                                      return empleado->getNombre() == nombre;
                                  }), empleados.end());
        cout << "Empleado eliminado correctamente" << endl;
    }

    void EditarEmpleado(const string& nombre, const string& nuevoNombre, double nuevoSalario, int nuevaFechaContratacion) {
        auto empleado = buscarEmpleado(nombre);
        empleado->setNombre(nuevoNombre);
        empleado->setSalario(nuevoSalario);
        empleado->setFechaContratacion(nuevaFechaContratacion);
        cout << "Empleado editado correctamente" << endl;
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
        cout << "Empleados ordenados correctamente" << endl;
    }

    void listarEmpleados() const {
        for (const auto& empleado : empleados) {
            cout << "Nombre: " << empleado->getNombre() << ", Salario: " << empleado->calcularSalario() << endl;
        }
    }

    void guardar(const string& archivo) {
        manejadorArchivos.guardar(archivo, empleados);
    }

    void cargar(const string& archivo) {
        manejadorArchivos.cargar(archivo, empleados);
    }

    string getNombre() {
        return nombre;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    vector<T*>& getEmpleados()  {
        return empleados;
    }
};

#endif // TRABAJOS_LP_2_DEPARTAMENTO_H
