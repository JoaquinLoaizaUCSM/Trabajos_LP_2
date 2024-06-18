import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Ruta {
    protected String id_ruta;
    protected String conductor;

    public Ruta(String id, String con) {
        this.id_ruta = id;
        this.conductor = con;
    }

    public <T> void vehiculoAsignado(T vehicle) {
        System.out.println("El vehiculo del conductor " + this.conductor + " sera el: " + vehicle);
    }

    public <G extends Number> void designarHorario() {
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

    public static <T extends Comparable<T>> void ordenamientoPropinas(List<T> vct) {
        int tamaño = vct.size();
        for (int i = 0; i < tamaño - 1; i++) {
            for (int j = 0; j < tamaño - i - 1; j++) {
                if (vct.get(j).compareTo(vct.get(j + 1)) > 0) {
                    T temp = vct.get(j);
                    vct.set(j, vct.get(j + 1));
                    vct.set(j + 1, temp);
                }
            }
        }
    }

    public static void main(String[] args) {
        Ruta ruta1 = new Ruta("001", "Grossman");
        Ruta ruta2 = new Ruta("002", "Joaquin");

        ruta1.vehiculoAsignado(5487);
        ruta2.vehiculoAsignado("Carcocha");

        List<Integer> propinitas = new ArrayList<>();
        propinitas.add(3);
        propinitas.add(2);
        propinitas.add(40);
        propinitas.add(22);
        propinitas.add(55);
        ordenamientoPropinas(propinitas);

        System.out.println("\n");
        for (int i = 0; i < propinitas.size(); i++){
            System.out.print(propinitas.get(i));
        }
        System.out.println("\n");

        List<Float> propinitasFlotantes = new ArrayList<>();
        propinitasFlotantes.add(5.4f);
        propinitasFlotantes.add(6.5f);
        propinitasFlotantes.add(88.4f);
        propinitasFlotantes.add(7.5f);
        propinitasFlotantes.add(99.4f);
        propinitasFlotantes.add(99.2f);
        ordenamientoPropinas(propinitasFlotantes);

        System.out.println("\n");
        for (int i = 0; i < propinitasFlotantes.size(); i++){
            System.out.print(propinitasFlotantes.get(i));
        }
        System.out.println("\n");

        ruta1.designarHorario();
        ruta2.designarHorario();
    }
}