package Trabajo_7.Actividades;

import java.util.Scanner;

interface Dispositivo {
    void encender();
    void apagar();
}

class Computadora implements Dispositivo {
    @Override
    public void encender() {
        System.out.println("La computadora está encendida.");
    }

    @Override
    public void apagar() {
        System.out.println("La computadora está apagada.");
    }
}

class Telefono implements Dispositivo {
    @Override
    public void encender() {
        System.out.println("El teléfono está encendido.");
    }

    @Override
    public void apagar() {
        System.out.println("El teléfono está apagado.");
    }
}

class Tablet implements Dispositivo {
    @Override
    public void encender() {
        System.out.println("La tablet está encendida.");
    }

    @Override
    public void apagar() {
        System.out.println("La tablet está apagada.");
    }
}

public class Actividad_4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Dispositivo dispositivo = null;

        System.out.println("Seleccione un dispositivo (1: Computadora, 2: Teléfono, 3: Tablet): ");
        int opcion = scanner.nextInt();

        switch (opcion) {
            case 1:
                dispositivo = new Computadora();
                break;
            case 2:
                dispositivo = new Telefono();
                break;
            case 3:
                dispositivo = new Tablet();
                break;
            default:
                System.out.println("Opción no válida.");
                break;
        }

        if (dispositivo != null) {
            dispositivo.encender();
            dispositivo.apagar();
        }

        scanner.close();
    }
}
