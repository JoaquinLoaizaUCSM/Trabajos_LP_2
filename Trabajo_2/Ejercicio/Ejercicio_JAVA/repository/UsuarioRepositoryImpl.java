package Trabajo_4.actividad.repository;

import Trabajo_4.actividad.models.Usuario;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class UsuarioRepositoryImpl implements IUsuarioRepository {

    private List<Usuario> usuarios = new ArrayList<>();

    @Override
    public Usuario findByUsername(String username) {
        Optional<Usuario> usuarioOptional = usuarios.stream()
                .filter(usuario -> usuario.getUsername().equals(username))
                .findFirst();

        return usuarioOptional.orElse(null);
    }

    @Override
    public void save(Usuario usuario) {
        usuarios.add(usuario);
        System.out.println("Guardando usuario " + usuario.getNombre());
    }

    @Override
    public Usuario findById(Long id) {
        Optional<Usuario> usuarioOptional = usuarios.stream()
                .filter(usuario -> usuario.getId() == id)
                .findFirst();

        return usuarioOptional.orElse(null);
    }

    @Override
    public void update(Usuario usuario) {
        Usuario existingUsuario = findById(usuario.getId());
        if (existingUsuario != null) {
            usuarios.remove(existingUsuario);
            usuarios.add(usuario);
        }
    }

    @Override
    public void deleteById(Long id) {
        Usuario existingUsuario = findById(id);
        if (existingUsuario != null) {
            usuarios.remove(existingUsuario);
        }
    }
}