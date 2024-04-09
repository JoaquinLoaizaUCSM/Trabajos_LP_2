package Trabajo_4.actividad.repository;


import Trabajo_4.actividad.models.Usuario;

public interface IUsuarioRepository {

    Usuario findByUsername(String username);

    void save(Usuario usuario);

    Usuario findById(Long id);

    void update(Usuario usuario);

    void deleteById(Long id);
}