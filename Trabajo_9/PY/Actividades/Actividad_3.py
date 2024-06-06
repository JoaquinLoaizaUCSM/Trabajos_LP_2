from abc import ABC, abstractmethod
class Figura(ABC):
    def calcularArea(self):
        pass

class Circulo(Figura):
    def __init__(self,radio):
        self.radio=radio
        self.pi=3.141592

    def calcularArea(self):
        print(f"Area de la circulo {self.pi*(self.radio * self.radio)}\n")

class Rectangulo(Figura):
    def __init__(self,base,altura):
        self.base=base
        self.altura=altura

    def calcularArea(self):
        print(f"Area de la rectangulo {self.base*self.altura}\n")

class Triangulo(Figura):
    def __init__(self,base,altura):
        self.base=base
        self.altura=altura

    def calcularArea(self):
        print(f"Area de la triangulo {self.base*self.altura/2}\n")

if __name__ == "__main__":
    circulo=Circulo(5)
    triangulo=Triangulo(3,4,)
    rectangulo=Rectangulo(3,5)
    figuras = [circulo,triangulo,rectangulo]

    for figura in figuras:
        figura.calcularArea()
