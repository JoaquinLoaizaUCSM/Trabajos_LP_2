#include "src/Departamento.h"
#include "src/Empleados/Contenedor.h"   // Es un archivo que contiene los datos de los empleados
using namespace std;
int main() {

    GestorArchivos gestorArchivos;
    Departamento<Empleado> sony = Departamento(empleados1, gestorArchivos);
    Departamento<Empleado> samsung = Departamento(empleados2, gestorArchivos);

    cout << "Lista de empleados" << endl;
    sony.listarEmpleados();
    sony.guardar("empleados.txt");

    cout << "Lista de empleados antes de cargar:" << endl;
    samsung.listarEmpleados();

    cout << "Lista de empleados despues de cargar:" << endl;
    samsung.cargar("empleados.txt");
    samsung.listarEmpleados();

    samsung.buscarEmpleado("Alice")->mostrarDatos();


    return 0;
}