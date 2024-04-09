package Trabajo_4.actividad;

import Trabajo_4.actividad.models.*;
import Trabajo_4.actividad.repository.*;
import Trabajo_4.actividad.services.*;


public class Main {
    public static void main(String[] args) {
        // Crear instancias de los repositorios
        UsuarioRepositoryImpl usuarioRepository = new UsuarioRepositoryImpl();
        TareaRepositoryImpl tareaRepository = new TareaRepositoryImpl();

        // Crear instancias de los servicios
        AuthService authService = new AuthService(usuarioRepository);
        TareaService tareaService = new TareaService(tareaRepository);
        UsuarioService usuarioService = new UsuarioService(usuarioRepository);

        // Crear un usuario y una tarea
        Usuario usuario = new Usuario("username",
                                        "password",
                                        "email@example.com",
                                        "nombre");

        Tarea tarea = new Tarea(1,"titulo", "description");
        Tarea tarea2 = new Tarea(2,"titulo2", "description2");
        Tarea tarea3 = new Tarea(3,"titulo3", "description3");

        // Registrar el usuario y la tarea
        usuarioService.registerUsuario(usuario);
        tareaService.createTarea(tarea);
        tareaService.createTarea(tarea2);
        tareaService.createTarea(tarea3);

        // Autenticar el usuario
        if(authService.authenticate("username", "password")) {
            System.out.println("Usuario autenticado");
        } else {
            System.out.println("Usuario no autenticado");
        }

        // Obtener todas las tareas
        System.out.println("Tareas:");
        for (Tarea t : tareaService.getAllTareas()) {
            System.out.println(t);
        }

        // Actualizar la tarea
        tarea.setTitulo("nuevo titulo");
        tareaService.updateTarea(tarea);

        // Obtener la tarea por ID
        Tarea tareaById = tareaService.getTareaById(tarea.getId());
        System.out.println("Tarea by id: " + tareaById);

        // Eliminar la tarea
        tareaService.deleteTarea(tarea.getId());

        // Obtener todos los nombres de las tareas
        System.out.println("Tareas:");
        for (Tarea t : tareaService.getAllTareas()) {
            System.out.println(t.getTitulo());
        }

        // Seguimiento de la tarea
        tareaService.trackTask(tarea2);

    }
}