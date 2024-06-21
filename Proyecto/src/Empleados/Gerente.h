#ifndef TRABAJOS_LP_2_GERENTE_H
#define TRABAJOS_LP_2_GERENTE_H

#include "Empleado.h"

class Gerente : public Empleado{
private:
    int  numEmpleados;
    double bono;

public:
    explicit Gerente(string nombre = "", double salario = 0, int fechaContratacion = 0, int numEmpleados =0,
                     double bono = 0.0) :
            Empleado(std::move(nombre), salario, fechaContratacion){
        this->numEmpleados = numEmpleados;
        this->bono = bono;
    }

    string serializar() const override {
        ostringstream oss;
        oss << nombre << " " << salario << " " << numEmpleados << " " <<fechaContratacion << " " << bono;
        return oss.str();
    }

    void deserializar(const string& data) override {
        istringstream iss(data);
        iss >> nombre >> salario >> numEmpleados >> fechaContratacion>> bono;
    }

    double calcularSalario() override{
        return salario + bono;
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Numero de empleados: " << numEmpleados << endl;
        cout << "Bono: " << bono << endl;
    }

    void ingresarDatos() override {
        cout << "Ingreso de datos de Gerente" << endl;
        cout << "   Nombre: "; cin >> nombre;
        cout << "   Salario: "; cin >> salario;
        cout << "   Fecha de contratacion: "; cin >> fechaContratacion;
        cout << "   Departamento: "; cin >> numEmpleados;
        cout << "   Bono: "; cin >> bono;
    }

    int getNumEmpleados() const {
        return numEmpleados;
    }

    void setNumEmpleados(int numEmpleados) {
        Gerente::numEmpleados = numEmpleados;
    }

    double getBono() const {
        return bono;
    }

    void setBono(double bono) {
        Gerente::bono = bono;
    }
};

#endif //TRABAJOS_LP_2_GERENTE_H
