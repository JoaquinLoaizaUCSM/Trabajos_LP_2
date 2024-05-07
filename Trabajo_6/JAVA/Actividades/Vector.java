package Trabajo_6.JAVA.Actividades;

public class Vector {

    private double x;
    private double y;

    public Vector(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {return x;}

    public void setX(double x) {this.x = x;}

    public double getY() {return y;}

    public void setY(double y) {this.y = y;}


    public Vector sumar(Vector vector) {
        return new Vector(this.x + vector.x, this.y + vector.y);
    }

    public Vector restar(Vector vector) {
        return new Vector(this.x - vector.x, this.y - vector.y);
    }

    public static void main(String[] args) {
        Vector vector1 = new Vector(3.0, 4.0);
        Vector vector2 = new Vector(5.0, 2.0);

        Vector suma = vector1.sumar(vector2);
        System.out.println("Vector suma: (" + suma.x + ", " + suma.y + ")");

        Vector resta = vector1.restar(vector2);
        System.out.println("Vector resta: (" + resta.x + ", " + resta.y + ")");
    }
}
