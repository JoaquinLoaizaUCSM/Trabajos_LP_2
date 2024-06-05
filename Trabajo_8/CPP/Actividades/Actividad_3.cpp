#include <iostream>

using namespace std;

class Animal {
public:
    virtual void hacerSonido() const = 0;
    virtual void moverse() const = 0;
    virtual ~Animal() = default;
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        cout << "El perro ladra: Guau guau!" << endl;
    }
    void moverse() const override {
        cout << "El perro corre." << endl;
    }
};

class Pajaro : public Animal {
public:
    void hacerSonido() const override {
        cout << "El pajaro canta: Pio pio!" << endl;
    }
    void moverse() const override {
        cout << "El pajaro vuela." << endl;
    }
};

int main() {
    Animal* ptrAnimal1;
    Animal* ptrAnimal2;

    Perro perro1;
    Pajaro pajaro1;

    ptrAnimal1 = &perro1;
    ptrAnimal2 = &pajaro1;

    ptrAnimal1->hacerSonido();
    ptrAnimal1->moverse();

    ptrAnimal2->hacerSonido();
    ptrAnimal2->moverse();

    return 0;
}