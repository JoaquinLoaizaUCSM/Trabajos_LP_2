package Trabajo_4.actividad;

import Trabajo_4.actividad.models.*;
import Trabajo_4.actividad.repository.*;

public class Main {
    public static void main(String[] args) {
        // Crear instancias de los repositorios
        ProyectRepositoryImpl proyectRepository = new ProyectRepositoryImpl();
        CommentRepositoryImpl commentRepository = new CommentRepositoryImpl();
        ArchivoRepositoryImpl archivoRepository = new ArchivoRepositoryImpl();

        // Crear un proyecto, un comentario y un archivo
        Date fecha = new Date("2021-10-10", "10:00");
        Usuario usuario = new Usuario("Joaqui.loaiza", "1234", "Joaquin.loaza@gmail.com", "joaquin");
        Project proyecto = new Project(1L, "Proyecto 1", "Este es un proyecto");
        Comment comentario = new Comment(1L,"Comenet", fecha, usuario);
        Archivo archivo = new Archivo("algoritmos", ".cpp", "busqueda binaria");

        // Probar el módulo de proyectos
        proyectRepository.createProyect(proyecto);
        proyectRepository.AdmitProyect(proyecto);
        proyectRepository.deleteProyect(proyecto.getId());

        // Probar el módulo de comentarios
        commentRepository.createComment(comentario);
        commentRepository.AdmitComment(comentario);
        commentRepository.deleteComment(comentario.getId());

        // Probar el módulo de archivos
        archivoRepository.createArchivo(archivo);
        archivoRepository.AdmitArchivo(archivo);
        archivoRepository.deleteArchivo(archivo.getNombre());
    }
}