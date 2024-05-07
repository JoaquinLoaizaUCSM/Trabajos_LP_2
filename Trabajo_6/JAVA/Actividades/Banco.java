package Trabajo_6.JAVA.Actividades;

public class Banco {
    static double tasaInteres;

    static void cambiarTasaInteres(double tasaInteres) {
        Banco.tasaInteres = tasaInteres;
    }

    public class CuentaBancaria {
        private double saldo;

        public CuentaBancaria(double saldoInicial) {
            this.saldo = saldoInicial;
        }

        public void depositar(double cantidad) {
            if (cantidad > 0) {
                saldo += cantidad;
            }
        }

        public void retirar(double cantidad) {
            if (cantidad > 0 && cantidad <= saldo) {
                saldo -= cantidad;
            }
        }

        public double calcularInteres() {
            return saldo * Banco.tasaInteres;
        }
    }

    public static void main(String[] args) {
        Banco.cambiarTasaInteres(0.05);
        Banco.CuentaBancaria cuenta = new Banco().new CuentaBancaria(1000);
        cuenta.depositar(500);
        cuenta.retirar(200);
        double interes = cuenta.calcularInteres();
        System.out.println("El interés generado es: " + interes);
    }
}