package Trabajo_4.actividad.models;

public class Tarea {

    private long id;
    private String titulo;
    private String descripcion;
    private boolean completada;
    private Date fechaLimite;

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public Tarea(long id, String titulo, String descripcion) {
        this.id = id;
        this.titulo = titulo;
        this.descripcion = descripcion;
        this.completada = false;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public boolean isCompletada() {
        return completada;
    }

    public void setCompletada(boolean completada) {
        this.completada = completada;
    }
}