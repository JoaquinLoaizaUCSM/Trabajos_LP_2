package Trabajo_4.actividad.repository;

import Trabajo_4.actividad.models.Archivo;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class ArchivoRepositoryImpl implements IArchivoRepository{
    private List<Archivo> archivos = new ArrayList<>();

    @Override
    public void createArchivo(Archivo archivo) {
        archivos.add(archivo);
        System.out.println("Archivo created: " + archivo.getNombre());
    }

    @Override
    public void deleteArchivo(String name) {
        Optional<Archivo> archivoToRemove = archivos.stream()
                .filter(archivo -> archivo.getNombre().equals(name))
                .findFirst();

        archivoToRemove.ifPresent(archivos::remove);
        System.out.println("Archivo deleted with name: " + name);
    }

    @Override
    public void AdmitArchivo(Archivo archivo) {
//        archivo.setStatus("Admitted");
        System.out.println("Archivo admitted: " + archivo.getNombre());
    }
}