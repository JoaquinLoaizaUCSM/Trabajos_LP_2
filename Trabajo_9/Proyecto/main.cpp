#include <iostream>

using namespace std;

class Empleados{
protected:
    string nombre;
    double salario;
    string fechaContratacion;

public:
    Empleados(string nombre, double salario, int fechaContratacion){
        this -> nombre = nombre;
        this -> salario = salario;
        this -> fechaContratacion = fechaContratacion;
    }

    virtual double calcularSalario() = 0;
    virtual void mostrarDatos() = 0;
    virtual void ingresarDatos() = 0;
};

class Gerente : public Empleados{
private:
    string departamento;
    double bono;

public:
    Gerente(string nombre = "", double salario = 0, int fechaContratacion = 0, string departamento = "", double bono = 0) :
            Empleados(nombre, salario, fechaContratacion){
        this->departamento = departamento;
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
};



class Desarrollador : public Empleados{

private:
    string lenguaje;
    int horasExtra;

public:
    Desarrollador(string nombre = "", double salario = 0, int fechaContratacion = 0, string lenguaje = "", int horasExtra = 0) :
            Empleados(nombre, salario, fechaContratacion){
        this->lenguaje = lenguaje;
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
};



class Diseñador : public Empleados{

private:
    string tipo;
    int proyectos;

public:
    Diseñador(string nombre = "", double salario = 0, int fechaContratacion = 0, string tipo = "", int proyectos = 0)
            : Empleados(nombre, salario, fechaContratacion){
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
        cout << "Ingreso de datos de nuebo Diseñador" << endl;
        cout << "   Nombre: ";
        cin >> nombre;
        cout << "   Salario: ";
        cin >> salario;
        cout << "   Fecha de contratacion: ";
        cin >> fechaContratacion;
        cout << "   Tipo de diseñador: ";
        cin >> tipo;
    }
};

class Tester : public Empleados{

private:
    string tipo;
    int bugs;

public:
    Tester(string nombre = "", double salario = 0, int fechaContratacion = 0, string tipo = "", int bugs = 0)
            : Empleados(nombre, salario, fechaContratacion){
        this->tipo = tipo;
        this->bugs = bugs;
    }

    double calcularSalario() override {
        return salario + (bugs * 10);
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Fecha de contratacion: " << fechaContratacion << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Bugs: " << bugs << endl;
    }

    void ingresarDatos() override {
        cout << "Ingreso de datos de Tester" << endl;
        cout << "   Nombre: "; cin >> nombre;
        cout << "   Salario: "; cin >> salario;
        cout << "   Fecha de contratacion: "; cin >> fechaContratacion;
        cout << "   Tipo : "; cin >> tipo;
        cout << "   Total de bugs: "; cin >> bugs;

    }
};

void mostrarSalarios(Empleados *empleados[], int n){
    for(int i = 0; i < n; i++){
        cout << "Salario: " << empleados[i]->calcularSalario() << endl;
    }
}

void mostrarEspecificaciones(Empleados *empleados[], int n){
    for(int i = 0; i < n; i++){
        empleados[i]->mostrarDatos();
    }
}


int main()
{

    Empleados *empleados[6];
    empleados[0] = new Gerente();
    empleados[0]->ingresarDatos();

    empleados[1] = new Desarrollador();
    empleados[1]->ingresarDatos();
    empleados[2] = new Desarrollador();
    empleados[2]->ingresarDatos();

    empleados[3] = new Diseñador();
    empleados[3]->ingresarDatos();
    empleados[4] = new Diseñador();
    empleados[4]->ingresarDatos();


    empleados[5] = new Tester();
    empleados[5]->ingresarDatos();

    mostrarEspecificaciones(empleados,6);
    mostrarSalarios(empleados, 6);


    return 0;

}