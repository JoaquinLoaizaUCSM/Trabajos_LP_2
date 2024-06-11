class Producto:
    def __init__(self, nombre, precio, cantidad):
        self.nombre = nombre
        self.precio = precio
        self.cantidad = cantidad

    def valor_inventario(self):
        return self.precio * self.cantidad

    def aplicar_descuento(self, porcentaje):
        self.precio *= (1 - porcentaje)

    def __str__(self):
        return f"{self.nombre}: {self.cantidad} unidades a {self.precio} cada una"
class Electronico(Producto):
    def aplicar_descuento(self, porcentaje):
        porcentaje_extra = 0.05  # 5% de descuento adicional
        super().aplicar_descuento(porcentaje + porcentaje_extra)

class Ropa(Producto):
    def aplicar_descuento(self, porcentaje):
        if porcentaje > 0.2:  # Máximo descuento del 20%
            porcentaje = 0.2
        super().aplicar_descuento(porcentaje)

class Alimento(Producto):
    def valor_inventario(self):
        valor_base = super().valor_inventario()
        return valor_base * 0.9  # Suponiendo una reducción del 10%

    def aplicar_descuento(self, porcentaje):
        porcentaje_extra = 0.1  # 10% de descuento adicional
        super().aplicar_descuento(porcentaje + porcentaje_extra)
# Creación de productos
tv = Electronico("Televisor", 1200, 30)
camisa = Ropa("Camisa", 40, 50)
manzana = Alimento("Manzana", 0.5, 500)

tv.aplicar_descuento(0.1)
camisa.aplicar_descuento(0.25)
manzana.aplicar_descuento(0.05)

print(tv)
print(camisa)
print(manzana)

