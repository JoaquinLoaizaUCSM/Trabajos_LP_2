package Trabajo_4.actividad.repository;

import Trabajo_4.actividad.models.Tarea;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class TareaRepositoryImpl implements ITareaRepository {

    private List<Tarea> tareas = new ArrayList<>();

    @Override
    public void save(Tarea tarea) {
        tareas.add(tarea);
        System.out.println("Guardando tarea " + tarea.getTitulo());
    }

    @Override
    public List<Tarea> findAll() {
        return new ArrayList<>(tareas);
    }

    @Override
    public Tarea findById(Long id) {
        Optional<Tarea> tareaOptional = tareas.stream()
                .filter(tarea -> tarea.getId() == id)
                .findFirst();

        return tareaOptional.orElse(null);
    }

    @Override
    public void update(Tarea tarea) {
        Tarea existingTarea = findById(tarea.getId());
        if (existingTarea != null) {
            tareas.remove(existingTarea);
            tareas.add(tarea);
        }
    }

    @Override
    public void deleteById(Long id) {
        Tarea existingTarea = findById(id);
        if (existingTarea != null) {
            tareas.remove(existingTarea);
        }
    }

    public void trackTask(Tarea tarea) {
        System.out.println("Tarea: " + tarea.getTitulo() + " " + tarea.getDescripcion());
        System.out.println("Estado: " + tarea.isCompletada());

    }
}