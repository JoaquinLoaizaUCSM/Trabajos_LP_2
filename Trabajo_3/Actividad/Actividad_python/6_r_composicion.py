class ObjetoCompuesto:
    def __init__(self, nombre):
        self.nombre = nombre

    def get_nombre(self):
        return self.nombre

    def set_nombre(self, nombre):
        self.nombre = nombre


class ClaseBase:
    def __init__(self, nombre_objeto_compuesto):
        self.objeto_compuesto = ObjetoCompuesto(nombre_objeto_compuesto)

    def get_objeto_compuesto(self):
        return self.objeto_compuesto



clase_base = ClaseBase("ObjetoCompuesto1")

# Accede al objeto compuesto
print("Objeto compuesto:", clase_base.get_objeto_compuesto().get_nombre())

# Modifica el objeto compuesto
clase_base.get_objeto_compuesto().set_nombre("NuevoObjetoCompuesto1")

# Accede al objeto compuesto después de la modificación
print("Objeto compuesto después de la modificación:", clase_base.get_objeto_compuesto().get_nombre())
