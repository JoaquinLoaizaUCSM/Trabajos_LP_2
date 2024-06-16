#include <iostream>
using namespace std;

template <typename T>
T calculo_distancia(T d1, T d2, T d3, T d4){
    T dt = ((d2-d1) + (d3-d2) + (d4-d3));
    cout << "La distancia total a recorrer es de " << dt << " km."<< endl;
    return dt;
}

template <typename T>
T tiempo_entrega(T dt, T vel){
    cout << "El tiempo de entrega estimado es de " << dt/vel << " horas."<< endl;
    return dt/vel;
}

template <typename T>
T realizar_informe(){
    T nI, d1, d2, d3, d4, dt, tf, vel;

    cout << "Indique el numero de informe : " << endl;
    cin >> nI;

    cout << "Ingrese la distancia n1 : " << endl;
    cin >> d1;

    cout << "Ingrese la distancia n2 : " << endl;
    cin >> d2;

    cout << "Ingrese la distancia n3 : " << endl;
    cin >> d3;

    cout << "Ingrese la distancia n4 : " << endl;
    cin >> d4;

    dt = calculo_distancia(d1 ,d2 ,d3 ,d4);

    cout << "Ingrese la velocidad a la que se ira : " << endl;
    cin >> vel;

    tf = tiempo_entrega(dt,vel);

    cout << "Informe de ruta: " << endl;
    cout << "Distancia recorrida        -> " << dt << endl;
    cout << "Velocidad del vehiculo     -> " << vel<< endl;
    cout << "Tiempo estimado de entrega -> " << tf << endl;

    return nI;
}

int main(){
    cout << "Ejecucion int :" << endl;
    int n1 = realizar_informe<int>();

    cout << "\nEjecucion double :" << endl;
    double n2 = realizar_informe<double>();

    cout << "\nEjecucion long :" << endl;
    long n3 = realizar_informe<long>();

    return 0;
}