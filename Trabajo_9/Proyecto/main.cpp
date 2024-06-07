#include <iostream>

using namespace std;

class Empleados{
protected:
    string nombre;
    double salario;
    int fechaContratacion;
public:
    Empleados(string nombre, double salario, int fechaContratacion){
        this->nombre = nombre;
        this->salario = salario;
        this->fechaContratacion = fechaContratacion;
    }

    virtual double calcularSalario() = 0;
    virtual void mostrarDatos() = 0;
};

class Gerente : public Empleados{
private:
    string departamento;
    double bono;

public:
    Gerente(string nombre, double salario, int fechaContratacion, string departamento, double bono) :
    Empleados(nombre, salario, fechaContratacion){
        this->departamento = departamento;
        this->bono = bono;
    }

    double calcularSalario(){
        return salario + bono;
    }

    void mostrarDatos(){
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Bono: " << bono << endl;
    }

};

class Desarrollador : public Empleados{

private:
    string lenguaje;
    int horasExtra;

public:
    Desarrollador(string nombre, double salario, int fechaContratacion, string lenguaje, int horasExtra) :
    Empleados(nombre, salario, fechaContratacion){
        this->lenguaje = lenguaje;
        this->horasExtra = horasExtra;
    }

    double calcularSalario(){
        return salario + (horasExtra * 50);
    }

    void mostrarDatos(){
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Lenguaje: " << lenguaje << endl;
        cout << "Horas extra: " << horasExtra << endl;
    }
};

class Diseñador : public Empleados{

private:
    string tipo;
    int proyectos;

public:
    Diseñador(string nombre, double salario, int fechaContratacion, string tipo, int proyectos)
    : Empleados(nombre, salario, fechaContratacion){
        this->tipo = tipo;
        this->proyectos = proyectos;
    }

    double calcularSalario(){
        return salario + (proyectos * 100);
    }

    void mostrarDatos(){
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Proyectos: " << proyectos << endl;
    }
};

class Tester : public Empleados{

private:
    string tipo;
    int bugs;

public:
    Tester(string nombre, double salario, int fechaContratacion, string tipo, int bugs)
    : Empleados(nombre, salario, fechaContratacion){
        this->tipo = tipo;
        this->bugs = bugs;
    }

    double calcularSalario(){
        return salario + (bugs * 10);
    }

    void mostrarDatos(){
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Bugs: " << bugs << endl;
    }
};

void mostrarSalarios(Empleados *empleados[], int n){
    for(int i = 0; i < n; i++){
        cout << "Salario: " << empleados[i]->calcularSalario() << endl;
    }
}

int main()
{
    Empleados *empleados[4];
    empleados[0] = new Gerente("Juan", 1000, 2020, "Sistemas", 500);
    empleados[1] = new Desarrollador("Pedro", 800, 2021, "Java", 10);
    empleados[2] = new Diseñador("Maria", 700, 2022, "Web", 1);
    empleados[3] = new Tester("Luis", 600, 2023, "Unitess", 20);

    mostrarSalarios(empleados, 4);

    return 0;

}