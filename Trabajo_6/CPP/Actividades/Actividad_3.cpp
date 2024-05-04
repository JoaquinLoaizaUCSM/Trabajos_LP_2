#include <iostream>
#include <string>


using namespace std;

class Banco {
private:
    static double tasaInteres;

public:

    static void cambiarTasaInteres(double tasa) {
        tasaInteres = tasa;
    }
    static double obtenerTasaInteres(){
        return tasaInteres;
    }
};
double Banco::tasaInteres=0.0;

class CuentaBancaria{
private:
    double saldo;
public:
    CuentaBancaria(double saldoInicial) : saldo(saldoInicial) {}
    void depositar(double cantidad){
        saldo= saldo + cantidad;
    }
    void retirar(double cantidad){
    if (saldo > cantidad){
        saldo= saldo - cantidad;
    } else{
        cout<<"no tienes plata maldito mendigo"<<endl;
    }
    }
};

int main(){
Banco::cambiarTasaInteres(0.10);
CuentaBancaria cuenta(200);
cuenta.depositar(199);
cuenta.retirar(500);

}