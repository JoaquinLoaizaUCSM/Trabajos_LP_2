#ifndef TRABAJOS_LP_2_DEPARTAMENTO_H
#define TRABAJOS_LP_2_DEPARTAMENTO_H

#include <map>
#include <string>
#include "GestorArchivos.h"


template <typename T>
class Departamento {
public:
    Departamento(string  nombre, GestorArchivos gestorArchivos) : nombre(std::move(nombre)), gestorArchivos(gestorArchivos) {}

    void agregarEmpleado(T* empleado) {
        empleados[nextId] = empleado;
        nextId++;
    }

    void eliminarEmpleado(int id) {
        empleados.erase(id);
    }

    void editarEmpleado(int id, string nombre, double salario) {
        auto it = empleados.find(id);
        if (it != empleados.end()) {
            it->second->setNombre(nombre);
            it->second->setSalario(salario);
        }
    }
    T* buscarEmpleado(int id) const {
        auto it = empleados.find(id);
        if (it != empleados.end()) {
            return it->second;
        }
        return nullptr;
    }

    void getEmpleado(string nombre) {
        for (auto& empleado : empleados) {
            if (empleado.second->getNombre() == nombre) {
                std::cout << "Empleado encontrado: " << empleado.second->getNombre() << std::endl;
                return;
            }
        }
        std::cout << "Empleado no encontrado" << std::endl;
    }

    map<int, T*>& getEmpleados(){
        return empleados;
    }

    string getNombre()  {
        return nombre;
    }

    void guardarEmpleados() {
        gestorArchivos.guardar("empleados.txt" ,empleados);
    }

    void cargarEmpleados() {
        GestorArchivos::cargar("empleados.txt", empleados);
    }
private:
    string nombre;
    map<int, T*> empleados;
    GestorArchivos gestorArchivos;
    int nextId = 0;
};


#endif // TRABAJOS_LP_2_DEPARTAMENTO_H
