package Trabajo_5.Ejercicios;

import java.util.ArrayList;

class Estudiante {
    private String nombre;
    private String direccion;
    private String numeroMatricula;
    private ArrayList<Asignatura> asignaturasMatriculadas;

    public Estudiante(String nombre, String direccion, String numeroMatricula, ArrayList<Asignatura> asignaturasMatriculadas) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.numeroMatricula = numeroMatricula;
        this.asignaturasMatriculadas = asignaturasMatriculadas;
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

    public String getNumeroMatricula() {
        return numeroMatricula;
    }

    public void setNumeroMatricula(String numeroMatricula) {
        this.numeroMatricula = numeroMatricula;
    }

    public ArrayList<Asignatura> getAsignaturasMatriculadas() {
        return asignaturasMatriculadas;
    }

    public void setAsignaturasMatriculadas(ArrayList<Asignatura> asignaturasMatriculadas) {
        this.asignaturasMatriculadas = asignaturasMatriculadas;
    }

}

class Profesor {
    private String nombre;
    private String direccion;
    private String telefono;
    private ArrayList<Asignatura> asignaturasImpartidas;

    public Profesor(String nombre, String direccion, String telefono, ArrayList<Asignatura> asignaturasImpartidas) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.asignaturasImpartidas = asignaturasImpartidas;
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

    public ArrayList<Asignatura> getAsignaturasImpartidas() {
        return asignaturasImpartidas;
    }

    public void setAsignaturasImpartidas(ArrayList<Asignatura> asignaturasImpartidas) {
        this.asignaturasImpartidas = asignaturasImpartidas;
    }
}

class Asignatura {
    private String codigo;
    private String nombre;
    private String descripcion;
    private Profesor profesor;
    private ArrayList<Estudiante> estudiantes;
    private ArrayList<Integer> notas;
    private ArrayList<Integer> faltas;

    public Asignatura(String codigo,
                      String nombre,
                      String descripcion,
                      Profesor profesor,
                      ArrayList<Estudiante> estudiantes,
                      ArrayList<Integer> notas,
                      ArrayList<Integer> faltas)
    {
        this.codigo = codigo;
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.profesor = profesor;
        this.estudiantes = estudiantes;
        this.notas = notas;
        this.faltas = faltas;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public Profesor getProfesor() {
        return profesor;
    }

    public void setProfesor(Profesor profesor) {
        this.profesor = profesor;
    }

    public ArrayList<Estudiante> getEstudiantes() {
        return estudiantes;
    }

    public void setEstudiantes(ArrayList<Estudiante> estudiantes) {
        this.estudiantes = estudiantes;
    }

    public ArrayList<Integer> getNotas() {
        return notas;
    }

    public void setNotas(ArrayList<Integer> notas) {
        this.notas = notas;
    }

    public ArrayList<Integer> getFaltas() {
        return faltas;
    }

    public void setFaltas(ArrayList<Integer> faltas) {
        this.faltas = faltas;
    }

    // Constructor, getters y setters
}

public class Universidad {
    private ArrayList<Estudiante> estudiantes;
    private ArrayList<Profesor> profesores;
    private ArrayList<Asignatura> asignaturas;

    // Métodos para agregar_empleado estudiantes, profesores y asignaturas
    public void agregarEstudiante(Estudiante estudiante) {
        if (!estudiantes.contains(estudiante)) {
            estudiantes.add(estudiante);
            System.out.println("Estudiante agregado.");
        }
    }

    public void agregarProfesor(Profesor profesor) {
        if (!profesores.contains(profesor)) {
            profesores.add(profesor);
            System.out.println("Profesor agregado.");
        }
    }

    public void agregarAsignatura(Asignatura asignatura) {
        if (!asignaturas.contains(asignatura)) {
            asignaturas.add(asignatura);
            System.out.println("Asignatura agregada.");
        }
    }

    public ArrayList<Estudiante> getEstudiantes() {
        return estudiantes;
    }

    public void setEstudiantes(ArrayList<Estudiante> estudiantes) {
        this.estudiantes = estudiantes;
    }

    public ArrayList<Profesor> getProfesores() {
        return profesores;
    }

    public void setProfesores(ArrayList<Profesor> profesores) {
        this.profesores = profesores;
    }

    public ArrayList<Asignatura> getAsignaturas() {
        return asignaturas;
    }

    public void setAsignaturas(ArrayList<Asignatura> asignaturas) {
        this.asignaturas = asignaturas;
    }

    // Constructor, getters y setters

    public Universidad(ArrayList<Estudiante> estudiantes, ArrayList<Profesor> profesores, ArrayList<Asignatura> asignaturas) {
        this.estudiantes = estudiantes;
        this.profesores = profesores;
        this.asignaturas = asignaturas;
    }

    public Universidad() {
        this.estudiantes = new ArrayList<>();
        this.profesores = new ArrayList<>();
        this.asignaturas = new ArrayList<>();
    }


    public static void main(String[] args) {
        ArrayList<Estudiante> estudiantes = new ArrayList<>();
        ArrayList<Profesor> profesores = new ArrayList<>();
        ArrayList<Asignatura> asignaturas = new ArrayList<>();

        Universidad universidad = new Universidad(estudiantes, profesores, asignaturas);

        Estudiante estudiante = new Estudiante("Juan", "Calle 123", "123", new ArrayList<>());
        Profesor profesor = new Profesor("Pedro", "Calle 456", "456", new ArrayList<>());
        Asignatura asignatura = new Asignatura("123", "Matematicas", "Calculo", profesor, new ArrayList<>(), new ArrayList<>(), new ArrayList<>());

        universidad.agregarEstudiante(estudiante);
        universidad.agregarProfesor(profesor);
        universidad.agregarAsignatura(asignatura);
    }
}
