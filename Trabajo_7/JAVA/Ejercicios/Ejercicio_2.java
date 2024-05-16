package Trabajo_7.Ejercicios;

class Persona {
    protected String correo;
    private String nombre;
    private int edad;
    private float salario;

    public Persona(String nombre, int edad, float salario, String correo) {
        this.nombre = nombre;
        this.edad = edad;
        this.salario = salario;
        this.correo = correo;
    }

    public String getNombre() {return nombre;}

    public int getEdad() {return edad;}

    public float getSalario() {return salario;}

    public String getCorreo() {return correo;}

    public void setCorreo(String correo) {this.correo = correo;}
}

class Empleado extends Persona {
    private int codigo;

    public Empleado(String nombre, int edad, float salario, String correo, int codigo) {
        super(nombre, edad, salario, correo);
        this.codigo = codigo;
    }

    @Override
    public String toString() {
        return "Datos del empleado:\n" +
                "Codigo  -> " + codigo + "\n" +
                "Nombre  -> " + getNombre() + "\n" +
                "Edad    -> " + getEdad() + "\n" +
                "Salario -> " + getSalario() + "\n" +
                "Correo  -> " + getCorreo();
    }
}

class Cliente extends Persona {
    private String estadoCivil;

    public Cliente(String nombre, int edad, float salario, String correo, String estadoCivil) {
        super(nombre, edad, salario, correo);
        this.estadoCivil = estadoCivil;
    }

    @Override
    public String toString() {
        return "Datos del cliente:\n" +
                "Estado  -> " + estadoCivil + "\n" +
                "Nombre  -> " + getNombre() + "\n" +
                "Edad    -> " + getEdad() + "\n" +
                "Salario -> " + getSalario() + "\n" +
                "Correo  -> " + getCorreo();
    }
}

public class Ejercicio_2 {
    public static void main(String[] args) {
        Empleado jose = new Empleado("Jose", 18, 950, "jose.luis@gmail.com", 123);
        Cliente pepe = new Cliente("Pepe", 19, 1000, "pepe.zoto@gmail.com", "Casado");
        jose.setCorreo("Joaquin.data.52@gmail.com");
        System.out.println(jose);
        System.out.println();
        System.out.println(pepe);
    }
}
