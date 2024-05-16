#include <iostream>

using namespace std;

class cliente{

protected:
    string nombre;
    int telefono{};
    string correo;
    string cuentaBancaria;
    double monto{};

    static string encriptarInformacion(string informacion, int desplazamiento=3) {
        string resultado;
        for (int i = 0; i < informacion.length(); i++) {
            if (isdigit(informacion[i]))
                resultado += char(int(informacion[i] + desplazamiento - 48) % 10 + 48);
            else if (isupper(informacion[i]))
                resultado += char(int(informacion[i] + desplazamiento - 65) % 26 + 65);
            else
                resultado += char(int(informacion[i] + desplazamiento - 97) % 26 + 97);
        }
        return resultado;
    }

public:

    cliente(string nombre, int telefono, const string& correo, const string& cuentaBancaria, double monto){
        this -> nombre = nombre;
        this -> telefono = telefono;
        this -> correo = correo;
        this -> cuentaBancaria = cuentaBancaria;
        this -> monto = monto;
    }


    friend ostream &operator<<(ostream &os, const cliente &cliente) {
        os << "Nombre: " << cliente.nombre << "\n"
           << "Telefono: " << cliente.telefono << "\n"
           << "Correo: " << cliente.correo << "\n"
           << "Cuenta Bancaria: " << cliente.cuentaBancaria << "\n"
           << "Monto: " << cliente.monto;
        return os;
    }
};



class clienteSeguro : public cliente {
private:
    string claveEncriptada;

    static string descriptarInformacion(string informacion, int desplazamiento=3) {
        string resultado;
        for (int i = 0; i < informacion.length(); i++) {
            if (isdigit(informacion[i]))        //verificar si es un digito
                resultado += char(int(informacion[i] - desplazamiento - 48 + 10) % 10 + 48);
            else if (isupper(informacion[i]))   // verificar si es una letra mayuscula
                resultado += char(int(informacion[i] - desplazamiento - 65 + 26) % 26 + 65);
            else                                   // verificar si es una letra minuscula
                resultado += char(int(informacion[i] - desplazamiento - 97 + 26) % 26 + 97);
        }
        return resultado;
    }


public:
    clienteSeguro(string nombre, int telefono, string correo, string cuentaBancaria, double monto, string clave)
            : cliente(encriptarInformacion(nombre), telefono, encriptarInformacion(correo), encriptarInformacion(cuentaBancaria), monto){

        this -> claveEncriptada = encriptarInformacion(std::move(clave));

    }

    string getClaveEncriptada()
    {
        return claveEncriptada;
    }

    static string encriptarInformacion(string informacion, int desplazamiento=3) {
        string resultado;
        for (int i = 0; i < informacion.length(); i++) {
            if (isdigit(informacion[i]))
                resultado += char(int(informacion[i] + desplazamiento - 48) % 10 + 48);
            else if (isupper(informacion[i]))
                resultado += char(int(informacion[i] + desplazamiento - 65) % 26 + 65);
            else
                resultado += char(int(informacion[i] + desplazamiento - 97) % 26 + 97);
        }
        return resultado;
    }

    bool verificarAutenticidad(const string& claveIngresada) {
        return claveIngresada == descriptarInformacion(claveEncriptada);
    }
};



int main(){

    clienteSeguro grossman = clienteSeguro("Juan Perez",
                                           987654321,
                                           "Juan.Perez@gmail.com",
                                           "123456789",
                                           1000.0,
                                           "1234");


    cout << grossman << endl;

    cout << "Clave encriptada: " << grossman.getClaveEncriptada() << endl;

    cout << "Ingrese la clave para verificar la autenticidad:" << endl;
    string claveIngresada;
    cin >> claveIngresada;

    if (grossman.verificarAutenticidad(claveIngresada)) {
        cout << "La clave ingresada es correcta" << endl;
    } else {
        cout << "La clave ingresada es incorrecta" << endl;
    }
}