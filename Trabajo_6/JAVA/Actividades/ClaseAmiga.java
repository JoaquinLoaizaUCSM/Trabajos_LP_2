package Trabajo_6.JAVA.Actividades;

class ClaseAmiga {
    private  class  Circulo {
        private double radio;
        private double diametro;

        // Constructor
        public Circulo(double radio) {
            this.radio = radio;
            this.diametro = 2 * radio;
        }

        // Método para obtener el radio
        public double getRadio() {
            return this.radio;
        }

        // Método para calcular el área
        public double calcularArea() {
            return Math.PI * Math.pow(this.radio, 2);
        }
    }
    public  void main(String[] args) {
        Circulo circulo = new Circulo(5.0);
        double area = circulo.calcularArea();
        System.out.println("El área del círculo es: " + area);
    }
}




