class ClasePadre:
    def __init__(self, atributo_base):
        self.atributo_base = atributo_base

    def metodo_base(self):
        print("Método de la clase base")

    def get_atributo_base(self):
        return self.atributo_base

    def set_atributo_base(self, atributo_base):
        self.atributo_base = atributo_base


class ClaseDerivada(ClasePadre):
    def __init__(self, atributo_base, atributo_derivada):
        super().__init__(atributo_base)
        self.atributo_derivada = atributo_derivada

    def metodo_derivada(self):
        print("Método de la clase derivada")

    def get_atributo_derivada(self):
        return self.atributo_derivada

    def set_atributo_derivada(self, atributo_derivada):
        self.atributo_derivada = atributo_derivada



objeto_derivada = ClaseDerivada("Atributo Base", "Atributo Derivada")

# Accede a los atributos y métodos heredados de la clase base
print("Atributo base:", objeto_derivada.atributo_base)
objeto_derivada.metodo_base()

# Accede a los atributos y métodos propios de la clase derivada
print()
print("Atributo derivada:", objeto_derivada.get_atributo_derivada())
objeto_derivada.metodo_derivada()
print()
# Modifica el atributo propio de la clase derivada
objeto_derivada.set_atributo_derivada("Nuevo Atributo Derivada")
print("Atributo derivada después de la modificación:", objeto_derivada.get_atributo_derivada())
