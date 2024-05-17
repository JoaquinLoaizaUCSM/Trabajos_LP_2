#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Dispositivo {
public:
    virtual void encender() const = 0;
    virtual void apagar() const = 0;
    virtual ~Dispositivo() = default;
};

class Computadora : public Dispositivo {
public:
    void encender() const override {
        cout << "La computadora esta encendida." << endl;
    }
    void apagar() const override {
        cout << "La computadora esta apagada." << endl;
    }
};

class Telefono : public Dispositivo {
public:
    void encender() const override {
        cout << "El telefono esta encendido." << endl;
    }
    void apagar() const override {
        cout << "El telefono esta apagado." << endl;
    }
};

class Tablet : public Dispositivo {
public:
    void encender() const override {
        cout << "La tablet esta encendida." << endl;
    }
    void apagar() const override {
        cout << "La tablet esta apagada." << endl;
    }
};

int main() {
    vector<unique_ptr<Dispositivo>> dispositivos;
    int opcion;

    while (true) {
        cout << "Seleccione un dispositivo (1: Computadora, 2: Telefono, 3: Tablet, 0: Salir): ";
        cin >> opcion;

        if (opcion == 0) break;

        unique_ptr<Dispositivo> dispositivo;
        switch (opcion) {
            case 1:
                dispositivo = make_unique<Computadora>();
                break;
            case 2:
                dispositivo = make_unique<Telefono>();
                break;
            case 3:
                dispositivo = make_unique<Tablet>();
                break;
            default:
                cout << "Opcion no valida." << endl;
                continue;
        }

        dispositivo->encender();
        dispositivo->apagar();
        dispositivos.push_back(std::move(dispositivo));
    }

    return 0;
}