#ifndef TRABAJOS_LP_2_EMPRESA_H
#define TRABAJOS_LP_2_EMPRESA_H

#include <set>
#include "Departamento.h"

template <typename T>
class Empresa {
public:
    explicit Empresa(string nombre, vector<T*> departamento) : nombre(nombre) ,departamentos(departamento){
    }

    Empresa(string nombre, T* departamento) : nombre(nombre) {
        departamentos.insert(departamento);
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
        departamentos.erase(remove_if(departamentos.begin(), departamentos.end(),
                                      [&nombre](T* departamento) {
                                          return departamento->getNombre() == nombre;
                                      }), departamentos.end());
        cout << "Departamento eliminado correctamente" << endl;
    }

    void guardarDatos() {
        for (auto departamento : departamentos) {
            departamento->guardar("empleados.txt");
        }
    }

    void cargarDatos() {
        for (auto departamento : departamentos) {
            departamento->cargar("empleados.txt");
        }
    }

    set<T *> & getDepartamentos() {
        return departamentos;
    }

    string getNombre() {
        return nombre;
    }


private:
    string nombre;
    set<T*> departamentos;
};




#endif //TRABAJOS_LP_2_EMPRESA_H
