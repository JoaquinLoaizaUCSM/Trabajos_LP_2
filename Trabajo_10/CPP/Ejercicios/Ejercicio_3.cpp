#include <iostream>
using namespace std;
#include <vector>

template <typename T>

class Ruta{
protected:
    string id_ruta;
    string conductor;
    int num_dis;
    vector<T> distancias = {};
    T dis_total = 0;
    T t_estimado = 0;
    T vel_vehiculo;
    T vehiculo;

public:
    Ruta(string id, string con, T vel, int num = 0){
        this -> id_ruta = id;
        this -> conductor = con;
        this -> vel_vehiculo = vel;
        this -> num_dis = num;
    }

    string &get_id(){
        return id_ruta;
    }

    void vehiculo_asignado(T vehicle){

        this -> vehiculo = vehicle;
        cout << "El vehiculo del conductor " << this -> conductor << " sera el: " << vehicle << endl;

    }

    void ingreso_rutas(){
        T dis;
        for (int i = 1; i < num_dis + 1; i++){
            cout << "Ingrese la distancia n" << i << " a recorrer: " << endl;
            cin >> dis;
            distancias.push_back(dis);
            cout << "Ingresado correctamente. " << endl;
        }
    }

    void calculo_distancia(){
        for (T dis : distancias){
            dis_total += dis;
        };
        cout << "La distancia total a recorrer es de " << dis_total << " km."<< endl;;
    }

    void tiempo_entrega(){
        this -> t_estimado = dis_total/vel_vehiculo;
        cout << "El tiempo de entrega estimado es de " << t_estimado << " horas."<< endl;
    }

    friend ostream& operator << (ostream& rs, Ruta& rute){

        rs << "Datos ruta ID " << rute.id_ruta << " :" << endl;

        rs << "Conductor       -> " << rute.conductor << endl;

        rs << "Vehiculo        -> " << rute.vehiculo << endl;

        rs << "Velocidad       -> " << rute.vel_vehiculo << endl;

        rs << "Distancia       -> " << rute.dis_total << endl;

        rs << "Tiempo estimado -> " << rute.t_estimado << endl;

        return rs;
    }

};

template <typename G>
class Gestion_rutas{
protected:
    vector<Ruta<G>> rutas;

public:
    void agregar_ruta(Ruta<G> &ruta) {
        rutas.push_back(ruta);
    }

    void eliminar_ruta(string id){
        for (int i = 0; i <rutas.size(); i++){
            if (rutas[i].get_id() == id){
                rutas.erase(rutas.begin()+i);
            }
        }
    }

    void buscar_ruta(string id){
        for (int i = 0; i <rutas.size(); i++){
            if (rutas[i].get_id() == id){
                cout << rutas[i];
            }
        }
    }

    void mostrar_rutas() {
        for (Ruta<G> ruta: rutas) {
            cout << ruta << endl;
        }
    }
};

int main(){
    cout << "Esta actividad ya cumplia con lo solicitado al contar con un almacen de objetos de otra clase :) " << endl;

    //Creacion Rutas
    Ruta<int> ruta1("001", "Grossman", 120, 3);
    ruta1.vehiculo_asignado(1234);
    ruta1.ingreso_rutas();
    ruta1.calculo_distancia();
    ruta1.tiempo_entrega();

    Ruta<int> ruta2("002", "Yhosfer", 5, 2);
    ruta2.vehiculo_asignado(5678);
    ruta2.ingreso_rutas();
    ruta2.calculo_distancia();
    ruta2.tiempo_entrega();

    //Ingreso de rutas
    Gestion_rutas<int> gestion;
    gestion.agregar_ruta(ruta1);
    gestion.agregar_ruta(ruta2);

    cout << "Rutas:" << endl;
    gestion.mostrar_rutas();

    //Eliminacion ruta
    gestion.eliminar_ruta("001");

    cout << "Rutas parte 2:" << endl;
    gestion.mostrar_rutas();
    return 0;
}