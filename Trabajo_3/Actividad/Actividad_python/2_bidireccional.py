class Estudiante:
    def __init__(self, nombre="", apellido="", dni=0, correo=""):
        self.nombre = nombre
        self.apellido = apellido
        self.dni = dni
        self.correo = correo
        self.cursos = []

    def agregar_curso(self, curso):
        self.cursos.append(curso)

    def eliminar_curso(self, curso):
        self.cursos.remove(curso)

    def imprimir_cursos(self):
        print("Estudiante:", self.nombre)
        print("Cursos inscritos:")
        for curso in self.cursos:
            print(" -", curso.get_nombre())
        print()
    def get_nombre(self):
        return self.nombre


class Curso:
    def __init__(self, nombre="", codigo=0, descripcion="", inicio="(AAAA-MM-DD)", finalizacion="(AAAA-MM-DD)"):
        self.nombre = nombre
        self.codigo = codigo
        self.descripcion = descripcion
        self.fecha_inicio = inicio
        self.fecha_finalizacion = finalizacion
        self.estudiantes = []

    def agregar_estudiante(self, estudiante):
        self.estudiantes.append(estudiante)

    def eliminar_estudiante(self, estudiante):
        self.estudiantes.remove(estudiante)

    def get_estudiantes(self):
        return self.estudiantes

    def get_nombre(self):
        return self.nombre


if __name__ == "__main__":
    est1 = Estudiante("Yoel", "Montenegro", 70101, "yoel@gmail.com")
    est2 = Estudiante("Juan", "Agudo", 70102, "juan@gmail.com")
    est3 = Estudiante("Alberto", "Perez", 70103, "alberto@gmail.com")

    curso1 = Curso("Calculo", 1001, "Integrales", "2024-3-11", "2024-6-15")
    curso2 = Curso("Fisica", 1001, "Electrostatica", "2024-3-13", "2024-6-15")

    curso1.agregar_estudiante(est1)
    curso1.agregar_estudiante(est2)
    curso2.agregar_estudiante(est3)
    curso2.agregar_estudiante(est1)

    est1.agregar_curso(curso1)
    est1.agregar_curso(curso2)
    est2.agregar_curso(curso1)
    est3.agregar_curso(curso2)

    for estudiante in [est1, est2, est3]:
        estudiante.imprimir_cursos()

    estudiantes_curso1 = curso1.get_estudiantes()
    estudiantes_curso2 = curso2.get_estudiantes()

    print(" Curso:", curso1.get_nombre(), "- Estudiantes:")
    for estudiante in estudiantes_curso1:
        print("   -", estudiante.get_nombre())

    print(" Curso:", curso2.get_nombre(), "- Estudiantes:")
    for estudiante in estudiantes_curso2:
        print("   -", estudiante.get_nombre())
