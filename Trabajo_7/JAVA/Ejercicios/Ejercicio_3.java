package Trabajo_7.Ejercicios;

class Movil {
    private String marca;
    private String modelo;
    private String sistema;

    public Movil(String marca, String modelo, String sistema) {
        this.marca = marca;
        this.modelo = modelo;
        this.sistema = sistema;
    }

    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }

    public String getSistema() {
        return sistema;
    }
}

class Telefono extends Movil {
    private int nCelular;

    public Telefono(String marca, String modelo, String sistema, int nCelular) {
        super(marca, modelo, sistema);
        this.nCelular = nCelular;
    }

    @Override
    public String toString() {
        return "Datos del telefono:\n" +
                "Marca             -> " + getMarca() + "\n" +
                "Modelo            -> " + getModelo() + "\n" +
                "Sistema Operativo -> " + getSistema() + "\n" +
                "Numero Celular    -> " + nCelular;
    }
}

class Tablet extends Movil {
    private boolean chip;

    public Tablet(String marca, String modelo, String sistema, boolean chip) {
        super(marca, modelo, sistema);
        this.chip = chip;
    }

    @Override
    public String toString() {
        return "Datos de la Tablet:\n" +
                "Marca             -> " + getMarca() + "\n" +
                "Modelo            -> " + getModelo() + "\n" +
                "Sistema Operativo -> " + getSistema() + "\n" +
                "Tiene chip        -> " + (chip ? "Si" : "No");
    }
}



public class Ejercicio_3 {
    public static void main(String[] args) {
        Telefono tel01 = new Telefono("Samsung", "A150", "Linux", 123456789);
        Tablet tab01 = new Tablet("IPhone", "90", "Ubuntu", true);
        System.out.println(tel01);
        System.out.println();
        System.out.println(tab01);
    }
}
