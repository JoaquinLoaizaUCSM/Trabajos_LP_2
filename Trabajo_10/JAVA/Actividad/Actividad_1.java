import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Ejecucion int :");
        realizar_informe(Integer.class);

        System.out.println("\nEjecucion double :");
        realizar_informe(Double.class);

        System.out.println("\nEjecucion long :");
        realizar_informe(Long.class);
    }

    public static <T extends Number> void realizar_informe(Class<T> type) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Indique el numero de informe : ");
        T nI = readInput(type, scanner);

        System.out.println("Ingrese la distancia n1 : ");
        T d1 = readInput(type, scanner);

        System.out.println("Ingrese la distancia n2 : ");
        T d2 = readInput(type, scanner);

        System.out.println("Ingrese la distancia n3 : ");
        T d3 = readInput(type, scanner);

        System.out.println("Ingrese la distancia n4 : ");
        T d4 = readInput(type, scanner);

        T dt = calculo_distancia(d1, d2, d3, d4);

        System.out.println("Ingrese la velocidad a la que se ira : ");
        T vel = readInput(type, scanner);

        T tf = tiempo_entrega(dt, vel);

        System.out.println("Informe de ruta: ");
        System.out.println("Distancia recorrida        -> " + dt);
        System.out.println("Velocidad del vehiculo     -> " + vel);
        System.out.println("Tiempo estimado de entrega -> " + tf);
    }

    public static <T extends Number> T calculo_distancia(T d1, T d2, T d3, T d4) {
        Double dt = d2.doubleValue() - d1.doubleValue() + d3.doubleValue() - d2.doubleValue() + d4.doubleValue() - d3.doubleValue();
        System.out.println("La distancia total a recorrer es de " + dt + " km.");
        return (T) dt;
    }

    public static <T extends Number> T tiempo_entrega(T dt, T vel) {
        Double tf = dt.doubleValue() / vel.doubleValue();
        System.out.println("El tiempo de entrega estimado es de " + tf + " horas.");
        return (T) tf;
    }

    private static <T extends Number> T readInput(Class<T> type, Scanner scanner) {
        if (type == Integer.class) {
            return (T) Integer.valueOf(scanner.nextInt());
        } else if (type == Double.class) {
            return (T) Double.valueOf(scanner.nextDouble());
        } else if (type == Long.class) {
            return (T) Long.valueOf(scanner.nextLong());
        } else {
            throw new IllegalArgumentException("Unsupported type: " + type);
        }
    }
}