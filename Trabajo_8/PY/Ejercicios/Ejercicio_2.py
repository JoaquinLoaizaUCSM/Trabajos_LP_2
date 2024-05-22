from abc import ABC, abstractmethod

class Reproductor(ABC):
    @abstractmethod
    def reproducir(self):
        pass
    @abstractmethod
    def pausar(self):
        pass
    @abstractmethod
    def detener(self):
        pass
    @abstractmethod
    def iniciar(self):
        pass

class ReproductorMP3(Reproductor):
    def __init__(self):
        # modo (pausado-reproduciento)
        self.estado = False
        # representa si esta apagado o encendido
        self.modo = False

    def reproducir(self):
        if self.modo == True:
            if self.estado == True:
                print("La musica ya se encuentra reproduciendo")
            else:
                self.modo = True
                print(f"Reproduciendo Lista Rock90...")
        else:
            print("Reproductor apagado")

    def pausar(self):
        if self.modo == True:
            if self.estado == True:
                self.estado = False
                print("Musica en pausa")
            else:
                print("Dispositivo ya en pausa")
        else:
            print("Reproductor apagado")

    def detener(self):
        if self.modo == True:
            self.estado = False
            print("Musica detenida")
        else:
            print("Dispositivo apagado")

def menu():
    print("Menu acciones Reproductor")
    print("1 - Reproducir Musica")
    print("2 - Pausar Musica")
    print("3 - Detener Musica")
    print("4 - Iniciar Musica")
