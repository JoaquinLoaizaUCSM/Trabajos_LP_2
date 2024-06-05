class Animal{
    public void hacerSonido(){
        System.out.println("Hacer sonido generico");
    }
}

class Perro extends Animal{
    @Override
    public void hacerSonido(){
        System.out.println("Guau!");
    }
}


public class Actividad_1 {
    public static void main(String[] args) {
        Animal animal1 = new Perro();

        animal1.hacerSonido();
    }
}