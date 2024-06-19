import java.util.Scanner;

public class Ruta {
    protected String id_ruta;
    protected String conductor;

    public Ruta(String id, String con) {
        this.id_ruta = id;
        this.conductor = con;
    }

    public <T> void vehiculo_asignado(T vehicle) {
        System.out.println("El vehiculo del conductor " + this.conductor + " sera el: " + vehicle);
    }

    public <G extends Number> void designar_horario() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese la distancia total: ");
        G dis_total = (G) Double.valueOf(scanner.nextDouble());
        if (dis_total.doubleValue() < 100) {
            System.out.println("La entrega se realizará el jueves.");
        } else {
            if (dis_total.doubleValue() > 101.5) {
                System.out.println("La entrega se realizará el viernes.");
            }
        }
    }

    public static void main(String[] args) {
        Ruta ruta1 = new Ruta("001", "Grossman");
        Ruta ruta2 = new Ruta("002", "Joaquin");

        ruta1.vehiculo_asignado(5487);
        ruta2.vehiculo_asignado("Carcocha");

        ruta1.designar_horario();
        ruta2.designar_horario();
    }
}