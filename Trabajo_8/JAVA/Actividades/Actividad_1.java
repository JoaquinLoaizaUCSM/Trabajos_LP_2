/*
package Trabajo_7.Actividades;

import java.util.Scanner;

interface Forma {
    double calcularPerimetro();
}

class Circulo implements Forma {
    private double radio;

    public Circulo(double radio) {
        this.radio = radio;
    }

    @Override
    public double calcularPerimetro() {
        return 2 * Math.PI * radio;
    }
}

class Rectangulo implements Forma {
    private double largo;
    private double ancho;

    public Rectangulo(double largo, double ancho) {
        this.largo = largo;
        this.ancho = ancho;
    }

    @Override
    public double calcularPerimetro() {
        return 2 * (largo + ancho);
    }
}

class Triangulo implements Forma {
    private double lado1;
    private double lado2;
    private double lado3;

    public Triangulo(double lado1, double lado2, double lado3) {
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
    }

    @Override
    public double calcularPerimetro() {
        return lado1 + lado2 + lado3;
    }
}

public class Actividad_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Forma forma = null;

        System.out.println("Seleccione una forma (1: Círculo, 2: Rectángulo, 3: Triángulo): ");
        int opcion = scanner.nextInt();

        switch (opcion) {
            case 1:
                System.out.println("Ingrese el radio del círculo: ");
                double radio = scanner.nextDouble();
                forma = new Circulo(radio);
                break;
            case 2:
                System.out.println("Ingrese el largo y ancho del rectángulo: ");
                double largo = scanner.nextDouble();
                double ancho = scanner.nextDouble();
                forma = new Rectangulo(largo, ancho);
                break;
            case 3:
                System.out.println("Ingrese los tres lados del triángulo: ");
                double lado1 = scanner.nextDouble();
                double lado2 = scanner.nextDouble();
                double lado3 = scanner.nextDouble();
                forma = new Triangulo(lado1, lado2, lado3);
                break;
            default:
                System.out.println("Opción no válida.");
                break;
        }

        if (forma != null) {
            System.out.println("El perímetro es: " + forma.calcularPerimetro());
        }

        scanner.close();
    }
}
*/
