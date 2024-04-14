package Trabajo_5.Actividades;

import java.util.ArrayList;

class Objeto {
    private String nombre;

    public Objeto(String nombre) {
        this.nombre = nombre;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

}

class Coleccion {
    private ArrayList<Objeto> objetos;

    public Coleccion() {
        this.objetos = new ArrayList<>();
    }

    public void agregarObjeto(Objeto objeto) {
        objetos.add(objeto);
    }

    public void eliminarObjeto(Objeto objeto) {
        objetos.remove(objeto);
    }

    public Objeto obtenerObjeto(int index) {
        return objetos.get(index);
    }
}

public class Actividad_5 {
    public static void main(String[] args) {
        Coleccion coleccion = new Coleccion();
        Objeto objeto1 = new Objeto("Objeto1");
        Objeto objeto2 = new Objeto("Objeto2");

        coleccion.agregarObjeto(objeto1);
        coleccion.agregarObjeto(objeto2);

        // Accede a los objetos de la colección
        System.out.println("Primer objeto: " + coleccion.obtenerObjeto(0).getNombre());
        System.out.println("Segundo objeto: " + coleccion.obtenerObjeto(1).getNombre());

        // Modifica y elimina objetos de la colección
        objeto1.setNombre("NuevoObjeto1");
        coleccion.eliminarObjeto(objeto2);

        // Accede a los objetos de la colección después de las modificaciones
        System.out.println("Primer objeto después de las modificaciones: " + coleccion.obtenerObjeto(0).getNombre());
    }
}

