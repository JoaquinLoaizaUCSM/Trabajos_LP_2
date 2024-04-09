package Trabajo_4.actividad.services;

import Trabajo_4.actividad.models.Usuario;
import Trabajo_4.actividad.repository.IUsuarioRepository;

public class AuthService {

    private IUsuarioRepository usuarioRepository;

    public AuthService(IUsuarioRepository usuarioRepository) {
        this.usuarioRepository = usuarioRepository;
    }

    public boolean authenticate(String username, String password) {
        Usuario usuario = usuarioRepository.findByUsername(username);
        return usuario != null && usuario.getPassword().equals(password);
    }
}
