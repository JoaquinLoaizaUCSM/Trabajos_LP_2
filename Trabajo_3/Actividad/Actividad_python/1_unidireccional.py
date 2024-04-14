class Hijo:
    def __init__(self, nombre):
        self.nombre = nombre

    def get_nombre(self):
        return self.nombre

    def set_nombre(self, nombre):
        self.nombre = nombre

class Padre:
    def __init__(self, nombre):
        self.nombre = nombre
        self.hijos = []
        self.num_hijos = 0

    def get_nombre(self):
        return self.nombre

    def set_nombre(self, nombre):
        self.nombre = nombre

    def agregar_hijo(self, hijo):
        if self.num_hijos <= 5:
            self.hijos.append(hijo)
            self.num_hijos += 1

    def imprimir_info(self):
        print(f"Papa: {self.nombre}")
        print("Hijos: ")
        for i in range(self.num_hijos):
            print(f"    {i + 1}. {self.hijos[i].get_nombre()}")

papa1 = Padre("Alvaro")
hijo1 = Hijo("Juan")
hijo2 = Hijo("Jose")
hijo3 = Hijo("Antonio")

papa1.agregar_hijo(hijo1)
papa1.agregar_hijo(hijo2)
papa1.agregar_hijo(hijo3)

papa1.imprimir_info()
