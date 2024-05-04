#include <iostream>

using namespace std;

class Circulo {
private:
    double radio;
    double diametro;
public:
    Circulo(double r) : radio(r), diametro(2*r) {}

    friend void calcularArea(Circulo&);
};

void calcularArea(Circulo& c) {
    double PI = 3.14;
    cout <<"El area del circulo es de "<< PI*(c.radio * c.radio) << endl;
}

int main() {
    Circulo circulo(5.0);

    calcularArea(circulo);
    return 0;
}
