#ifndef ACTIVIDADES_GESTORARCHIVOS_H
#define ACTIVIDADES_GESTORARCHIVOS_H

#include <iostream>
using namespace std;

class IGestorArchivos{
public:
    virtual void leer(string) const = 0;
    virtual void escribir(string) = 0;
    virtual void eliminar(string) = 0;
    virtual void enviar(string) = 0;

};


class GestorArchivos : public IGestorArchivos{

public:
    void leer(string) const override;
    void escribir(string) override;
    void eliminar(string) override;
    void enviar(string) override;
};


void GestorArchivos::leer(string ubicasion) const
{
    cout << "Leyendo Archivo" << endl;
}

void GestorArchivos::escribir(string ubicasion)
{
    cout << "Escribiendo Archivo" << endl;
}


void GestorArchivos::eliminar(string ubicasion)
{
    cout << "Eliminando Archivo" << endl;
}


void GestorArchivos::enviar(string ubicasion)
{
    cout << "Enviando Archivo" << endl;
}


#endif //ACTIVIDADES_GESTORARCHIVOS_H
