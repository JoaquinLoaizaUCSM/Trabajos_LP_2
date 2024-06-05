#include <iostream>
using namespace std;

class Animal{
public:
    virtual void hacersonido(){
        cout << "waos" << endl;
    } ;
};

class Perro : public Animal{
private:
    string nombre;
    int edad;
    string raza;

public:
    Perro(string n, int a, string r){
        this -> nombre = n;
        this -> edad = a;
        this -> raza = r;
    }

    void hacersonido() override{
        cout << "miau" << endl;
    }

};



int main(){

    cout << "Dinamico (HEAP): " << endl;
    //El asterisco indica que el objeto creado es un puntero tipo clase Animal
    //Es una "Asignación dinámica", es decir que permanecerá en la memoria hasta que lo borremos
    //Nos ayuda a trabajar mejor con el polimorfismo

    Animal* perrito = new Perro("Perrito",180,"Chitsu");

    //Se usa la flechita porque se trabaja con un puntero
    perrito->hacersonido();

    delete perrito;


    cout << "Estatico (STACK): " << endl;
    Animal animalito;
    animalito = Perro("waos",20,"Bulldog");

    animalito.hacersonido();

    return 0;
}

