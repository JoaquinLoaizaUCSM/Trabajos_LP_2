#include <iostream>
using namespace std;

//Interfaz
class Empleado{
    virtual void calcular_Salario() = 0;
    virtual void despedir() = 0;
};


//Clases Derivadas
class Empleado_Completo : public Empleado{
private:
    bool estado;
    string nombre;
    string apellido;
    int codigo;
    int horas_trabajo;
    int horas_extra;
    float salario;

public:
    Empleado_Completo(string name, string last_name, int code, int hours_base, int hours_ext,bool state = true, float salary = 0){
        this -> nombre = name;
        this -> apellido = last_name;
        this -> codigo = code;
        this -> salario = salary;
        this -> horas_trabajo = hours_base;
        this -> horas_extra = hours_ext;
        this -> estado = state;
    }

    void calcular_Salario() override{
        this -> salario = ((horas_trabajo * 25) + (horas_extra * 40));
        cout << "Salario Calculado..." << endl;
    }

    void despedir() override{
        this -> estado = false;
        this -> horas_trabajo = 0;
        this -> horas_extra = 0;
        this -> salario = 0;
        cout << "Empleado " << this -> nombre << " despedido." << endl;
    }

    friend ostream& operator << ( ostream& rt, Empleado_Completo Grossman) {
        if (Grossman.estado == 0) {
            rt << "Estado -> Despedido" << endl;
        } else {
            rt << "Estado -> Trabajando" << endl;
        }
        rt << "Nombre Completo -> " << Grossman.nombre << " " << Grossman.apellido << endl;
        rt << "Codigo -> " << Grossman.codigo << endl;
        rt << "Salario -> " << Grossman.salario << endl;
        rt << "Horas -> " << Grossman.horas_trabajo + Grossman.horas_extra << endl;
        return rt;
    }



};

class Empleado_Medio : public Empleado{
private:
    bool estado;
    string nombre;
    string apellido;
    int codigo;
    int horas_trabajo;
    int horas_extra;
    float salario;

public:
    Empleado_Medio(string name, string last_name, int code, int hours_base, int hours_ext, bool state = true, float salary = 0){
        this -> nombre = name;
        this -> apellido = last_name;
        this -> codigo = code;
        this -> salario = salary;
        this -> horas_trabajo = hours_base;
        this -> horas_extra = hours_ext;
        this -> estado = state;
    }

    void calcular_Salario() override{
        this -> salario = ((horas_trabajo * 5) + (horas_extra * 10))/2;
        cout << "Salario Calculado..." << endl;
    }

    void despedir() override{
        this -> estado = false;
        this -> horas_trabajo = 0;
        this -> horas_extra = 0;
        this -> salario = 0;
        cout << "Empleado " << this ->nombre << " despedido por lavado de dinero." << endl;
    }

    friend ostream& operator << ( ostream& rt, Empleado_Medio Grossman) {
        if (Grossman.estado == 0) {
            rt << "Estado -> Despedido" << endl;
        } else {
            rt << "Estado -> Trabajando" << endl;
        }
        rt << "Nombre Completo -> " << Grossman.nombre << " " << Grossman.apellido << endl;
        rt << "Codigo -> " << Grossman.codigo << endl;
        rt << "Salario -> " << Grossman.salario << endl;
        rt << "Horas -> " << Grossman.horas_trabajo + Grossman.horas_extra << endl;
        return rt;
    }

};

int main() {
    cout << "Prueba:\n" << endl;

    Empleado_Completo Grossman("Grossman","Vargas", 123456789, 20, 2);

    Grossman.calcular_Salario();
    cout << Grossman;
    Grossman.despedir();
    cout << Grossman;

    cout << "\n" << endl;

    Empleado_Medio Yhosfer("Yhosfer", "Quispe", 987654321, 50, 5);

    Yhosfer.calcular_Salario();
    cout << Yhosfer;

    Yhosfer.despedir();
    cout << Yhosfer;

    return 0;
}