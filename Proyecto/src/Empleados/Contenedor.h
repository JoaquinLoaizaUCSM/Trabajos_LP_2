#ifndef TRABAJOS_LP_2_CONTENEDOR_H
#define TRABAJOS_LP_2_CONTENEDOR_H
#include "Empleado.h"
#include <vector>

// Primer modulo de empleados
Empleado* gerente = new Gerente("Alice", 5000,2, "desarrollo", 1000);
Empleado* desarrollador = new Desarrollador("Bob", 3000, 3,"C++", 2);
Empleado* disenador = new Disenador("Charlie", 3500, 2, "Photoshop", 1);
Empleado* tester = new Tester("David", 4000, 2, "Windows", 2);

vector<Empleado*> empleados1 = {gerente, desarrollador, disenador, tester};


// Segundo modulo de empleados

Empleado* gerente2 = new Gerente("Joaquin", 5000,2, "servicios", 3000);
Empleado* desarrollador2 = new Desarrollador("Grossman", 3000, 3,"Java", 20);
Empleado* disenador2 = new Disenador("Salvador", 3500, 2, "Illustrator", 2);
Empleado* tester2 = new Tester("Yhosfer", 4000, 2, "Linux", 3);

vector<Empleado*> empleados2 = {gerente2, desarrollador2, disenador2, tester2};


#endif //TRABAJOS_LP_2_CONTENEDOR_H
