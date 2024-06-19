#ifndef TRABAJOS_LP_2_EMPLEADO_H
#define TRABAJOS_LP_2_EMPLEADO_H

#include <iostream>

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

    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        Empleado::nombre = nombre;
    }

    double getSalario() const {
        return salario;
    }

    void setSalario(double salario) {
        Empleado::salario = salario;
    }

    const int &getFechaContratacion() const {
        return fechaContratacion;
    }

    void setFechaContratacion(const int &fechaContratacion) {
        Empleado::fechaContratacion = fechaContratacion;
    }
};

class Gerente : public Empleado{
private:
    string departamento;
    double bono;

public:
    explicit Gerente(string nombre = "", double salario = 0, int fechaContratacion = 0, string departamento = "", double bono = 0) :
            Empleado(std::move(nombre), salario, fechaContratacion){
        this->departamento = std::move(departamento);
        this->bono = bono;
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



class Disenador : public Empleado{

private:
    string tipo;
    int proyectos;

public:
    explicit Disenador(string nombre = "", double salario = 0, int fechaContratacion = 0, string tipo = "", int proyectos = 0)
            : Empleado(nombre, salario, fechaContratacion){
        this->tipo = tipo;
        this->proyectos = proyectos;
    }

    double calcularSalario() override {
        return salario + (proyectos * 100);
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Tipo: " << tipo << endl;
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
        cin >> tipo;
    }

    const string &getTipo() const {
        return tipo;
    }

    void setTipo(const string &tipo) {
        Disenador::tipo = tipo;
    }

    int getProyectos() const {
        return proyectos;
    }

    void setProyectos(int proyectos) {
        Disenador::proyectos = proyectos;
    }
};

class Tester : public Empleado{

private:
    int bugs;

public:
    explicit Tester(string nombre = "", double salario = 0, int fechaContratacion = 0, string tipo = "", int bugs = 0)
            : Empleado(std::move(nombre), salario, fechaContratacion){
        this->bugs = bugs;
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

    int getBugs() const {
        return bugs;
    }

    void setBugs(int bugs) {
        Tester::bugs = bugs;
    }
};

#endif //TRABAJOS_LP_2_EMPLEADO_H
