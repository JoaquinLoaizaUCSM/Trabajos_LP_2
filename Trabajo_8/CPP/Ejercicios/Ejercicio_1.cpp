#include <iostream>
using namespace std;

//Interfaz
class Figura{
    //El igual a 0 es para que en la clase interfaz no sea necesario dar uso al método
    //Es una buena práctica el uso del const y al fin y al cabo no se va modificar el objeto
    virtual void dibujar() const = 0;
    //En este caso el const no encajaría ya que modificaremos al objeto
    virtual void calculo_area() = 0;
};


//Clases Derivadas
class Circulo : public Figura{
private:
    int radio;
    double const pi = 3.1415;
    float area;

public:
    Circulo(int radius, float erea = 0){
        this -> radio = radius;
        this -> area = erea;
    }

    void dibujar() const override{
        cout << "El circulo de radio " << this -> radio << " fue correctamente dibujado." << endl;
    }

    void calculo_area() override{
        this -> area = pi*(radio*radio);
        cout << "Area calculada correctamente." << endl;
    }

    friend ostream& operator <<(ostream& os, Circulo C_01){
        os << "Caracteristicas del circulo:" << endl;
        os << "Radio -> " << C_01.radio << endl;
        os << "Area  -> " << C_01.area << endl;
        return os;
    }
};


class Rectangulo : public Figura{
private:
    float base;
    float altura;
    float area;

public:
    Rectangulo(float bese, float high, float erea = 0){
        this -> base = bese;
        this -> altura = high;
        this -> area = erea;
    }

    void dibujar() const override{
        cout << "El Rectangulo con base " << this -> base << " y altura " << this -> altura << " fue fibujado." << endl;
    }

    void calculo_area() override{
        this ->  area = base * altura;
        cout << "Area calculada correctamente." << endl;
    }

    friend ostream& operator <<(ostream& os, Rectangulo R_01){
        os << "Caracteristicas del Rectangulo:" << endl;
        os << "Base    -> " << R_01.base << endl;
        os << "Altura  -> " << R_01.altura << endl;
        os << "Area    -> " << R_01.area << endl;
        return os;
    }
};


class Triangulo : public Figura{
private:
    float base;
    float altura;
    float area;

public:
    Triangulo(float bese, float high, float erea = 0){
        this -> base = bese;
        this -> altura = high;
        this -> area = erea;
    }

    void dibujar() const override{
        cout << "El Triangulo con base " << this -> base << " y altura " << this -> altura << " fue fibujado." << endl;
    }

    void calculo_area() override{
        this ->  area = (base * altura)/2;
        cout << "Area calculada correctamente." << endl;
    }

    friend ostream& operator <<(ostream& os, Triangulo T_01){
        os << "Caracteristicas del Triangulo:" << endl;
        os << "Base    -> " << T_01.base << endl;
        os << "Altura  -> " << T_01.altura << endl;
        os << "Area    -> " << T_01.area << endl;
        return os;
    }
};


int main() {
    cout << "Prueba:\n" << endl;

    Circulo circle_01(5);
    circle_01.dibujar();
    circle_01.calculo_area();
    cout << circle_01 << endl;

    Rectangulo rectangle_01(5,10);
    rectangle_01.dibujar();
    rectangle_01.calculo_area();
    cout << rectangle_01 << endl;

    Triangulo Triangle_01(5,4);
    Triangle_01.dibujar();
    Triangle_01.calculo_area();
    cout << Triangle_01 << endl;
    return 0;
}