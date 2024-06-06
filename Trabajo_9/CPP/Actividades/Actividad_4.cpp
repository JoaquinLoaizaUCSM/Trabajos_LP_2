#include <iostream>
using namespace std;
//class interfaz - base
class Animal{
public:
    virtual void hacerSonido() = 0;
    virtual ostream& operator<<(ostream& os) const = 0;
};

ostream& operator<<(ostream& os, const Animal& animal) {
    return animal.operator<<(os);
}

class Perro : public Animal{
private:
    string nombre;
    int edad;

public:
    Perro(string n, int a){
        this -> nombre = n;
        this -> edad = a;
    }

    void hacerSonido() override{
        cout << "Miau" << endl;
    }

    ostream& operator<<(ostream& os) const override {
        os << "Nombre -> " << nombre << endl;
        os << "Edad -> " << edad << endl;
        return os;
    }

};

class Gato : public Animal{
private:
    string nombre;
    int edad;

public:
    Gato(string n, int a){
        this -> nombre = n;
        this -> edad = a;
    }

    void hacerSonido() override{
        cout << "Guau" << endl;
    }

    ostream& operator<<(ostream& os) const override {
        os << "Nombre -> " << nombre << endl;
        os << "Edad -> " << edad << endl;
        return os;
    }
};

class Vaca : public Animal{
private:
    string nombre;
    int edad;

public:
    Vaca(string n, int a){
        this -> nombre = n;
        this -> edad = a;
    }

    void hacerSonido() override{
        cout << "Invadamos Polonia" << endl;
    }

    ostream& operator<<(ostream& os) const override {
        os << "Nombre -> " << nombre << endl;
        os << "Edad -> " << edad << endl;
        return os;
    }
};

int main(){
    Animal* perrito = new Perro("Mateo", 5);
    Animal* gatito = new Gato("Steve", 9);
    Animal* vaquita = new Vaca("Dario", 2);


    cout << *perrito ;






    return 0;
}



