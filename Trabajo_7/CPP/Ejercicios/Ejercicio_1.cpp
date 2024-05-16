#include <iostream>
using namespace std;

class Vehiculo{
private:
    string marca;
    string modelo;
    int anio;
    float precio;

public:
    Vehiculo(string brand, string model, int year, float price){
        this -> marca = brand;
        this -> modelo = model;
        this -> anio = year;
        this -> precio = price;
    }

    //Metodos G y S
    string getMarca() {
        return marca;
    }

    string getModelo() {
        return modelo;
    }

    int getAnio() {
        return anio;
    }

    float getPrecio() {
        return precio;
    }

};

class Automovil : public Vehiculo{
private:
    int n_puertas;
    string tipo_c;

public:
    Automovil(string brand, string model, int year, float price, int n_doors, string type_c)
            : Vehiculo(brand,model,year,price){
        this -> n_puertas = n_doors;
        this -> tipo_c = type_c;
    }

    friend ostream& operator << (ostream& os, Automovil Autito){
        os << "Caracteristicas de Auto xd:" << endl;
        os << "Marca            -> " << Autito.getMarca() << endl;
        os << "Modelo           -> " << Autito.getModelo() << endl;
        os << "Anio             -> " << Autito.getAnio() << endl;
        os << "Precio           -> " << Autito.getPrecio() << endl;
        os << "Numero Puertas   -> " << Autito.n_puertas << endl;
        os << "Tipo Combustible -> " << Autito.tipo_c << endl;
        return os;
    }

};

class Moto : public Vehiculo{
private:
    int cilindrada;

public:
    Moto(string brand, string model, int year, float price, int cilin)
            : Vehiculo(brand,model,year,price){
        this -> cilindrada = cilin;
    }

    friend ostream& operator << (ostream& os, Moto Motito){
        os << "Caracteristicas de Moto:" << endl;
        os << "Marca        -> " << Motito.getMarca() << endl;
        os << "Modelo       -> " << Motito.getModelo() << endl;
        os << "Anio         -> " << Motito.getAnio() << endl;
        os << "Precio       -> " << Motito.getPrecio() << endl;
        os << "Cilindrada   -> " << Motito.cilindrada << "cc" << endl;
        return os;
    }
};




int main(){
    Automovil Auto_01("Nissan", "WAA", 2005, 250000, 4, "Premium");
    Moto Mototaxi_01("La", "Moto", 2010, 10000, 150);
    cout << Auto_01;
    cout << "" << endl;
    cout << Mototaxi_01;
    return 0;
}