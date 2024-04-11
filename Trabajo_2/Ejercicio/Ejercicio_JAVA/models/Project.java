package Trabajo_4.actividad.models;

import java.util.ArrayList;
import java.util.List;

public class Project {
    private Long id;
    private String nombre;
    private List<Tarea> tasks;
    private String descripcion;

    public Project(Long id, String nombre, String descripcion) {
        this.id = id;
        this.nombre = nombre;
        this.tasks = new ArrayList<>();
        this.descripcion = descripcion;
    }


    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public List<Tarea> getTasks() {
        return tasks;
    }

    public void setTasks(List<Tarea> tasks) {
        this.tasks = tasks;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }
}
