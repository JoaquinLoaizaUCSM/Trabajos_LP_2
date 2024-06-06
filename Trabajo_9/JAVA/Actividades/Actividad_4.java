package Trabajo_9.Actividades;

class Animal {
    public void hacerSonido() 
    {
        System.out.println("Sonido genérico de animal");
    }
}

class Perro extends Animal {
    @Override
    public void hacerSonido() 
    {
        System.out.println("Guau!");
    }
}

class Gato extends Animal{
    @Override
    public void hacerSonido()
    {
        System.out.println("Miau");
    }

}

class Vaca extends Animal{
    @Override
    public void hacerSonido()
    {
        System.out.println("Muuu");
    }

}

public class Actividad_4 {
    public static void main(String[] args) {
    
        Animal[] animales = new Animal[3];

        animales[0] = new Perro();
        animales[1] = new Gato();
        animales[2] = new Vaca();

        for (Animal animal : animales) {
            animal.hacerSonido();
        }   
    }
}  