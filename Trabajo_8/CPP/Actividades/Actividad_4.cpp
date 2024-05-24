#include <iostream>
#include <format>

using namespace std;

class Vehiculo {
public:
    virtual void acelerar() const {
        cout << format("Acelerando el vehiculo\n");
    }
    virtual ~Vehiculo() = default;
};

class Coche : public Vehiculo {
public:
    void acelerar() const override {
        cout << format("Acelerando el coche\n");
    }
    void encenderLuces() const {
        cout << format("Luces del coche encendidas\n");
    }
};

class Motocicleta : public Vehiculo {
public:
    void acelerar() const override {
        cout << format("Acelerando la motocicleta\n");
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