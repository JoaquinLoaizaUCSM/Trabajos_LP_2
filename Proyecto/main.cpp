#include <iostream>

using namespace std;

#include <vector>

class Empleados{
protected:
    string nombre;
    double salario;
    string fechaContratacion;

public:
    Empleados(string nombre, double salario, string fechaContratacion){
        this -> nombre = nombre;
        this -> salario = salario;
        this -> fechaContratacion = fechaContratacion;
    }

    string get_nombre(){
        return this->nombre;
    }

    virtual double calcularSalario() = 0;
    virtual void mostrarDatos() = 0;
    virtual void ingresarDatos() = 0;

};




class Gerente : public Empleados{
private:
    //En ejemplos de plaza se pueden colocar las de profesional, tecnico, etc
    //en este caso serían por rangos: P1, P2, T1, T3
    string plaza;
    double bono;

public:
    Gerente(string nombre = "", double salario = 0, string fechaContratacion = "", string p = "", double bono = 0) :
    Empleados(nombre, salario, fechaContratacion){
        this->plaza = p;
        this->bono = bono;
    }

    double calcularSalario() override{
        return salario + bono;
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;

        cout << "Salario base: " << salario << endl;

        cout << "Fecha de contratacion: " << fechaContratacion << endl;

        cout << "Plaza: " << plaza << endl;

        cout << "Bono: " << bono << endl;
    }

    void ingresarDatos() override {
        cout << "Ingreso de datos de Gerente" << endl;

        cout << "   Nombre: ";
        cin >> nombre;

        cout << "   Salario base: ";
        cin >> salario;

        cout << "   Fecha de contratacion: ";
        cin >> fechaContratacion;

        cout << "   Plaza: ";
        cin >> plaza;

        cout << "   Bono: ";
        cin >> bono;
    }
};




class Desarrollador : public Empleados{

private:
    string lenguaje;
    int horasExtra;

public:
    Desarrollador(string nombre = "", double salario = 0, string fechaContratacion = "", string lenguaje = "", int horasExtra = 0) :
    Empleados(nombre, salario, fechaContratacion){
        this->lenguaje = lenguaje;
        this->horasExtra = horasExtra;
    }

    double calcularSalario() override {
        return salario + (horasExtra * 50);
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;

        cout << "Salario base: " << salario << endl;

        cout << "Fecha de contratacion: " << fechaContratacion << endl;

        cout << "Lenguaje: " << lenguaje << endl;

        cout << "Horas extra: " << horasExtra << endl;
    }

    void ingresarDatos() override {
        cout << "Ingreso de datos de Desarrollador" << endl;

        cout << "   Nombre: ";
        cin >> nombre;

        cout << "   Salario base: ";
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
    Diseñador(string nombre = "", double salario = 0, string fechaContratacion = "", string tipo = "", int proyectos = 0):
    Empleados(nombre, salario, fechaContratacion){
        this->tipo = tipo;
        this->proyectos = proyectos;
    }

    double calcularSalario() override {
        return salario + (proyectos * 100);
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;

        cout << "Salario base: " << salario << endl;

        cout << "Fecha de contratacion: " << fechaContratacion << endl;

        cout << "Tipo: " << tipo << endl;

        cout << "Proyectos: " << proyectos << endl;
    }

    void ingresarDatos() override {
        cout << "Ingreso de datos de nuebo Diseñador" << endl;

        cout << "   Nombre: ";
        cin >> nombre;

        cout << "   Salario base: ";
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
    Tester(string nombre = "", double salario = 0, string fechaContratacion = "", string tipo = "", int bugs = 0):
    Empleados(nombre, salario, fechaContratacion){
        this->tipo = tipo;
        this->bugs = bugs;
    }

    double calcularSalario() override {
        return salario + (bugs * 10);
    }

    void mostrarDatos() override {
        cout << "Nombre: " << nombre << endl;

        cout << "Salario base: " << salario << endl;

        cout << "Fecha de contratacion: " << fechaContratacion << endl;

        cout << "Tipo: " << tipo << endl;

        cout << "Bugs: " << bugs << endl;
    }

    void ingresarDatos() override {
        cout << "Ingreso de datos de Tester" << endl;

        cout << "   Nombre: ";
        cin >> nombre;

        cout << "   Salario base: ";
        cin >> salario;

        cout << "   Fecha de contratacion: ";
        cin >> fechaContratacion;

        cout << "   Tipo : ";
        cin >> tipo;

        cout << "   Total de bugs: ";
        cin >> bugs;
    }
};




template <typename T>

class Departamento{

//Lo que se hace en este caso es la creación de un vector de punteros de la clase
//base Empleados con el fin de que pueda almacenar cualquier tipo de objetos
//de clases derivadas para posteriormente y usando la plantilla agregarlos.

protected:
    vector<Empleados*> empleados;
    string nombre_dep;

public:
    Departamento(string n){
        this -> nombre_dep = n;
    }

    void agregar_empleado(T *empleado){
        cout << "Se agrego efectivamente el empleado." << endl;
        empleados.push_back(empleado);
    }

    void eliminar_empleado(string nombre) {

        for (int i = 0; i < empleados.size(); i++) {

            if (empleados[i]->get_nombre() == nombre) {

                empleados.erase(empleados.begin() + i);
                cout << "Empleado " << nombre << " eliminado." << endl;
                return; //Solo se usa este return para romper el bucle, no devuelve nada

            }
        }
        cout << "Empleado " << nombre << " no encontrado." << endl;
    }

    //Practicamente hago lo mismo que en el de eliminar pero buscando
    void buscar_empleado(string nombre) {

        for (int i = 0; i < empleados.size(); i++) {

            if (empleados[i]->get_nombre() == nombre) {

                empleados[i]->mostrarDatos();
                return; //Solo se usa este return para romper el bucle, no devuelve nada

            }
        }
        cout << "Empleado " << nombre << " no encontrado." << endl;
    }

    void mostrarDatos(){
        cout << "\n" ;

        cout << "Datos de los empleados del departamento de " << this -> nombre_dep << ": " << endl;

        for(Empleados* empleado : empleados){

            cout << "\n";
            empleado->mostrarDatos();
            cout << "Salario Final: " << empleado->calcularSalario() << endl;

        }
    }

};




/*Funciones extra prueba semana 1
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
*/




int main()
{
    /*

    Prueba semana 1
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

    */




    //Prueba semana 2
    //Agregamiento y enlistamiento
    Departamento <Empleados> Finanzas("Finanzas");

    Empleados *P1;
    P1 = new Gerente(       "Grossman",
                            2000,
                            "29/12/2022",
                            "Profesional 1",
                            500);

    Empleados *P2;
    P2 = new Desarrollador( "Yhosfer",
                            1050,
                            "28/10/2023",
                            "Python",10);

    Empleados *P3;
    P3 = new Diseñador(     "Luis",
                            1000,
                            "03/11/2023",
                            "Grafico",
                            16);

    Empleados *P4;
    P4 = new Tester(    "Joaquin",
                        0,
                        "10/06/2024",
                        "Humano",
                        1000);


    Finanzas.agregar_empleado(P1);

    Finanzas.agregar_empleado(P2);

    Finanzas.agregar_empleado(P3);

    Finanzas.agregar_empleado(P4);



    Finanzas.mostrarDatos();

    //Eliminacion
    Finanzas.eliminar_empleado("Grossman");

    Finanzas.mostrarDatos();
    cout << "\n";

    //Busqueda
    cout << "Empleado Buscado: " << endl;
    Finanzas.buscar_empleado("Yhosfer");

    Finanzas.buscar_empleado("Pepito");

    return 0;

}