#include <iostream>
using namespace std;

class Animal{
public:
    virtual void hacerSonido() = 0;
};

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

    friend ostream& operator << (ostream& os, Perro perrito){
        os << "Nombre -> " << perrito.nombre << endl;
        os << "Edad -> " << perrito.edad << endl;
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

    friend ostream& operator << (ostream& os, Gato &gatito){
        os << "Nombre -> " << gatito.nombre << endl;
        os << "Edad -> " << gatito.edad << endl;
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

    friend ostream& operator << (ostream& os, Vaca &vaquita) {
        os << "Nombre -> " << vaquita.nombre << endl;
        os << "Edad -> " << vaquita.edad << endl;
        return os;
    }
};

int main(){
    Animal* perrito = new Perro("Mateo", 5);
    Animal* gatito = new Gato("Steve", 9);
    Animal* vaquita = new Vaca("Dario", 2);

    Animal *arreglo[3] = {perrito, gatito, vaquita};


    //Los animales estan actuando extraño
    for (Animal *p : arreglo){
        p->hacerSonido();
    }






    return 0;
}



