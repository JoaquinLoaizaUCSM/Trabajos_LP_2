package Trabajo_4.actividad.repository;

import Trabajo_4.actividad.models.Archivo;

public interface IArchivoRepository {

    void createArchivo(Archivo archivo);

    void deleteArchivo(String id);

    void AdmitArchivo(Archivo archivo);
}
