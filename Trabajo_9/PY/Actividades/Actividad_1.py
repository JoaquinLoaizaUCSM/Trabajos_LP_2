from abc import ABC, abstractmethod

class Animal(ABC):
    @abstractmethod
    def hacerSonidos(self):
        print("Hacer sonidos")

class Perro(Animal):
    def __init__(self, nombre, edad, raza):
        self.nombre = nombre
        self.edad = edad
        self.raza = raza

    def hacerSonidos(self):
        print("Guau")


if __name__ == "__main__":
    print("Dinámico (HEAP):")
    perrito = Perro("Perrito", 180, "Chitsu")
    perrito.hacerSonidos()

    print("Estático (STACK):")
    animalito = Perro("waos", 20, "Bulldog")
    animalito.hacerSonidos()