from abc import ABC, abstractmethod
from datetime import date

class Tarea(ABC):
    def __init__(self, titulo, descripcion, fecha_limite):
        self.titulo = titulo
        self.descripcion = descripcion
        self.fecha_limite = fecha_limite
        self.completada = False

    @abstractmethod
    def completar_tarea(self):
        pass
    def mostrar_tiempo_restante(self):
        pass

class TareaSimple(Tarea):
    def __init__(self, titulo, descripcion, fecha_limite):
        super().__init__(titulo, descripcion, fecha_limite)

    def completar_tarea(self):
        self.completada = True
    def mostrar_tiempo_restante(self):
        hoy = date.today()
        tiempo_restante = self.fecha_limite - hoy
        print(f"Tiempo restante: {tiempo_restante.days} dias")

class TareaImportante(Tarea):
    def __init__(self, titulo, descripcion, fecha_limite):
        super().__init__(titulo, descripcion, fecha_limite)

    def completar_tarea(self):
        self.completada = True
    def mostrar_tiempo_restante(self):
        hoy = date.today()
        tiempo_restante = self.fecha_limite - hoy
        print(f"Tiempo restante: {tiempo_restante.days} dias")

class GestorTareas:
    def __init__(self):
        self.tareas = []

    def anexar_tarea(self, tarea):
        self.tareas.append(tarea)

    def mostrar_tareas_pendientes(self):
        print("Lista de tareas pendientes: ")
        for tarea in self.tareas:
            if not tarea.completada:
                print(f"- Titulo: {tarea.titulo}\n"
                      f"- Descripcion: {tarea.descripcion}\n"
                      f"- Fecha Limite: {tarea.fecha_limite}\n")

    def mostrar_tareas(self):
        print("Lista de tareas : ")
        for tarea in self.tareas:
            print(f"- Titulo: {tarea.titulo}\n"
                  f"- Descripcion: {tarea.descripcion}\n"
                  f"- Fecha Limite: {tarea.fecha_limite}\n"
                  f"- Completada: {tarea.completada}\n")

    def completar_tareas(self, tarea):
        tarea.completar_tarea()

def probar_metodos(tarea):
    print("\nProbarmente")
    tarea.mostrar_tiempo_restante()


tareaImportante = TareaImportante("Viaje","viaje anual de vacaciones", date(2024,12,15))
tareaSimple = TareaSimple("Compras","Ir por la tarde a la tienda", date(2024,4,15))

gestor = GestorTareas()
gestor.anexar_tarea(tareaImportante)
gestor.anexar_tarea(tareaSimple)

# Mostrar tareas pendientes
gestor.mostrar_tareas_pendientes()
# Completar tarea1
gestor.completar_tareas(tareaSimple)
gestor.mostrar_tareas_pendientes()

tareaImportante.mostrar_tiempo_restante()

probar_metodos(tareaSimple)