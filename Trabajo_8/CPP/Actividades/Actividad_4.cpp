#include <iostream>

using namespace std;

class Vehiculo {
public:
    virtual void acelerar() const {
        cout << "Acelerando el vehiculo\n";
    }
    virtual ~Vehiculo() = default;
};

class Coche : public Vehiculo {
public:
    void acelerar() const override {
        cout << "Acelerando el coche\n";
    }
    void encenderLuces() const {
        cout << "Luces del coche encendidas\n";
    }
};

class Motocicleta : public Vehiculo {
public:
    void acelerar() const override {
        cout << "Acelerando la motocicleta\n";
    }
};

void acelerarVehiculo(const Vehiculo& vehiculo) {
    vehiculo.acelerar();
}

int main() {
    Coche coche;
    acelerarVehiculo(coche);
    coche.encenderLuces();

    Motocicleta moto;
    acelerarVehiculo(moto);

    return 0;
}