#include <iostream>
#include <vector>
#include <algorithm>
#include "clases/Departamento.h"
#include "clases/Empleado.h"


using namespace std;


int main() {

    Departamento<Empleado> sony;

    auto gerente = new Gerente("Alice", 5000,2, "departemente");
    auto desarrollador = new Desarrollador("Bob", 3000, 3);
    auto disenador = new Disenador("Charlie", 3500, 2);

    sony.agregarEmpleado(gerente);
    sony.agregarEmpleado(desarrollador);
    sony.agregarEmpleado(disenador);

    cout << "Lista de empleados antes de ordenar:" << endl;
    sony.listarEmpleados();

    // Ordenar empleados por nombre
    sony.ordenarEmpleados([](Empleado* a, Empleado* b) {
        return a->getNombre() < b->getNombre();
    });

    cout << endl;

    cout << "Lista de empleados despues de ordenar:" << endl;
    sony.listarEmpleados();

    sony.guardar("empleados.txt");


    Departamento<Empleado> nuevoDepartamento;
    nuevoDepartamento.cargar("empleados.txt");

    cout << "Lista de empleados cargados:" << endl;
    nuevoDepartamento.listarEmpleados();

    return 0;
}
