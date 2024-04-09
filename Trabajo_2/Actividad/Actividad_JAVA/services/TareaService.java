package Trabajo_4.actividad.services;

import Trabajo_4.actividad.models.Tarea;
import Trabajo_4.actividad.repository.TareaRepositoryImpl;

import java.util.List;

public class TareaService {

    private TareaRepositoryImpl tareaRepository;

    public TareaService(TareaRepositoryImpl tareaRepository) {
        this.tareaRepository = tareaRepository;
    }

    public void createTarea(Tarea tarea) {
        tareaRepository.save(tarea);
    }

    public List<Tarea> getAllTareas() {
        return tareaRepository.findAll();
    }

    public Tarea getTareaById(Long id) {
        return tareaRepository.findById(id);
    }

    public void updateTarea(Tarea tarea) {
        tareaRepository.update(tarea);
    }

    public void deleteTarea(Long id) {
        tareaRepository.deleteById(id);
    }

    public void trackTask(Tarea task) {
        tareaRepository.trackTask(task);
    }

}