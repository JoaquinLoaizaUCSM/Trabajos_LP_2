#ifndef TRABAJOS_LP_2UTILIDADES_H
#define TRABAJOS_LP_2UTILIDADES_H

#include <fstream>
#include <stdexcept>
#include <map>

#include "Empleados/Empleado.h"
#include "Empleados/Gerente.h"
#include "Empleados/Desarrollador.h"
#include "Empleados/Disenador.h"
#include "Empleados/Tester.h"


using namespace std;

class EmpleadoFactory {
public:
    static Empleado* crearEmpleado(const string& tipo) {
        if (tipo == typeid(Gerente).name()) {
            return new Gerente("", 0, 0);
        } else if (tipo == typeid(Desarrollador).name()) {
            return new Desarrollador("", 0, 0);
        } else if (tipo == typeid(Disenador).name()) {
            return new Disenador("", 0, 0);
        } else if (tipo == typeid(Tester).name()){
            return new Tester("", 0, 0);
        }
        return nullptr;
    }
};

class GestorArchivos {
public:

    static void guardar(const string& archivo, const map<int, Empleado*>& empleados) {
        try {
            ofstream ofs(archivo);
            if (!ofs) {
                throw runtime_error("Error al abrir el archivo para guardar");
            }
            for (pair<int,Empleado*> empleado : empleados) {
                ofs << empleado.first << " " << typeid(*empleado.second).name() << " " << empleado.second->serializar() << endl;
            }
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }
    }


    static void cargar(const string& archivo, map<int, Empleado*>& empleados) {

        try {
            ifstream ifs(archivo);
            if (!ifs) {
                throw runtime_error("Error al abrir el archivo para cargar");
            }
            int id;
            string tipo, data;
            while (ifs >> id >> tipo) {
                ifs.ignore(); // Ignorar el espacio después del programa
                getline(ifs, data);
                Empleado* empleado = EmpleadoFactory::crearEmpleado(tipo);
                if (empleado) {
                    empleado->deserializar(data);
                    empleados[id] = empleado;
                }
            }

            cout << "Cargado con exito" << endl;
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }
    }
};

#endif // TRABAJOS_LP_2UTILIDADES_H

