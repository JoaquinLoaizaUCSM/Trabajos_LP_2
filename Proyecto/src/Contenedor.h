#ifndef TRABAJOS_LP_2_CONTENEDOR_H
#define TRABAJOS_LP_2_CONTENEDOR_H
#include "Empleados/Empleado.h"
#include "Empleados/Gerente.h"
#include "Empleados/Desarrollador.h"
#include "Empleados/Disenador.h"
#include "Empleados/Tester.h"
#include "GestorArchivos.h"
#include "Departamento.h"

GestorArchivos gestorArchivos;

Departamento<Empleado> crearDepartamentoDesarrollo() {
    Departamento<Empleado> departamento("Desarrollo", gestorArchivos);
    departamento.agregarEmpleado(new Gerente("Alice", 5000, 2, "desarrollo", 1000));
    departamento.agregarEmpleado(new Desarrollador("Bob", 3000, 3, "C++", 2));
    departamento.agregarEmpleado(new Disenador("Charlie", 3500, 2, "Photoshop", 1));
    departamento.agregarEmpleado(new Tester("David", 4000, 2, "Windows", 2));
    return departamento;
}

Departamento<Empleado> crearDepartamentoServicios() {
    Departamento<Empleado> departamento("Servicios", gestorArchivos);
    departamento.agregarEmpleado(new Gerente("Joaquin", 5000, 2, "servicios", 3000));
    departamento.agregarEmpleado(new Desarrollador("Grossman", 3000, 3, "Java", 20));
    departamento.agregarEmpleado(new Disenador("Salvador", 3500, 2, "Illustrator", 2));
    departamento.agregarEmpleado(new Tester("Yhosfer", 4000, 2, "Linux", 3));
    return departamento;
}

Departamento<Empleado> marketing = crearDepartamentoDesarrollo();
Departamento<Empleado> ventas = crearDepartamentoServicios();

#endif // CONTENEDOR_H

