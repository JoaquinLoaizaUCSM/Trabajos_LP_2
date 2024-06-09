from abc import ABC, abstractmethod

class Animal(ABC):
    @abstractmethod
    def comer(self):
        pass
    @abstractmethod
    def dormir(self):
        pass
    @abstractmethod
    def moverse(self):
        pass

class Mamifero(Animal):
    def comer(self):
        print("El mamifero esta comiendo")

    def dormir(self):
        print("El mamifero esta durmiendo")

    def moverse(self):
        print("El mamifero esta caminando")

class Ave(Animal):
    def comer(self):
        print("El ave esta comiendo")

    def dormir(self):
        print("El ave esta durmiendo")


    def moverse(self):
        print("El ave est volando")

class Reptil(Animal):
    def comer(self):
        print("El reptil esta comiendo")

    def dormir(self):
        print("El reptil est@ durmiendo")

    def moverse(self):
        print("El reptil esta reptando.")

class Anfibio(Animal):
    def comer(self):
        print("El anfibio esta comiendo")

    def dormir(self):
        print("El anfibio esta durmiendo")

    def moverse(self):
        print("El anfibio esta saltando...")


if __name__ == "__main__":
    animales = []
    animales.append(Anfibio())
    animales.append(Reptil())
    animales.append(Ave())
    animales.append(Mamifero())

    for animal in animales:
        animal.comer()
        animal.dormir()
        animal.moverse()
    