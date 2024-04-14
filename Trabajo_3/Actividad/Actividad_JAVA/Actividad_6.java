package Trabajo_5.Actividades;

class ObjetoCompuesto {
    private String nombre;

    public ObjetoCompuesto(String nombre) {
        this.nombre = nombre;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}

class ClaseBase {
    private ObjetoCompuesto objetoCompuesto;

    public ClaseBase(String nombreObjetoCompuesto) {
        this.objetoCompuesto = new ObjetoCompuesto(nombreObjetoCompuesto);
    }

    public ObjetoCompuesto getObjetoCompuesto() {
        return objetoCompuesto;
    }

    // No hay un destructor explícito en Java. El recolector de basura se encarga de eso.
}

public class Actividad_6 {
    public static void main(String[] args) {
        ClaseBase claseBase = new ClaseBase("ObjetoCompuesto1");

        // Accede al objeto compuesto
        System.out.println("Objeto compuesto: " + claseBase.getObjetoCompuesto().getNombre());

        // Modifica el objeto compuesto
        claseBase.getObjetoCompuesto().setNombre("NuevoObjetoCompuesto1");

        // Accede al objeto compuesto después de la modificación
        System.out.println("Objeto compuesto después de la modificación: " + claseBase.getObjetoCompuesto().getNombre());
    }
}
