#include <iostream>
using namespace std;

class Figura{
public:
    virtual void calcularArea() = 0;
};

class Circulo : public Figura {
private:
    int radio;
    const float pi = 3.14;
public:

    Circulo(int r){
        this -> radio = r;
    }

    void calcularArea() override{
        cout << "Area: " << pi*(radio * radio) << endl;
    }
};

class Rectangulo : public Figura{
private:
    int base;
    int altura;

public:

    Rectangulo(int b, int h){
        this -> base = b;
        this -> altura = h;
    }

    void calcularArea() override{
        cout << "Area: " << base * altura << endl;
    }
};

class Triangulo : public Figura{
private:
    int base;
    int altura;
public:

    Triangulo(int b, int h){
        this -> base = b;
        this -> altura = h;
    }

    void calcularArea() override{
        cout << "Area: " << (base * altura)/2 << endl;
    }
};

int main(){
    //Trabajamos dinamicamente con punteros
    Figura* circulito = new Circulo(2);
    Figura* rectangulito = new Rectangulo(2,5);
    Figura* triangulito = new Triangulo(10,80);


    Figura *arreglo[3] = {circulito, rectangulito, triangulito};

    for (Figura *p : arreglo){
        p->calcularArea();
    }
    return 0;




}