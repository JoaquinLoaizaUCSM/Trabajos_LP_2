#ifndef LP_04_ACT_03_H
#define LP_04_ACT_03_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Docente {
private:
    string nombre;
    string apellido;
    int dni;
    string correo;
public:
    Docente(string nombre="", string apellido="", string correo="") {
        this->nombre = nombre;
        this->apellido = apellido;
        this->correo = correo;
    }
    string getNombre() {
        return nombre;
    }
    string getApellido() {
        return apellido;
    }
};

class Curso {
private:
    string nombre;
    int codigo;
    string descripcion;

public:
    Curso(string n, int codigo, string descripcion) {
        this->nombre = n;
        this->codigo = codigo;
        this->descripcion = descripcion;
    }
    string getNombre() {
        return nombre;
    }
    string getDescripcion() {
        return descripcion;
    }
};

class Asociacion {
private:
    Estudiante* estudiante_;
    Docente* docente_;
    Curso* curso_;

public:
    Asociacion(Estudiante* est, Docente* doc, Curso* curso) {
        this->estudiante_ = est;
        this->docente_ = doc;
        this->curso_ = curso;
    }
    Estudiante* getEstudiante() {
        return estudiante_;
    }
    Docente* getDocente() {
        return docente_;
    }
    Curso* getCurso() {
        return curso_;
    }
};


#endif
