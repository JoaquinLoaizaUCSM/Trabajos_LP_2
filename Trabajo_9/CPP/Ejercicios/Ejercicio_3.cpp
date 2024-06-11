#include <iostream>
using namespace std;

//Funciones extra
void menu_bono(){
    cout << "Ingrese el bono correspondiente: " << endl;
    cout << "0 -> s/0" << endl;
    cout << "1 -> s/50" << endl;
    cout << "2 -> s/100" << endl;
    cout << "3 -> s/150" << endl;
};

bool validacion(int i, int end){
    for (int x = 0; x < end; x++){
        if ( x == i ){
            return true;
        }
    }
    return false;
}

//Clases
class Empleados{
public:
    virtual void calcularSalario() const = 0;
    virtual void agregarBono() = 0;
};

class Asalariados : public Empleados {
private:
    string nombre;
    string apellido;
    int codigo;
    int bono;
    int const salario = 1000;

public:
    Asalariados(string n, string l, int code, int b = 0) {
        this->nombre = n;
        this->apellido = l;
        this->codigo = code;
        this->bono = b;
    }

    void calcularSalario() const override {
        cout << "Salario c/bono -> " << salario + bono << endl;
    }

    void agregarBono() override {
        menu_bono();
        int extra;
        cin >> extra;
        while (!validacion(extra, 4)) {
            cout << "Ingrese una opcion valida: " << endl;
            cin >> extra;
        }

        switch (extra) {
            case 0:
                break;
            case 1:
                this->bono = 50;
                break;
            case 2:
                this->bono = 100;
                break;
            case 3:
                this->bono = 150;
                break;
        }
    }

    friend ostream& operator << (ostream& ou, Asalariados asalario){
        ou << "Datos de empleado de nombre " << asalario.nombre + asalario.apellido << " :" << endl;
        ou << "Codigo        -> " << asalario.codigo << endl;
        ou << "Sueldo base   -> " << asalario.salario << endl;
        asalario.agregarBono();
        asalario.calcularSalario();
        return ou;
    }
};

class Por_hora: public Empleados {
private:
    string nombre;
    string apellido;
    int codigo;
    int horas;
    int bono;

public:
    Por_hora(string n, string l, int code, int hours = 0, int b = 0) {
        this->nombre = n;
        this->apellido = l;
        this->codigo = code;
        this->horas = hours;
        this->bono = b;
    }

    void calcularSalario() const override {
        cout << "Salario -> " << (horas * 50) + bono << endl;
    }

    void agregarBono() override {
        int extra = horas * 25;
        this -> bono = extra;
        cout << "Siendo las horas trabajadas -> " << horas << " su bono es de " << extra << endl;
    }

    friend ostream& operator << (ostream& ou, Por_hora porHora){
        ou << "Datos de empleado de nombre " << porHora.nombre + porHora.apellido << " :" << endl;
        ou << "Codigo           -> " << porHora.codigo << endl;
        ou << "Horas Trabajadas -> " << porHora.horas << endl;
        porHora.agregarBono();
        porHora.calcularSalario();
        return ou;
    }
};


class Comisionista: public Empleados{
private:
    string nombre;
    string apellido;
    int codigo;
    int const precio_maquina = 1000;
    int maquinas_vendidas;
    int bono;

public:
    Comisionista(string n, string l, int code, int machines = 0, int b = 0) {
        this->nombre = n;
        this->apellido = l;
        this->codigo = code;
        this->maquinas_vendidas= machines;
        this->bono = b;
    }

    void calcularSalario() const override {
        cout << "Salario -> " << maquinas_vendidas*(precio_maquina * 0.25) + bono << endl;
    }

    void agregarBono() override {
        int extra = maquinas_vendidas * 100;
        this -> bono = extra;
        cout << "Siendo las maquinas vendidas -> " << maquinas_vendidas << " su bono es de " << extra << endl;
    }

    friend ostream& operator << (ostream& ou, Comisionista comisionista){
        ou << "Datos de empleado de nombre " << comisionista.nombre + comisionista.apellido << " :" << endl;
        ou << "Codigo            -> " << comisionista.codigo << endl;
        ou << "Maquinas Vendidas -> " << comisionista.maquinas_vendidas << endl;
        comisionista.agregarBono();
        comisionista.calcularSalario();
        return ou;
    }
};

void menu_empleados() {
    cout << "Crear: " << endl;
    cout << "0 -> Finalizar Programa" << endl;
    cout << "1 -> Asalariado" << endl;
    cout << "2 -> Por hora" << endl;
    cout << "3 -> Comisionista" << endl;
}

int main() {
    while (true) {
        menu_empleados();
        int opc;
        cout << "Ingrese una opcion: " << endl;
        cin >> opc;
        while (!validacion(opc, 4)) {
            cout << "Ingrese una opcion valida: " << endl;
            cin >> opc;
        }
        switch (opc) {
            case 0: {
                return 0;
            }
            case 1: {
                Asalariados asalariado("Grossman ", "Vargas", 1);
                cout << asalariado;
                break;
            }
            case 2: {
                Por_hora porHora("Yhosfer ", "Quispe", 2, 40);
                cout << porHora;
                break;
            }
            case 3: {
                Comisionista comisionista("Luis ", "Pozu", 3, 10);
                cout << comisionista;
                break;
            }
        }
    }
}