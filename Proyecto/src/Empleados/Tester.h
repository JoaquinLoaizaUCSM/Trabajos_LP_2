#ifndef TRABAJOS_LP_2_TESTER_H
#define TRABAJOS_LP_2_TESTER_H

#include "Empleado.h"

class Tester : public Empleado{

private:
    int bugs;
    string system;

public:
    explicit Tester(string nombre = "", double salario = 0, int fechaContratacion = 0, string system = "", int bugs = 0)
            : Empleado(std::move(nombre), salario, fechaContratacion){
        this->system = std::move(system);
        this->bugs = bugs;
    }

    [[nodiscard]] string serializar() const override {
        ostringstream oss;
        oss << nombre << " " << salario << " " << fechaContratacion << " " << system << " "<< bugs;
        return oss.str();
    }

    void deserializar(const string& data) override {
        istringstream iss(data);
        iss >> nombre >> salario >> fechaContratacion >> system >> bugs;
    }

    double calcularSalario() override {
        return salario + (bugs * 10);
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Bugs: " << bugs << endl;
    }

    void ingresarDatos() override {
        cout << "Ingreso de datos de Tester" << endl;
        cout << "   Nombre: "; cin >> nombre;
        cout << "   Salario: "; cin >> salario;
        cout << "   Fecha de contratacion: "; cin >> fechaContratacion;
        cout << "   Total de bugs: "; cin >> bugs;

    }

    [[nodiscard]] int getBugs() const {
        return bugs;
    }

    void setBugs(int bugs) {
        Tester::bugs = bugs;
    }
};

#endif //TRABAJOS_LP_2_TESTER_H
