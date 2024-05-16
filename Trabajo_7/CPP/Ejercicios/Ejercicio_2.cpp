#include <iostream>
using namespace std;

class Persona{
protected:
    string correo;

private:
    string nombre;
    int edad;
    float salario;

public:
    Persona(string name, int age, float salary, string mail){
        this -> nombre = name;
        this -> edad = age;
        this -> salario = salary;
        this -> correo = mail;
    }

    //Metodos G y S
    string getNombre() {
        return nombre;
    }

    int getEdad() {
        return edad;
    }

    float getSalario() {
        return salario;
    }

    string &getCorreo(){
        return correo;
    }

};

class Empleado : protected Persona{
private:
    int codigo;
public:
    Empleado(string name, int age, float salary, string mail, int code)
            : Persona(name,age,salary,mail) {
        this -> codigo = code;
    }

    void setCorreo(string mail){
        this->getCorreo() = mail;
    }

    friend ostream& operator << (ostream& os, Empleado Emp_01){
        os << "Datos del empleado:" << endl;
        os << "Codigo  -> " << Emp_01.codigo << endl;
        os << "Nombre  -> " << Emp_01.getNombre()<< endl;
        os << "Edad    -> " << Emp_01.getEdad() << endl;
        os << "Salario -> " << Emp_01.getSalario() << endl;
        os << "Correo  -> " << Emp_01.getCorreo() << endl;

        return os;
    }



};

class Cliente : protected Persona{
private:
    string estado_civil;
public:
    Cliente(string name, int age, float salary, string mail, string civil_status)
            : Persona(name,age,salary,mail) {
        this -> estado_civil = civil_status;
    }

    void setCorreo(string mail){
        this->getCorreo() = mail;
    }

    friend ostream& operator << (ostream& os, Cliente Cli_01){
        os << "Datos del cliente:" << endl;
        os << "Estado  -> " << Cli_01.estado_civil << endl;
        os << "Nombre  -> " << Cli_01.getNombre()<< endl;
        os << "Edad    -> " << Cli_01.getEdad() << endl;
        os << "Salario -> " << Cli_01.getSalario() << endl;
        os << "Correo  -> " << Cli_01.getCorreo() << endl;

        return os;
    }

};


int main(){
    Empleado Jose("Jose", 18, 950, "jose.luis@gmail.com", 123);
    Cliente Pepe("Pepe", 19, 1000, "pepe.zoto@gmail.com", "Casado");
    Jose.setCorreo("Joaquin.data.52@gmail.com");
    cout << Jose;
    cout << "" << endl;
    cout << Pepe;

    return 0;
}