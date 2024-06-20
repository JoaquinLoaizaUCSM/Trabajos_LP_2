import pickle

class Persona:
    def __init__(self, nombre, edad, direccion):
        self.nombre = nombre
        self.edad = edad
        self.direccion = direccion

    def __str__(self):
        return f"Nombre: {self.nombre}, Edad: {self.edad}, Dirección: {self.direccion}"

    def binario(self, archivo):
        with open(archivo, 'wb') as f:
            pickle.dump(self, f)

    def desbinario(archivo):
        with open(archivo, 'rb') as f:
            return pickle.load(f)


persona = Persona("Juan", "30", "Calle Principal 123")


persona.binario("persona.bin")


persona_desbinario = Persona.desbinario("persona.bin")

print(persona_desbinario)


