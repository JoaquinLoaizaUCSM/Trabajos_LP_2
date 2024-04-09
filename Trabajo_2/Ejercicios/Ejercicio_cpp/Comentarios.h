#ifndef ACTIVIDADES_COMENTARIOS_H
#define ACTIVIDADES_COMENTARIOS_H

#include <iostream>
using namespace std;

class IComentarios{
public:
    virtual void mostrar_comentarios() const = 0;
    virtual void anadir_comentario() = 0;
    virtual void eliminar_comentario() = 0;
};

class Comentarios
{
public:
    string comentario;
    string fecha;
    string usuario;

    Comentarios(string com, string date, string user)
    {
        this -> comentario = com;
        this -> fecha = date;
        this -> usuario = user;
    }

    void mostrar_comentarios() const
    {
        cout << "Usuario: " << usuario << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Comentario: " << comentario << endl;
    }

    void anadir_comentario()
    {
        string com;
        string date;
        string user;
        cout << "Ingrese el comentario: ";
        cin >> com;
        cout << "Ingrese la fecha: ";
        cin >> date;
        cout << "Ingrese el usuario: ";
        cin >> user;
        Comentarios nuevo_comentario(com, date, user);
    }

    void eliminar_comentario()
    {
        comentario = "";
        fecha = "";
        usuario = "";
    }
};





#endif //ACTIVIDADES_COMENTARIOS_H
