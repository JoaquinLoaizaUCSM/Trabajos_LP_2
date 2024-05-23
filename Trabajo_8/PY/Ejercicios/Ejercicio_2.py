from abc import ABC, abstractmethod
import time


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
    def encender(self):
        pass

    @abstractmethod
    def apagar(self):
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
                print("Reanunando reproduccion")
            else:
                self.modo = True
                print(f"Reproduciendo archivo mp3")
        else:
            print("Reproductor apagado")

    def pausar(self):
        if self.modo == True:
            if self.estado == False:
                self.estado = True
                print("Pausando reproduccion")
            else:
                print("Archivo mp3 ya en pausa")
        else:
            print("Reproductor apagado")

    def detener(self):
        if self.modo == True:
            self.estado = False
            print("Deteniendo Reproduccion de musica")
        else:
            print("Dispositivo apagado")

    def encender(self):
        if self.modo == False:
            self.modo = True
            print("Encendiendo MP3...")

    def apagar(self):
        if self.modo == True:
            self.modo = False
            self.estado = False
            print("Apagando Reproductor")

def menu():
    print(" ***** Menu ***** ")
    print("1. Encender Reproductor")
    print("2. Reproducir archivo Mp3")
    print("3. Pausar archivo Mp3")
    print("4. Detener archivo Mp3 ")
    print("5. Apagar Reproductor")

def menu_acciones():
    print("Menu Acciones")
    print("1. Reproducir archivo Mp3")
    print("2. Pausar archivo Mp3")
    print("3. Detener archivo Mp3 ")

if __name__ == "__main__":
    mp3 = ReproductorMP3()
    while True:
        menu()
        op = int(input("Ingrese una opcion: "))
        if op == 1:
            mp3.encender()


        elif op == 2:
            mp3.reproducir()


        elif op == 3:
            mp3.pausar()


        elif op == 4:
            mp3.detener()


        elif op == 5:
            mp3.apagar()
            break
        else:
            print("Opcion invalida")
        print("\n")
        time.sleep(1.5)



