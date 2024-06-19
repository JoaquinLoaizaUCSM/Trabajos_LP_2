#include <iostream>
using namespace std;

class Ruta{
protected:
    string id_ruta;
    string conductor;


public:
    Ruta(string id, string con){
        this -> id_ruta = id;
        this -> conductor = con;
    }

    template<typename T>
    void vehiculo_asignado(T vehicle){
        cout << "El vehiculo del conductor " << this -> conductor << " sera el: " << vehicle << endl;
    }

    template<typename G>
    void designar_horario(){
        G dis_total;
        cout <<"Ingrese la distancia total: " << endl;
        cin >> dis_total;
        if(dis_total<100){
            cout << "La entrega se realizará el jueves." << endl;
        } else{
            if(dis_total>101.5){
                cout << "La entrega se realizará el viernes." << endl;
            }
        }
    }

};

int main(){
    Ruta ruta1("001", "Grossman");
    Ruta ruta2("002", "Joaquin");

    ruta1.vehiculo_asignado(5487);
    ruta2.vehiculo_asignado("Carcocha");


    ruta1.designar_horario<double>();
    ruta2.designar_horario<int>();
    return 0;
}