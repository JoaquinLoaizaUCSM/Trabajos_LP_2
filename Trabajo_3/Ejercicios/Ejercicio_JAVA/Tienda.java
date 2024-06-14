package Trabajo_5.Ejercicios;

import java.util.ArrayList;
import java.util.Date;

class Cliente {
    private String nombre;
    private String direccion;
    private String telefono;
    private ArrayList<Venta> compras;

    public Cliente(String nombre, String direccion, String telefono, ArrayList<Venta> compras) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.compras = compras;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public ArrayList<Venta> getCompras() {
        return compras;
    }

    public void setCompras(ArrayList<Venta> compras) {
        this.compras = compras;
    }

}

class Producto {
    private String codigo;
    private String descripcion;
    private double precio;
    private String proveedor;

    public Producto(String codigo, String descripcion, double precio, String proveedor) {
        this.codigo = codigo;
        this.descripcion = descripcion;
        this.precio = precio;
        this.proveedor = proveedor;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public String getProveedor() {
        return proveedor;
    }

    public void setProveedor(String proveedor) {
        this.proveedor = proveedor;
    }


}

class Venta {
    private String numeroFactura;
    private Date fecha;
    private Cliente cliente;
    private ArrayList<Producto> productosVendidos;

    public Venta(String numeroFactura, Date fecha, Cliente cliente, ArrayList<Producto> productosVendidos) {
        this.numeroFactura = numeroFactura;
        this.fecha = fecha;
        this.cliente = cliente;
        this.productosVendidos = productosVendidos;
    }

    public String getNumeroFactura() {
        return numeroFactura;
    }

    public void setNumeroFactura(String numeroFactura) {
        this.numeroFactura = numeroFactura;
    }

    public Date getFecha() {
        return fecha;
    }

    public void setFecha(Date fecha) {
        this.fecha = fecha;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public ArrayList<Producto> getProductosVendidos() {
        return productosVendidos;
    }

    public void setProductosVendidos(ArrayList<Producto> productosVendidos) {
        this.productosVendidos = productosVendidos;
    }
}

class Pago {
    private Cliente cliente;
    private Venta venta;
    private double monto;
    private Date fecha;

    public Pago(Cliente cliente, Venta venta, double monto, Date fecha) {
        this.cliente = cliente;
        this.venta = venta;
        this.monto = monto;
        this.fecha = fecha;
    }


    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public Venta getVenta() {
        return venta;
    }

    public void setVenta(Venta venta) {
        this.venta = venta;
    }

    public double getMonto() {
        return monto;
    }

    public void setMonto(double monto) {
        this.monto = monto;
    }

    public Date getFecha() {
        return fecha;
    }

    public void setFecha(Date fecha) {
        this.fecha = fecha;
    }
}

class Tiendas {
    private ArrayList<Cliente> clientes;
    private ArrayList<Producto> productos;
    private ArrayList<Venta> ventas;
    private ArrayList<Pago> pagos;

    public Tiendas(ArrayList<Cliente> clientes, ArrayList<Producto> productos, ArrayList<Venta> ventas, ArrayList<Pago> pagos) {
        this.clientes = clientes;
        this.productos = productos;
        this.ventas = ventas;
        this.pagos = pagos;
    }

    // Métodos para agregar_empleado clientes, productos, ventas y pagos

    public void agregarCliente(Cliente cliente) {
        if (!clientes.contains(cliente)) {
            clientes.add(cliente);
            System.out.println("Cliente agregado.");
        }
    }

    public void eliminarCliente(Cliente cliente) {
        clientes.remove(cliente);
        System.out.println("Cliente eliminado.");
    }

    public void agregarProducto(Producto producto) {
        if (!productos.contains(producto)) {
            productos.add(producto);
            System.out.println("Producto agregado.");
        }
    }

    public void agregarVenta(Venta venta) {
        if (!ventas.contains(venta)) {
            ventas.add(venta);
            System.out.println("Venta agregada.");
        }
    }

    public void agregarPago(Pago pago) {
        if (!pagos.contains(pago)) {
            pagos.add(pago);
            System.out.println("Pago realizado.");
        }
    }


    public ArrayList<Cliente> getClientes() {
        return clientes;
    }

    public void setClientes(ArrayList<Cliente> clientes) {
        this.clientes = clientes;
    }

    public ArrayList<Producto> getProductos() {
        return productos;
    }

    public void setProductos(ArrayList<Producto> productos) {
        this.productos = productos;
    }

    public ArrayList<Venta> getVentas() {
        return ventas;
    }

    public void setVentas(ArrayList<Venta> ventas) {
        this.ventas = ventas;
    }

    public ArrayList<Pago> getPagos() {
        return pagos;
    }

    public void setPagos(ArrayList<Pago> pagos) {
        this.pagos = pagos;
    }
}

public class Tienda{
    public static void main(String[] args) {
        ArrayList<Cliente> clientes = new ArrayList<>();
        ArrayList<Producto> productos = new ArrayList<>();
        ArrayList<Venta> ventas = new ArrayList<>();
        ArrayList<Pago> pagos = new ArrayList<>();

        Tiendas tiendas = new Tiendas(clientes, productos, ventas, pagos);
        Cliente cliente1 = new Cliente("Cliente1", "Direccion1", "Telefono1", new ArrayList<>());
        Cliente cliente2 = new Cliente("Cliente2", "Direccion2", "Telefono2", new ArrayList<>());
        Producto producto1 = new Producto("Codigo1", "Descripcion1", 100.0, "Proveedor1");
        Producto producto2 = new Producto("Codigo2", "Descripcion2", 200.0, "Proveedor2");
        Venta venta1 = new Venta("Factura1", new Date(), cliente1, new ArrayList<>());
        Venta venta2 = new Venta("Factura2", new Date(), cliente2, new ArrayList<>());
        Pago pago1 = new Pago(cliente1, venta1, 100.0, new Date());
        Pago pago2 = new Pago(cliente2, venta2, 200.0, new Date());

        tiendas.agregarCliente(cliente1);
        tiendas.agregarCliente(cliente2);
        tiendas.agregarProducto(producto1);
        tiendas.agregarProducto(producto2);
        tiendas.agregarVenta(venta1);
        tiendas.agregarVenta(venta2);
        tiendas.agregarPago(pago1);
        tiendas.agregarPago(pago2);

        // Accede a los clientes de la tienda
        System.out.println("Primer cliente: " + tiendas.getClientes().get(0).getNombre());
        System.out.println("Segundo cliente: " + tiendas.getClientes().get(1).getNombre());

        // Modifica y elimina clientes de la tienda
        cliente1.setNombre("NuevoCliente1");
        tiendas.eliminarCliente(cliente2);

        // Accede a los clientes de la tienda después de las modificaciones
        System.out.println("Primer cliente después de las modificaciones: " + tiendas.getClientes().get(0).getNombre());
    }

}
