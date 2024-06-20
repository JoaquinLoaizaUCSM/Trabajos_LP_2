#include <iostream>
#include <fstream>
using namespace std;

int main(){
    try {
        string name;
        cout << "Ingrese el nombre del archivo a ejecutar: " << endl;
        cin >> name;
        ifstream archivito("Trabajo_11/CPP/Ejercicios/" + name + ".txt", ios::in);

        if (!archivito) {
            throw string("No se abrio correctamente.");
        }

        string linea;
        int n_linea = 0;
        while (getline(archivito, linea)){
            n_linea++;
            cout << "Linea " << n_linea << " : " << linea << endl;
        }

        archivito.close();


    } catch (const string& e){
        cout << "Excepcion capturada: " << e << endl;
    }



    return 0;
};
