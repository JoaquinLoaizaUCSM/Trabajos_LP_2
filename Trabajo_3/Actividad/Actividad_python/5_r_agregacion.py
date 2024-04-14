class Curso:
    def __init__(self, nombre):
        self.nombre = nombre
        self.estudiantes = []

    def inscribir_estudiante(self, estudiante):
        self.estudiantes.append(estudiante)

    def dar_de_baja(self, estudiante):
        self.estudiantes.remove(estudiante)

    def imprimir_estudiantes(self):
        print("Estudiantes en", self.nombre + ":")
        for estudiante in self.estudiantes:
            print("  - " + estudiante.nombre)


class Estudiante:
    def __init__(self, nombre):
        self.nombre = nombre
        self.cursos = []

    def inscribirse(self, curso):
        self.cursos.append(curso)
        curso.inscribir_estudiante(self)

    def dejar(self, curso):
        self.cursos.remove(curso)
        curso.dar_de_baja(self)

    def imprimir_cursos(self):
        print("Cursos de", self.nombre + ":")
        for curso in self.cursos:
            print("  - " + curso.nombre)


if __name__ == "__main__":
    estudiante1 = Estudiante("Alice")
    estudiante2 = Estudiante("Bob")
    curso1 = Curso("Matemáticas")
    curso2 = Curso("Ciencias")
    estudiante1.inscribirse(curso1)
    estudiante1.inscribirse(curso2)
    estudiante2.inscribirse(curso2)
    curso1.inscribir_estudiante(estudiante2)
    print()
    print("Después de inscribirse y dejar cursos:")
    estudiante1.imprimir_cursos()
    curso2.imprimir_estudiantes()

    estudiante1.dejar(curso1)
    curso2.dar_de_baja(estudiante2)
    print()
    print("Después de dejar cursos:")
    estudiante1.imprimir_cursos()
    curso2.imprimir_estudiantes()
