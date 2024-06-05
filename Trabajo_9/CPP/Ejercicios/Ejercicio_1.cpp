#include <iostream>
using namespace std;
#include <math.h>

class Forma{
public:
    virtual void cambiarPropiedades() = 0;
    virtual void calcularArea() const= 0;
    virtual void calcularPerimetro() const = 0;
    virtual void especificaciones() const = 0;
};


class Circulo : public Forma{
private:
    int radio;
    int diametro;

public:
    Circulo(int r = 0){
        this -> radio = r;
        this -> diametro = 2*radio;
    }

    void cambiarPropiedades() override{
        int r;
        cout << "Ingrese el nuevo radio -> ";
        cin >> r;
        this -> radio = r;
        this -> diametro = 2*r;
    }

    void calcularArea() const override{
        cout << "Area: " << 3.14 * (radio * radio) << endl;
    }

    void calcularPerimetro() const override{
        cout << "Perimetro: " << 3.14 * (diametro) << endl;
    }

    void especificaciones() const override{
        cout << "Datos del Circulo: " << endl;
        cout << "Radio -> " << this -> radio << endl;
        cout << "Diametro -> " << this -> diametro << endl;
        this -> calcularPerimetro();
        this -> calcularArea();
    }
};


class Rectangulo: public Forma{
private:
    int base;
    int altura;

public:
    Rectangulo(int b = 0, int h = 0){
        this -> base = b;
        this -> altura = h;
    }

    void cambiarPropiedades() override{
        int b;
        int h;
        cout << "Ingrese la nueva base -> ";
        cin >> b;
        cout << "Ingrese la nueva altura -> ";
        cin >> h;
        this -> base = b;
        this -> altura = h;
    }

    void calcularArea() const override{
        cout << "Area: " << base * altura << endl;
    }

    void calcularPerimetro() const override{
        cout << "Perimetro: " << 2*(base+altura) << endl;
    }

    void especificaciones() const override{
        cout << "Datos del Rectangulo: " << endl;
        cout << "Base -> " << this -> base << endl;
        cout << "Altura -> " << this -> altura << endl;
        this -> calcularPerimetro();
        this -> calcularArea();
    }
};


class Triangulo: public Forma{
private:
    int base;
    int altura;
    int hipotenusa;

public:
    Triangulo(int b = 0, int h = 0){
        this -> base = b;
        this -> altura = h;
        this -> hipotenusa = sqrt((b*b)+(h*h));
    }

    void cambiarPropiedades() override{
        int b;
        int h;
        cout << "Ingrese la nueva base -> ";
        cin >> b;
        cout << "Ingrese la nueva altura -> ";
        cin >> h;
        this -> base = b;
        this -> altura = h;
        this -> hipotenusa = sqrt((b*b)+(h*h));
    }

    void calcularArea() const override{
        cout << "Area: " << (base * altura)/2 << endl;
    }

    void calcularPerimetro() const override{
        cout << "Perimetro: " << (base+altura+hipotenusa) << endl;
    }

    void especificaciones() const override{
        cout << "Datos del Triangulo: " << endl;
        cout << "Base -> " << this -> base << endl;
        cout << "Altura -> " << this -> altura << endl;
        cout << "Hipotenusa -> " << this -> hipotenusa << endl;
        this -> calcularPerimetro();
        this -> calcularArea();
    }
};

class Trapecio: public Forma{
private:
    int baseMayor;
    int baseMenor;
    int altura;
    int lado1;
    int lado2;

public:
    Trapecio(int bMayor = 0, int bMenor = 0, int h = 0, int l1 = 0, int l2 = 0){
        this -> baseMayor = bMayor;
        this -> baseMenor = bMenor;
        this -> altura = h;
        this -> lado1 = l1;
        this -> lado2 = l2;
    }

    void cambiarPropiedades() override{
        int bMayor, bMenor, h, l1, l2;
        cout << "Ingrese la nueva base mayor -> ";
        cin >> bMayor;
        cout << "Ingrese la nueva base menor -> ";
        cin >> bMenor;
        cout << "Ingrese la nueva altura -> ";
        cin >> h;
        cout << "Ingrese el nuevo lado 1 -> ";
        cin >> l1;
        cout << "Ingrese el nuevo lado 2 -> ";
        cin >> l2;
        this -> baseMayor = bMayor;
        this -> baseMenor = bMenor;
        this -> altura = h;
        this -> lado1 = l1;
        this -> lado2 = l2;
    }

    void calcularArea() const override{
        cout << "Area: " << ((baseMayor + baseMenor) * altura) / 2 << endl;
    }

    void calcularPerimetro() const override{
        cout << "Perimetro: " << baseMayor + baseMenor + lado1 + lado2 << endl;
    }

    void especificaciones() const override{
        cout << "Datos del Trapecio: " << endl;
        cout << "Base Mayor -> " << this -> baseMayor << endl;
        cout << "Base Menor -> " << this -> baseMenor << endl;
        cout << "Altura -> " << this -> altura << endl;
        cout << "Lado 1 -> " << this -> lado1 << endl;
        cout << "Lado 2 -> " << this -> lado2 << endl;
        this -> calcularPerimetro();
        this -> calcularArea();
    }
};

void menu_figuras(){
    cout << "Crear: " << endl;
    cout << "0 -> Finalizar Programa" << endl;
    cout << "1 -> Circulo" << endl;
    cout << "2 -> Rectangulo" << endl;
    cout << "3 -> Triangulo" << endl;
    cout << "4 -> Trapecio" << endl;
}

int validacion(int end){
    int num;
    while (true){
        cin >> num;
        for (int i = 0, end){
            if (num == i){
                return num;
            }
        }
    }
}

int main(){
    while (true){
        menu_figuras()
    }





    return 0;
}