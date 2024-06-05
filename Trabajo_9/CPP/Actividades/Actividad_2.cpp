#include <iostream>
using namespace std;

class Calculadora{
public:
    void sumar(int a, int b){
        cout << "Respuesta: " << a + b << endl;
    }

    void sumar(int a, int b, int c){
        cout << "Respuesta: " << a + b + c << endl;
    }

    void sumar(double a, double b){
        cout << "Respuesta: " << a + b << endl;
    }

    void sumar(string a, string b){
        cout << a + " " + b << endl;
    }
};



int main(){
    Calculadora calculadora;
    calculadora.sumar(1,2);
    calculadora.sumar(1.3,2.5);
    calculadora.sumar(4,5,2);
    calculadora.sumar("Hola", "Mundo xd");

    return 0;
}

