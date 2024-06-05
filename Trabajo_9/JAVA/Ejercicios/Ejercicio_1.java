package Trabajo_9.Ejercicios;
import java.util.Scanner;

interface Figura { // Interfaz Figura
    double calcularArea();
    double calcularPerimetro();
    void mostrarInformacion();
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

    public void mostrarInformacion() {
        System.out.println("Círculo");
        System.out.println("Radio: " + radio);
        System.out.println("Área: " + calcularArea());
        System.out.println("Perímetro: " + calcularPerimetro());
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

    public void mostrarInformacion() {
        System.out.println("Rectángulo");
        System.out.println("Base: " + base);
        System.out.println("Altura: " + altura);
        System.out.println("Área: " + calcularArea());
        System.out.println("Perímetro: " + calcularPerimetro());
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

    public void mostrarInformacion() {
        System.out.println("Triángulo");
        System.out.println("Base: " + base);
        System.out.println("Altura: " + altura);
        System.out.println("Área: " + calcularArea());
        System.out.println("Perímetro: " + calcularPerimetro());
    }
}

class Trapecio implements Figura {

    private double baseMayor, baseMenor, altura;

    public Trapecio(double bM, double bm, double h) {
        baseMayor = bM;
        baseMenor = bm;
        altura = h;
    }

    public double calcularArea() {
        return ((baseMayor + baseMenor) * altura) / 2;
    }

    public double calcularPerimetro() {
        return baseMayor + baseMenor + 2 * Math.sqrt(Math.pow((baseMayor - baseMenor) / 2, 2) + Math.pow(altura, 2));
    }

    public void mostrarInformacion() {
        System.out.println("Trapecio");
        System.out.println("Base Mayor: " + baseMayor);
        System.out.println("Base Menor: " + baseMenor);
        System.out.println("Altura: " + altura);
        System.out.println("Área: " + calcularArea());
        System.out.println("Perímetro: " + calcularPerimetro());
    }
}

public class Ejercicio_1 {

    static void menu() {
        System.out.println("Ingrese la figura que desea agregar: ");
        System.out.println("1. Círculo");
        System.out.println("2. Rectángulo");
        System.out.println("3. Triángulo");
    }

    static void opciones(int opcion, Figura[] figuras, int i, Scanner sc) {
        switch (opcion) {
            case 1:
                System.out.println("Ingrese el radio del círculo: ");
                double radio = sc.nextDouble();
                figuras[i] = new Circulo(radio);
                break;

            case 2:
                System.out.println("Ingrese la base del rectángulo: ");
                double base = sc.nextDouble();
                System.out.println("Ingrese la altura del rectángulo: ");
                double altura = sc.nextDouble();
                figuras[i] = new Rectangulo(base, altura);
                break;

            case 3:
                System.out.println("Ingrese la base del triángulo: ");
                double baseT = sc.nextDouble();
                System.out.println("Ingrese la altura del triángulo: ");
                double alturaT = sc.nextDouble();
                figuras[i] = new Triangulo(baseT, alturaT);
                break;

            case 4:
                System.out.println("Ingrese la base mayor del trapecio: ");
                double baseMayor = sc.nextDouble();
                System.out.println("Ingrese la base menor del trapecio: ");
                double baseMenor = sc.nextDouble();
                System.out.println("Ingrese la altura del trapecio: ");
                double alturaTrapecio = sc.nextDouble();
                figuras[i] = new Trapecio(baseMayor, baseMenor, alturaTrapecio);
                break;

            default:
                System.out.println("Opción inválida");
                break;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int NumFiguras = 0;

        System.out.println("Ingrese el número de figuras que desea agregar: ");
        NumFiguras = sc.nextInt();
        Figura[] figuras = new Figura[NumFiguras];

        for (int i = 0; i < NumFiguras; i++) {
            menu();
            int opcion = sc.nextInt();
            opciones(opcion, figuras, i, sc);
        }

        for (Figura figura : figuras) {
            figura.mostrarInformacion();
        }

    }
}