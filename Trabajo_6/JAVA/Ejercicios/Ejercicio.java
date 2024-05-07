package Trabajo_6.JAVA.Ejercicios;

import java.util.ArrayList;
import java.util.List;

class Alumno {

    private String nombre;
    private int edad;
    private float promedio;

    public Alumno(String nombre, int edad, float promedio) {
        this.nombre = nombre;
        this.edad = edad;
        this.promedio = promedio;
    }

    @Override
    public String toString() {
        return "Alumno: " + nombre + " (Edad: " + edad + ", Promedio: " + promedio + ")";
    }

    public boolean esMenorPromedioQue(Alumno otro) {
        return this.promedio < otro.promedio;
    }

    public String getNombre() {return nombre;}

    public void setNombre(String nombre) {this.nombre = nombre;}

    public int getEdad() {return edad;}

    public void setEdad(int edad) {this.edad = edad;}

    public float getPromedio() {return promedio;}

    public void setPromedio(float promedio) {this.promedio = promedio;}
}

class Grupo {

    private List<Alumno> alumnos;
    private int cantidadMaxima;

    public Grupo(int cantidadMaxima) {
        this.alumnos = new ArrayList<>();
        this.cantidadMaxima = cantidadMaxima;
    }

    @Override
    public String toString() {
        StringBuilder informacionGrupo = new StringBuilder("Grupo (Cantidad máxima: " + cantidadMaxima + "):\n");
        for (Alumno alumno : alumnos) {
            informacionGrupo.append("  - ").append(alumno).append("\n");
        }
        return informacionGrupo.toString();
    }

    public void agregarAlumno(String nombre, int edad, float promedio) {
        if (alumnos.size() < cantidadMaxima) {
            Alumno nuevoAlumno = new Alumno(nombre, edad, promedio);
            alumnos.add(nuevoAlumno);
            System.out.println("Alumno " + nombre + " agregado al grupo.");
        } else {
            System.out.println("No se pudo agregar al alumno " + nombre + ". El grupo está lleno.");
        }
    }

    public void ordenarPorPromedio() {
        alumnos.sort((a1, a2) -> Float.compare(a1.getPromedio(), a2.getPromedio()));
    }

    public float calcularPromedioGrupo() {
        if (!alumnos.isEmpty()) {
            float sumaPromedios = 0;
            for (Alumno alumno : alumnos) {
                sumaPromedios += alumno.getPromedio();
            }
            return sumaPromedios / alumnos.size();
        } else {
            return 0.0f;
        }
    }

    public Alumno obtenerAlumnoMejorPromedio() {
        if (!alumnos.isEmpty()) {
            return alumnos.stream().max((a1, a2) -> Float.compare(a1.getPromedio(), a2.getPromedio())).get();
        } else {
            return null;
        }
    }
}
public class Ejercicio {

    public static void main(String[] args) {
        Grupo grupo = new Grupo(5);

        // Agregamos a los alumnos
        grupo.agregarAlumno("Juan Perez", 17, 8.5f);
        grupo.agregarAlumno("Maria Gomez", 18, 9.2f);
        grupo.agregarAlumno("Pedro Lopez", 16, 7.8f);
        grupo.agregarAlumno("Ana Rodriguez", 17, 9.1f);
        grupo.agregarAlumno("Carlos Martinez", 18, 8.7f);

        // Muestra el grupo
        System.out.println(grupo);

        // Calcula y muestra el promedio general del grupo
        float promedioGeneral = grupo.calcularPromedioGrupo();
        System.out.println("Promedio general del grupo: " + promedioGeneral);

        // Obtiene y muestra el alumno con mejor promedio
        Alumno mejorAlumno = grupo.obtenerAlumnoMejorPromedio();
        if (mejorAlumno != null) {
            System.out.println("Alumno con mejor promedio: " + mejorAlumno);
        } else {
            System.out.println("No hay alumnos en el grupo.");
        }
    }
}

