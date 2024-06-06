/*
package Trabajo_9.Actividades;

abstract class Figura {
    public abstract double calcularArea();
}

class Circulo extends Figura {
    private double radio;

    public Circulo(double r) { radio = r; }
    @Override
    public double calcularArea() {
        return 3.14159 * radio * radio;
    }
}

class Rectangulo extends Figura {
    private double base, altura;

    public Rectangulo(double b, double h) { base = b; altura = h; }
    @Override
    public double calcularArea() {
        return base * altura;
    }
}


class Triangulo extends Figura{
    private double base, altura;

    public Triangulo(double b, double h){base =b; altura = h;}
    @Override
    public double calcularArea(){
        return (base*altura)/2;
    }

}

public class Actividad_3 {
    public static void main(String[] args) {
    Figura[] figuras = new Figura[3];

    figuras[0] = new Circulo(5.0);
    figuras[1] = new Rectangulo(4.0, 6.0);
    figuras[2] = new Triangulo(2, 10);

        for (Figura figura : figuras) {
            System.out.println("Área: " + figura.calcularArea());
        }
    }
}

*/
