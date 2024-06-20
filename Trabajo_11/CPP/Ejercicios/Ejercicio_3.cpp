#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include <sstream>

class Persona {
protected:
    string nombre;
    int edad;
    string direccion;

public:
    Persona(string name, int age, string direc) {
        this->nombre = name;
        this->edad = age;
        this->direccion = direc;
    }

    int get_Edad(){
        return edad;
    }

    string get_Nombre(){
        return nombre;
    }
    string get_Codigo(){
        return direccion;
    }

    void actualizar_info(int dato) {
        int edad;
        string name, direc;

        switch (dato) {
            case 0:
                cin >> edad;
                this->edad = edad;
                break;

            case 1:
                cin >> name;
                this->nombre = name;
                break;

            case 2:
                cin >> direc;
                this->direccion = direc;
                break;

        }
    }
    string serializar() {
        ostringstream oss;
        oss << nombre << " " << edad << " " << direccion;
        return oss.str();
    }

    void deserializar(const string& data){
        istringstream iss(data);
        iss >> nombre >> edad >> direccion;
    }


    void actualizar_registro_binary(string &data){
        ofstream registroPersonas("Trabajo_11/CPP/Actividades/Registros_bin.dat", ios::out | ios::binary);
        if (!registroPersonas) {
            cerr << "Nose pudo abrir el archivo" << endl;
            exit(EXIT_FAILURE);
        }
        registroPersonas.write(reinterpret_cast<char*>(&data), sizeof(data));
    }

};


int main() {
    Persona p1("Grossman", 19, "123 sjl");
    cout << "Persona inicial: " << p1.serializar() << endl;


    cout << "Actualiza la edad: ";
    p1.actualizar_info(0);
    cout << "Persona actualizada: " << p1.serializar() << endl;


    string data = p1.serializar();
    cout << "Datos serializados: " << data << endl;


    p1.actualizar_registro_binary(data);


    Persona p2("", 0, "");
    p2.deserializar(data);
    cout << "Persona deserializada: " << p2.serializar() << endl;

    return 0;
}
