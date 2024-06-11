#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Producto {
public:
    virtual double calculo() const = 0;
    virtual void aplicarDescuento(double porcentaje) = 0;
    virtual void imprimirDatos() const = 0;
};

class Electronico : public Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Electronico(string n, double p, int c) {
        this->nombre = n;
        this->precio = p;
        this->cantidad = c;
    }

    double calculo() const override {
        return precio * cantidad;
    }

    void aplicarDescuento(double porcentaje) override {
        precio *= (1 - porcentaje / 100);
    }

    void imprimirDatos() const override {
        cout << "Producto: " << nombre << endl;
        cout << "Categoria: Electronico" << endl;
        cout << "Precio: " << precio << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
};

class Ropa : public Producto {
private:
    string nombre;
    double precio;
    int cantidad;
    string talla;

public:
    Ropa(string n, double p, int c, string t) {
        this->nombre = n;
        this->precio = p;
        this->cantidad = c;
        this->talla = t;
    }

    double calculo() const override {
        return precio * cantidad;
    }

    void aplicarDescuento(double porcentaje) override {
        precio *= (1 - porcentaje / 100);
    }

    void imprimirDatos() const override {
        cout << "Producto: " << nombre << endl;
        cout << "Categoria: Ropa" << endl;
        cout << "Precio: " << precio << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Talla: " << talla << endl;
    }
};

class Alimento : public Producto {
private:
    string nombre;
    double precio;
    int cantidad;
    string vencimiento;

public:
    Alimento(string n, double p, int c, string v) {
        this->nombre = n;
        this->precio = p;
        this->cantidad = c;
        this->vencimiento = v;
    }

    double calculo() const override {
        return precio * cantidad;
    }

    void aplicarDescuento(double porcentaje) override {
        precio *= (1 - porcentaje / 100);
    }

    void imprimirDatos() const override {
        cout << "Producto: " << nombre << endl;
        cout << "Categoria: Alimento" << endl;
        cout << "Precio: " << precio << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Fecha de Expiracion: " << vencimiento << endl;
    }
};

int main() {
    vector<Producto*> inventario;

    inventario.push_back(new Electronico("Laptop", 1500, 10));
    inventario.push_back(new Ropa("Camisa", 30, 50, "S"));
    inventario.push_back(new Alimento("Manzana", 1, 100, "2023-12-31"));

    double total = 0;
    for (Producto* p : inventario) {
        total += p->calculo();
    }

    cout << "Precio fuinal: s/" << total << endl;

    for (Producto* p : inventario) {
        p->aplicarDescuento(10);
    }

    total = 0;
    for (Producto* p : inventario) {
        total += p->calculo();
    }

    cout << "Precio Final: s/" << total << endl;

    cout << "Inventario:" << endl;
    for (Producto* p : inventario) {
        p->imprimirDatos();
        cout << "" << endl;
    }

    for (Producto* p :inventario){
        delete p;
    }

    return 0;
}
