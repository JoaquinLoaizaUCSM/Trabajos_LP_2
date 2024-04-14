#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cliente {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<string> compras;

public:
    Cliente(string _nombre, string _direccion, string _telefono) : nombre(_nombre), direccion(_direccion), telefono(_telefono) {}

    // Métodos para acceder y modificar los atributos
    string getNombre() const { return nombre; }
    string getDireccion() const { return direccion; }
    string getTelefono() const { return telefono; }
    void agregarCompra(string compra) { compras.push_back(compra); }
};

class Producto {
private:
    string codigo;
    string descripcion;
    double precio;
    string proveedor;

public:
    Producto(string _codigo, string _descripcion, double _precio, string _proveedor) : codigo(_codigo), descripcion(_descripcion), precio(_precio), proveedor(_proveedor) {}

    // Métodos para acceder a los atributos
    string getCodigo() const { return codigo; }
    string getDescripcion() const { return descripcion; }
    double getPrecio() const { return precio; }
    string getProveedor() const { return proveedor; }
};

class Venta {
private:
    string numFactura;
    string fecha;
    Cliente* cliente;
    vector<Producto*> productosVendidos;

public:
    Venta(string _numFactura, string _fecha, Cliente* _cliente) : numFactura(_numFactura), fecha(_fecha), cliente(_cliente) {}

    // Métodos para acceder y modificar los atributos
    string getNumFactura() const { return numFactura; }
    string getFecha() const { return fecha; }
    Cliente* getCliente() const { return cliente; }
    void agregarProductoVendido(Producto* producto) { productosVendidos.push_back(producto); }
};

class Pago {
private:
    Cliente* cliente;
    double monto;
    string fecha;

public:
    Pago(Cliente* _cliente, double _monto, string _fecha) : cliente(_cliente), monto(_monto), fecha(_fecha) {}

    // Métodos para acceder a los atributos
    Cliente* getCliente() const { return cliente; }
    double getMonto() const { return monto; }
    string getFecha() const { return fecha; }
};

int main() {
    // Ejemplo de uso
    Cliente cliente("Juan", "Calle A, Ciudad B", "123456789");
    Producto producto("001", "Camisa", 20.99, "Proveedor X");
    Venta venta("F001", "2024-04-13", &cliente);
    Pago pago(&cliente, 50.0, "2024-04-13");

    // Agregar compra al cliente
    cliente.agregarCompra("F001");

    return 0;
}

