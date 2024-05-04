#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estudiante {

public:
    string nombre;
    int edad;
    float promedio;

    explicit Estudiante(string nombre="", int edad=0, float promedio=0){
        this->nombre = nombre;
        this->edad = edad;
        this->promedio = promedio;
    }

    friend ostream& operator<<(ostream& os, const Estudiante& estudiante) {
        return os << "Nombre: " << estudiante.nombre
                  << ", Edad: " << estudiante.edad
                  << ", Nota: " << estudiante.promedio;
    }

    bool operator < (const Estudiante &otroEstudiante) const  {
        if (promedio < otroEstudiante.promedio) {
            return true;
        } else
            return false;
    }

    bool operator > (const Estudiante &otroEstudiante) const  {
        if (promedio > otroEstudiante.promedio) {
            return true;
        } else
            return false;
    }
};

class Grupo{
public:
    vector<Estudiante> alumnos;
    int cantidad;

    Grupo( vector<Estudiante> alumnos, int cantidad){
        this->alumnos= alumnos;
        this->cantidad = cantidad;
    }

    friend ostream& operator<<(ostream& os, const Grupo& grupo) {
        for (const auto& estudiante : grupo.alumnos) {
            os << estudiante << endl;
        }
        return os;
    }


    void agregar_alumno(string& nombre, int edad, float promedio) {
        if(alumnos.size() == cantidad) {
            alumnos.push_back(Estudiante(nombre, edad, promedio));
        }
        else {
            cout << "No se puede agregar más alumnos" << endl;
        }
    }

    void ordenarEstudiantes() {
        int n = alumnos.size();
        for(int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (alumnos[j].promedio < alumnos[j+1].promedio) {
                    // Intercambiar estudiantes[j] y estudiantes[j+1]
                    Estudiante temp = alumnos[j];
                    alumnos[j] = alumnos[j+1];
                    alumnos[j+1] = temp;
                }
            }
        }
    }

    float promedio_grupo()  {
        float sum = 0;
        int count = 0;
        for(const auto& alumno : alumnos) {
            sum += alumno.promedio;
            ++count;
        }
        return  (sum/count);
    }

    Estudiante mejor_promedio() {

        Estudiante mejor = alumnos[0];

        for (const auto& alumno : alumnos) {
            if (alumno.promedio > mejor.promedio) {
                mejor = alumno;
            }
        }
        return mejor;
    }
};




vector<Estudiante> creacionEstudiantes(int  cantidad)
{
    vector<Estudiante> grupo(cantidad);

    for (int i = 0; i < cantidad; ++i) {
        grupo[i].nombre = "Estudiante " + to_string(i+1);
        grupo[i].edad =  20;
        grupo[i].promedio = 10+i;
    };

    return grupo;
};


int main() {
    vector<Estudiante> grupo = creacionEstudiantes(5);
    Grupo grupo1(grupo, 5);

    cout << "Grupo 1: " << endl;
    cout << grupo1 << endl;

    grupo1.ordenarEstudiantes();
    cout << "Grupo 1 ordenado por promedio: " << endl;
    cout << grupo1 << endl;

    cout << "Promedio del grupo: " << grupo1.promedio_grupo() << endl;
    cout << endl;

    Estudiante estudiantePrimer = grupo1.mejor_promedio();
    cout << "Mejor promedio: " << estudiantePrimer << endl;
}