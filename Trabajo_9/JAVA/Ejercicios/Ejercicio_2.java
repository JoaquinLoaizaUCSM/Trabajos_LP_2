package Trabajo_9.Ejercicios;

interface Animal {
    void comer();
    void dormir();
    void moverse();
}

class Mamifero implements Animal {
    @Override
    public void comer() {
        System.out.println("Comiendo como un mamífero");
    }

    @Override
    public void dormir() {
        System.out.println("Durmiendo como un mamífero");
    }

    @Override
    public void moverse() {
        System.out.println("Moviendo como un mamífero");
    }
}

class Ave implements Animal {
    @Override
    public void comer() {
        System.out.println("Comiendo como un ave");
    }

    @Override
    public void dormir() {
        System.out.println("Durmiendo como un ave");
    }

    @Override
    public void moverse() {
        System.out.println("Moviendo como un ave");
    }
}

class Reptil implements Animal {
    @Override
    public void comer() {
        System.out.println("Comiendo como un reptil");
    }

    @Override
    public void dormir() {
        System.out.println("Durmiendo como un reptil");
    }

    @Override
    public void moverse() {
        System.out.println("Moviendo como un reptil");
    }
}

class Pez implements Animal {
    @Override
    public void comer() {
        System.out.println("Comiendo como un pez");
    }

    @Override
    public void dormir() {
        System.out.println("Durmiendo como un pez");
    }

    @Override
    public void moverse() {
        System.out.println("Moviendo como un pez");
    }
}

public class Ejercicio_2 {

    static void infoAnimal(Animal animal) {
        animal.comer();
        animal.dormir();
        animal.moverse();
    }
    public static void main(String[] args) {
        Animal[] animales = new Animal[4];

        animales[0] = new Mamifero();
        animales[1] = new Ave();
        animales[2] = new Reptil();
        animales[3] = new Pez();

        for (Animal animal : animales) {
            infoAnimal(animal);
        }
    }
}