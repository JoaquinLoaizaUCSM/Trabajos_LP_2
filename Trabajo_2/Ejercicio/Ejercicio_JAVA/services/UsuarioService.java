package Trabajo_4.actividad.services;

import Trabajo_4.actividad.models.Usuario;
import Trabajo_4.actividad.repository.IUsuarioRepository;

public class UsuarioService {

    private IUsuarioRepository usuarioRepository;

    public UsuarioService(IUsuarioRepository usuarioRepository) {
        this.usuarioRepository = usuarioRepository;
    }

    public void registerUsuario(Usuario usuario) {
        usuarioRepository.save(usuario);
    }

    public Usuario getUsuarioById(Long id) {
        return usuarioRepository.findById(id);
    }

    public void updateUsuario(Usuario usuario) {
        usuarioRepository.update(usuario);
    }

    public void deleteUsuario(Long id) {
        usuarioRepository.deleteById(id);
    }
}