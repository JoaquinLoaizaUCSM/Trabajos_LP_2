package Trabajo_5.Actividades;

import java.util.ArrayList;

class Estudiante {
    private String nombre;
    private String apellido;
    private String id;
    private String correo;
    private ArrayList<Curso> cursos;

    public Estudiante(String nombre, String apellido, String id, String correo) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.id = id;
        this.correo = correo;
        this.cursos = new ArrayList<>();
    }

    public void agregarCurso(Curso curso) {
        if (!cursos.contains(curso)) {
            cursos.add(curso);
            curso.agregarEstudiante(this);
        }
    }

    public void eliminarCurso(Curso curso) {
        if (cursos.contains(curso)) {
            cursos.remove(curso);
            curso.eliminarEstudiante(this);
        }
    }

    public ArrayList<Curso> getCursos() {
        return cursos;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public void setCursos(ArrayList<Curso> cursos) {
        this.cursos = cursos;
    }
}

class Curso {
    private String nombre;
    private String codigo;
    private String descripcion;
    private String fechaInicio;
    private String fechaFin;
    private ArrayList<Estudiante> estudiantes;

    public Curso(String nombre, String codigo, String descripcion, String fechaInicio, String fechaFin) {
        this.nombre = nombre;
        this.codigo = codigo;
        this.descripcion = descripcion;
        this.fechaInicio = fechaInicio;
        this.fechaFin = fechaFin;
        this.estudiantes = new ArrayList<>();
    }

    public void agregarEstudiante(Estudiante estudiante) {
        if (!estudiantes.contains(estudiante)) {
            estudiantes.add(estudiante);
            estudiante.agregarCurso(this);
        }
    }

    public void eliminarEstudiante(Estudiante estudiante) {
        if (estudiantes.contains(estudiante)) {
            estudiantes.remove(estudiante);
            estudiante.eliminarCurso(this);
        }
    }

    public ArrayList<Estudiante> getEstudiantes() {
        return estudiantes;
    }

    public String getNombre() {
        return nombre;
    }

}

public class Actividad_2 {
    public static void main(String[] args) {
        Estudiante estudiante1 = new Estudiante("Juan", "Perez", "123", "juan.perez@gmail.com");
        Estudiante estudiante2 = new Estudiante("Ana", "Gomez", "456", "ana.gomez@gmail.com");

        Curso curso1 = new Curso("Matematicas", "MAT101", "Curso de matematicas basicas", "01/01/2024", "30/06/2024");
        Curso curso2 = new Curso("Fisica", "FIS101", "Curso de fisica basica", "01/01/2024", "30/06/2024");

        estudiante1.agregarCurso(curso1);
        estudiante1.agregarCurso(curso2);

        estudiante2.agregarCurso(curso1);

        System.out.println("Estudiantes en el curso de Matematicas: " + curso1.getEstudiantes().size());
        System.out.println("Estudiantes en el curso de Fisica: " + curso2.getEstudiantes().size());

        System.out.println("Cursos de Juan: " + estudiante1.getCursos().size());
        System.out.println("Cursos de Ana: " + estudiante2.getCursos().size());
    }
}
