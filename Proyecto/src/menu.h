#ifndef TRABAJOS_LP_2_MENU_H
#define TRABAJOS_LP_2_MENU_H

#include <iostream>
#include "Empresa.h"
#include "Contenedor.h"   // Es un archivo que contiene los datos de los empleados

class Menu {
private:
    Empresa<Departamento<Empleado>> empresa;

public:
    Menu();
    void mostrarMenuPrincipal();
    void mostrarMenuDepartamentos();
    void crearDepartamento();
    static void crearEmpleado(Departamento<Empleado>* departamento);
    void listarDepartamentos();
    static void listarEmpleados(Departamento<Empleado>* departamento);
    static void editarEmpleado(Departamento<Empleado>* departamento);
    static void eliminarEmpleado(Departamento<Empleado>* departamento);
    static void buscarEmpleado(Departamento<Empleado>* departamento);
    static void guardarDatos(Departamento<Empleado>* departamento);
    static void cargarDatos(Departamento<Empleado>* departamento);
    void generarReporte();
};

Menu::Menu() : empresa("TechCorp", &marketing) {}

void Menu::mostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "1. Crear Departamento" << endl;
        cout << "2. Listar Departamentos" << endl;
        cout << "3. Generar Reporte" << endl;
        cout << "4. Configurar Departamento" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion:";
        cin >> opcion;
        cin.ignore(); // Ignorar nueva línea

        switch (opcion) {
            case 1:
                crearDepartamento();
                break;
            case 2:
                listarDepartamentos();
                break;
            case 3:
                generarReporte();
                break;
            case 4:
                mostrarMenuDepartamentos();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
}

void Menu::mostrarMenuDepartamentos() {
    int opcion;
    Departamento<Empleado>* departamento = nullptr;
    listarDepartamentos();
    cout << "Ingrese el nombre del departamento:";
    string nombreDepto;
    getline(cin, nombreDepto);

    for (auto depto : empresa.getDepartamentos()) {
        if (depto->getNombre() == nombreDepto) {
            departamento = depto;
            break;
        }
    }

    if (departamento == nullptr) {
        cout << "Departamento no encontrado." << endl;
        mostrarMenuPrincipal();
    }

    do {
        cout << "1. Crear Empleado" << endl;
        cout << "2. Listar Empleados" << endl;
        cout << "3. Editar Empleado" << endl;
        cout << "4. Eliminar Empleado" << endl;
        cout << "5. Buscar Empleado" << endl;
        cout << "6. Guardar Datos" << endl;
        cout << "7. Cargar Datos" << endl;
        cout << "8. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion:";
        cin >> opcion;
        cin.ignore(); // Ignorar nueva línea

        switch (opcion) {
            case 1:
                crearEmpleado(departamento);
                break;
            case 2:
                listarEmpleados(departamento);
                break;
            case 3:
                editarEmpleado(departamento);
                break;
            case 4:
                eliminarEmpleado(departamento);
                break;
            case 5:
                buscarEmpleado(departamento);
                break;
            case 6:
                guardarDatos(departamento);
                break;
            case 7:
                cargarDatos(departamento);
                break;
            case 8:
                mostrarMenuPrincipal();
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 9);
}

void Menu::crearDepartamento() {
    string nombre;
    cout << "Ingrese el nombre del departamento:";
    getline(cin, nombre);
    GestorArchivos archivos;
    vector<Empleado*> empleados;
    auto* departamento = new Departamento<Empleado>(nombre, archivos);
    empresa.agregarDepartamento(departamento);
    cout << "Departamento creado correctamente." << endl;
}

void Menu::crearEmpleado(Departamento<Empleado>* departamento) {
    string nombre, puesto;
    cout << "Ingrese el nombre del empleado:";
    getline(cin, nombre);
    cin.ignore(); // Ignorar nueva línea
    cout << "Ingrese el salario del empleado:";
    double salario;
    cin >> salario;
    cout << "Ingrese la fecha de contratacion (AAAA): ";
    int fechaContratacion;
    cin >> fechaContratacion;
    cin.ignore(); // Ignorar nueva línea

    cout << "Puestos disponibles: Desarrollador, Disenador, Gerente, Tester" << endl;
    cout << "Ingrese el puesto del empleado: ";
    getline(cin, puesto);

    Empleado *empleado = nullptr;

    if (puesto == "Desarrollador") {
        string experiencia;
        cout << "Ingrese la lenguaje de programacion:";
        cin >> experiencia;
        cin.ignore(); // Ignorar nueva línea
        Empleado* empleado = new Desarrollador(nombre, salario, fechaContratacion, experiencia);
    } else if (puesto == "Disenador") {
        string herramienta;
        cout << "Ingrese la herramienta:";
        getline(cin, herramienta);

        Empleado* empleado = new Disenador(nombre, salario, fechaContratacion, herramienta);
    } else if (puesto == "Gerente") {
        int numEmpleados;
        cout << "Ingrese el número de empleados a cargo:";
        cin >> numEmpleados;
        cin.ignore(); // Ignorar nueva línea
        Empleado* empleado = new Gerente(nombre, numEmpleados);
    } else if (puesto == "Tester") {
        string especialidad;
        cout << "Ingrese la sistema operativo:";
        getline(cin, especialidad);
        Empleado* empleado = new Tester(nombre, salario, fechaContratacion, especialidad);
    } else {
        cout << "Puesto no válido." << endl;
        return;
    }

    departamento->agregarEmpleado(empleado);
    cout << "Empleado creado correctamente." << endl;
}

void Menu::listarDepartamentos() {
    cout << "Lista de Departamentos:" << endl;
    for (const auto& departamento : empresa.getDepartamentos()) {
        cout << " - " << departamento->getNombre() << endl;
    }
}

void Menu::listarEmpleados(Departamento<Empleado>* departamento) {
    cout << "Lista de Empleados del Departamento " << departamento->getNombre() << ":" << endl;
    Reportes<Departamento<Empleado>>::mostrarEmpleadosDelDepartamento(departamento);
}

void Menu::editarEmpleado(Departamento<Empleado>* departamento) {
    string nombre, nuevoNombre;
    int id;

    cout << "Ingrese el id del empleado a editar:";
    cin >> id;
    cin.ignore(); // Ignorar nueva línea

    double nuevoSalario;
    cout << "Ingrese el nuevo salario:";
    cin >> nuevoSalario;

    try {
        departamento->editarEmpleado(id, nombre, nuevoSalario);
        cout << "Empleado editado correctamente." << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
}

void Menu::eliminarEmpleado(Departamento<Empleado>* departamento) {
    int id;
    cout << "Ingrese el id del empleado a eliminar:";
    cin >> id;

    try {
        departamento->eliminarEmpleado(id);
        cout << "Empleado eliminado correctamente." << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
}

void Menu::buscarEmpleado(Departamento<Empleado>* departamento) {
    int id;
    cout << "Ingrese el nombre del empleado a buscar:";
    cin >> id;

    try {
        Empleado* empleado = departamento->buscarEmpleado(id);
        cout << "Empleado encontrado:" << endl;
        empleado->mostrarDatos();
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
}

void Menu::guardarDatos(Departamento<Empleado>* departamento) {
    departamento->guardarEmpleados();
}

void Menu::cargarDatos(Departamento<Empleado>* departamento) {
    departamento->cargarEmpleados();
}

void Menu::generarReporte() {
    Reportes<Empresa<Departamento<Empleado>>>::generarReporte(empresa);
}

#endif //TRABAJOS_LP_2_MENU_H
