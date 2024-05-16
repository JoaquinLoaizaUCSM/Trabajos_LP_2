package Trabajo_7.Ejercicios;

class Vehiculo {
    private String marca;
    private String modelo;
    private int anio;
    private float precio;

    public Vehiculo(String marca, String modelo, int anio, float precio) {
        this.marca = marca;
        this.modelo = modelo;
        this.anio = anio;
        this.precio = precio;
    }

    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }

    public int getAnio() {
        return anio;
    }

    public float getPrecio() {
        return precio;
    }
}


}

class Automovil extends Vehiculo {
    private int n_puertas;
    private String tipo_c;

    public Automovil(String marca, String modelo, int anio, float precio, int n_puertas, String tipo_c) {
        super(marca, modelo, anio, precio);
        this.n_puertas = n_puertas;
        this.tipo_c = tipo_c;
    }

    @Override
    public String toString() {
        return "Caracteristicas de Auto xd:\n" +
                "Marca            -> " + getMarca() + "\n" +
                "Modelo           -> " + getModelo() + "\n" +
                "Anio             -> " + getAnio() + "\n" +
                "Precio           -> " + getPrecio() + "\n" +
                "Numero Puertas   -> " + n_puertas + "\n" +
                "Tipo Combustible -> " + tipo_c;
    }
}

class Moto extends Vehiculo {
    private int cilindrada;

    public Moto(String marca, String modelo, int anio, float precio, int cilindrada) {
        super(marca, modelo, anio, precio);
        this.cilindrada = cilindrada;
    }

    @Override
    public String toString() {
        return "Caracteristicas de Moto:\n" +
                "Marca        -> " + getMarca() + "\n" +
                "Modelo       -> " + getModelo() + "\n" +
                "Anio         -> " + getAnio() + "\n" +
                "Precio       -> " + getPrecio() + "\n" +
                "Cilindrada   -> " + cilindrada + "cc";
    }
}

public class Ejercicio_1 {
    public static void main(String[] args) {
        Automovil auto_01 = new Automovil("Nissan", "WAA", 2005, 250000, 4, "Premium");
        Moto mototaxi_01 = new Moto("La", "Moto", 2010, 10000, 150);
        System.out.println(auto_01);
        System.out.println();
        System.out.println(mototaxi_01);
    }
}
