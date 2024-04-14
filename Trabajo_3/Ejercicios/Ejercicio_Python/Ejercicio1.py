from datetime import datetime

class Libro:
    def __init__(self, ISBN, titulo, anoPublicacion, cantidadEjemplares, autor):
        self.ISBN = ISBN
        self.titulo = titulo
        self.anoPublicacion = anoPublicacion
        self.cantidadEjemplares = cantidadEjemplares
        self.autor = autor

class Autor:
    def __init__(self, nombre, nacionalidad):
        self.nombre = nombre
        self.nacionalidad = nacionalidad
        self.librosEscritos = []

class Usuario:
    def __init__(self, nombre, direccion, telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono
        self.librosPrestados = []

class Prestamo:
    def __init__(self, usuario, libro, fechaPrestamo, fechaDevolucion):
        self.usuario = usuario
        self.libro = libro
        self.fechaPrestamo = fechaPrestamo
        self.fechaDevolucion = fechaDevolucion

class Bibliotecas:
    def __init__(self):
        self.libros = []
        self.autores = []
        self.usuarios = []
        self.prestamos = []

    def agregarLibro(self, libro):
        if libro not in self.libros:
            self.libros.append(libro)
            print("Libro agregado")

    def agregarAutor(self, autor):
        if autor not in self.autores:
            self.autores.append(autor)
            print("Autor agregado")

    def agregarUsuario(self, usuario):
        if usuario not in self.usuarios:
            self.usuarios.append(usuario)
            print("Usuario agregado")

    def agregarPrestamo(self, prestamo):
        if prestamo not in self.prestamos:
            self.prestamos.append(prestamo)
            print("Prestamo agregado")

if __name__ == "__main__":
    libro1 = Libro("1234567890", "El Quijote", 1605, 100, Autor("Miguel de Cervantes", "Español"))
    libro2 = Libro("0987654321", "Don Juan Tenorio", 1844, 50, Autor("José Zorrilla", "Español"))
    libro3 = Libro("1357924680", "La Celestina", 1499, 75, Autor("Fernando de Rojas", "Español"))

    autor1 = Autor("Miguel de Cervantes", "Español")

    usuario1 = Usuario("Juan", "Calle 123", "1234567890")
    usuario2 = Usuario("Pedro", "Calle 456", "0987654321")

    prestamo1 = Prestamo(usuario1, libro1, datetime.now(), datetime.now())
    prestamo2 = Prestamo(usuario2, libro2, datetime.now(), datetime.now())

    biblioteca = Bibliotecas()

    biblioteca.agregarLibro(libro1)
    biblioteca.agregarAutor(autor1)
    biblioteca.agregarUsuario(usuario1)
    biblioteca.agregarPrestamo(prestamo1)
    biblioteca.agregarLibro(libro2)
