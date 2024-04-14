class Trabajador:
    def __init__(self, nombre="", apellido=""):
        self.nombre = nombre
        self.apellido = apellido
        self.companeros = []

    def agregar_companero(self, trabajador):
        self.companeros.append(trabajador)

    def mostrar_compas(self):
        print(f"Companeros de {self.nombre}:")
        for companero in self.companeros:
            print(f"   - {companero.nombre}")


class Gerente(Trabajador):
    def __init__(self, nombre="", apellido=""):
        super().__init__(nombre, apellido)
        self.trabajadores_cargo = []

    def agregar_trabajador_cargo(self, trabajador):
        self.trabajadores_cargo.append(trabajador)

    def mostrar_trabajadores_cargo(self):
        print(f"Trabajadores a cargo de {self.nombre}:")
        for trabajador in self.trabajadores_cargo:
            print(f"   - {trabajador.nombre}")



trabajador1 = Trabajador("Julian", "Perez")
trabajador2 = Trabajador("Marco", "Gonzalez")
trabajador3 = Trabajador("Carlos", "Flores")

# Crear instancia de Gerente
gerente = Gerente("Yhon", "Lopez")

# Establecer relaciones entre los trabajadores y el gerente
gerente.agregar_companero(trabajador1)
gerente.agregar_companero(trabajador2)
gerente.agregar_companero(trabajador3)

# Establecer relaciones entre los trabajadores bajo el mismo gerente
trabajador1.agregar_companero(trabajador2)
trabajador2.agregar_companero(trabajador1)
trabajador1.agregar_companero(trabajador3)
trabajador3.agregar_companero(trabajador1)
trabajador2.agregar_companero(trabajador3)
trabajador3.agregar_companero(trabajador2)

# Imprimir información sobre las relaciones
gerente.mostrar_compas()
trabajador1.mostrar_compas()
trabajador2.mostrar_compas()
trabajador3.mostrar_compas()
