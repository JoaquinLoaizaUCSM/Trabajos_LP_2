#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Asignatura;

class Estudiante {
private:
    string nombre;
    string direccion;
    string numeroMatricula;
    vector<Asignatura*> asignaturasMatriculadas;
    vector<int> notas;
    vector<int> faltasAsistencia;

public:
    Estudiante(string _nombre, string _direccion, string _numeroMatricula) : nombre(_nombre), direccion(_direccion), numeroMatricula(_numeroMatricula) {}

    // Métodos para acceder y modificar los atributos
    string getNombre() const { return nombre; }
    string getDireccion() const { return direccion; }
    string getNumeroMatricula() const { return numeroMatricula; }
    void matricularAsignatura(Asignatura* asignatura) { asignaturasMatriculadas.push_back(asignatura); }
    void agregarNota(int nota) { notas.push_back(nota); }
    void registrarFaltaAsistencia(int faltas) { faltasAsistencia.push_back(faltas); }
};

class Profesor {
private:
    string nombre;
    string direccion;
    string numeroTelefono;
    vector<Asignatura*> asignaturasImpartidas;

public:
    Profesor(string _nombre, string _direccion, string _numeroTelefono) : nombre(_nombre), direccion(_direccion), numeroTelefono(_numeroTelefono) {}

    // Métodos para acceder y modificar los atributos
    string getNombre() const { return nombre; }
    string getDireccion() const { return direccion; }
    string getNumeroTelefono() const { return numeroTelefono; }
    void asignarAsignatura(Asignatura* asignatura) { asignaturasImpartidas.push_back(asignatura); }
};

class Asignatura {
private:
    string codigo;
    string nombre;
    string descripcion;
    Profesor* profesorAsociado;

public:
    Asignatura(string _codigo, string _nombre, string _descripcion, Profesor* _profesor) : codigo(_codigo), nombre(_nombre), descripcion(_descripcion), profesorAsociado(_profesor) {}

    // Métodos para acceder a los atributos
    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    string getDescripcion() const { return descripcion; }
    Profesor* getProfesorAsociado() const { return profesorAsociado; }
};

int main() {
    // Ejemplo de uso
    Estudiante estudiante("Juan", "Calle A, Ciudad B", "2024001");
    Profesor profesor("Dr. Pérez", "Avenida X, Ciudad Y", "123456789");
    Asignatura asignatura("CS101", "Introducción a la Programación", "Curso introductorio a la programación", &profesor);

    // Matricular estudiante en asignatura
    estudiante.matricularAsignatura(&asignatura);

    return 0;
}
