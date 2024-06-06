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

    def __str__(self):
        return (f"Nombre: {self.nombre} "
                f"Edad: {self.edad} "
                f"Raza: {self.raza}")

    def hacerSonidos(self):
        print("Guau")

class Gato(Animal):
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def __str__(self):
        return (f"Nombre: {self.nombre} "
                f"Edad: {self.edad}")
    def hacerSonidos(self):
        print("Miau")

class Vaca(Animal):
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def __str__(self):
        return (f"Nombre: {self.nombre} "
                f"Edad: {self.edad}")

    def hacerSonidos(self):
        print("¡Muuu...!")


if __name__ == "__main__":
    perrito = Perro("Mike", 2, "Salchicha")
    gatito = Gato("Luke", 3)
    vaca = Vaca("Lola", 4)

    Animals = [perrito, gatito, vaca]
    for animal in Animals:
        animal.hacerSonidos()
        print(animal,"\n")
