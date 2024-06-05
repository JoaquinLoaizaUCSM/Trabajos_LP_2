#include <iostream>

using namespace std;

class Forma {
public:
    virtual double calcularPerimetro() const = 0;
    virtual void leerDatos() = 0;
    virtual ~Forma() = default;
};

class Circulo : public Forma {
public:
    Circulo() : radio(0.0) {}
    void leerDatos() override {
        cout << "Ingrese el radio del circulo: ";
        cin >> radio;
    }
    double calcularPerimetro() const override {
        return 2 * 3.14 * radio;
    }
private:
    double radio;

};

class Rectangulo : public Forma {
public:
    Rectangulo() : ancho(0.0), alto(0.0) {}
    void leerDatos() override {
        cout << "Ingrese el ancho del rectangulo: ";
        cin >> ancho;
        cout << "Ingrese el alto del rectangulo: ";
        cin >> alto;
    }
    double calcularPerimetro() const override {
        return 2 * (ancho + alto);
    }
private:
    double ancho;
    double alto;
};

class Triangulo : public Forma {
public:
    Triangulo() : lado1(0.0), lado2(0.0), lado3(0.0) {}
    void leerDatos() override {
        cout << "Ingrese el primer lado del triangulo: ";
        cin >> lado1;
        cout << "Ingrese el segundo lado del triangulo: ";
        cin >> lado2;
        cout << "Ingrese el tercer lado del triangulo: ";
        cin >> lado3;
    }
    double calcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }
private:
    double lado1;
    double lado2;
    double lado3;
};


int main() {

    int opcion;

    while (true) {
        cout << "Seleccione una forma (1: Circulo, 2: Rectangulo, 3: Triangulo, 0: Salir)\n->";
        cin >> opcion;

        if (opcion == 0) break;

        Forma* forma;
        switch (opcion) {
            case 1:
                forma = new Circulo();
                break;
            case 2:
                forma = new Rectangulo();
                break;
            case 3:
                forma = new Triangulo();
                break;
            default:
                cout << "Opcion no valida." << endl;
                continue;
        }

        forma->leerDatos();
        cout << "El perimetro es: " << forma->calcularPerimetro() << endl;
        delete forma;
        break;
    }

    return 0;
}