package Trabajo_5.Actividades;

class ClasePadre {
    protected String atributoBase;

    public ClasePadre(String atributoBase) {
        this.atributoBase = atributoBase;
    }

    public void metodoBase() {
        System.out.println("Método de la clase base");
    }

    public String getAtributoBase() {
        return atributoBase;
    }

    public void setAtributoBase(String atributoBase) {
        this.atributoBase = atributoBase;
    }
}

class ClaseDerivada extends ClasePadre {
    private String atributoDerivada;

    public ClaseDerivada(String atributoBase, String atributoDerivada) {
        super(atributoBase);
        this.atributoDerivada = atributoDerivada;
    }

    public void metodoDerivada() {
        System.out.println("Método de la clase derivada");
    }

    public String getAtributoDerivada() {
        return atributoDerivada;
    }

    public void setAtributoDerivada(String atributoDerivada) {
        this.atributoDerivada = atributoDerivada;
    }
}

public class Actividad_7 {
    public static void main(String[] args) {
        ClaseDerivada objetoDerivada = new ClaseDerivada("Atributo Base", "Atributo Derivada");

        // Accede a los atributos y métodos heredados de la clase base
        System.out.println("Atributo base: " + objetoDerivada.atributoBase);
        objetoDerivada.metodoBase();

        // Accede a los atributos y métodos propios de la clase derivada
        System.out.println("Atributo derivada: " + objetoDerivada.getAtributoDerivada());
        objetoDerivada.metodoDerivada();

        // Modifica el atributo propio de la clase derivada
        objetoDerivada.setAtributoDerivada("Nuevo Atributo Derivada");
        System.out.println("Atributo derivada después de la modificación: " + objetoDerivada.getAtributoDerivada());
    }
}
