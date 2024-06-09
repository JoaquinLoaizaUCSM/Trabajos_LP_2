from abc import ABC, abstractmethod

class Forma(ABC):
    @abstractmethod
    def cambiarPropiedades(self):
        pass
    @abstractmethod
    def calcularArea(self):
        pass
    @abstractmethod
    def calcularPerimetro(self):
        pass
    @abstractmethod
    def especificaciones(self):
        pass

class Circulo(Forma):
    def __init__(self, radio):
        self.radio = radio
        self.diametro = 2*radio

    def cambiarPropiedades(self):
        self.radio = int(input("Ingrese nuevo radio -> "))
        self.diametro = self.radio*2

    def calcularArea(self):
        print(f"Area: {3.14*self.radio**2}")

    def calcularPerimetro(self):
        print(f"Perimetro: {3.14*self.diametro}")

    def especificaciones(self):
        print(f"Datos del circulo\n"
              f"Radio: {self.radio}\n"
              f"Diametro: {self.diametro}")
        self.calcularArea()
        self.calcularPerimetro()

class Rectangulo(Forma):
    def __init__(self, base, altura):
        self.base = base
        self.altura = altura

    def cambiarPropiedades(self):
        self.base = int(input("Ingrese nueva base: "))
        self.altura = int(input("Ingrese nueva altura: "))

    def calcularArea(self):
        print(f"Area: {self.altura*self.base}")

    def calcularPerimetro(self):
        print(f"Perimetro: {2*(self.altura+self.base)}")

    def especificaciones(self):
        print(f"Datos del Rectangulo\n"
              f"Base: {self.base}\n"
              f"Altura: {self.altura}")
        self.calcularArea()
        self.calcularPerimetro()

class Triangulo(Forma):
    def __init__(self, base, altura, hipotenusa):
        self.base = base
        self.altura = altura
        self.hipotenusa = hipotenusa

    def cambiarPropiedades(self):
        self.base = int(input("Ingrese nueva base: "))
        self.altura = int(input("Ingrese nueva altura: "))
        self.hipotenusa = int(input("Ingrese nueva hipotenusa"))

    def calcularArea(self):
        print(f"Area: {0.5*(self.altura*self.base)}")

    def calcularPerimetro(self):
        print(f"Perimetro: {self.altura+self.base+self.hipotenusa}")

    def especificaciones(self):
        print(f"Datos del triangulo\n"
              f"Base: {self.base}\n"
              f"Altura: {self.altura}\n"
              f"Hipotenusa; {self.hipotenusa}")
        self.calcularArea()
        self.calcularPerimetro()

class Trapecio(Forma):
    def __init__(self, baseMenor, baseMayor, altura, lado1, lado2):
        self.baseMenor = baseMenor
        self.baseMayor = baseMayor
        self.altura = altura
        self.lado1 = lado1
        self.lado2 = lado2

    def cambiarPropiedades(self):
        self.baseMenor = int(input("Ingrese nueva Base Menor: "))
        self.baseMayor = int(input("Ingrese nueva Base Mayor: "))
        self.altura = int(input("Ingrese nueva altura: "))
        self.lado1 = int(input("Ingrese nuevo lado1: "))
        self.lado2 = int(input("Ingrese nuevo lado2: "))

    def calcularArea(self):
        print(f"Area: {((self.baseMenor + self.baseMayor)*self.altura)/2}")

    def calcularPerimetro(self):
        print(f"Perimetro: {self.lado1+self.lado2+self.baseMayor+self.baseMenor}")

    def especificaciones(self):
        print(f"Datos del Trapecio\n"
              f"Base Mayor: {self.baseMayor}\n"
              f"Base Menor: {self.baseMenor}\n"
              f"Altura: {self.altura}\n"
              f"Lado 1: {self.lado1}\n"
              f"Lado 2: {self.lado2}")
        self.calcularArea()
        self.calcularPerimetro()

def menu():
    print("Crear Figuras\n"
          " 1.Circulo\n"
          " 2.Rectangulo\n"
          " 3.Triangulo\n"
          " 4.Trapecio\n"
          " 0.Salir")


if __name__ == "__main__":
    figuras = []
    while True:
        menu()
        op = int(input("ingrese una Opción: "))
        if op == 1:
            circulo1 = Circulo(1)
            circulo1.cambiarPropiedades()
            figuras.append(circulo1)
            print("Figura Creada")
        elif op == 2:
            rectangulo1 = Rectangulo(5,4)
            rectangulo1.cambiarPropiedades()
            figuras.append(rectangulo1)
            print("Figura Creada")
        elif op == 3:
            triangulo1 = Triangulo(3,4,5)
            figuras.append(triangulo1)
            print("Figura Creada")
        elif op == 4:
            trapecio1 = Trapecio(5,16,4,5,5)
            figuras.append(trapecio1)
            print("Figura Creada")
        elif op == 0:
            break
        else:
            print("Opcion no valida")

    for figura in figuras:
        figura.especificaciones()
        print("\n")
