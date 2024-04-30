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

Coche menu_coche() {
    string marca, modelo, color, nombre;
    int year, numPuertas, opcion, edad;

    int opc = 0;
    while (opc <= 0 or opc >= 4) {
        cout << "1 : Crear Vehículo sin datos" << endl;
        cout << "2 : Ingresar Vehículo" << endl;
        cout << "3 : Ingresar Marca y modelo" << endl;
        cin >> opc;
    }

    if (opc == 1) {
        Coche M1("","",0,"",0);
        return M1;
    }

    if (opc == 2) {
        cout << "Ingresar Marca:" << endl;
        cin >> marca;
        cout << "Ingresar Modelo:" << endl;
        cin >> modelo;
        cout << "Ingresar Año:" << endl;
        cin >> year;
        cout << "Ingresar Color:" << endl;
        cin >> color;
        cout << "Ingresar N_Puertas:" << endl;
        cin >> numPuertas;
        Coche M1(marca, modelo, year, color, numPuertas);
        return M1;
    }

    if (opc == 3) {
        cout << "Ingresar Marca:" << endl;
        cin >> marca;
        cout << "Ingresar Modelo:" << endl;
        cin >> modelo;
        Coche M1(marca, modelo);
        return M1;
    }
}

void menu_Gestor(Coche m){
    string marca,modelo,color;
    int year, n_puertas;
    string nombre;
    int edad;

    cout << "Ingrese su nombre:" << endl;
    cin >> nombre;
    cout << "Digite su edad:" << endl;
    cin >> edad;

    Gestor_Coche M2(m, nombre, edad);

    int opc = 0;
    while (opc <= 0 or opc >= 6) {
        cout << "1 : Modificar Marca y Modelo" << endl;
        cout << "2 : Modificar Año" << endl;
        cout << "3 : Modificar Color" << endl;
        cout << "4 : Modifiar N_Puertas" << endl;
        cout << "5 : Reingresar Datos" << endl;
        cout << "6 : Imprimir Datos" << endl;
        cin >> opc;
    }

    if (opc == 1){
        cout << "Reingresar marca: " << endl;
        cin >> marca;
        cout << "Reingresar modelo: " << endl;
        cin >> modelo;
        M2.modif_marca_modelo(marca,modelo);
        M2.imprimirInformacion();
    }

    if (opc == 2){
        cout << "Reingresar año: " << endl;
        cin >> year;
        M2.modif_year(year);
        M2.imprimirInformacion();
    }

    if (opc == 3){
        cout << "Reingresar color: " << endl;
        cin >> color;
        M2.modif_color(color);
        M2.imprimirInformacion();
    }

    if (opc == 4){
        cout << "Reingresar n_Puertas: " << endl;
        cin >> n_puertas;
        M2.modif_numPuertas(n_puertas);
        M2.imprimirInformacion();
    }

    if (opc == 5){
        cout << "Reingresar marca: " << endl;
        cin >> marca;
        cout << "Reingresar modelo: " << endl;
        cin >> modelo;
        cout << "Reingresar año: " << endl;
        cin >> year;
        cout << "Reingresar color: " << endl;
        cin >> color;
        cout << "Reingresar N_puertas:" << endl;
        cin >> n_puertas;
        M2.reingresar_datos(marca,modelo,year,color,n_puertas);
        M2.imprimirInformacion();
    }

    if (opc == 6){
        M2.imprimirInformacion();
    }
}




int main() {
    Coche m;
    m = menu_coche();
    menu_Gestor(m);
    return 0;
}
