class Alumno:
    def __init__(self, nombre, edad, promedio):
        self.nombre = nombre
        self.edad = edad
        self.promedio = promedio

    def __str__(self):
        return f'{self.nombre} {self.edad} {self.promedio}'

    def __lt__(self, cantidad):
        return self.promedio < cantidad.promedio


class Group:
    def __init__(self, cantidad):
        self.cantidad = cantidad
        self.alumnos = []

    def __str__(self):
        for alumno in self.alumnos:
            print(alumno)
        return ""

    def agregar_alumno(self, nombre, edad, promedio):
        if len(self.alumnos) < self.cantidad:
            self.alumnos.append(Alumno(nombre, edad, promedio))
        else:
            print('No se puede agregar mas alumnos')

    def ordenar_por_promedio(self):
        n = len(self.alumnos)
        for i in range(n - 1):
            for j in range(0, n - i - 1):
                if self.alumnos[j].promedio < self.alumnos[j + 1].promedio:
                    # Intercambiar los elementos si están en el orden incorrecto
                    self.alumnos[j], self.alumnos[j + 1] = self.alumnos[j + 1],
                    self.alumnos[j]

    def ordenar_por_promedio_sort(self):
        self.alumnos.sort(key=lambda alumno: alumno.promedio, reverse=True)

    def mejor_promedio(self):
        mejor_promedio = 0
        for alumno in self.alumnos:
            if alumno.promedio > mejor_promedio:
                mejor_promedio = alumno.promedio
        return mejor_promedio


grupo1 = Group(5)
grupo1.agregar_alumno("Alberto", 21, 13)
grupo1.agregar_alumno("Juan", 20, 15)
grupo1.agregar_alumno("Luis", 22, 10)
grupo1.agregar_alumno("Joaquin", 22, 17)
grupo1.agregar_alumno("Carlos", 22, 16)
print("Nombre - Edad - Promedio")
print(grupo1)
print("Mejor promedio: ")
print(grupo1.mejor_promedio(), "\n")
grupo1.ordenar_por_promedio()
print("Nombre - Edad - Promedio")
print(grupo1)
