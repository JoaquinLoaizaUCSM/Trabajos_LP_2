#include <iostream>
using namespace std;

class Movil{
private:
    string marca;
    string modelo;
    string sistema;

public:
    Movil(string brand, string model, string system){
        this -> marca = brand;
        this -> modelo = model;
        this -> sistema = system;
    }

    ~Movil(){};

    //Metodos G y S
    string getMarca() {
        return marca;
    }

    string getModelo() {
        return modelo;
    }

    string getSistema() {
        return sistema;
    }

};

class Telefono : public Movil{
private:
    int n_celular;
public:
    Telefono(string brand, string model, string system, int n_cel)
            : Movil(brand, model, system) {
        this -> n_celular = n_cel;
    }

    ~Telefono(){
        cout << "Destruido telefono con N celular -> " << this -> n_celular << endl;
    };

    friend ostream& operator << (ostream& os, Telefono& Tel_01){
        os << "Datos del telefono:" << endl;
        os << "Marca             -> " << Tel_01.getMarca() << endl;
        os << "Modelo            -> " << Tel_01.getModelo() << endl;
        os << "Sistema Operativo -> " << Tel_01.getSistema() << endl;
        os << "Numero Celular    -> " << Tel_01.n_celular << endl;

        return os;
    }



};

class Tablet : public Movil{
private:
    bool chip;
public:
    Tablet(string brand, string model, string system, bool chap)
            : Movil(brand, model, system) {
        this -> chip = chap;
    }

    ~Tablet(){
        cout << "Destruido tablet con Modelo -> " << this -> getModelo() << endl;
    };

    friend ostream& operator << (ostream& os, Tablet& Tab_01){
        os << "Datos de la Tablet:" << endl;
        os << "Marca             -> " << Tab_01.getMarca() << endl;
        os << "Modelo            -> " << Tab_01.getModelo() << endl;
        os << "Sistema Operativo -> " << Tab_01.getSistema() << endl;
        if (Tab_01.chip == false){
            os << "Tiene chip        -> Si" << endl;
        } else{
            os << "Tiene chip        -> No" << endl;
        }

        return os;
    }



};


int main(){
    Telefono Tel_01("Samsung", "A150", "Linux", 123456789);
    Tablet Tab_01("IPhone", "90", "Ubuntu", 1);
    cout << Tel_01;
    cout << "" << endl;
    cout << Tab_01;
    cout << "" << endl;

    return 0;
}