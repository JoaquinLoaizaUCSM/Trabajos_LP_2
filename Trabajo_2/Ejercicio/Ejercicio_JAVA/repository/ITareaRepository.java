package Trabajo_4.actividad.repository;

import Trabajo_4.actividad.models.Tarea;
import java.util.List;



public interface ITareaRepository {

    void save(Tarea tarea);

    List<Tarea> findAll();

    Tarea findById(Long id);

    void update(Tarea tarea);

    void deleteById(Long id);

}