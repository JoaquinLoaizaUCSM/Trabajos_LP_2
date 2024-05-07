package Trabajo_6.JAVA.Actividades;


class VectoresObjetos {


    // Clase estudiante
    private static class Estudiante{
        String nombre;
        Integer edad;
        String carrera;
        Integer notaPonderada;


        void MostrarDatos(){
            System.out.println("Nombre: " + nombre);
            System.out.println("Edad: " + edad);
            System.out.println("Carrera: " + carrera);
            System.out.println("Nota Ponderada: " + notaPonderada);
        }
    }


    public static void ordenarEstudiantes(Estudiante[] estudiantes) {
        for (int i = 0; i < estudiantes.length - 1; i++) {
            int maxIndex = i;
            for (int j = i + 1; j < estudiantes.length; j++) {
                if (estudiantes[j].notaPonderada > estudiantes[maxIndex].notaPonderada) {
                    maxIndex = j;
                }
            }
            Estudiante temp = estudiantes[maxIndex];
            estudiantes[maxIndex] = estudiantes[i];
            estudiantes[i] = temp;
        }
    }

    public static void imprimirTablaEstudiantes(Estudiante[] estudiantes) {
        System.out.printf("%-20s %-10s %-30s %-15s%n", "Nombre", "Edad", "Carrera", "Nota Ponderada");
        for (Estudiante estudiante : estudiantes) {
            System.out.printf("%-20s %-10d %-30s %-15d%n", estudiante.nombre,
                                                           estudiante.edad,
                                                           estudiante.carrera,
                                                           estudiante.notaPonderada);
        }
        System.out.println(); // Para el salto de linea
    }

    public static Estudiante[] crearEstudiantesGenrerica(int cantidad) {
        Estudiante[] estudiantes = new Estudiante[cantidad];
        for (int i = 0; i < cantidad; i++) {
            estudiantes[i] = new Estudiante();
            estudiantes[i].nombre = "Estudiante " + i;
            estudiantes[i].edad = 20 + i;
            estudiantes[i].carrera = "Ingenieria de sistemas";
            estudiantes[i].notaPonderada = 50 + i;
        }
        return estudiantes;
    }

    public static void main(String[] args) {
        // crear estudiantes
        Estudiante[] estudiantes = crearEstudiantesGenrerica(10);

        // imprimir lista de estudiantes
        System.out.println("Lista de estudiantes sin ordenar");
        imprimirTablaEstudiantes(estudiantes);

        // ordenar estudiantes
        ordenarEstudiantes(estudiantes);
        System.out.println("Lista de estudiantes ordenados");
        imprimirTablaEstudiantes(estudiantes);
    }

}
