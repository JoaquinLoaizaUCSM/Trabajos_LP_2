#include <iostream>
using namespace std;
#include <math.h>

class FiguraGeometrica{
public:
    virtual void calcularArea() = 0;
    virtual void calcularPerimetro() = 0;
    //pi*diametro
};

class Circulo : public FiguraGeometrica{
private:
    int radio;
    int diametro;
public:
    Circulo(int r){
        this -> radio = r;
        this -> diametro = 2*radio;
    }

    void calcularArea() override{
        cout << "Area: " << 3.14 * (radio * radio);
    }

    void calcularPerimetro() override{
        cout << "Perimetro: " << 3.14 * (diametro);
    }
};

class Rectangulo : public FiguraGeometrica{
private:
    int base;
    int altura;
public:
    Rectangulo(int b, int h){
        this -> base = b;
        this -> altura = h;
    }

    void calcularArea() override{
        cout << "Area: " << base*altura;
    }

    void calcularPerimetro() override{
        cout << "Perimetro: " << (base+altura)*2;
    }
};

class Triangulo : public FiguraGeometrica{
private:
    int base;
    int altura;
    int hipotenusa;
public:
    Triangulo(int b, int h){
        this -> base = b;
        this -> altura = h;
        this -> hipotenusa = sqrt((b*b)+(h*h));
    }

    void calcularArea() override{
        cout << "Area: " << (base*altura)/2;
    }

    void calcularPerimetro() override{
        cout << "Perimetro: " << (base+altura+hipotenusa);
    }
};

int main(){
    FiguraGeometrica* circulito = new Circulo(5);
    FiguraGeometrica* rectangulito = new Rectangulo(10,20);
    FiguraGeometrica* triangulito = new Triangulo(7,14);

    FiguraGeometrica *arreglo[3] = {circulito,rectangulito,triangulito};

    for (FiguraGeometrica *p : arreglo){
        cout << "\n" ;
        p->calcularArea();
        cout << "\n" ;
        p->calcularPerimetro();
    }

    return 0;
}