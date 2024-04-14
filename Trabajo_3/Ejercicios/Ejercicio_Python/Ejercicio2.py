from datetime import datetime

class Pago:
    def __init__(self, cliente, venta, monto, fecha):
        self.cliente = cliente
        self.venta = venta
        self.monto = monto
        self.fecha = fecha

class Tiendas:
    def __init__(self):
        self.clientes = []
        self.productos = []
        self.ventas = []
        self.pagos = []

    def agregarCliente(self, cliente):
        if cliente not in self.clientes:
            self.clientes.append(cliente)
            print("Cliente agregado.")
        else:
            print("El cliente ya existe.")

    def eliminarCliente(self, cliente):
        if cliente in self.clientes:
            self.clientes.remove(cliente)
            print("Cliente eliminado.")
        else:
            print("El cliente no existe.")

    def agregarProducto(self, producto):
        if producto not in self.productos:
            self.productos.append(producto)
            print("Producto agregado.")
        else:
            print("El producto ya existe.")

    def agregarVenta(self, venta):
        if venta not in self.ventas:
            self.ventas.append(venta)
            print("Venta agregada.")
        else:
            print("La venta ya existe.")

    def agregarPago(self, pago):
        if pago not in self.pagos:
            self.pagos.append(pago)
            print("Pago realizado.")
        else:
            print("El pago ya existe.")

class Cliente:
    def __init__(self, nombre, direccion, telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono

class Producto:
    def __init__(self, codigo, descripcion, precio, proveedor):
        self.codigo = codigo
        self.descripcion = descripcion
        self.precio = precio
        self.proveedor = proveedor

class Venta:
    def __init__(self, factura, fecha, cliente, productos):
        self.factura = factura
        self.fecha = fecha
        self.cliente = cliente
        self.productos = productos

# Creación de la instancia de Tiendas
tiendas = Tiendas()

# Creación de instancias de Cliente, Producto, Venta y Pago
cliente1 = Cliente("Cliente1", "Direccion1", "Telefono1")
cliente2 = Cliente("Cliente2", "Direccion2", "Telefono2")
producto1 = Producto("Codigo1", "Descripcion1", 100.0, "Proveedor1")
producto2 = Producto("Codigo2", "Descripcion2", 200.0, "Proveedor2")
venta1 = Venta("Factura1", datetime.now(), cliente1, [])
venta2 = Venta("Factura2", datetime.now(), cliente2, [])
pago1 = Pago(cliente1, venta1, 100.0, datetime.now())
pago2 = Pago(cliente2, venta2, 200.0, datetime.now())

# Agregar clientes, productos, ventas y pagos a la tienda
tiendas.agregarCliente(cliente1)
tiendas.agregarCliente(cliente2)
tiendas.agregarProducto(producto1)
tiendas.agregarProducto(producto2)
tiendas.agregarVenta(venta1)
tiendas.agregarVenta(venta2)
tiendas.agregarPago(pago1)
tiendas.agregarPago(pago2)

# Acceder a los clientes de la tienda
print("Primer cliente: " + tiendas.clientes[0].nombre)
print("Segundo cliente: " + tiendas.clientes[1].nombre)

# Modificar y eliminar clientes de la tienda
cliente1.nombre = "NuevoCliente1"
tiendas.eliminarCliente(cliente2)

# Acceder a los clientes de la tienda después de las modificaciones
print("Primer cliente después de las modificaciones: " + tiendas.clientes[0].nombre)
