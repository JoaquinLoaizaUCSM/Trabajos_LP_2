from abc import ABC, abstractmethod
class Figura(ABC):
    def calcularArea(self):
        pass
    def calcularPerimetro(self):
        pass

class Circulo(Figura):
    def __init__(self,radio):
        self.radio=radio
        self.pi=3.1415

    def calcularArea(self):
        print(f"Area de la circulo: {round(self.pi*(self.radio * self.radio),2)}")

    def calcularPerimetro(self):
        print(f"Perimetro de la circulo: {round(2*(self.pi*self.radio),2)}\n")

class Rectangulo(Figura):
    def __init__(self,base,altura):
        self.base=base
        self.altura=altura

    def calcularArea(self):
        print(f"Area de la rectangulo: {self.base*self.altura}")

    def calcularPerimetro(self):
        print(f"Perimetro de la rectangulo: {(self.base+self.altura)*2}\n")

class Triangulo(Figura):
    def __init__(self,base,altura,hipotenusa):
        self.base=base
        self.altura=altura
        self.hipotenusa=hipotenusa

    def calcularArea(self):
        print(f"Area de la triangulo: {self.base*self.altura/2}")

    def calcularPerimetro(self):
        print(f"Perimetro de la triangulo: {self.base+self.altura+self.hipotenusa}\n")

if __name__ == "__main__":
    circulo=Circulo(5)
    triangulo=Triangulo(3,4,5)
    rectangulo=Rectangulo(3,5)
    figuras = [circulo,triangulo,rectangulo]

    for figura in figuras:
        figura.calcularArea()
        figura.calcularPerimetro()

