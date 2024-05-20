package Trabajo_7.Actividades;

import java.util.ArrayList;
import java.util.List;


interface Animal {
    void hacerSonido();
    void moverse();
}

// Perro.java
class Perro implements Animal {
    @Override
    public void hacerSonido() {
        System.out.println("El perro ladra: ¡Guau guau!");
    }

    @Override
    public void moverse() {
        System.out.println("El perro corre.");
    }
}

class Pajaro implements Animal {
    @Override
    public void hacerSonido() {
        System.out.println("El pájaro canta: ¡Pío pío!");
    }

    @Override
    public void moverse() {
        System.out.println("El pájaro vuela.");
    }
}

public class Actividad_3 {
    public static void main(String[] args) {
        List<Animal> animales = new ArrayList<>();
        animales.add(new Perro());
        animales.add(new Pajaro());

        for (Animal animal : animales) {
            animal.hacerSonido();
            animal.moverse();
        }
    }
}
