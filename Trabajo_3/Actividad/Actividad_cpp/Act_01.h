#ifndef LP_04_ACT_01_H
#define LP_04_ACT_01_H
#include <iostream>
using namespace std;

class Hijo{
private:
    string nombre;

public:
    Hijo(string name = "Grossman"){
        this -> nombre = name;
    }

    string get_nombre(){
        return nombre;
    }

    void set_nombre(string name){
        nombre = name;
    }
};


class Padre{
private:
    string nombre;
    int numhijos = 0;
    Hijo hijos[5];


public:
    Padre(string name = "Grossman"){
        this -> nombre = name;
    }

    void agregarhijo(Hijo hijo){
        if (numhijos < 5){
            hijos[numhijos] = hijo;
            numhijos++;
        } else {
            cout << "numero maximo de hijos alcanzado xd" << endl;
        }
    }

    void impresion_detalles(){
        cout << "Nombre -> " << nombre << endl;
        cout << "Cantidad de Hijos -> " << numhijos << endl;

    }

    string get_nombre(){
        return nombre;
    }

    void set_nombre(string name){
        nombre = name;
    }
};








#endif
