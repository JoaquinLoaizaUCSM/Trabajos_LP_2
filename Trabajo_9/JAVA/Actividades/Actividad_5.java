package Trabajo_9.Actividades;


interface Figura { // Interfaz Figura
    double calcularArea();
    double calcularPerimetro();
}


class Circulo implements Figura {

    private double radio;
    public Circulo(double r) { radio = r; }

    public double calcularArea() {
        return Math.PI * radio * radio;
    }

    public double calcularPerimetro() {
        return Math.PI * radio;
    }

}

class Rectangulo implements Figura {

    private double base, altura;

    public Rectangulo(double b, double h) { base = b; altura = h; }

    public double calcularArea() {
        return base * altura;
    }

    public double calcularPerimetro() {
        return 2 * (base + altura);
    }
}


class Triangulo implements Figura {

    private double base, altura;

    public Triangulo(double b, double h) {
        base = b;
        altura = h;
    }

    public double calcularArea() {
        return (base * altura) / 2;
    }

    public double calcularPerimetro() {
        return base + altura + Math.sqrt(Math.pow(base, 2) + Math.pow(altura, 2));
    }
}

public class Actividad_5 {
    public static void main(String[] args) {


        Figura figura1 = new Circulo(5.0);
        Figura figura2 = new Rectangulo(4.0, 6.0);
        Figura figura3 = new Triangulo(2, 10);

        // Los resultados en 2 decimales
        System.out.println("Área del círculo: " + String.format("%.2f", figura1.calcularArea()));
        System.out.println("Perímetro del círculo: " + String.format("%.2f", figura1.calcularPerimetro()));
        System.out.println("Área del rectángulo: " + String.format("%.2f", figura2.calcularArea()));

        System.out.println("Perímetro del rectángulo: " + String.format("%.2f", figura2.calcularPerimetro()));
        System.out.println("Perímetro del triángulo: " + String.format("%.2f", figura3.calcularPerimetro()));
        System.out.println("Perímetro del triángulo: " + String.format("%.2f", figura3.calcularPerimetro()));

    }
}
