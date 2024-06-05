#include <iostream>
using namespace std;

class Figura {
    public:
        virtual double calcularArea() const = 0;
};

class Circulo : public Figura {
    public:
        explicit Circulo(double r=1) : radio(r) {}
        double calcularArea() const override {
            return 3.14 * radio * radio;
        }

    private:
        double radio;
};

class Rectangulo : public Figura {
    public:
        explicit Rectangulo(double w=1, double h=1) : ancho(w), alto(h) {}
        double calcularArea() const override {
            return ancho * alto;
        }

    private:
        double ancho;
        double alto;
};

class Cuadrado : public Figura {
    public:
        explicit Cuadrado(double l=1) : lado(l) {}
        double calcularArea() const override {
            return lado * lado;
        }

    private:
        double lado;
};

class Pentagono : public Figura {
    public:
        explicit Pentagono(double l=1) : lado(l) {}
        double calcularArea() const override {
            return 1.72 * lado * lado;
        }

    private:
        double lado;
};

class Triangulo : public Figura {
    public:
        explicit Triangulo(double b=1, double h=1) : base(b), altura(h) {}
        double calcularArea() const override {
            return 0.5 * base * altura;
        }

    private:
        double base;
        double altura;
};


int main() {
    int opcion;
    double a, b;

    cout << "Elige una figura:\n1. Circulo\n2. Rectangulo\n3. Triangulo\n4. Cuadrado\n5. Pentagono\n-> ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Introduce el radio: ";
            cin >> a;
            cout << "El area del circulo es de " << Circulo(a).calcularArea() << endl;
            break;
        case 2:
            cout << "Introduce el ancho y la altura: ";
            cin >> a >> b;
            cout << "El area del rectangulo es de " << Rectangulo(a, b).calcularArea() << endl;
            break;
        case 3:
            cout << "Introduce la base y la altura: ";
            cin >> a >> b;
            cout << "El area del triangulo es de " << Triangulo(a, b).calcularArea() << endl;
            break;
        case 4:
            cout << "Introduce el lado: ";
            cin >> a;
            cout << "El area del cuadrado es de " << Cuadrado(a).calcularArea() << endl;
            break;
        case 5:
            cout << "Introduce el lado: ";
            cin >> a;
            cout << "El area del pentagono es de " << Pentagono(a).calcularArea() << endl;
            break;

        default:
            cout << "Opcion invalida.\n";
            return 1;
    }

    return 0;
}