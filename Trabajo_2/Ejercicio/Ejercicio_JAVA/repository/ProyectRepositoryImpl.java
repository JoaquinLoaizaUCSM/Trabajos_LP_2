package Trabajo_4.actividad.repository;

import Trabajo_4.actividad.models.Project;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class ProyectRepositoryImpl {
    private List<Project> projects = new ArrayList<>();

    public void createProyect(Project project) {
        projects.add(project);
    }

    public void deleteProyect(Long id) {
        Optional<Project> projectToRemove = projects.stream()
                .filter(project -> project.getId().equals(id))
                .findFirst();

        projectToRemove.ifPresent(projects::remove);
    }

    public void AdmitProyect(Project project) {
        System.out.println("Proyecto admitido: " + project.getNombre());
    }
}