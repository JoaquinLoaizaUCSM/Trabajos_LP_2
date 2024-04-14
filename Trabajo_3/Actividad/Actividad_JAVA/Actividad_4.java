package Trabajo_5.Actividades;

class Trabajador {
    private String nombre;
    private Trabajador[] companeros;
    private int numCompaneros;

    public Trabajador(String nombre, int maxCompaneros) {
        this.nombre = nombre;
        this.companeros = new Trabajador[maxCompaneros];
        this.numCompaneros = 0;
    }

    public void agregarCompanero(Trabajador companero) {
        if (numCompaneros < companeros.length) {
            companeros[numCompaneros] = companero;
            numCompaneros++;
        } else {
            System.out.println("No se puede agregar más compañeros.");
        }
    }

    // Métodos get y set para 'nombre' y otros métodos necesarios
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public Trabajador[] getCompaneros() {
        return companeros;
    }

    public void setCompaneros(Trabajador[] companeros) {
        this.companeros = companeros;
    }

    public int getNumCompaneros() {
        return numCompaneros;
    }

    public void setNumCompaneros(int numCompaneros) {
        this.numCompaneros = numCompaneros;
    }

    public void imprimirInfo() {
        System.out.println("Trabajador: " + nombre + ", Numero de compañeros: " + numCompaneros);
    }

}

class Gerente extends Trabajador {
    private Trabajador[] trabajadores;

    public Gerente(String nombre, int maxTrabajadores) {
        super(nombre, maxTrabajadores);
        this.trabajadores = new Trabajador[maxTrabajadores];
    }

    // Métodos para agregar y eliminar trabajadores
    public void agregarTrabajador(Trabajador trabajador) {
        if (trabajador.getNumCompaneros() < trabajador.getCompaneros().length) {
            trabajadores[trabajador.getNumCompaneros()] = trabajador;
            trabajador.setNumCompaneros(trabajador.getNumCompaneros() + 1);

        } else {
            System.out.println("No se puede agregar más trabajadores.");
        }
    }

    public void eliminarTrabajador(Trabajador trabajador) {
        if (trabajador.getNumCompaneros() < trabajador.getCompaneros().length) {
            trabajadores[trabajador.getNumCompaneros()] = trabajador;
            trabajador.setNumCompaneros(trabajador.getNumCompaneros() - 1);
        } else {
            System.out.println("No se puede agregar más trabajadores.");
        }
    }
}

public class Actividad_4 {
    public static void main(String[] args) {
        Gerente gerente = new Gerente("Joaquin", 10);
        Trabajador trabajador1 = new Trabajador("Trabajador1", 10);
        Trabajador trabajador2 = new Trabajador("Trabajador2", 10);

        trabajador1.agregarCompanero(trabajador2);
        trabajador2.agregarCompanero(trabajador1);

        // Imprime la información de los trabajadores y sus compañeros
        System.out.println("Trabajador 1: " + trabajador1.getNombre());
        System.out.println("Trabajador 2: " + trabajador2.getNombre());

        // Imprime la información del gerente y sus trabajadores
        System.out.println("Gerente: " + gerente.getNombre());


    }
}
