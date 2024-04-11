package Trabajo_4.actividad.repository;

import Trabajo_4.actividad.models.Project;

public interface IProyectRepository {

    void createProyect(Project project);

    void deleteProyect(Long id);

    void AdmitProyect(Project project);

}

