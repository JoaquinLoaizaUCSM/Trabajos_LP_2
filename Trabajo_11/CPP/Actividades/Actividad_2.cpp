#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Producto {
protected:
    int codigo;
    string nombre;
    int precio;
    int stock;

public:
    Producto(int code, string name, int price, int cant) {
        this->codigo = code;
        this->nombre = name;
        this->precio = price;
        this->stock = cant;
    }

    int get_Stock(){
        return stock;
    }

    string get_Nombre(){
        return nombre;
    }
    int get_Codigo(){
        return codigo;
    }

    void actualizar_info(int dato){
        int code, price, cant;
        string name;

        switch (dato) {
            case 0:
                cin >> code;
                this -> codigo = code;
                break;
            case 1:
                cin >> name;
                this -> nombre = name;
                break;
            case 2:
                cin >> price;
                this -> precio = price;
                break;
            case 3:
                cin >> cant;
                this -> stock = cant;
        }
    }

    void venta_producto(int cantidad){
        cout << "Se vendieron " << cantidad << " " + nombre << "." <<endl;
        this -> stock -= cantidad;
    }

    friend ostream& operator << (ostream& os, Producto& p){
        os << "\n";
        os << "Info producto n " << p.codigo << endl;
        os << "Nombre producto     -> " << p.nombre <<  endl;
        os << "Precio producto     -> " << p.precio << endl;
        os << "Cantidad disponible -> " << p.stock << endl;
        return os;
    }

};

class Gestor {
protected:
    vector <Producto> productos = {};
    int n_caja;

public:
    Gestor(int n){
        this -> n_caja = n;
    }

    void agregar_producto(Producto p){
        cout << "El producto -> " << p.get_Nombre() << " se agrego correctamente." << endl;
        productos.push_back(p);
        actualizar_registro();
    }

    void venta(int code, int cant){
        for (Producto &p : productos){
            if (p.get_Codigo() == code){
                p.venta_producto(cant);
            }
        }
        actualizar_registro();
    }


    void actualizar_registro() {
            ofstream registroProductos("Trabajo_11/CPP/Actividades/Registros.txt", ios::out);
            if (!registroProductos) {
                exit(EXIT_FAILURE);
            }
            for (Producto p: productos) {
                registroProductos << p;
            }
            registroProductos.close();
        }
        

    void inventario(){
        cout << "Inventario completo: " << endl;
        for (Producto p : productos){
            cout << p;
        }
    }


};



int main() {
    Producto brocoli(2023,"Brocoli",199,10);
    Producto mani(2845,"Mani",2000,25);
    Producto crema(27777,"Crema",285,4);


    Gestor gestorcito(2);

    gestorcito.agregar_producto(brocoli);
    gestorcito.agregar_producto(mani);
    gestorcito.agregar_producto(crema);


    gestorcito.venta(2023,5);

    gestorcito.venta(2023,3);




    return 0;
}
