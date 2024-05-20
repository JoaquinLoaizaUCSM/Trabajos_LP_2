from abc import ABC, abstractmethod
import math

class Figura(ABC):
    @abstractmethod
    def dibujar(self):
        pass

    def calcularArea(self):
        pass

class Circulo(Figura):
    def __init__(self, radio):
        self.radio = radio
        self.area = round(self.calcularArea(),2)

    def __str__(self):
        return (f"Circulo\n"
                f"  radio: {self.radio}\n"
                f"  area: {self.area}\n")

    def dibujar(self):
        print(f"Dibujando circulo de radio: {self.raio}")

    def calcularArea(self):
        self.area = math.pi*(self.radio*self.radio)
        return self.area

class Rectangulo(Figura):
    def __init__(self,base, altura):
        self.base = base
        self.altura = altura
        self.area = round(self.calcularArea(),2)

    def __str__(self):
        return (f"Rectangulo"
                f"  base: {self.base}\n"
                f"  altura: {self.altura}\n"
                f"  area: {self.area}\n")

    def dibujar(self):
        print(f"Dibujando rectangulo de "
              f"base: {self.base} y "
              f"altura: {self.altura}")

    def calcularArea(self):
        self.area = self.base * self.altura
        return self.area

if __name__ == "__main__":
    circulo = Circulo(5)
    print(f"area del circulo: {circulo.area}")
    print(circulo)

    rectangulo = Rectangulo(5, 5)
    print(f"area del rectangulo: {rectangulo.area}")
    print(rectangulo)
