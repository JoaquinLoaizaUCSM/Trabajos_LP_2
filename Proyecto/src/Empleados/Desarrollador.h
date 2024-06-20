#ifndef TRABAJOS_LP_2_DESARROLLADOR_H
#define TRABAJOS_LP_2_DESARROLLADOR_H


#include "Empleado.h"

class Desarrollador : public Empleado{

private:
    string lenguaje;
    int horasExtra;

public:
    explicit Desarrollador(string nombre = "", double salario = 0, int fechaContratacion = 0, string lenguaje = "", int horasExtra = 0) :
            Empleado(std::move(nombre), salario, fechaContratacion){
        this->lenguaje = std::move(lenguaje);
        this->horasExtra = horasExtra;
    }

    string serializar() const override {
        ostringstream oss;
        oss << nombre << " " << salario << " " << fechaContratacion << " " << lenguaje << " " << horasExtra;
        return oss.str();
    }

    void deserializar(const string& data) override {
        istringstream iss(data);
        iss >> nombre >> salario >> fechaContratacion >> lenguaje >> horasExtra;
    }

    double calcularSalario() override {
        return salario + (horasExtra * 50);
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Lenguaje: " << lenguaje << endl;
        cout << "Horas extra: " << horasExtra << endl;
    }
    void ingresarDatos() override {
        cout << "Ingreso de datos de Desarrollador" << endl;
        cout << "   Nombre: ";
        cin >> nombre;
        cout << "   Salario: ";
        cin >> salario;
        cout << "   Fecha de contratacion: ";
        cin >> fechaContratacion;
        cout << "   Lenguaje:  ";
        cin >> lenguaje;
        cout << "   horasExtra:  ";
        cin >> horasExtra;
    }

    const string &getLenguaje() const {
        return lenguaje;
    }

    void setLenguaje(const string &lenguaje) {
        Desarrollador::lenguaje = lenguaje;
    }

    int getHorasExtra() const {
        return horasExtra;
    }

    void setHorasExtra(int extra) {
        Desarrollador::horasExtra = extra;
    }
};


#endif //TRABAJOS_LP_2_DESARROLLADOR_H
