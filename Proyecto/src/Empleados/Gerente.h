#ifndef TRABAJOS_LP_2_GERENTE_H
#define TRABAJOS_LP_2_GERENTE_H

#include "Empleado.h"

class Gerente : public Empleado{
private:
    string departamento;
    double bono;

public:
    explicit Gerente(string nombre = "", double salario = 0, int fechaContratacion = 0, string departamento = "",
                     double bono = 0.0) :
            Empleado(std::move(nombre), salario, fechaContratacion){
        this->departamento = std::move(departamento);
        this->bono = bono;
    }

    string serializar() const override {
        ostringstream oss;
        oss << nombre << " " << salario << " " << departamento << " " <<fechaContratacion << " " << bono;
        return oss.str();
    }

    void deserializar(const string& data) override {
        istringstream iss(data);
        iss >> nombre >> salario >> departamento >> fechaContratacion>> bono;
    }

    double calcularSalario() override{
        return salario + bono;
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Bono: " << bono << endl;
    }

    void ingresarDatos() override {
        cout << "Ingreso de datos de Gerente" << endl;
        cout << "   Nombre: "; cin >> nombre;
        cout << "   Salario: "; cin >> salario;
        cout << "   Fecha de contratacion: "; cin >> fechaContratacion;
        cout << "   Departamento: "; cin >> departamento;
        cout << "   Bono: "; cin >> bono;
    }

    const string &getDepartamento() const {
        return departamento;
    }

    void setDepartamento(const string &departamento) {
        Gerente::departamento = departamento;
    }

    double getBono() const {
        return bono;
    }

    void setBono(double bono) {
        Gerente::bono = bono;
    }
};

#endif //TRABAJOS_LP_2_GERENTE_H
