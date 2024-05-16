class Movil:
    def __init__(self, marca, modelo, sist_operativo):
        self.marca = marca
        self.modelo = modelo
        self.sist_operativo = sist_operativo

    def __del__(self):
        print("Destructor Movil")

class Telefono(Movil):
    def __init__(self, marca, modelo, sist_operativo):
        Movil.__init__(self, marca, modelo, sist_operativo)

    def __str__(self):
        return (f"Telefono\n"
                f"  Marca: {self.marca}\n"
                f"  Modelo: {self.modelo}\n"
                f"  Sist Operativo: {self.sist_operativo}\n")

    def __del__(self):
        print("Destructor Telefono")

class Tablet(Movil):
    def __init__(self, marca, modelo, sist_operativo):
        Movil.__init__(self, marca, modelo, sist_operativo)

    def __str__(self):
        return (f"Tablet\n"
                f"  Marca: {self.marca}\n"
                f"  Modelo: {self.modelo}\n"
                f"  Sist Operativo: {self.sist_operativo}\n")

    def __del__(self):
        print("Destructor Tablet")


telefono1 = Telefono("Xiaomi", "Redmi", "Android")
print(telefono1)

tablet1 = Tablet("iPap", "air", "apple")
print(tablet1)

del telefono1
del tablet1
