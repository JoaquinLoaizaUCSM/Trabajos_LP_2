class Estudiante:
    def __init__(self, nombre, direccion, numeroMatricula, asignaturasMatriculadas=None):
        self.nombre = nombre
        self.direccion = direccion
        self.numeroMatricula = numeroMatricula
        if asignaturasMatriculadas is None:
            asignaturasMatriculadas = []
        self.asignaturasMatriculadas = asignaturasMatriculadas

class Profesor:
    def __init__(self, nombre, direccion, telefono, asignaturasImpartidas=None):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono
        if asignaturasImpartidas is None:
            asignaturasImpartidas = []
        self.asignaturasImpartidas = asignaturasImpartidas

class Asignatura:
    def __init__(self, codigo, nombre, descripcion, profesor, estudiantes=None, notas=None, faltas=None):
        self.codigo = codigo
        self.nombre = nombre
        self.descripcion = descripcion
        self.profesor = profesor
        if estudiantes is None:
            estudiantes = []
        self.estudiantes = estudiantes
        if notas is None:
            notas = []
        self.notas = notas
        if faltas is None:
            faltas = []
        self.faltas = faltas

class Universidad:
    def __init__(self, estudiantes=None, profesores=None, asignaturas=None):
        if estudiantes is None:
            estudiantes = []
        if profesores is None:
            profesores = []
        if asignaturas is None:
            asignaturas = []
        self.estudiantes = estudiantes
        self.profesores = profesores
        self.asignaturas = asignaturas

    def agregarEstudiante(self, estudiante):
        if estudiante not in self.estudiantes:
            self.estudiantes.append(estudiante)
            print("Estudiante agregado.")
        else:
            print("El estudiante ya existe.")

    def agregarProfesor(self, profesor):
        if profesor not in self.profesores:
            self.profesores.append(profesor)
            print("Profesor agregado.")
        else:
            print("El profesor ya existe.")

    def agregarAsignatura(self, asignatura):
        if asignatura not in self.asignaturas:
            self.asignaturas.append(asignatura)
            print("Asignatura agregada.")
        else:
            print("La asignatura ya existe.")

# Creación de una instancia de Universidad
universidad = Universidad()

# Creación de instancias de Estudiante, Profesor y Asignatura
estudiante = Estudiante("Juan", "Calle 123", "123")
profesor = Profesor("Pedro", "Calle 456", "456")
asignatura = Asignatura("123", "Matematicas", "Calculo", profesor)

# Agregar estudiante, profesor y asignatura a la universidad
universidad.agregarEstudiante(estudiante)
universidad.agregarProfesor(profesor)
universidad.agregarAsignatura(asignatura)
