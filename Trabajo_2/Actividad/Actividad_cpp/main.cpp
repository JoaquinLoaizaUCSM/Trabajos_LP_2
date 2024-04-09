
#include "Gestor.h"
#include <iostream>
using namespace std;

int main(){
    Gestor Gest_01;
    Tarea tarea_01("03", "Quiero_Dormir", "28/10/2050");
    Tarea tarea_02("04", "aaaaaa", "22/12/2043");
    Gest_01.añadir_tarea(tarea_01);
    Gest_01.añadir_tarea(tarea_02);
    //Tareas sin completar
    Gest_01.mostrar();
    //Tareas completadas
    cout << "Funcionamiento Completar xd" << endl;
    Gest_01.completar("03");
    Gest_01.mostrar();
    return 0;
}
