package Trabajo_5.Ejercicios;

import java.util.ArrayList;
import java.util.Date;

class Libro {

    private String ISBN;
    private String titulo;
    private int anoPublicacion;
    private int cantidadEjemplares;
    private Autor autor;

    public Libro(String ISBN, String titulo, int anoPublicacion, int cantidadEjemplares, Autor autor) {
        this.ISBN = ISBN;
        this.titulo = titulo;
        this.anoPublicacion = anoPublicacion;
        this.cantidadEjemplares = cantidadEjemplares;
        this.autor = autor;
    }

    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public int getAnoPublicacion() {
        return anoPublicacion;
    }

    public void setAnoPublicacion(int anoPublicacion) {
        this.anoPublicacion = anoPublicacion;
    }

    public int getCantidadEjemplares() {
        return cantidadEjemplares;
    }

    public void setCantidadEjemplares(int cantidadEjemplares) {
        this.cantidadEjemplares = cantidadEjemplares;
    }

    public Autor getAutor() {
        return autor;
    }

    public void setAutor(Autor autor) {
        this.autor = autor;
    }

}

class Autor {
    private String nombre;
    private String nacionalidad;
    private ArrayList<Libro> librosEscritos;

    public Autor(String nombre, String nacionalidad, ArrayList<Libro> librosEscritos) {
        this.nombre = nombre;
        this.nacionalidad = nacionalidad;
        this.librosEscritos = librosEscritos;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getNacionalidad() {
        return nacionalidad;
    }

    public void setNacionalidad(String nacionalidad) {
        this.nacionalidad = nacionalidad;
    }

    public ArrayList<Libro> getLibrosEscritos() {
        return librosEscritos;
    }

    public void setLibrosEscritos(ArrayList<Libro> librosEscritos) {
        this.librosEscritos = librosEscritos;
    }
}

class Usuario {
    private String nombre;
    private String direccion;
    private String telefono;
    private ArrayList<Libro> librosPrestados;

    public Usuario(String nombre, String direccion, String telefono, ArrayList<Libro> librosPrestados) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.librosPrestados = librosPrestados;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public ArrayList<Libro> getLibrosPrestados() {
        return librosPrestados;
    }

    public void setLibrosPrestados(ArrayList<Libro> librosPrestados) {
        this.librosPrestados = librosPrestados;
    }
}

class Prestamo {
    private Usuario usuario;
    private Libro libro;
    private Date fechaPrestamo;
    private Date fechaDevolucion;

    public Prestamo(Usuario usuario, Libro libro, Date fechaPrestamo, Date fechaDevolucion) {
        this.usuario = usuario;
        this.libro = libro;
        this.fechaPrestamo = fechaPrestamo;
        this.fechaDevolucion = fechaDevolucion;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    public Libro getLibro() {
        return libro;
    }

    public void setLibro(Libro libro) {
        this.libro = libro;
    }

    public Date getFechaPrestamo() {
        return fechaPrestamo;
    }

    public void setFechaPrestamo(Date fechaPrestamo) {
        this.fechaPrestamo = fechaPrestamo;
    }

    public Date getFechaDevolucion() {
        return fechaDevolucion;
    }

    public void setFechaDevolucion(Date fechaDevolucion) {
        this.fechaDevolucion = fechaDevolucion;
    }
}

class Bibliotecas {
    private ArrayList<Libro> libros;
    private ArrayList<Autor> autores;
    private ArrayList<Usuario> usuarios;
    private ArrayList<Prestamo> prestamos;

    public Bibliotecas() {
        this.libros = new ArrayList<>();
        this.autores = new ArrayList<>();
        this.usuarios = new ArrayList<>();
        this.prestamos = new ArrayList<>();
    }

    public void agregarLibro(Libro libro) {
        if (!libros.contains(libro)) {
            libros.add(libro);
            System.out.println("Libro agregado");
        }
    }

    public void agregarAutor(Autor autor) {
        if (!autores.contains(autor)) {
            autores.add(autor);
            System.out.println("Autor agregado");
        }
    }

    public void agregarUsuario(Usuario usuario) {
        if (!usuarios.contains(usuario)) {
            usuarios.add(usuario);
            System.out.println("Usuario agregado");
        }
    }

    public void agregarPrestamo(Prestamo prestamo) {
        if (!prestamos.contains(prestamo)) {
            prestamos.add(prestamo);
            System.out.println("Prestamo agregado");
        }
    }


}


public class Biblioteca {

    public static void main(String[] args) {
        Libro libro1 = new Libro("1234567890", "El Quijote", 1605, 100, new Autor("Miguel de Cervantes", "Español", new ArrayList<>()));
        Libro libro2 = new Libro("0987654321", "Don Juan Tenorio", 1844, 50, new Autor("José Zorrilla", "Español", new ArrayList<>()));
        Libro libro3 = new Libro("1357924680", "La Celestina", 1499, 75, new Autor("Fernando de Rojas", "Español", new ArrayList<>()));

        Autor autor1 = new Autor("Miguel de Cervantes", "Español", new ArrayList<>());

        Usuario usuario1 = new Usuario("Juan", "Calle 123", "1234567890", new ArrayList<>());
        Usuario usuario2 = new Usuario("Pedro", "Calle 456", "0987654321", new ArrayList<>());

        Prestamo prestamo1 = new Prestamo(usuario1, libro1, new Date(), new Date());
        Prestamo prestamo2 = new Prestamo(usuario2, libro2, new Date(), new Date());

        Bibliotecas biblioteca = new Bibliotecas();

        biblioteca.agregarLibro(libro1);

        biblioteca.agregarAutor(autor1);

        biblioteca.agregarUsuario(usuario1);

        biblioteca.agregarPrestamo(prestamo1);

        biblioteca.agregarLibro(libro2);

    }
}
