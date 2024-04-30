#include <iostream>
#include <string>
using namespace std;

class Coche {
private:
    string marca;
    string modelo;
    int year;
    string color;
    int numeroDePuertas;

public:

    Coche(){
        this -> marca = "Desconocido";
        this -> modelo = "Desconocido";
        this -> year = 0;
        this -> color = "Desconocido";
        this -> numeroDePuertas = 0;
    }

    Coche(string brand, string model, int year, string colour, int num_puertas){
        this -> marca = brand;
        this -> modelo = model;
        this -> year = year;
        this -> color = colour;
        this -> numeroDePuertas = num_puertas;
    }

    Coche(string brand, string model){
        this -> marca = brand;
        this -> modelo = model;
        this -> year = 0;
        this -> color = "Desconocido";
        this -> numeroDePuertas = 0;
    }

    Coche(int num_puertas){
        this -> marca = "Desconocido";
        this -> modelo = "Desconocido";
        this -> year = 0;
        this -> color = "Desconocido";
        this -> numeroDePuertas = num_puertas;
    }

    // Destructor
    ~Coche() {}

    //Autorreferencias
    Coche& set_marca(string brand){
        this -> marca = brand;
        return *this;
    }

    Coche& set_modelo(string model){
        this -> modelo = model;
        return *this;
    }

    Coche& set_year(int anio){
        this -> year = anio;
        return *this;
    }

    Coche& set_color(string colour){
        this -> color = colour;
        return *this;
    }

    Coche& set_numPuertas(int num_puertas){
        this -> numeroDePuertas = num_puertas;
        return *this;
    }

    string getMarca() {
        return marca;
    }

    string getModelo() {
        return modelo;
    }

    int getYear() {
        return year;
    }

    string getColor() {
        return color;
    }
    int getNumeroDePuertas() {
        return numeroDePuertas;
    }
};

// Que dios nos ayude con esto

class Gestor_Coche{
public:
    Gestor_Coche(Coche M1, string name = "Grossman", int age = 19){
        this -> Franchesco = M1;
        this -> nombre = name;
        this -> edad = age;
    };

    void modif_marca_modelo(string marca, string modelo){
        Franchesco.set_marca(marca).set_modelo(modelo);
    }

    void modif_year(int _year){
        Franchesco.set_year(_year);
    }

    void modif_color(string colour){
        Franchesco.set_color(colour);
    }

    void modif_numPuertas(int numPuertas){
        Franchesco.set_numPuertas(numPuertas);
    }

    void reingresar_datos(string marca, string modelo, int _year, string colour, int numPuertas){
        Franchesco.set_marca(marca).set_modelo(modelo).set_year(_year).set_color(colour).set_numPuertas(numPuertas);
    }

    void imprimirInformacion() {
        cout << "Dueño del vehicculo: " << nombre << " edad: " << edad;
        cout << "Datos del vehivulo: " << endl;
        cout << "   - Marca: " << Franchesco.getMarca() << endl;
        cout << "   - Modelo: " << Franchesco.getModelo() << endl;
        cout << "   - Añó: " << Franchesco.getYear() << endl;
        cout << "   - Color: " << Franchesco.getColor() << endl;
        cout << "   - Puertas: " << Franchesco.getNumeroDePuertas() << endl;
    }

private:
    Coche Franchesco;
    string nombre;
    int edad;


};

int menu() {
    int eleccion;

    cout << "1. Crear un nuevo coche" << endl;
    cout << "2. Modificar propiedades del coche" << endl;
    cout << "3. Imprimir información del coche" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese su elección: ";
    cin >> eleccion;

    return eleccion;
}

int main() {
    Coche M1("Wa","Ya",2015, "Azul",4);
    M1.set_color("Ga").set_marca("Raro").set_numPuertas(150);
    Gestor_Coche manager(M1, "Grossman", 25);

    while (true) {
        int choice = menu();

        switch (choice) {
            case 1: {
                string marca, modelo, color;
                int year, numPuertas;
                cout << "Ingrese la marca del coche: ";
                cin >> marca;
                cout << "Ingrese el modelo del coche: ";
                cin >> modelo;
                cout << "Ingrese el año del coche: ";
                cin >> year;
                cout << "Ingrese el color del coche: ";
                cin >> color;
                cout << "Ingrese el número de puertas del coche: ";
                cin >> numPuertas;
                Coche M2(marca, modelo, year, color, numPuertas);
                manager = Gestor_Coche(M2, "Joaquin", 25);
                break;
            }
            case 2: {
                string marca, modelo, color;
                int year, numPuertas;
                cout << "Ingrese la nueva marca del coche: ";
                cin >> marca;
                cout << "Ingrese el nuevo modelo del coche: ";
                cin >> modelo;
                cout << "Ingrese el nuevo año del coche: ";
                cin >> year;
                cout << "Ingrese el nuevo color del coche: ";
                cin >> color;
                cout << "Ingrese el nuevo número de puertas del coche: ";
                cin >> numPuertas;
                manager.reingresar_datos(marca, modelo, year, color, numPuertas);
                break;
            }
            case 3:
                manager.imprimirInformacion();
                break;
            case 4:
                return 0;
            default:
                cout << "Elección inválida. Por favor, inténtelo de nuevo." << endl;
        }
    }
}
