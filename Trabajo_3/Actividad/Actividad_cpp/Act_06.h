#include <iostream>
#include <string>
using namespace std;

class ObjetoCompuesto {
private:
    string nombre;

public:
    ObjetoCompuesto(string nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }
};

class ClaseBase {
private:
    ObjetoCompuesto objetoCompuesto;

public:
    ClaseBase(string nombreObjetoCompuesto) : objetoCompuesto(nombreObjetoCompuesto) {}

    ObjetoCompuesto& getObjetoCompuesto() {
        return objetoCompuesto;
    }
};


