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
        try {
            int code, price, cant;
            string name;

            switch (dato) {
                case 0:
                    cin >> code;
                    if (!isdigit(code)) {
                        throw invalid_argument("Dato invalido. ");
                    }
                    this->codigo = code;
                    break;
                case 1:
                    cin >> name;
                    this->nombre = name;
                    if (!isdigit(code)) {
                        throw invalid_argument("Dato invalido. ");
                    }
                    break;
                case 2:
                    cin >> price;
                    this->precio = price;
                    if (!isdigit(code)) {
                        throw invalid_argument("Dato invalido. ");
                    }
                    break;
                case 3:
                    cin >> cant;
                    this->stock = cant;
            }
        }
        catch (invalid_argument &e){
            cerr << "Error. " << e.what() << endl;
            exit(EXIT_FAILURE);
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
        try {
            ofstream registroProductos("C:\\Userds\\USER\\Desktop\\Archivos\\Proyectos\\Registrossss", ios::out);
            if (!registroProductos) {
                throw string("No se pudo abrir el archivo chivo jajaja");
            }
            for (Producto p: productos) {
                registroProductos << p;
            }
            registroProductos.close();
        }
        catch(string &chivo){
            cerr << "Error Chivo. " << endl;
            exit(EXIT_FAILURE);
        }
    }

    void actualizar_registro_binary(){
        try {
            ofstream registroProductos("Trabajo_11/CPP/Actividades/Registros_bin.dat", ios::out | ios::binary);
            if (!registroProductos) {
                throw string("Chivo...");
            }
            for (Producto p: productos) {
                registroProductos.write(reinterpret_cast<char *>(&p), sizeof(p));
            }
        }
        catch (string &error){
            cerr << "error  .... " <<endl;
            exit(EXIT_FAILURE);

        }
    }
    void leer_registro_binario() {
        ifstream registroProductos("Trabajo_11/CPP/Actividades/Registros_bin.dat", ios::in | ios::binary);
        if (!registroProductos) {
            cerr << "Nose pudo abrir el archivo" << endl;
            exit(EXIT_FAILURE);
        }
        for (Producto p: productos) {
            registroProductos.read(reinterpret_cast<char*>(&p),sizeof(p));
        }

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

    brocoli.actualizar_info(2);

    Gestor gestorcito(2);

    gestorcito.agregar_producto(brocoli);
    gestorcito.agregar_producto(mani);
    gestorcito.agregar_producto(crema);


    gestorcito.venta(2023,5);

    gestorcito.venta(2023,3);
    gestorcito.actualizar_registro_binary();
    gestorcito.leer_registro_binario();



    return 0;
}
