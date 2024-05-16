/*

package Trabajo_7.Actividades;


import java.util.Scanner;

class Cliente {
    protected String nombre;
    protected int telefono;
    protected String correo;
    protected String cuentaBancaria;
    protected double monto;

    Cliente(String nombre, int telefono, String correo, String cuentaBancaria, double monto) {
        this.nombre = nombre;
        this.telefono = telefono;
        this.correo = correo;
        this.cuentaBancaria = cuentaBancaria;
        this.monto = monto;
    }

    @Override
    public String toString() {
        return "Nombre: " + nombre + "\n" +
                "Telefono: " + telefono + "\n" +
                "Correo: " + correo + "\n" +
                "Cuenta Bancaria: " + cuentaBancaria + "\n" +
                "Monto: " + monto;
    }
}

class ClienteSeguro extends Cliente {
    private final String claveEncriptada;

    ClienteSeguro(String nombre, int telefono, String correo, String cuentaBancaria, double monto, String clave) {
        super(nombre, telefono, correo, cuentaBancaria, monto);
        this.nombre = encriptarInformacion(nombre,3);
        this.telefono = telefono;
        this.correo = encriptarInformacion(correo,3);
        this.cuentaBancaria = encriptarInformacion(cuentaBancaria,3);
        this.monto = monto;
        this.claveEncriptada = encriptarInformacion(clave,3);
    }

    String getClaveEncriptada() {
        return claveEncriptada;
    }

    static String encriptarInformacion(String informacion, int desplazamiento) {
        StringBuilder resultado = new StringBuilder();
        for (int i = 0; i < informacion.length(); i++) {
            if (Character.isDigit(informacion.charAt(i))) // verificar si es un digito
                resultado.append((char) ((informacion.charAt(i) + desplazamiento - '0') % 10 + '0'));
            else if (Character.isUpperCase(informacion.charAt(i))) // verificar si es una letra mayuscula
                resultado.append((char) ((informacion.charAt(i) + desplazamiento - 'A') % 26 + 'A'));
            else  // verificar si es una letra minuscula
                resultado.append((char) ((informacion.charAt(i) + desplazamiento - 'a') % 26 + 'a'));
        }
        return resultado.toString();
    }

    private static String descriptarInformacion(String informacion, int desplazamiento) {
        StringBuilder resultado = new StringBuilder();
        for (int i = 0; i < informacion.length(); i++) {
            if (Character.isDigit(informacion.charAt(i))) // verificar si es un digito
                resultado.append((char) ((informacion.charAt(i) - desplazamiento - 48 + 10) % 10 + 48));
            else if (Character.isUpperCase(informacion.charAt(i))) // verificar si es una letra mayuscula
                resultado.append((char) ((informacion.charAt(i) - desplazamiento - 65 + 26) % 26 + 65));
            else // verificar si es una letra minuscula
                resultado.append((char) ((informacion.charAt(i) - desplazamiento - 97 + 26) % 26 + 97));
        }
        return resultado.toString();
    }

    boolean verificarAutenticidad(String claveIngresada) {
        return claveIngresada.equals(descriptarInformacion(claveEncriptada,3));
    }
}

public class Actividad_1 {
    public static void main(String[] args) {
        ClienteSeguro grossman = new ClienteSeguro("Juan Perez",
                987654321,
                "Juan.Perez@gmail.com",
                "123456789",
                1000.0,
                "1234");

        System.out.println(grossman);

        System.out.println("Clave encriptada: " + grossman.getClaveEncriptada());

        System.out.println("Ingrese la clave para verificar la autenticidad:");
        Scanner scanner = new Scanner(System.in);
        String claveIngresada = scanner.nextLine();

        if (grossman.verificarAutenticidad(claveIngresada)) {
            System.out.println("La clave ingresada es correcta");
        } else {
            System.out.println("La clave ingresada es incorrecta");
        }
    }
}
*/
