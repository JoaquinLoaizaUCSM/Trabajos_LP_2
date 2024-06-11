#include <iostream>
using namespace std;
#include <cmath>

//Clases
class Personaje{
public:
    virtual int ataque_basico()  = 0;
    virtual int habilidad_especial() = 0;
    virtual void defensa() = 0;
};

class Guerrero : public Personaje {
private:
    string nickname;
    int atq;
    int vida;

public:
    Guerrero(string n, int a, int v = 10) {
        this->nickname = n;
        this->atq = a;
        this->vida = v;
    }

    int ataque_basico() override {
        int a = round(atq/2);
        cout << "El guerrero blande su espada y realiza una ataque cortante; ATQ -> " << a << endl;
        return a;
    }

    int habilidad_especial() override {
        int q = atq * 3;
        cout << "El guerrero imbuye su espada en fuego y ataca; ATQ -> " << q << endl;
        return q;
    }

    void defensa() override{
        cout << "El guerrero se esconde detras de una piedra y no recibe daño" << endl;
    }

    friend ostream& operator << (ostream& ou, Guerrero guerrero){
        ou << "Datos de " << guerrero.nickname << " :" << endl;
        ou << "Clase         -> Guerrero" << endl;
        ou << "ATQ base      ->  " << guerrero.atq << endl;
        ou << "Vida          ->  " << guerrero.vida<< endl;
        return ou;
    }
};

class Mago : public Personaje {
private:
    string nickname;
    int atq;
    int nivel_magia;
    int vida;

public:
    Mago(string n, int a, int l, int v = 8) {
        this -> nickname = n;
        this -> atq = a;
        this -> nivel_magia = l;
        this -> vida = v;
    }

    int ataque_basico() override {
        int a = nivel_magia*(round(atq / 2));
        cout << "El mago lanza un hechizo; ATQ -> " << a << endl;
        return a;
    }

    int habilidad_especial() override {
        int q = atq * nivel_magia;
        cout << "El mago invoca un meteoro; ATQ -> " << q << endl;
        return q;
    }

    void defensa() override {
        cout << "El mago crea un escudo mágico que absorbe el daño" << endl;
    }

    friend ostream& operator<<(ostream& ou, Mago mago) {
        ou << "Datos de " << mago.nickname << " :" << endl;
        ou << "Clase         -> Mago" << endl;
        ou << "ATQ base      ->  " << mago.atq << endl;
        ou << "Nivel de magia->  " << mago.nivel_magia << endl;
        ou << "Vida          ->  " << mago.vida << endl;
        return ou;
    }
};

class Arquero : public Personaje {
private:
    string nickname;
    bool precision;
    int atq;
    int vida;

public:
    Arquero(string n, int a, bool l, int v = 10) {
        this->nickname = n;
        this->atq = a;
        this->precision = l;
        this->vida = v;
    }

    int ataque_basico() override {
        if (precision){
            int a = (round(atq/2)) * 5;
            cout << "El arquero dispara una flecha precisa; ATQ -> " << a << endl;
            return a;
        } else{
            int a = round(atq / 2);
            cout << "El arquero dispara una flecha; ATQ -> " << a << endl;
            return a;
        }
    }

    int habilidad_especial() override {
        if (precision){
            int q = (atq * 2) * 5;
            cout << "El arquero dispara una lluvia de flechas efectiva; ATQ -> " << q << endl;
            return q;
        } else{
            int q = atq * 2;
            cout << "El arquero dispara una lluvia de flechas; ATQ -> " << q << endl;
            return q;
        }
    }

    void defensa() override {
        cout << "El arquero se esconde entre los arbustos y evita el daño" << endl;
    }

    friend ostream& operator<<(ostream& ou, Arquero arquero) {
        ou << "Datos de " << arquero.nickname << " :" << endl;
        ou << "Clase         -> Arquero" << endl;
        ou << "ATQ base      ->  " << arquero.atq << endl;
        ou << "Vida          ->  " << arquero.vida << endl;
        return ou;
    }
};

int main() {
    Guerrero g("Juan", 100);
    Mago m("Pedro", 80, 3);
    Arquero a("Simon", 60, true);

    cout << g << endl;
    g.ataque_basico();
    g.habilidad_especial();
    g.defensa();

    cout << m << endl;
    m.ataque_basico();
    m.habilidad_especial();
    m.defensa();

    cout << a << endl;
    a.ataque_basico();
    a.habilidad_especial();
    a.defensa();

    return 0;
}