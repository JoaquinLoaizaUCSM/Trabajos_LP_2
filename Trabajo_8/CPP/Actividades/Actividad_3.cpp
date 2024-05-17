#include <iostream>
#include <vector>
#include <memory>

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
    vector<unique_ptr<Animal>> animales;        //
    animales.push_back(make_unique<Perro>());
    animales.push_back(make_unique<Pajaro>());

    for (const auto& animal : animales) {
        animal->hacerSonido();
        animal->moverse();
    }

    return 0;
}