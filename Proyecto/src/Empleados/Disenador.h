#ifndef TRABAJOS_LP_2_DISENADOR_H
#define TRABAJOS_LP_2_DISENADOR_H

#include <utility>

#include "Empleado.h"

class Disenador : public Empleado{

private:
    string programa;
    int proyectos;

public:
    explicit Disenador(string nombre = "", double salario = 0, int fechaContratacion = 0, string programa = "", int proyectos = 0)
            : Empleado(std::move(nombre), salario, fechaContratacion){
        this->programa = std::move(programa);
        this->proyectos = proyectos;
    }

    string serializar() const override {
        ostringstream oss;
        oss << nombre << " " << salario << " " << fechaContratacion << " " << programa << " " << proyectos;
        return oss.str();
    }

    void deserializar(const string& data) override {
        istringstream iss(data);
        iss >> nombre >> salario >> fechaContratacion >> programa >> proyectos;
    }

    double calcularSalario() override {
        return salario + (proyectos * 100);
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Tipo: " << programa << endl;
        cout << "Proyectos: " << proyectos << endl;
    }

    void ingresarDatos() override {
        cout << "Ingreso de datos de nuebo Disenador" << endl;
        cout << "   Nombre: ";
        cin >> nombre;
        cout << "   Salario: ";
        cin >> salario;
        cout << "   Fecha de contratacion: ";
        cin >> fechaContratacion;
        cout << "   Tipo de diseñador: ";
        cin >> programa;
    }

    const string &getTipo() const {
        return programa;
    }

    void setTipo(const string &tipo) {
        Disenador::programa = tipo;
    }

    int getProyectos() const {
        return proyectos;
    }

    void setProyectos(int proyectos) {
        Disenador::proyectos = proyectos;
    }
};


#endif //TRABAJOS_LP_2_DISENADOR_H
