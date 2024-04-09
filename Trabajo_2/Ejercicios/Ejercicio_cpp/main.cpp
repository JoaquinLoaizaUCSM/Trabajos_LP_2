
#include "Comentarios.h"
#include "GestorArchivos.h"
#include "Proyectos.h"
#include "Gestor.h"
#include <iostream>
using namespace std;

int main(){
//    Gestor Gest_01;
//    Tarea tarea_01("03", "Quiero_Dormir", "28/10/2050");
//    Tarea tarea_02("04", "aaaaaa", "22/12/2043");
//    Gest_01.anadir_tarea(tarea_01);
//    Gest_01.anadir_tarea(tarea_02);
//    //Tareas sin completar
//    Gest_01.mostrar();
//    //Tareas completadas
//    cout << "Funcionamiento Completar xd" << endl;
//    Gest_01.completar("03");
//    Gest_01.mostrar();

    Proyectos proyectoX("Ivestigación");
    //proyectoX.añadirTarea();
    proyectoX.mostrar_tareas();
    //proyectoX.finalizarTarea();

    Comentarios comentario1("Sugerencia Imagenes Multiespectrales xd","2024/4/8","Kiko");
    comentario1.mostrar_comentarios();
    comentario1.eliminar_comentario();

    GestorArchivos archivox = GestorArchivos();

    archivox.escribir("Carpeta X");
    archivox.leer("Carpeta x");
    archivox.enviar("Carpeta x");
    archivox.eliminar("Carpeta X");

    return 0;
}
