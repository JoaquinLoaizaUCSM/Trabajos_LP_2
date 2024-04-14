package Trabajo_5.Actividades;

class Alumnos {
    private String nombre;

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public Alumnos(String nombre) {
        this.nombre = nombre;
    }

}

class Docente {
    private String nombre;

    public Docente(String nombre) {
        this.nombre = nombre;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}

class Materia {
    private String nombre;

    public Materia(String nombre) {
        this.nombre = nombre;
    }


    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}

class Asociacion {
    private Alumnos alumnos;
    private Docente docente;
    private Materia materia;

    public Asociacion(Alumnos alumnos, Docente docente, Materia materia) {
        this.alumnos = alumnos;
        this.docente = docente;
        this.materia = materia;
    }

    public Alumnos getEstudiante() {
        return alumnos;
    }

    public void setEstudiante(Alumnos alumnos) {
        this.alumnos = alumnos;
    }

    public Docente getDocente() {
        return docente;
    }

    public void setDocente(Docente docente) {
        this.docente = docente;
    }

    public Materia getCurso() {
        return materia;
    }

    public void setCurso(Materia materia) {
        this.materia = materia;
    }
}

public class Actividad_3 {
    public static void main(String[] args) {
        Alumnos alumnos = new Alumnos("Joaquin");
        Docente docente = new Docente("Oscar");
        Materia materia = new Materia("Lenguaje de programación");

        Asociacion asociacion = new Asociacion(alumnos, docente, materia);

        // Imprime la información de la asociación
        System.out.println("Alumnos: " + asociacion.getEstudiante().getNombre());
        System.out.println("Docente: " + asociacion.getDocente().getNombre());
        System.out.println("Materia: " + asociacion.getCurso().getNombre());
    }
}
