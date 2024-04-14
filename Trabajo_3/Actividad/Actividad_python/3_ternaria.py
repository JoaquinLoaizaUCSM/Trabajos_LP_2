class Estudiante:
    def __init__(self, nombre="", apellido="", correo=""):
        self.nombre = nombre
        self.apellido = apellido
        self.correo = correo

    def get_nombre(self):
        return self.nombre

    def get_apellido(self):
        return self.apellido


class Docente:
    def __init__(self, nombre="", apellido="", correo=""):
        self.nombre = nombre
        self.apellido = apellido
        self.correo = correo

    def get_nombre(self):
        return self.nombre

    def get_apellido(self):
        return self.apellido


class Curso:
    def __init__(self, nombre="", codigo=0, descripcion=""):
        self.nombre = nombre
        self.codigo = codigo
        self.descripcion = descripcion

    def get_nombre(self):
        return self.nombre

    def get_descripcion(self):
        return self.descripcion


class Asociacion:
    def __init__(self, estudiante, docente, curso):
        self.estudiante = estudiante
        self.docente = docente
        self.curso = curso

    def get_estudiante(self):
        return self.estudiante

    def get_docente(self):
        return self.docente

    def get_curso(self):
        return self.curso


if __name__ == "__main__":
    estudiante1 = Estudiante("Yhosfer", "Quispe", "ander@gmail.com")
    estudiante2 = Estudiante("Fernando", "Aranya", "fer@gmail.com")

    docente1 = Docente("German", "Alvarez", "german.alvarez@gmail.com")
    docente2 = Docente("Pedro", "Gomez", "pedro.gomez@gmail.com")

    curso1 = Curso("Fisica", 1001, "Movimiendod en dos dimenciones")
    curso2 = Curso("Geometria", 1002, "Geometria del espacio")

    asociaciones = [
        Asociacion(estudiante1, docente1, curso1),
        Asociacion(estudiante2, docente1, curso1)
    ]

    for i, asociacion in enumerate(asociaciones):
        estudiante = asociacion.get_estudiante()
        docente = asociacion.get_docente()
        curso = asociacion.get_curso()

        print(f"Asociacion {i + 1}:")
        print("   - Estudiante:", estudiante.get_nombre())
        print("   - Docente:", docente.get_nombre())
        print("   - Curso:", curso.get_nombre())
