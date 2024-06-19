import java.util.ArrayList;
import java.util.List;

public class Main {
    public static <T extends Comparable<T>> void ordenamientoVector(List<T> vct) {
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
        List<Integer> numeritos = new ArrayList<>();
        numeritos.add(1);
        numeritos.add(2);
        numeritos.add(3);
        numeritos.add(0);
        numeritos.add(9);
        numeritos.add(7);
        numeritos.add(6);
        ordenamientoVector(numeritos);

        for (int i = 0; i < numeritos.size(); i++){
            System.out.print(numeritos.get(i));
        }

        System.out.println("\n");

        List<Float> numeritosFlotantes = new ArrayList<>();
        numeritosFlotantes.add(6.5f);
        numeritosFlotantes.add(45.7f);
        numeritosFlotantes.add(85.5f);
        numeritosFlotantes.add(2.2f);
        numeritosFlotantes.add(1.1f);
        numeritosFlotantes.add(2.5f);
        numeritosFlotantes.add(4.9f);
        ordenamientoVector(numeritosFlotantes);

        for (int i = 0; i < numeritosFlotantes.size(); i++){
            System.out.print(numeritosFlotantes.get(i));
        }
    }
}