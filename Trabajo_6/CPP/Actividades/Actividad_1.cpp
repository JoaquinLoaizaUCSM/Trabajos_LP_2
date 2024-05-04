#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Estudiante {

public:
    string nombre;
    int edad{};
    int notas{};

};

vector<Estudiante> creacionEstudiantes(int const cantidad)
{
    vector<Estudiante> grupo(cantidad);

    for (int i = 0; i < cantidad; ++i) {
        grupo[i].nombre = "Estudiante " + to_string(i+1);
        grupo[i].edad =  20;
        grupo[i].notas = 10+i;
    };

    return grupo;
}

void imprimirEstudiantes(const vector<Estudiante>& grupo) {
    cout << left << setw(15) << "Nombre" << setw(10) << "Edad" << setw(15) << "Nota Ponderada" << endl;
    cout << "---------------------------------------" << endl;

    for(const auto& estudiante : grupo) {
        cout << left << setw(15) << estudiante.nombre
             << setw(10) << estudiante.edad
             << setw(15) << estudiante.notas << endl;
    }
};

void ordenarEstudiantes(vector<Estudiante>& estudiantes) {
    int n = estudiantes.size();
    for(int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (estudiantes[j].notas < estudiantes[j+1].notas) {
                // Intercambiar estudiantes[j] y estudiantes[j+1]
                Estudiante temp = estudiantes[j];
                estudiantes[j] = estudiantes[j+1];
                estudiantes[j+1] = temp;
            }
        }
    }
}

int main() {
    vector<Estudiante> estudiantes = creacionEstudiantes(5);
    cout << "Lista de estudiantes desordenada"<<endl;
    imprimirEstudiantes(estudiantes);
    ordenarEstudiantes(estudiantes);
    cout << "Lista de estudiantes ordenada"<<endl;
    imprimirEstudiantes(estudiantes);
}
