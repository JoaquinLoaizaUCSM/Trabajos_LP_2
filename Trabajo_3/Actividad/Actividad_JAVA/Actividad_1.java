package Trabajo_5.Actividades;

class Hijo {

    private String nombre;

    public Hijo(String nombre) {
        this.nombre = nombre;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}

class Padre {
    private final String nombre;
    private final Hijo[] hijos;
    private int numHijos;

    public Padre(String nombre, int maxHijos) {
        this.nombre = nombre;
        this.hijos = new Hijo[maxHijos];
        this.numHijos = 0;
    }

    public void agregarHijo(Hijo hijo) {
        if (numHijos < hijos.length) {
            hijos[numHijos] = hijo;
            numHijos++;
        } else {
            System.out.println("No se puede agregar más hijos.");
        }
    }

    public void imprimirInfo() {
        System.out.println("Padre: " + nombre + ", Numero de hijos: " + numHijos);
    }
}

public class Actividad_1 {

    public static void main(String[] args) {
        Padre padre = new Padre("Juan", 3);
        Hijo hijo1 = new Hijo("Pedro");
        Hijo hijo2 = new Hijo("Ana");
        Hijo hijo3 = new Hijo("Maria");
        Hijo hijo4 = new Hijo("Jose");

        padre.agregarHijo(hijo1);
        padre.agregarHijo(hijo2);
        padre.agregarHijo(hijo3);
        padre.agregarHijo(hijo4);

        padre.imprimirInfo();
    }
}
