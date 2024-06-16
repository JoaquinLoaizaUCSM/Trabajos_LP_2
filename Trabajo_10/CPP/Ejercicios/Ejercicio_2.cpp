#include <iostream>
using namespace std;
#include <vector>



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

    template <typename T>
    void ordenamiento_propinas(vector<T> &vct) {
        int tamaño = vct.size();
        for (int i = 0; i < tamaño - 1; i++) {
            for (int j = 0; j < tamaño - i - 1; j++) {
                if (vct[j] > vct[j + 1]) {
                    T temp = vct[j];
                    vct[j] = vct[j + 1];
                    vct[j + 1] = temp;
                }
            }
        }
    }

};

int main(){
    Ruta ruta1("001", "Grossman");
    Ruta ruta2("002", "Joaquin");

    ruta1.vehiculo_asignado(5487);
    ruta2.vehiculo_asignado("Carcocha");

    vector<int> propinitas = {3,2,40,22,55};
    ruta1.ordenamiento_propinas(propinitas);

    cout << "\n";
    for (int i = 0; i < propinitas.size(); i++){
        cout << propinitas[i];
    }
    cout << "\n";

    vector<float> propinitas_flotantes = { 5.4,6.5,88.4,7.5,99.4,99.2};
    ruta2.ordenamiento_propinas(propinitas_flotantes);

    cout << "\n";
    for (int i = 0; i < propinitas_flotantes.size(); i++){
        cout << propinitas_flotantes[i];
    }
    cout << "\n";

    ruta1.designar_horario<double>();
    ruta2.designar_horario<int>();
    return 0;
}