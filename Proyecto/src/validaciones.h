#ifndef LP_02_GRUPAL_VALIDACIONES_H
#define LP_02_GRUPAL_VALIDACIONES_H

#include <iostream>


using namespace std;


bool esEntero(string entrada) {
    int inicio = 0;
    bool esValido = true;
    bool tieneSigno = false;

    if (entrada.empty()) {
        esValido = false;
    }

    if (entrada.at(0) == '+' || entrada.at(0) == '-') {
        inicio = 1;
        tieneSigno = true;
    }

    if (tieneSigno && entrada.length() == 1) {
        esValido = false;
    }

    for (int i = inicio; esValido && i < entrada.length(); i++) {
        if (!isdigit(entrada.at(i))) {
            esValido = false;
        }
    }

    return esValido;
}


bool esDoble(string entrada) {
    int inicio = 0;
    bool esValido = true;
    bool tieneSigno = false;
    bool tieneDecimal = false;

    if (entrada.empty()) {
        esValido = false;
    }

    if (entrada.at(0) == '+' || entrada.at(0) == '-') {
        inicio = 1;
        tieneSigno = true;
    }

    if (tieneSigno && entrada.length() == 1) {
        esValido = false;
    }

    for (int i = inicio; esValido && i < entrada.length(); i++) {
        if (!isdigit(entrada.at(i))) {
            if (entrada.at(i) == '.' && !tieneDecimal) {
                tieneDecimal = true;
            } else {
                esValido = false;
            }
        }
    }

    return esValido;
}


int obtenerEntero(const string& mensaje = "Ingresa un número entero:", bool esPositivo = false) {
    bool noEsEntero = true;
    string valorEntrada;

    cout << mensaje;

    while (noEsEntero) {
        try {
            cin >> valorEntrada;
            if (!esEntero(valorEntrada)) {
                throw invalid_argument("El valor ingresado no es un número entero.");
            } else if (esPositivo && stoi(valorEntrada) < 0) {
                throw invalid_argument("El valor ingresado no es un número entero positivo.");
            }
        } catch (invalid_argument &e) {
            cerr << e.what() << endl;
            cerr << "Ingresa un número entero:";
            continue;
        }
        noEsEntero = false;
    }
    return stoi(valorEntrada);
}


double obtenerDoble(const string& mensaje = "Ingresa un número real:", bool esPositivo = false) {
    bool noEsDoble = true;
    string valorEntrada;

    cout << mensaje;

    while (noEsDoble) {
        try {
            cin >> valorEntrada;
            if (!esDoble(valorEntrada)) {
                throw invalid_argument("El valor ingresado no es un número real.");
            } else if (esPositivo && stod(valorEntrada) < 0) {
                throw invalid_argument("El valor ingresado no es un número real positivo.");
            }
        } catch (invalid_argument &e) {
            cerr << e.what() << endl;
            cerr << "Ingresa un número real:";
            continue;
        }
        noEsDoble = false;
    }
    return stod(valorEntrada);
}


string obtenerCadena(const string& mensaje = "Ingresa una cadena de texto:") {
    string valorEntrada;

    if (!mensaje.empty()) {
        cout << mensaje;
    }

    cin >> valorEntrada;

    return valorEntrada;
}

#endif // LP_02_GRUPAL_VALIDACIONES_H
