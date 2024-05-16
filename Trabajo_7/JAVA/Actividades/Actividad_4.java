/*
package Trabajo_7.Actividades;

class Cliente {

    public String getNombre() {return nombre;}

    public String getApellido() {return apellido;}

    public String getNumeroIdentificacion() {return numeroIdentificacion;}

    protected String nombre;
    protected String apellido;
    protected String numeroIdentificacion;
    protected String correoElectronico;
    protected String cuentaBancaria;

    public Cliente(String nombre, String apellido, String numeroIdentificacion, String correoElectronico, String cuentaBancaria) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.numeroIdentificacion = numeroIdentificacion;
        this.correoElectronico = correoElectronico;
        this.cuentaBancaria = cuentaBancaria;
    }

    // Getters and setters (opcional)

    @Override
    public String toString() {
        return "Nombre='" + nombre + '\'' +
                ", Apellido='" + apellido + '\'' +
                ", Identificacion='" + numeroIdentificacion + '\'' +
                ", Correo electronico='" + correoElectronico + '\'' +
                ", CuentaBancaria='" + cuentaBancaria + '\''
                ;
    }

    protected String encriptarInformacion(String informacion) {
        // Implementar la lógica de encriptación (por ejemplo, usando una biblioteca de encriptación)

        String informacionEncriptada = informacion + " encriptada";
        return informacionEncriptada;
    }
}

class ClienteSeguro extends Cliente {

    private String claveEncriptada;

    public ClienteSeguro(String nombre, String apellido, String numeroIdentificacion,
                         String correoElectronico, String cuentaBancaria, String claveEncriptada) {
        super(nombre, apellido, numeroIdentificacion, correoElectronico, cuentaBancaria); // Llamada al constructor de la clase base
        this.claveEncriptada = claveEncriptada;
    }

    public String getClaveEncriptada() {
        return claveEncriptada;
    }

    public void setClaveEncriptada(String claveEncriptada) {
        this.claveEncriptada = claveEncriptada;
    }

    // Métodos para encriptar y verificar la autenticidad del cliente (implementarlos según la lógica requerida)
    public String encriptarInformacionAdicionalConProteccion(String informacionAdicional) {
        // Encriptar información adicional utilizando el método protegido de la clase base
        String informacionEncriptadaAdicional = super.encriptarInformacion(informacionAdicional);
        // Procesamiento adicional sobre la información encriptada (opcional)
        return informacionEncriptadaAdicional;
    }

    public boolean verificarAutenticidad(String claveIngresada) {
        // Implementar la lógica de verificación de autenticidad (comparar la clave ingresada con la clave encriptada)
        return claveIngresada.equals(claveEncriptada);
    }

    @Override
    protected void finalize() throws Throwable{
        // Liberar recursos específicos de la clase derivada (si los hay)
        System.out.println("Liberando recursos de ClienteSeguro para: " + nombre + " " + apellido);
    }
}



public class Actividad_4 {

    public static void main(String[] args) {
        ClienteSeguro clienteSeguro = new ClienteSeguro("Juan Perez",
                "Gomez",
                "123456789",
                "juan.perez@email.com",
                "1234567890",
                "claveSecretaEncriptada");

        // Acceso a atributos heredados de la clase base "Cliente"
        System.out.println("Nombre: " + clienteSeguro.getNombre());
        System.out.println("Apellido: " + clienteSeguro.getApellido());
        System.out.println("Número de identificación: " + clienteSeguro.getNumeroIdentificacion());

        // Llamada a métodos heredados de la clase base "Cliente"
        System.out.println("Información del cliente: " + clienteSeguro.toString());

        // Acceso a atributos específicos de la clase derivada "ClienteSeguro"
        System.out.println("Clave encriptada: " + clienteSeguro.getClaveEncriptada());

        // Llamada a métodos específicos de la clase derivada "ClienteSeguro"
        String informacionEncriptada = clienteSeguro.encriptarInformacion("Información personal");
        System.out.println("Información personal encriptada: " + informacionEncriptada);

        boolean autenticado = clienteSeguro.verificarAutenticidad("claveSecretaEncriptada");
        if (autenticado) {
            System.out.println("Autenticación exitosa.");
        } else {
            System.out.println("Autenticación fallida.");
        }
    }
}
*/
