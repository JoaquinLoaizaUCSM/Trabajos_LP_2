class Vehiculo:
    def __init__(self, marca, modelo, year_build, precio):
        self.marca = marca
        self.modelo = modelo
        self.year_build = year_build
        self.precio = precio

class Automovil(Vehiculo):
    def __init__(self, marca, modelo, year_build, precio, nPuertas, tipo_combustible):
        Vehiculo.__init__(self, marca, modelo, year_build, precio)
        self.nPuertas = nPuertas
        self.tipo_combustible = tipo_combustible

    def __str__(self):
        return (f'Marca: {self.marca}\n'
                f'Modelo: {self.modelo}\n'
                f'Anio Frabricacion: {self.year_build}\n'
                f'Precio: {self.precio}$\n'
                f'Puertas: {self.nPuertas}\n'
                f'Tipo combustible: {self.tipo_combustible}\n')
    def __del__(self):
        print("Automovil destruido")


class Motocicleta(Vehiculo):
    def __init__(self, marca, modelo, year_build, precio, cilindrada):
        super().__init__(marca, modelo, year_build, precio)
        self.cilindrada = cilindrada

    def __str__(self):
        return (f'Marca: {self.marca}\n'
                f'Modelo: {self.modelo}\n'
                f'Anio Frabricacion: {self.year_build}\n'
                f'Cilindrada: {self.cilindrada}cm^3\n')

    def __del__(self):
        print("Motocicleta destruida")

coche = Automovil("Honda","S2000","1999",20000,
                  2,"95 octanos")
print(coche)

moto = Motocicleta("Pulsar", "v2", 2000, 1400,50)
print(moto)
