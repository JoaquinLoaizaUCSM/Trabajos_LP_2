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
                print("El archivo mp3 ya se encuentra en reproduccion")
            else:
                self.modo = True
                print(f"Reproduciendo archivo mp3")
        else:
            print("Reproductor apagado")

    def pausar(self):
        if self.modo == True:
            if self.estado == True:
                self.estado = False
                print("Pausando archivo mp3")
            else:
                print("Archivo m'3 ya en pausa")
        else:
            print("Reproductor apagado")

    def detener(self):
        if self.modo == True:
            self.estado = False
            print("Dteneiendo Reproduccion de musica")
        else:
            print("Dispositivo apagado")

    def iniciar(self):
        if self.modo == True:
            print("Encendiendo MP3")
def menu_():
    print("Menu acciones Reproductor")
    print("1. Encender Reproductor")
    print("2. Reproducir Reproductor")
