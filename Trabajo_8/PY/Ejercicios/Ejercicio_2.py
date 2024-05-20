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
        self.estado = False
        self.modo = False

    def reproducir(self):
        self.estado = True

