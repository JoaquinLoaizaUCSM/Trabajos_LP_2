#ifndef TRABAJOS_LP_2_EMPLEADO_H
#define TRABAJOS_LP_2_EMPLEADO_H

#include <iostream>
#include <sstream>  // Es necesario para usar ostringstream
#include <utility>

using namespace std;

class Empleado{
protected:
    string nombre;
    double salario;
    int fechaContratacion;

public:
    Empleado(string nombre, double salario, int fechaContratacion){
        this -> nombre = std::move(nombre);
        this -> salario = salario;
        this -> fechaContratacion = fechaContratacion;
    }

    virtual double calcularSalario() = 0;
    virtual void mostrarDatos() = 0;
    virtual void ingresarDatos() = 0;
    virtual string serializar() const = 0;
    virtual void deserializar(const string& data) = 0;

    string getNombre()  {
        return nombre;
    }

    void setNombre(string nombre) {
        Empleado::nombre = std::move(nombre);
    }

    double getSalario() const {
        return salario;
    }

    void setSalario(double salario) {
        Empleado::salario = salario;
    }

     int getFechaContratacion() const {
        return fechaContratacion;
    }

    void setFechaContratacion(const int &fechaContratacion) {
        Empleado::fechaContratacion = fechaContratacion;
    }
};



#endif //TRABAJOS_LP_2_EMPLEADO_H
