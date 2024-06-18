import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class Ruta<T extends Number> {
    protected String id_ruta;
    protected String conductor;
    protected int num_dis;
    protected List<T> distancias = new ArrayList<>();
    protected T dis_total;
    protected T t_estimado;
    protected T vel_vehiculo;
    protected T vehiculo;

    public Ruta(String id, String con, T vel, int num) {
        this.id_ruta = id;
        this.conductor = con;
        this.vel_vehiculo = vel;
        this.num_dis = num;
    }

    public String getId() {
        return id_ruta;
    }

    public void vehiculoAsignado(T vehicle) {
        this.vehiculo = vehicle;
        System.out.println("El vehiculo del conductor " + this.conductor + " sera el: " + vehicle);
    }

    public void ingresoRutas() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 1; i < num_dis + 1; i++) {
            System.out.println("Ingrese la distancia n" + i + " a recorrer: ");
            T dis = (T) Double.valueOf(scanner.nextDouble());
            distancias.add(dis);
            System.out.println("Ingresado correctamente.");
        }
    }

    public void calculoDistancia() {
        double total = 0;
        for (T dis : distancias) {
            total += dis.doubleValue();
        }
        this.dis_total = (T) total;
        System.out.println("La distancia total a recorrer es de " + dis_total + " km.");
    }

    public void tiempoEntrega() {
        this.t_estimado = (T) (dis_total.doubleValue() / vel_vehiculo.doubleValue());
        System.out.println("El tiempo de entrega estimado es de " + t_estimado + " horas.");
    }

    @Override
    public String toString() {
        return "Datos ruta ID " + id_ruta + " :\n" +
                "Conductor       -> " + conductor + "\n" +
                "Vehiculo        -> " + vehiculo + "\n" +
                "Velocidad       -> " + vel_vehiculo + "\n" +
                "Distancia       -> " + dis_total + "\n" +
                "Tiempo estimado -> " + t_estimado + "\n";
    }
}

class GestionRutas<G extends Number> {
    protected List<Ruta<G>> rutas = new ArrayList<>();

    public void agregarRuta(Ruta<G> ruta) {
        rutas.add(ruta);
    }

    public void eliminarRuta(String id) {
        Iterator<Ruta<G>> iterator = rutas.iterator();
        while (iterator.hasNext()) {
            Ruta<G> ruta = iterator.next();
            if (ruta.getId().equals(id)) {
                iterator.remove();
            }
        }
    }

    public void buscarRuta(String id) {
        for (Ruta<G> ruta : rutas) {
            if (ruta.getId().equals(id)) {
                System.out.println(ruta);
            }
        }
    }

    public void mostrarRutas() {
        for (Ruta<G> ruta : rutas) {
            System.out.println(ruta);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("Esta actividad ya cumplia con lo solicitado al contar con un almacen de objetos de otra clase :) ");

        // Creacion Rutas
        Ruta<Integer> ruta1 = new Ruta<>("001", "Grossman", 120, 3);
        ruta1.vehiculoAsignado(1234);
        ruta1.ingresoRutas();
        ruta1.calculoDistancia();
        ruta1.tiempoEntrega();

        Ruta<Integer> ruta2 = new Ruta<>("002", "Yhosfer", 5, 2);
        ruta2.vehiculoAsignado(5678);
        ruta2.ingresoRutas();
        ruta2.calculoDistancia();
        ruta2.tiempoEntrega();

        // Ingreso de rutas
        GestionRutas<Integer> gestion = new GestionRutas<>();
        gestion.agregarRuta(ruta1);
        gestion.agregarRuta(ruta2);

        System.out.println("Rutas:");
        gestion.mostrarRutas();

        // Eliminacion ruta
        gestion.eliminarRuta("001");

        System.out.println("Rutas parte 2:");
        gestion.mostrarRutas();
    }
}