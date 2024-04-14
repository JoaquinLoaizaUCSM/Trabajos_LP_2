#include <iostream>
#include <string>

using namespace std;

class ClasePadre {
protected:
    string atributoBase;

public:
    ClasePadre(string atributoBase) : atributoBase(atributoBase) {}

    void metodoBase() {
        cout << "Metodo de la clase base" << endl;
    }

    string getAtributoBase() {
        return atributoBase;
    }

    void setAtributoBase(string atributoBase) {
        this->atributoBase = atributoBase;
    }
};

class ClaseDerivada : public ClasePadre {
private:
    string atributoDerivada;

public:
    ClaseDerivada(string atributoBase, string atributoDerivada) : ClasePadre(atributoBase), atributoDerivada(atributoDerivada) {}

    void metodoDerivada() {
        cout << "Metodo de la clase derivada" << endl;
    }

    string getAtributoDerivada() {
        return atributoDerivada;
    }

    void setAtributoDerivada(string atributoDerivada) {
        this->atributoDerivada = atributoDerivada;
    }
};


