#include <iostream>
#include "clases/Empleado.h"

using namespace std;

template <typename T>
class Departamento {
private:
    T* empleados[3];
    int numEmpleados;

public:
    Departamento(int numEmpleados =0, T* empleados[3]=nullptr) : numEmpleados(numEmpleados) {
        numEmpleados = numEmpleados;

        if (empleados == nullptr) {
            for (int i = 0; i < numEmpleados; i++) {
                this->empleados[i] = nullptr;
            }
        }
    }

    void agregarEmpleado(T* empleado) {
        if (numEmpleados < 100) {
            empleados[numEmpleados++] = empleado;
        } else {
            cout << "No se puede agregar más empleados, el departamento está lleno." << endl;
        }
    }

    void eliminarEmpleado(size_t indice) {
        if (indice < numEmpleados) {
            delete empleados[indice];
            for (int i = indice; i < numEmpleados - 1; i++) {
                empleados[i] = empleados[i + 1];
            }
            numEmpleados--;
        }
    }

    T* buscarEmpleado(const string& nombre) {
        for (int i = 0; i < numEmpleados; i++) {
            if (empleados[i]->getNombre() == nombre) {
                return empleados[i];
            }
        }
        return nullptr;
    }

    void listarEmpleados() const {
        for (int i = 0; i < numEmpleados; i++) {
            empleados[i]->mostrarDatos();
            cout << "Salario Calculado: " << empleados[i]->calcularSalario() << endl;
        }
    }

    ~Departamento() {
        for (int i = 0; i < numEmpleados; i++) {
            delete empleados[i];
        }
    }
};

int main() {
    Departamento<Empleado> departamento(3);

    Empleado* empleados[3];

    empleados[0] = new Gerente("Juan", 1000,10062024);
    empleados[1] = new Desarrollador("Ana",3000,10062024);
    empleados[2] = new Disenador("Luis", 20, 10062024);

    for (int i = 0; i < 3; i++) {
        departamento.agregarEmpleado(empleados[i]);
    }

    departamento.listarEmpleados();

    departamento.buscarEmpleado("Ana")->mostrarDatos();

    departamento.eliminarEmpleado(1);

    return 0;
}