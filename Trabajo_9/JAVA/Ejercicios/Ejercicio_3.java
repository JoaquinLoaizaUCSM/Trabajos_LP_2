package Trabajo_9.Ejercicios;
/*Sistema de Nómina de Empleados: Desarrolle un sistema de nómina que calcule los salarios de
diferentes tipos de empleados (asalariados, por hora, comisionistas). Utilice el polimorfismo para
calcular los salarios de manera flexible y extensible, permitiendo agregar nuevos tipos de
empleados en el futuro.*/

import java.util.Scanner;

interface Empleado {
    double calcularSalario();
    void mostrarInformacion();
}

class Asalariado implements Empleado {
    private double salario;

    public Asalariado(double s) {
        salario = s;
    }

    public double calcularSalario() {
        return salario;
    }

    public void mostrarInformacion() {
        System.out.println("Empleado Asalariado");
        System.out.println("Salario: " + salario);
    }
}

class PorHora implements Empleado {
    private double horasTrabajadas;
    private double tarifa;

    public PorHora(double h, double t) {
        horasTrabajadas = h;
        tarifa = t;
    }

    public double calcularSalario() {
        return horasTrabajadas * tarifa;
    }

    public void mostrarInformacion() {
        System.out.println("Empleado Por Hora");
        System.out.println("Horas trabajadas: " + horasTrabajadas);
        System.out.println("Tarifa: " + tarifa);
        System.out.println("Salario: " + calcularSalario());
    }
}

class Comisionista implements Empleado {
    private double ventas;
    private double comision;

    public Comisionista(double v, double c) {
        ventas = v;
        comision = c;
    }

    public double calcularSalario() {
        return ventas * comision;
    }

    public void mostrarInformacion() {
        System.out.println("Empleado Comisionista");
        System.out.println("Ventas: " + ventas);
        System.out.println("Comisión: " + comision);
        System.out.println("Salario: " + calcularSalario());
    }
}

public class Ejercicio_3 {
    static void crearEmpleado(Empleado[] empleados, int i, Scanner sc) {
        System.out.println("Ingrese el tipo de empleado: ");
        System.out.println("1. Asalariado");
        System.out.println("2. Por Hora");
        System.out.println("3. Comisionista");
        int tipo = sc.nextInt();

        switch (tipo) {
            case 1:
                System.out.println("Ingrese el salario del empleado: ");
                double salario = sc.nextDouble();
                empleados[i] = new Asalariado(salario);
                break;

            case 2:
                System.out.println("Ingrese las horas trabajadas: ");
                double horas = sc.nextDouble();
                System.out.println("Ingrese la tarifa por hora: ");
                double tarifa = sc.nextDouble();
                empleados[i] = new PorHora(horas, tarifa);
                break;

            case 3:
                System.out.println("Ingrese las ventas del empleado: ");
                double ventas = sc.nextDouble();
                System.out.println("Ingrese la comisión: ");
                double comision = sc.nextDouble();
                empleados[i] = new Comisionista(ventas, comision);
                break;

            default:
                System.out.println("Opción inválida");
                break;
        }
    }

    public static void main(String[] args) {
        Empleado[] empleados = new Empleado[3];

        empleados[0] = new Asalariado(5000);
        empleados[1] = new PorHora(40, 10);
        empleados[2] = new Comisionista(10000, 0.05);

        for (Empleado empleado : empleados) {
            empleado.mostrarInformacion();
        }


    System.out.println("Ingrese el número de empleados que desea agregar_empleado: ");
    Scanner sc = new Scanner(System.in);
    int NumEmpleados = sc.nextInt();

    empleados = new Empleado[NumEmpleados];

    for (int i = 0; i < NumEmpleados; i++) crearEmpleado(empleados, i, sc);

    for (Empleado empleado : empleados) {
        empleado.mostrarInformacion();
    }

    }

}
