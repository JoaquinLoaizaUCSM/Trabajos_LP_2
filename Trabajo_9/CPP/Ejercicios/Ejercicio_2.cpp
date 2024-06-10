#include <iostream>
using namespace std;
#include <cstdlib>

class Animales{
public:
    virtual void comer() = 0;
    virtual void dormir() = 0;
    virtual void moverse() = 0;
    virtual void lastimar() = 0;
    virtual void especificaciones() const = 0;
};


class Mamifero : public Animales{
private:
    int saciedad;
    int estado_salud;
    int posicion;

public:
    Mamifero(int s = 0, int h = 0, int p = 0){
        this -> saciedad = s;
        this -> estado_salud = h;
        this -> posicion = p;
    }

    void comer() override{
        int valor = rand() % 3;
        cout << "Su nivel de saciedad ha aumentado en " << valor << endl;
        this -> saciedad + valor;
    }

    void dormir() override{
        cout << "El animal durmio satisfactoriamente; salud aumentada en 1" << endl;
        this -> estado_salud += 1;
    }

    void lastimar() override{
        cout << "El animal se lastimo; salud reducida en 2" << endl;
        this -> estado_salud -= 1;
    }

    void moverse() override{
        cout << "El animal se movio un paso adelante." << endl;
        this -> posicion;
    }

    void especificaciones() const override{
        cout << "Datos del Mamifero encontrado en la posicion " << this -> posicion << " :" << endl;
        cout << "Nivel de saciedad -> " << this -> saciedad << endl;
    }
};

class Ave : public Animales {
private:
    int saciedad;
    int estado_salud;
    int posicion;

public:
    Ave(int s = 0, int h = 0, int p = 0) {
        this -> saciedad = s;
        this -> estado_salud = h;
        this -> posicion = p;
    }

    void comer() override {
        int valor = rand() % 3 + 2;
        cout << "Su nivel de saciedad ha aumentado en " << valor << endl;
        this -> saciedad += valor;
    }

    void dormir() override {
        cout << "El ave durmio satisfactoriamente; salud aumentada en 2" << endl;
        this -> estado_salud += 2;
    }

    void lastimar() override {
        cout << "El ave se lastimo las alas; salud reducida en 3" << endl;
        this -> estado_salud -= 3;
    }

    void moverse() override {
        cout << "El ave volo una milla." << endl;
        this -> posicion += 1000;
    }

    void especificaciones() const override {
        cout << "Datos del Ave encontrada en la posicion " << this -> posicion << " :" << endl;
        cout << "Nivel de saciedad -> " << this -> saciedad << endl;
        cout << "Estado de salud -> " << this -> estado_salud << endl;
    }
};

class Reptil : public Animales {
private:
    int saciedad;
    int estado_salud;
    int posicion;

public:
    Reptil(int s = 0, int h = 0, int p = 0) {
        this -> saciedad = s;
        this -> estado_salud = h;
        this -> posicion = p;
    }

    void comer() override {
        int valor = rand() % 3 + 3;
        cout << "Su nivel de saciedad ha aumentado en " << valor << endl;
        this -> saciedad += valor;
    }

    void dormir() override {
        cout << "El reptil durmio satisfactoriamente; salud aumentada en 4" << endl;
        this -> estado_salud += 4;
    }

    void lastimar() override {
        cout << "El reptil se partio a la mitad; salud multiplicada por 2" << endl;
        this -> estado_salud *= 2;
    }

    void moverse() override {
        cout << "El reptil se movio." << endl;
        this -> posicion += -1;
    }

    void especificaciones() const override {
        cout << "Datos del Reptil encontrado en la posicion " << this -> posicion << " :" << endl;
        cout << "Nivel de saciedad -> " << this -> saciedad << endl;
        cout << "Estado de salud -> " << this -> estado_salud << endl;
    }

};

void menu_animales() {
    cout << "Crear: " << endl;
    cout << "0 -> Finalizar Programa" << endl;
    cout << "1 -> Ave" << endl;
    cout << "2 -> Reptil" << endl;
    cout << "3 -> Mamifero" << endl;
}

bool validacion(int i, int end) {
    for (int x = 0; x < end; x++) {
        if (x == i) {
            return true;
        }
    }
    return false;
}

int main() {
    while (true) {
        menu_animales();
        int opc;
        cout << "Ingrese una opcion: " << endl;
        cin >> opc;
        while (!validacion(opc, 4)) {
            cout << "Ingrese una opcion valida: " << endl;
            cin >> opc;
        }
        switch (opc) {
            case 0: {
                return 0;
            }
            case 1: {
                Ave ave;
                ave.comer();
                ave.dormir();
                ave.moverse();
                ave.lastimar();
                ave.especificaciones();
                break;
            }
            case 2: {
                Reptil reptil;
                reptil.comer();
                reptil.dormir();
                reptil.moverse();
                reptil.lastimar();
                reptil.especificaciones();
                break;
            }
            case 3: {
                Mamifero mamifero;
                mamifero.comer();
                mamifero.dormir();
                mamifero.moverse();
                mamifero.lastimar();
                mamifero.especificaciones();
                break;
            }
        }
    }
}
