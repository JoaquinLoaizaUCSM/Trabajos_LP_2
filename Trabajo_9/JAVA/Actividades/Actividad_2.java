package Trabajo_9.Actividades;

class Calculadora {
    public int sumar(int a, int b) {
        System.out.println("Sumando enteros");
        return a + b;
    }
    public double sumar(double a, double b) {
        System.out.println("Sumando doubles");
        return a + b;
    }
    public int sumar(int a, int b, int c) {
        System.out.println("Sumando enteros");
        return a + b + c;
    }
}
public class Actividad_2 {
    public static void main(String[] args) {
        Calculadora calc = new Calculadora();
        System.out.println(calc.sumar(5, 3)); 
        System.out.println(calc.sumar(2.5, 3.7)); 
        System.out.println(calc.sumar(10, 20,30)); 
    }
}